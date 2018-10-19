#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "matrix.h"
#include "simplex.h"

<<<<<<< HEAD
size_t optimality(Matrix NB, Matrix Binv, Matrix Cnb){
	Matrix O, decition;
	Matrix zj, Paux;
	size_t col[1], index;
=======
int optimality(Matrix NB, Matrix Binv, Matrix Cnb){
	Matrix O, decition, Paux;
	Matrix zj;
	size_t col[1]; 
>>>>>>> 3af07e61d4a57878de1702d5c1736b5572b88842

	initMatrix(&decition, 1, NB.w);
	O = product(Cb,Binv);

	for(size_t i = 0; i < NB.w; i++){
		col[0] = i;
		Paux = fromColumns(NB, col, 1);
<<<<<<< HEAD
		zj = product(O,Paux);
		setAt(&decition,0,i,getAt(zj, 0, 0) - getAt(Cnb, 0, i));
		freeMatrix(&zj);
		freeMatrix(&Paux);
	}
	index = minimum(decition.loc, decition.w);
	freeMatrix(&O);
	freeMatrix(&decition);
	return index;
=======
		printMatrix(Paux);
		printf("\n");
		zj = product(O,Paux);
		setAt(&decition,1,i,getAt(zj, 0, 0) - getAt(Cnb, 0, i));
		freeMatrix(&zj);
		freeMatrix(&Paux);
	}

	printMatrix(decition);

	freeMatrix(&O);
	freeMatrix(&decition);
	return 1;
>>>>>>> 3af07e61d4a57878de1702d5c1736b5572b88842
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

<<<<<<< HEAD
void simplex(Matrix NB,Matrix Cnb,Matrix b){
	Matrix Binv;
	size_t entry;
=======
void simplex(Matrix NB, Matrix Cnb, Matrix b){

	Matrix Binv;
	int entry;
>>>>>>> 3af07e61d4a57878de1702d5c1736b5572b88842

	initialize(NB);

	Binv = inverse(B);
	entry = optimality(NB,Binv,Cnb);
	simplexEnd();
}

void initialize(Matrix NB){
	initMatrix(&Cb, 1, NB.h);
	B = loadIdentity(NB.h);

	for(size_t i = 0; i < Cb.w; i++)
		setAt(&Cb , 0, i, 0);
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
<<<<<<< HEAD
}
=======
}

>>>>>>> 3af07e61d4a57878de1702d5c1736b5572b88842
