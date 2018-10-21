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

	printf("INGRESA LAS RESTRICCIONES:\n");
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

Matrix recoef(){
	int rest, var;
	MTYPE c;
	Matrix G;
	//codigo marginal, poco tiempo para un parser xD
	printf("Numero restricciones: ");
	scanf(" %d", &rest);
	printf("Numero de variables: ");
	scanf(" %d", &var);

	initMatrix(&G, rest, var);

	for(int i = 0; i < rest; i++){
		for(int j = 0; j < var; j++){
			printf("Ingresa Coeficiente de %d restriccion, %d Variable: ", i+1, j+1);
			scanf(" %f", &c);
			setAt(&G, i, j,  c);
		}
	}
	printf("Esta es su matriz: \n");
	printMatrix(G);
	return G;
}

Matrix focoef(size_t var, int *mult){
	MTYPE c;
	Matrix C;

	printf("(1)Min\n(2)Max\n?:");
	scanf(" %d",mult);
	if(*mult == 1) *mult = -1;
	else *mult = 1;

	initMatrix(&C, 1, var);
	for(size_t i = 0; i < var; i++){
		printf("Ingresa Coeficiente de %zu Variable de la funcion objetivo: ",i+1);
		scanf(" %f", &c);
		C.loc[i] = *mult * c;
	}
	printf("Esta es su matriz: \n");
	printMatrix(C);
	return C;
}

Matrix rco(size_t rest){
	Matrix b;
	MTYPE c;
	int dec;

	initMatrix(&b, rest, 1);
	for(size_t i = 0; i < rest; i++){
		printf("Ingresa %lu Lado derecho de las restricciones: \n", i+1);
		printf("(1) >=\n(2) <=\n(3) =\n?:");
		scanf(" %d",&dec);
		printf("Ingresa el Valor: ");
		scanf(" %f",&c);
		if((dec == 1 && c > 0)||dec == 3){
			//error hay q pedir la base
			b.w = 0;
			b.h = 0;
		}
		b.loc[i] = c;
	}
	printf("Esta es su matriz: \n");
	printMatrix(b);
	return b;
}

int main() {

	Matrix G, C, b;
	int mult;

	initMatrix(&b, 3, 1);

	b.loc[0] = 240;
	b.loc[1] = 100;
	b.loc[2] = 0;

	G = recoef();
	C = focoef(G.w,&mult);
	b = rco(G.h);
	if(b.w==0&&b.h==0){
		//pedir la base y todo como si ya hubiesen hecho dos fases
	}
	// printMatrix(G);
	simplex(G,C,b,mult);

	freeMatrix(&G);
	freeMatrix(&C);
	freeMatrix(&b);

	return 0;
}
