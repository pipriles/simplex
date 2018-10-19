#ifndef _SIMPLEX_H_
#define _SIMPLEX_H_
#include "matrix.h"

Matrix B, Cb;

void initialize(Matrix G, size_t *, size_t *);
size_t optimality(Matrix NB, Matrix Binv, Matrix Cnb);
Matrix oComputation(Matrix NB, Matrix Binv, Matrix Cnb);
Matrix loadIdentity(size_t s);
void simplex(Matrix NB,Matrix Cnb,Matrix b);
void simplexEnd();
size_t minimum(MTYPE *array, size_t n);
int finished(MTYPE *array, size_t n);
void swap(Matrix NB,Matrix Cnb,size_t *NBV, size_t *BV, size_t entry, size_t exit);

#endif

