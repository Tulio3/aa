#include <stdio.h>
#include <stdlib.h>

int indice(float* ap, int n);
void fun(float* pt, int n);
void selectionSort(float* V, int N);
float ** createMatrix(int nRens,int nCols);
void producto(float** A, int rA, int cA, float** B, int rB, int cB, float** C);
void llenarMatriz(float** mat, int nRens, int mCols);
void printMatrix(float ** mat,int nRens, int mCols);
void freeMatrix(float ** mat, int nRens);

int main(){
	
	int n = 7869, i, j;
	
	float* arr = (float*) malloc(n*sizeof(float));
	
	// Se llena el vector de números aleatorios
	for(i=0; i<n; i++) arr[i] = (float)rand()/(float)(RAND_MAX);
	
	printf("\nInciso c)\n\nVector desordenado\n\n");
	
	// Se imprimen solamente los primeros 64 elementos
	for(i=0; i<8; i++){
		for(j=0; j<8; j++) printf("%f ", arr[8*i+j]);
		printf("\n");
	}
		
	printf("\n\n");
	
	selectionSort(arr,n);
	
	printf("Vector ordenado\n\n");
	
	// Se imprimen los primeros 64 términos del vector ordenado
	for(i=0; i<8; i++){
		for(j=0; j<8; j++) printf("%f ", arr[8*i+j]);
		printf("\n");
	}
	
	free(arr);
	
	// Inciso d)
	
	printf("\n\nInciso d)\n");
	
	int renA = 4, colA = 6, renB = 6, colB = 3;
	
	float** A = createMatrix(renA,colA);
	llenarMatriz(A,renA,colA);

	float** B = createMatrix(renB,colB);
	llenarMatriz(B,renB,colB);
	
	float** C = createMatrix(renA,colB);
	
	printMatrix(A,renA,colA);
	
	printf("\n   *\n");
	
	printMatrix(B,renB,colB);

	producto(A,renA,colA,B,renB,colB,C);
	
	printf("\n   =\n");
	
	printMatrix(C,renA,colB);
	
	freeMatrix(A,renA);
	freeMatrix(B,renB);
	freeMatrix(C,renA);
	
	return 0;
}

int indice(float* ap, int n){
	
	int i,r=0;
	
	// r almacena el índice
	for(i=0;i<n;i++){
		if(ap[i] > ap[r]) r=i;
	}
	
	return r;
}

void reemplazo(float* pt, int n){
	
	float aux;
	int ind;
	
	ind = indice(pt, n);
	aux = pt[0];
	pt[0] = pt[ind];
	pt[ind] = aux;
	
}

void selectionSort(float* V, int N){
	int i;
	for(i=0;i<N;i++) reemplazo(V+i,N-i);
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

void llenarMatriz(float** mat, int nRens, int mCols){
	int i,k;
	float counter = 0.0;
	for(i=0;i<nRens;i++){
		for(k=0;k<mCols;k++){
			mat[i][k] = counter; //entrada i,k
			counter += 0.25;
		}
	}
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

void freeMatrix(float ** mat, int nRens){
	int i;
	for(i=0;i<nRens;i++) free(mat[i]);
	free(mat);
}

void producto(float** A, int rA, int cA, float** B, int rB, int cB, float** C){
	
	int i,j,k;
	
	// Se utiliza rA como las filas de C
	// y cB como las columnas de C,
	// finalmente cA=rB es el tamaño de los vectores 
	// para los que realizamos producto interno en cada entrada
	for(i=0; i<rA; i++){
		for(j=0; j<cB; j++){
			C[i][j] = 0;
			for(k=0; k<cA; k++) C[i][j] += A[i][k]*B[k][j];	
		}
	}
}
