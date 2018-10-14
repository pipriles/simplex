#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main() {

	Matrix m,inv;

	initMatrix(&m, 3, 3);

	setAt(&m, 0, 0, 3);
	setAt(&m, 0, 1, 0);
	setAt(&m, 0, 2, 2);

	setAt(&m, 1, 0, 2);
	setAt(&m, 1, 1, 0);
	setAt(&m, 1, 2, -2);

	setAt(&m, 2, 0, 0);
	setAt(&m, 2, 1, 1);
	setAt(&m, 2, 2, 1);

	inv = inverse(m);

	printMatrix(inv);

	freeMatrix(&m);
	freeMatrix(&inv);

	return 0;
}
