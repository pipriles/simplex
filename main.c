#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main() {

	Matrix m1, m2, r;

	initMatrix(&m1, 3, 2);
	initMatrix(&m2, 2, 2);

	setAt(&m1, 0, 0, 1);
	setAt(&m1, 0, 1, -2);
	setAt(&m1, 1, 0, 0);
	setAt(&m1, 1, 1, 3);
	setAt(&m1, 2, 0, -1);
	setAt(&m1, 2, 1, 4);

	setAt(&m2, 0, 0, 4);
	setAt(&m2, 0, 1, 1);
	setAt(&m2, 1, 0, -1);
	setAt(&m2, 1, 1, 2);

	r = product(m1, m2);
	printMatrix(r);

	freeMatrix(&m1);
	freeMatrix(&m2);
	freeMatrix(&r);

	return 0;
}

