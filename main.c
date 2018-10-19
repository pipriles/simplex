#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"
#include "simplex.h"

int main() {

	Matrix G, C, b;

	initMatrix(&G, 3, 3);
	initMatrix(&C, 1, 3);
	initMatrix(&b, 3, 1);

	b.loc[0] = 240;
	b.loc[1] = 100;
	b.loc[2] = 0;

	C.loc[0] = 70;
	C.loc[1] = 50;
	C.loc[2] = 35;

	setAt(&G, 0, 0,  4);
	setAt(&G, 1, 0,  2);
	setAt(&G, 2, 0, -4);

	setAt(&G, 0, 1, 3);
	setAt(&G, 1, 1, 1);
	setAt(&G, 2, 1, 1);

	setAt(&G, 0, 2, 1);
	setAt(&G, 1, 2, 1);
	setAt(&G, 2, 2, 0);

	printMatrix(G);
	simplex(G,C,b);

	freeMatrix(&G);
	freeMatrix(&C);
	freeMatrix(&b);

	return 0;
}
