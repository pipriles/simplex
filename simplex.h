#ifndef _SIMPLEX_H_
#define _SIMPLEX_H_
#include "matrix.h"

Matrix B, Cb;

void initialize(Matrix, size_t *, size_t *);
void simplex(Matrix, Matrix, Matrix);
void simplexEnd();

Matrix loadIdentity(size_t);
Matrix oComputation(Matrix, Matrix, Matrix);

void swap(Matrix, Matrix, size_t *, size_t *, size_t, size_t);

long optimality(Matrix, Matrix, Matrix);
long feasibility(Matrix, Matrix);
long minimum(MTYPE *, size_t);

int finished(MTYPE *, size_t);

#endif

