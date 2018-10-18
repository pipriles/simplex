#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

Matrix variableValues(Matrix r, Matrix b){
	return product(r,b);
}

MTYPE optimallity(Matrix C, Matrix r, Matrix P, Matrix CnB){
	Matrix O, PAUX;
	MTYPE min = -99999

	initMatrix(&PAUX, 1, P.h);

	for(int i = 0; i < P.w; i++){
		for(int j = 0; j < P.h; j++){
			setAt(&P, 0, j, getAt(P, i, j));
		}
		if(product(O,PAUX))
	}

	O = product(C,r);



	freeMatrix(&O);
	freeMatrix(&PAUX);
}

int main() {

	Matrix B, b, r, C, X, Z, P, CnB;
	MTYPE in;

	initMatrix(&B, 4, 4);
	initMatrix(&b, 4, 1);
	initMatrix(&C, 1, 4);
	initMatrix(&P, 2, 4);
	initMatrix(&CnB, 1, 2);

	setAt(&CnB, 0, 0, 5);
	setAt(&CnB, 0, 1, 4);

	setAt(&P, 0, 0, 6);
	setAt(&P, 0, 1, 1);
	setAt(&P, 0, 2, -1);
	setAt(&P, 0, 3, 0);
	setAt(&P, 1, 0, 4);
	setAt(&P, 1, 1, 2);
	setAt(&P, 1, 2, 1);
	setAt(&P, 1, 3, 1);

	setAt(&C, 0, 0, 0);
	setAt(&C, 0, 1, 0);
	setAt(&C, 0, 2, 0);
	setAt(&C, 0, 3, 0);

	setAt(&b, 0, 0, 24);
	setAt(&b, 1, 0, 6);
	setAt(&b, 2, 0, 1);
	setAt(&b, 3, 0, 2);

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

	r = inverse(B);
	truncate(&r);

	X = variableValues(r,b); //Valor de las xses
	printMatrix(X);

	Z = product(C,X); //valor de la funcion objetivo en esta iteracion.
	printMatrix(Z);

	in = optimallity(C, r, P)

	freeMatrix(&b);
	freeMatrix(&B);
	freeMatrix(&r);
	freeMatrix(&C);
	freeMatrix(&X);
	freeMatrix(&Z);
	freeMatrix(&P);
	freeMatrix(&CnB);

	return 0;
}
