#ifndef _SIMPLEX_H_
#define _SIMPLEX_H_

#include "matrix.h"

Matrix B, Cb;

void initialize(Matrix G);
void simplex(Matrix NB,Matrix Cnb,Matrix b);
void simplexEnd();

int optimality(Matrix NB, Matrix Binv, Matrix Cnb);
size_t minimum(MTYPE *, size_t);

Matrix loadIdentity(size_t s);

#endif

