
#include <stdio.h>
#include <stdlib.h>

// imprime una matriz de dimensiones nRens renglones x mCols columnas a pantalla
void printMatrix(float ** mat,int nRens, int mCols);
float ** createMatrix(int nRens,int nCols);
void freeMatrix(float ** mat, int nRens);
void iniZeroMatrix(float ** mat, int nRens,int nCols);
float** transpuesta(float** mat, int nRens, int nCols);
float*** createCube(int nRens, int nCols, int nTajadas);
void freeCube(float*** cube, int nRens, int mCols);

int main(void){
	
	int nRens=4,mCols=5;
	int i,k;
	
	// Inciso a) segundo punto, primera función
	float** matriz = createMatrix(nRens,mCols);
	
	// Inciso b)
	iniZeroMatrix(matriz,nRens,mCols);
	
	printf("\n   Matriz inicializada en 0.\n");
	printMatrix(matriz,nRens,mCols);
	
	// llenarla con algunos datos arbitrarios
	float counter = 0.0;
	for(i=0;i<nRens;i++){
		for(k=0;k<mCols;k++){

			matriz[i][k] = counter; //entrada i,k
			counter += 0.25;
		}
	}
	
	printf("\n   Matriz con valores.\n");
	printMatrix(matriz,nRens,mCols);
	
	// Inciso c)
	float** transMatrix = transpuesta(matriz,nRens,mCols);
	
	printf("\n   Matriz transpuesta.\n");
	printMatrix(transMatrix,mCols,nRens);
	
	// Inciso d)
	float*** c = createCube(4,6,5);

	// TAREA, LIBERAR **TODA** LA MEMORIA AQUI !!!
	
	// Inciso a) segundo punto, segunda función
	freeMatrix(matriz,nRens);
	freeMatrix(transMatrix,mCols);
	
	// Liberar memoria de la matriz 3D del inciso d)
	freeCube(c,4,6);
	
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

float ** createMatrix(int nRens,int nCols){
	
	float ** mat;
	int i;
	mat = (float **) malloc(nRens*sizeof(float*));

	for(i=0;i<nRens;i++){
		mat[i] = (float *) malloc(nCols*sizeof(float));
	}
	
	return mat;
}

void freeMatrix(float ** mat, int nRens){
	int i;
	for(i=0;i<nRens;i++) free(mat[i]);
	free(mat);
}

void iniZeroMatrix(float ** mat, int nRens,int nCols){
	int i,k;
	for(i=0;i<nRens;i++){
		for(k=0;k<nCols;k++) mat[i][k] = 0; //entrada i,k
	}	
}

float** transpuesta(float** mat, int nRens, int nCols){
	
	int i,k;
	float** tmat = createMatrix(nCols,nRens); // Invertimos filas y columnas
	
	for(i=0;i<nCols;i++){
		for(k=0;k<nRens;k++) tmat[i][k] = mat[k][i]; // Definición de transpuesta
	}	
	
	return tmat;
}

float *** createCube(int nRens,int nCols, int nTajadas){
	
	float *** mat;
	int i,k;
	
	mat = (float ***) malloc(nRens*sizeof(float**));
	
	for(i=0;i<nRens;i++) mat[i] = (float **) malloc(nCols*sizeof(float*));
	
	for(i=0;i<nRens;i++){
		for(k=0;k<nCols;k++) mat[i][k] = (float *) malloc(nTajadas*sizeof(float));
	}
	
	return mat;
}

void freeCube(float*** cube, int nRens, int mCols){
	
	int i,k;
	
	for(i=0;i<nRens;i++){
		for(k=0;k<mCols;k++) free(cube[i][k]);
	}
	
	for(i=0;i<nRens;i++) free(cube[i]);
	
	free(cube);
	
}
