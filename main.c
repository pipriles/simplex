#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main() {

	Matrix B, r;
	size_t cols[] = { 0, 3 };

	initMatrix(&B, 4, 4);

	setAt(&B, 0, 0, 1);
	setAt(&B, 0, 1, 0);
	setAt(&B, 0, 2, 0);
	setAt(&B, 0, 3, 0);

	setAt(&B, 1, 0, 0);
	setAt(&B, 1, 1, 1);
	setAt(&B, 1, 2, 0);
	setAt(&B, 1, 3, 0);

	setAt(&B, 2, 0, 0);
	setAt(&B, 2, 1, 0);
	setAt(&B, 2, 2, 1);
	setAt(&B, 2, 3, 0);

	setAt(&B, 3, 0, 0);
	setAt(&B, 3, 1, 0);
	setAt(&B, 3, 2, 0);
	setAt(&B, 3, 3, 1);

	// r = inverse(B);
	// truncate(&r);
	
	r = fromColumns(B, cols, 2);
	printMatrix(r);

	freeMatrix(&B);
	freeMatrix(&r);

	return 0;
}
