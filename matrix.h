#ifndef _MATRIX_H_
#define _MATRIX_H_

#define MTYPE float

typedef struct {
	MTYPE *loc;
	int w, h;
} Matrix;

typedef Matrix Vector;

void initMatrix(Matrix *, int, int);
void initVector(Vector *, int);
void freeMatrix(Matrix *);

MTYPE getAt(Matrix, int, int);
void  setAt(Matrix *, int, int, MTYPE);
void sliceAt(Matrix, Matrix, int, int);

void printMatrix(Matrix);
void truncate(Matrix *);

/* Matrix operations */
MTYPE determinant(Matrix);

Matrix inverse(Matrix);
Matrix product(Matrix, Matrix);
Matrix kproduct(Matrix, MTYPE);
Matrix transpose(Matrix);
Matrix minorsMatrix(Matrix);
Matrix cofactorsMatrix(Matrix);
Matrix adjointMatrix(Matrix);

#endif

