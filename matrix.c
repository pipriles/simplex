#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "matrix.h"

void initMatrix(Matrix *m, size_t h, size_t w) {
	/* Should use malloc + memset or calloc? */
	m->loc = (MTYPE *) malloc(w * h * sizeof(MTYPE));
	m->w = w;
	m->h = h;
}

bool isidentity(Matrix m) {

	size_t i, n = m.w;
	bool ret = true;

	if (m.w != m.h) return false;
	for (i=0; i < n; i++) 
		ret = ret && (getAt(m, i, i) == 1);

	return ret;
}

void freeMatrix(Matrix *m) {
	free(m->loc);
	m->w = 0;
	m->h = 0;
}

MTYPE getAt(Matrix m, size_t i, size_t j) {
	return m.loc[i*m.w + j];
}

void setAt(Matrix *m, size_t i, size_t j, MTYPE value) {
	m->loc[i*m->w + j] = value;
}

/* Print matrix */
void printMatrix(Matrix m) {
	for (size_t i=0; i < m.h; i++) {
		for (size_t j=0; j < m.w; j++) {
			printf(" %.4f", getAt(m, i, j));
		} printf("\n");
	}
}

Matrix product(Matrix m1, Matrix m2) {

	Matrix r;
	size_t i = 0, j = 0, k = 0;
	size_t h = m1.h;
	size_t w = m2.w;
	size_t s = m2.h;

	if (m1.w != m2.h) {
		printf("\n");
		printMatrix(m1);
		printf("\n");
		printMatrix(m2);
		printf("Can't compute product!");
		exit(1);
	}

	initMatrix(&r, m1.h, m2.w);

	for (i=0; i < h; i++)
		for (j=0; j < w; j++) {
			r.loc[i*w + j] = 0;
			for (k=0; k < s; k++)
				r.loc[i*w + j] += getAt(m1, i, k) * getAt(m2, k, j);
		}

	return r;

}

MTYPE determinant(Matrix m){

	Matrix nMatx;
	MTYPE val = 0;
	int mult = -1;

	if(m.w == 1) return getAt(m,0,0);

	initMatrix(&nMatx,m.h-1,m.w-1);
	for(size_t j = 0; j < m.w; j++){
		sliceAt(m, nMatx,0,j);
		mult *= -1;
		val +=  mult * getAt(m,0,j) * determinant(nMatx);
	}

	freeMatrix(&nMatx);
	return val;

}

void sliceAt(Matrix m, Matrix nMatx, size_t is, size_t js){

	size_t ni = 0,nj = 0;
	for(size_t i = 0; i < m.h; i++){
		if(is != i){
			for(size_t j = 0; j < m.w; j++){
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
	for(size_t i=0; i < m.h; i++) {
		for(size_t j=0; j < m.w; j++) {
			sliceAt(m,nMatx,i,j);
			setAt(&minors,i,j,determinant(nMatx));
		}
	}

	freeMatrix(&nMatx);
	return minors;
}

Matrix cofactorsMatrix(Matrix m){

	Matrix minors, cofactors;
	int mult;

	minors = minorsMatrix(m);
	initMatrix(&cofactors,minors.h,minors.w);

	for(size_t i=0; i < minors.h; i++) {
		for(size_t j=0; j < minors.w; j++) {
			if((i+j)%2 == 0) mult = 1;
			else mult = -1;
			setAt(&cofactors,i,j,mult * getAt(minors,i,j));
		}
	}

	freeMatrix(&minors);
	return cofactors;
}

Matrix transpose(Matrix m) {

	Matrix r;
	initMatrix(&r, m.w, m.h);

	for (size_t i=0; i < m.h; i++) 
		for (size_t j=0; j < m.w; j++)
			setAt(&r, j, i, getAt(m, i, j));

	return r;
}

Matrix kproduct(Matrix m, MTYPE k) {

	Matrix r;
	size_t h = m.h;
	size_t w = m.w;
	size_t i;

	initMatrix(&r, m.h, m.w);
	for (i=0; i < h*w; i++)
		r.loc[i] = m.loc[i] * k;

	return r;
}

Matrix adjointMatrix(Matrix m){

	Matrix cofactors;

	cofactors = cofactorsMatrix(m);
	return transpose(cofactors);
}

Matrix inverse(Matrix m) {

	Matrix adjoint = adjointMatrix(m), inv;
	MTYPE det = determinant(m);

	inv = kproduct(adjoint, 1.0/det);
	freeMatrix(&adjoint);

	return inv;
}

void truncate(Matrix *m) {

	double t = 0.0001;
	size_t i, size = m->w * m->h;

	for (i=0; i < size; i++)
		if ( fabs(m->loc[i]) < t ) m->loc[i] = 0;
}

Matrix substract(Matrix a, Matrix b){

	Matrix s;
	initMatrix(&s, a.h, a.w);

	if (a.w != b.w && a.h != b.h) {
		printf("Can't compute sunbstract!");
		exit(1);
	}

	for (size_t i=0; i < a.h; i++) 
		for (size_t j=0; j < a.w; j++)
			setAt(&s, i, j, getAt(a,i,j) - getAt(b,i,j));

	return s;
}	

Matrix fromColumns(Matrix m, size_t *v, size_t n) {

	size_t index;
	Matrix new;
	MTYPE value;

	initMatrix(&new, m.h, n);

	for (size_t i=0; i < n; i++)
		for (size_t j=0; j < m.h; j++) {
			index = v[i];
			value = getAt(m, j, index);
			setAt(&new, j, i, value);
		}

	return new;
}


