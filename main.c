#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "matrix.h"
#include "simplex.h"

bool readMat(Matrix *C, Matrix *G, Matrix *CB, Matrix *B, Matrix *b, int *mult){
	FILE *fp;
	int vn,rn;
	MTYPE a;
	char rest, mode[3];
	bool valid = 1;

  	fp = fopen("matrix.mt", "r");
  	fscanf(fp, " %[^\n]", mode);
  	fscanf(fp, " %d", &vn);	
  	initMatrix(C, 1, vn);
  	if(strcmp(mode,"min") == 0) *mult = -1;
  	for(int i = 0; i < vn; i++){
  		fscanf(fp, " %f", &a);
  		C->loc[i] = (*mult)*a;
  	}
	fscanf(fp, "%d", &rn);
	initMatrix(G, rn, vn);
	for(int i = 0; i < rn; i++){
		for(int j = 0; j < vn; j++){
			fscanf(fp, " %f", &a);
			setAt(G,i,j,a);
		}
	}
	initMatrix(CB, 1, rn);
	for(int i = 0; i < rn; i++){
		fscanf(fp, " %f", &a);
  		CB->loc[i] = a;
	}
	initMatrix(B, rn, rn);
	for(int i = 0; i < rn; i++){
		for(int j = 0; j < rn; j++){
			fscanf(fp, " %f", &a);
			setAt(B,i,j,a);
		}
	}
	initMatrix(b, rn, 1);
	for(int i = 0; i < rn; i++){
		fscanf(fp, " %c", &rest);
		fscanf(fp, " %f", &a);
  		b->loc[i] = a;
  		if((rest == '>' && a > 0)|| rest == '=') valid = 0;
	}
   	fclose(fp);

   	return valid;
}

int main() {

	Matrix G, C, b, CB, B;
	int mult = 1;
	bool valid;

	valid = readMat(&C,&G,&CB,&B,&b,&mult);
	if(valid){
		simplex(G,C,B,CB,b,mult);
	}
	else{
		printf("Mi Cerebro de peruano no sabe q hacer..\n");
	}

	freeMatrix(&G);
	freeMatrix(&C);
	freeMatrix(&b);
	freeMatrix(&CB);
	freeMatrix(&B);

	return 0;
}
