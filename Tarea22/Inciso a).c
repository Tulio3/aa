
#include <stdio.h>
#include <stdlib.h>

// imprime una matriz de dimensiones nRens renglones x mCols columnas a pantalla
void printMatrix(float ** mat,int nRens, int mCols);


int main(void){
	
	int nRens=15,mCols=4,i,k;

	// crear (pedir la memoria) de una matriz rectangular 
	float ** mat;
	mat = (float **) malloc(nRens*sizeof(float*));

	for(i=0;i<nRens;i++){
		mat[i] = (float *) malloc(mCols*sizeof(float));
	}
	

	// llenarla con algunos datos arbitrarios
	float counter = 0.0;
	for(i=0;i<nRens;i++){
		for(k=0;k<mCols;k++){

			mat[i][k] = counter; //entrada i,k
			counter += 0.25;
		}
	}


	printMatrix(mat,nRens,mCols);


	// TAREA, LIBERAR **TODA** LA MEMORIA AQUI !!!

	for(i=0;i<nRens;i++) free(mat[i]);
	free(mat);

	return 0;
}



void printMatrix(float ** mat,int nRens, int mCols){
	int i,k;
	printf("\n");
	for(i=0;i<nRens;i++){
		for(k=0;k<mCols;k++){
			printf("%10.3f",mat[i][k]);
		}
		printf("\n");
	}
}

