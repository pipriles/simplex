#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main() {

	Matrix m,cofactors;

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

	cofactors = cofactorsMatrix(m);

	printMatrix(cofactors);

	freeMatrix(&m);
	freeMatrix(&cofactors);

	return 0;
}
