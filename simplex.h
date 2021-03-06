#ifndef _SIMPLEX_H_
#define _SIMPLEX_H_

#include "matrix.h"

#define true 1
#define false 0

typedef short bool;

void initialize(Matrix, Matrix, size_t **, size_t **);
void simplex(Matrix, Matrix, Matrix, Matrix, Matrix, int);
void simplexEnd();

Matrix loadIdentity(size_t);
Matrix oComputation(Matrix, Matrix, Matrix, Matrix);

void swap(Matrix, Matrix, Matrix, Matrix, size_t *, size_t *, size_t, size_t);

long optimality(Matrix, Matrix, Matrix, Matrix);
long feasibility(Vector, Vector);
long minimum(MTYPE *, size_t);

bool finished(MTYPE *, size_t);

#endif

