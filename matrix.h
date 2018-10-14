#ifndef _MATRIX_H_
#define _MATRIX_H_

#define MTYPE float

typedef struct {
	MTYPE *loc;
	int w, h;
} Matrix;

void initMatrix(Matrix *, int, int);
void freeMatrix(Matrix *);

MTYPE getAt(Matrix, int, int);
void  setAt(Matrix *, int, int, MTYPE);

void printMatrix(Matrix);

#endif
