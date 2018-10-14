#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"

void initMatrix(Matrix *m, int h, int w) {
	m->loc = (MTYPE*) malloc(w * h * sizeof(MTYPE));
	m->w = w;
	m->h = h;
}

void freeMatrix(Matrix *m) {
	free(m->loc);
	m->w = 0;
	m->h = 0;
}

MTYPE getAt(Matrix m, int i, int j) {
	return m.loc[i * m.w + j];
}

void setAt(Matrix *m, int i, int j, MTYPE value) {
	m->loc[i * m->w + j] = value;
}


/* Print matrix */
void printMatrix(Matrix m) {
	for(int i=0; i < m.h; i++) {
		for(int j=0; j < m.w; j++) {
			printf(" %.1f", getAt(m, i, j));
		} printf("\n");
	}
}

MTYPE determinant(Matrix m){
	Matrix nMatx;
	MTYPE val = 0;
	int mult = -1;

	if(m.w == 1) return getAt(m,0,0);

	initMatrix(&nMatx,m.h-1,m.w-1);
	for(int j = 0; j < m.w; j++){
		sliceAt(m, nMatx,0,j);
		mult *= -1;
		val +=  mult * getAt(m,0,j) * determinant(nMatx);
	}
	freeMatrix(&nMatx);
	return val;
}

void sliceAt(Matrix m, Matrix nMatx, int is, int js){
	int ni = 0,nj = 0;
	for(int i = 0; i < m.h; i++){
		if(is != i){
			for(int j = 0; j < m.w; j++){
				if(js != j){
					setAt(&nMatx,ni,nj,getAt(m,i,j));
					nj++;
					if(nj == nMatx.w){
						nj = 0;
						ni++;
					}
				}
			}
		}
	}
}

Matrix minorsMatrix(Matrix m){
	Matrix nMatx, minors;

	initMatrix(&nMatx,m.h-1,m.w-1);
	initMatrix(&minors,m.h,m.w);
	for(int i=0; i < m.h; i++) {
		for(int j=0; j < m.w; j++) {
			sliceAt(m,nMatx,i,j);
			setAt(&minors,i,j,determinant(nMatx));
		}
	}
	freeMatrix(&nMatx);
	return minors;
}

Matrix cofactorsMatrix(Matrix m){
	Matrix minors, cofactors;
	int mult = -1;

	minors = minorsMatrix(m);
	initMatrix(&cofactors,minors.h,minors.w);

	for(int i=0; i < minors.h; i++) {
		for(int j=0; j < minors.w; j++) {
			mult *= -1;
			setAt(&cofactors,i,j,mult * getAt(minors,i,j));
		}
	}
	freeMatrix(&minors);
	return cofactors;
}