#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main() {

	Matrix G, C, b;

	initMatrix(&G, 4, 6);
	initMatrix(&C, 1, 6);
	initMatrix(&b, 4, 1);

	setAt(&C, 0, 0, 5);
	setAt(&C, 0, 1, 4);
	setAt(&C, 0, 2, 0);
	setAt(&C, 0, 3, 0);
	setAt(&C, 0, 4, 0);
	setAt(&C, 0, 5, 0);

	setAt(&b, 0, 0, 24);
	setAt(&b, 1, 0, 6);
	setAt(&b, 2, 0, 1);
	setAt(&b, 3, 0, 2);

	setAt(&b, 0, 0, 24);
	setAt(&b, 0, 1, 6);
	setAt(&b, 0, 2, 1);
	setAt(&b, 0, 3, 2);

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
	freeMatrix(&C);
	freeMatrix(&b);

	return 0;
}
