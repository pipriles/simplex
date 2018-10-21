#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>

#include "matrix.h"
#include "simplex.h"

Matrix oComputation(Matrix NB, Matrix Binv, Matrix Cnb){
	Matrix O, decition,zj;

	initMatrix(&decition, 1, NB.w);
	O = product(Cb,Binv);

	zj = product(O,NB);
	decition = substract(zj,Cnb);

	freeMatrix(&O);
	freeMatrix(&zj);
	return decition;
}

long optimality(Matrix NB, Matrix Binv, Matrix Cnb){

	size_t index;
	Matrix decition;
	bool finish;

	decition = oComputation(NB,Binv,Cnb);
	index = minimum(decition.loc, decition.w);
	finish = finished(decition.loc, decition.w);
	freeMatrix(&decition);
	if(finish) return -2;
	else return index;
}

bool finished(MTYPE *array, size_t n) {
	bool cond = true;
	for (size_t i=0; i < n && cond; i++)
		if (array[i] < 0) cond = false;
	return cond;
}

Matrix loadIdentity(size_t s){
	Matrix identity;
	initMatrix(&identity, s, s);

	for(size_t i = 0; i < s; i++){
		for(size_t j = 0; j < s; j++){
			setAt(&identity , i, j, 0);
			if(i == j) setAt(&identity , i, j, 1);
		}
	}

	return identity;
}

void swap(Matrix NB, Matrix Cnb, 
		size_t *NBV, size_t *BV, size_t entry, size_t exit) {

	MTYPE aux;

	for(size_t i = 0; i < NB.h; i++){
		aux = getAt(NB,i,entry);
		setAt(&NB,i,entry,getAt(B,i,exit));
		setAt(&B,i,exit,aux);
	}
	aux = getAt(Cnb,0,entry);
	setAt(&Cnb,0,entry,getAt(Cb,0,exit));
	setAt(&Cb,0,exit,aux);

	NBV[entry] = NBV[entry] ^ BV[exit];
	BV[exit]   = NBV[entry] ^ BV[exit];
	NBV[entry] = NBV[entry] ^ BV[exit];
}

void simplex(Matrix NB, Matrix Cnb, Matrix b, int mult){

	size_t *NBV = NULL, *BV = NULL;
	long entry, leave;
	bool finish = false;

	Matrix Binv, Xb, BP, Pi, z;

	initialize(NB, &NBV, &BV);

	while(!finish){
		Binv = inverse(B);
		truncate(&Binv);

		/* Optimality computations */
		entry = optimality(NB, Binv, Cnb);

		if (entry != -2) {
			// Compute parameters for feasibility
			Xb = product(Binv, b);
			Pi = fromColumns(NB, (size_t *) &entry, 1);
			BP = product(Binv, Pi);
			// Index from the basis 
			leave = feasibility(Xb, BP);
			//printf(" %li", leave);
			//printMatrix(B);

			freeMatrix(&Xb);
			freeMatrix(&BP);
			freeMatrix(&Pi);

			swap(NB, Cnb, NBV, BV, entry, leave);
		}

		else {
			finish = true;
		}

		printf("NO BASE:\n");
		printMatrix(NB);
				
		printf("BASE:\n");
		printMatrix(B);
		printf("--------------------\n");

	}
	if (finish){
		printf("INVERSE:\n");
		Binv = inverse(B);
		printMatrix(Binv);
		Xb = product(Binv,b);
		printf("VALUES:\n");
		printMatrix(Xb);
		printf("COEFICIENTS:\n");
		printMatrix(Cb);
		printMatrix(Cnb);
		printf("OBJECTIVE FUNCTION:\n");
		z = product(Cb,Xb);
		printf(" %f\n",z.loc[0]*mult);
		printf("VARIABLE ORDER:\n");
		for(size_t i = 0; i < B.w;i++){
			printf(" %zu", BV[i]);
		}
		printf("\n");
	}

	freeMatrix(&z);
	freeMatrix(&Xb);
	freeMatrix(&Binv);
	simplexEnd();
	free(NBV);
	free(BV);
}

long feasibility(Vector Xb, Vector BP) {

	/* Feasibility computations */

	size_t i, cont, size = Xb.w * Xb.h;
	long leave = -1;

	size_t indexs[size]; // Real index...
	MTYPE choices[size];

	for (i=0, cont=0; i < size; i++) 
		if ( Xb.loc[i] >= 0 && BP.loc[i] > 0 ) {
			indexs[cont]  = i;
			choices[cont] = Xb.loc[i] / BP.loc[i];
			cont++;
		}

	if (cont <= 0) {
		printf("QUE NOOOOOOO, PORROS NO!!!!!!!");
		exit(1);
	}

	leave = minimum(choices, cont);

	// Debug
	// printMatrix(Xb);
	// printf("\n");
	// printMatrix(BP);
	// printf("MIN: %f\n", choices[leave]);
	// printf("LEAVING: %lu\n", indexs[leave]);
	// printf("\n");
	// printMatrix(BP);

	/* -------------------- */

	return indexs[leave];
}

void initialize(Matrix NB, size_t **NBV, size_t **BV){

	size_t n = 0;
	initMatrix(&Cb, 1, NB.h);
	B = loadIdentity(NB.h);

	for(size_t i = 0; i < Cb.w; i++)
		setAt(&Cb , 0, i, 0);	

	*NBV = (size_t *) malloc(NB.w * sizeof(size_t));
	*BV  = (size_t *) malloc(B.w  * sizeof(size_t));

	for(size_t i = 0; i < NB.w; i++) (*NBV)[i] = n++;
	for(size_t i = 0; i < B.w; i++)  (*BV)[i] = n++;
}

void simplexEnd(){
	freeMatrix(&Cb);
	freeMatrix(&B);
}

long minimum(MTYPE *array, size_t n) {

	long index = 0;

	if (!array) 
		return -1;

	for (size_t i=1; i < n; i++)
		if (array[i] < array[index]) index = i;

	return index;
}
