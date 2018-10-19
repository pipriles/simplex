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

long optimality(Matrix NB, Matrix Binv, Matrix Cnb){
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

int finished(MTYPE *array, size_t n) {

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

void swap(Matrix NB,Matrix Cnb,size_t *NBV, size_t *BV, size_t entry, size_t exit){
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
	BV[exit] = NBV[entry] ^ BV[exit];
	NBV[entry] = NBV[entry] ^ BV[exit];
}

void simplex(Matrix NB, Matrix Cnb, Matrix b){

	size_t *NBV = NULL, *BV = NULL;
	long entry;
	Matrix Binv;

	initialize(NB, NBV, BV);

	Binv = inverse(B);
	entry = optimality(NB, Binv, Cnb);

	if (entry != -2) {
		swap(NB,Cnb,NBV,BV,entry,1);
	}

	else {
		//imprimir cosas por q termino
		//andres estuvo aqui
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
	BV  = (size_t *) malloc(B.w * sizeof(size_t));

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

long minimum(MTYPE *array, size_t n) {

	long index = 0;

	if (!array) 
		return -1;

	for (size_t i=1; i < n; i++)
		if (array[i] < array[index]) index = i;

	return index;
}

