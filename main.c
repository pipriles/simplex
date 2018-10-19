#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"
#include "simplex.h"

int main() {

	Matrix G, C, b;

	initMatrix(&G, 4, 2);
	initMatrix(&C, 1, 2);
	initMatrix(&b, 4, 1);

	b.loc[0] = 24;
	b.loc[1] = 6;
	b.loc[2] = 1;
	b.loc[3] = 2;

	C.loc[0] = 5;
	C.loc[1] = 4;

	setAt(&G, 0, 0, 6);
	setAt(&G, 1, 0, 1);
	setAt(&G, 2, 0, -1);
	setAt(&G, 3, 0, 0);

	setAt(&G, 0, 1, 4);
	setAt(&G, 1, 1, 2);
	setAt(&G, 2, 1, 1);
	setAt(&G, 3, 1, 1);

	simplex(G,C,b);

	freeMatrix(&G);
	freeMatrix(&C);
	freeMatrix(&b);

	return 0;
}
