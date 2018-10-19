#ifndef _SIMPLEX_H_
#define _SIMPLEX_H_

#include "matrix.h"

Matrix B, Cb;

void initialize(Matrix G);
<<<<<<< HEAD
size_t optimality(Matrix NB, Matrix Binv, Matrix Cnb);
Matrix loadIdentity(size_t s);
void simplex(Matrix NB,Matrix Cnb,Matrix b);
void simplexEnd();
size_t minimum(MTYPE *array, size_t n);
=======
void simplex(Matrix NB,Matrix Cnb,Matrix b);
void simplexEnd();

int optimality(Matrix NB, Matrix Binv, Matrix Cnb);
size_t minimum(MTYPE *, size_t);

Matrix loadIdentity(size_t s);
>>>>>>> 3af07e61d4a57878de1702d5c1736b5572b88842

#endif

