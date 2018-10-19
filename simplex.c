#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "matrix.h"
#include "simplex.h"

void loadIdentity(size_t s){
	Matrix identity;

	initMatrix(&indentity, s, s);

	for(int i = 0; i < s; i++){
		for(int j = 0; j < s; j++){
			setAt(&indentity , i, j, 0);
			if(i == j) setAt(&indentity , i, j, 1);
		}
	}

	return identity;
}

void simplex(Matrix NB,Matrix Cn,Matrix b){
	initialize()
	simplexEnd()
}

void initialize(Matrix NB){
	initMatrix(&Cb, 1, NB.h);
	B = loadIdentity(NB.h);

	for(int i = 0; i < Cb.w; i++)
		setAt(&Cb , 0, i, 0);
}

void simplexEnd(){
	freeMatrix(&Cb);
	freeMatrix(&B);
}

MTYPE* minimum(MTYPE *array, size_t n) {

	MTYPE *found = array;

	if (!array) 
		return NULL;

	for (size_t i=0; i < n; i++)
		if (array[i] < *found) found = array + i;

	return found;
}

