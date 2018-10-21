#ifndef _MATRIX_H_
#define _MATRIX_H_

#define MTYPE float

#define true 1
#define false 0

typedef short bool;

typedef struct {
	MTYPE *loc;
	size_t w, h;
} Matrix;

typedef Matrix Vector;

void initMatrix(Matrix *, size_t, size_t);
void freeMatrix(Matrix *);

MTYPE getAt(Matrix, size_t, size_t);
void  setAt(Matrix *, size_t, size_t, MTYPE);
void sliceAt(Matrix, Matrix, size_t, size_t);

void printMatrix(Matrix);
void truncate(Matrix *);

/* Matrix operations */
MTYPE determinant(Matrix);

Matrix substract(Matrix, Matrix);
Matrix inverse(Matrix);
Matrix product(Matrix, Matrix);
Matrix kproduct(Matrix, MTYPE);
Matrix transpose(Matrix);
Matrix minorsMatrix(Matrix);
Matrix cofactorsMatrix(Matrix);
Matrix adjointMatrix(Matrix);

Matrix fromColumns(Matrix, size_t *, size_t);

#endif

