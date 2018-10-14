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

