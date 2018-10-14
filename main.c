#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main() {

	Matrix m;

	initMatrix(&m, 3, 2);

	setAt(&m, 2, 1, 1);
	setAt(&m, 1, 0, 2);
	setAt(&m, 0, 1, 3);

	printf("%f\n", getAt(m, 1, 0));

	printMatrix(m);
	printf("Hello world!");

	freeMatrix(&m);

	return 0;
}
