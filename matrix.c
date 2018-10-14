#include <stdlib.h>
#include <stdio.h>

#include "matrix.h"

void initMatrix(Matrix *m, int h, int w) {
	/* Should use malloc + memset or calloc? */
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
	return m.loc[i*m.w + j];
}

void setAt(Matrix *m, int i, int j, MTYPE value) {
	m->loc[i*m->w + j] = value;
}


/* Print matrix */
void printMatrix(Matrix m) {
	for (int i=0; i < m.h; i++) {
		for (int j=0; j < m.w; j++) {
			printf(" %.1f", getAt(m, i, j));
		} printf("\n");
	}
}

Matrix product(Matrix m1, Matrix m2) {

	Matrix r;
	unsigned int h = m1.h;
	unsigned int w = m2.w;
	unsigned int s = m2.h;

	if (m1.w != m2.h) {
		printf("Can't compute product!");
		exit(1);
	}

	initMatrix(&r, m1.h, m2.w);

	for (int i=0; i < h; i++)
		for (int j=0; j < w; j++) {
			r.loc[i*w + j] = 0;
			for (int k=0; k < s; k++)
				r.loc[i*w + j] += getAt(m1, i, k) * getAt(m2, k, j);
		}

	return r;
}

