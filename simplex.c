#include <stdlib.h>
#include <stdio.h>
#include <math.h>

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

size_t optimality(Matrix NB, Matrix Binv, Matrix Cnb){
	size_t index;
	Matrix decition;
	int finish;

	decition = oComputation(NB,Binv,Cnb);
	index = minimum(decition.loc, decition.w);
	finish = finished(decition.loc, decition.w);
	freeMatrix(&decition);
	if(finish) return -2;
	else return index;
}

int finished(MTYPE *array, size_t n){
	int positive = 1;

	for (size_t i=0; i < n && positive; i++)
		if (array[i] < 0) positive = 0;

	return positive;
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

void simplex(Matrix NB,Matrix Cnb,Matrix b){
	Matrix Binv;
	size_t entry, *NBV, *BV;

	initialize(NB, NBV, BV);

	Binv = inverse(B);
	entry = optimality(NB,Binv,Cnb);
	if(entry != -2){

	}
	else{
		//imprimir cosas por q termino
	}
	simplexEnd();
}

void initialize(Matrix NB, size_t *NBV, size_t *BV){
	size_t n = 0;

	initMatrix(&Cb, 1, NB.h);
	B = loadIdentity(NB.h);

	for(size_t i = 0; i < Cb.w; i++)
		setAt(&Cb , 0, i, 0);

	NBV = (size_t *) malloc(NB.w * sizeof(size_t));
	BV = (size_t *) malloc(B.w * sizeof(size_t));

	for(size_t i = 0; i < NB.w; i++){
		NBV[i] = n;
		n++;
	}
	for(size_t i = 0; i < B.w; i++){
		BV[i] = n;
		n++;
	}
}

void simplexEnd(){
	freeMatrix(&Cb);
	freeMatrix(&B);
}

size_t minimum(MTYPE *array, size_t n) {

	size_t index = 0;

	if (!array) 
		return -1;

	for (size_t i=1; i < n; i++)
		if (array[i] < array[index]) index = i;

	return index;
}