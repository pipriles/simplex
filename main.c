#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"
#include "simplex.h"

int main() {

	Matrix G, C, b;

	initMatrix(&G, 4, 2);
	initMatrix(&C, 1, 2);
	initMatrix(&b, 4, 1);

	setAt(&b, 0, 0, 24);
	setAt(&b, 1, 0, 6);
	setAt(&b, 2, 0, 1);
	setAt(&b, 3, 0, 2);

	setAt(&b, 0, 0, 24);
	setAt(&b, 0, 1, 6);
	setAt(&b, 0, 2, 1);
	setAt(&b, 0, 3, 2);

	setAt(&G, 0, 0, 6);
	setAt(&G, 0, 1, 1);
	setAt(&G, 0, 2, -1);
	setAt(&G, 0, 3, 0);

	setAt(&G, 1, 0, 4);
	setAt(&G, 1, 1, 2);
	setAt(&G, 1, 2, 1);
	setAt(&G, 1, 3, 1);

	setAt(&C, 0, 0, 5);
	setAt(&C, 0, 1, 4);

	freeMatrix(&G);
	freeMatrix(&C);
	freeMatrix(&b);


	MTYPE arr[] = { -99, 44.5, -2, -100 };
	size_t index = -1;
	index = minimum(arr, 4);
	printf("%f", arr[index]);

	return 0;
}
