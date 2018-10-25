#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "matrix.h"
#include "simplex.h"

int main() {

	Matrix G, C, fB, b;
	int mult;

	initMatrix(&b, 3, 1);

	b.loc[0] = 240;
	b.loc[1] = 100;
	b.loc[2] = 0;

	// printMatrix(G);
	simplex(G, C, b, fB, mult);

	freeMatrix(&G);
	freeMatrix(&C);
	freeMatrix(&b);

	return 0;
}
