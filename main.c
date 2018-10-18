#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main() {

	Matrix G;

	initMatrix(&G, 6, 4);

	setAt(&G, 0, 0, 1);
	setAt(&G, 0, 1, 0);
	setAt(&G, 0, 2, 0);
	setAt(&G, 0, 3, 0);

	setAt(&G, 1, 0, 1);
	setAt(&G, 1, 1, 0);
	setAt(&G, 1, 2, 0);
	setAt(&G, 1, 3, 0);

	setAt(&G, 2, 0, 1);
	setAt(&G, 2, 1, 0);
	setAt(&G, 2, 2, 0);
	setAt(&G, 2, 3, 0);

	setAt(&G, 3, 0, 0);
	setAt(&G, 3, 1, 1);
	setAt(&G, 3, 2, 0);
	setAt(&G, 3, 3, 0);

	setAt(&G, 4, 0, 0);
	setAt(&G, 4, 1, 0);
	setAt(&G, 4, 2, 1);
	setAt(&G, 4, 3, 0);

	setAt(&G, 5, 0, 0);
	setAt(&G, 5, 1, 0);
	setAt(&G, 5, 2, 0);
	setAt(&G, 5, 3, 1);

	freeMatrix(&G);

	return 0;
}
