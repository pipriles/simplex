#ifndef _SIMPLEX_H_
#define _SIMPLEX_H_

#include "matrix.h"

Matrix B, Cb;

void initialize(Matrix G);
MTYPE* minimum(MTYPE *, size_t);

#endif

