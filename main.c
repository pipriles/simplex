#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "matrix.h"
#include "simplex.h"

void parse_fn() {

	size_t length = 0;
	char str[100], token[100] = "", *acum = NULL;
	MTYPE sign = 1; 
	MTYPE value = 1;

	scanf(" %[^\n]", str);
	printf("%s\n", str);

	for (size_t i=0; i < 100; i++) {

		if ((str[i] >= 48 && str[i] <= 57) 
			|| str[i] == 46) {
			if (!acum) acum = &str[i];
			length++;
		}

		else if ((str[i] >= 97 && str[i] <= 122) 
			|| (str[i] >= 65 && str[i] <= 90)
			|| (str[i] == '\0')) {
			
			if (acum != NULL) {
				strncpy(token, acum, length);
				value = atof(token);
			} // add token to matrix

			printf(" %.2f", sign * value);

			// Clear token
			acum = NULL;
			length = 0;
			sign = 1;
			value = 1;
		}

		else if (str[i] == 45) sign = -1;
		if (str[i] == '\0') break;

	}
}

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

	// printMatrix(G);
	// simplex(G,C,b);
	ask_objective();

	freeMatrix(&G);
	freeMatrix(&C);
	freeMatrix(&b);

	return 0;
}
