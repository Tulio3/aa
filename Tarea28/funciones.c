#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int* leeImpares2Enteros(char* nombreArchivo, int* m){
	
	FILE* fp = fopen(nombreArchivo,"r");
	
	if(!fp){
		printf("No se pudo abrir %s", nombreArchivo);
		return NULL;
	}

	int n, i, cont = 0; // cont va guardando el número de impares que hay
	float var;
	
	fscanf(fp,"%d",&n);
	
	int* v1 = (int*) malloc(n*sizeof(int)); // Creamos un vector con el número máximo de enteros posible
	int* move = v1; // Para movernos en el vector e ir escribiendo
	
	for(i=0;i<n;i++){
		
		fscanf(fp,"%f",&var);
		
		if((int) var % 2 == 1){
			*move = (int) var;
			move++;
			cont++;
		}
	}
	
	*m = cont;
	
	int* v2 = (int*) malloc(cont*sizeof(int)); // declaramos ahora si un vector del tamaño correcto

	for(i=0;i<cont;i++) v2[i] = v1[i];
	
	free(v1); // Liberamos el vector que es demasiado grande
	
	fclose(fp);
	
	return v2;
}

void copia(char* nombre, int m, int* vec){
	
	int i;
	char esp = ' ', ent = '\n';
	
	FILE* fp = fopen(nombre,"wb");
	
	if(!fp){
		printf("No se pudo abrir %s", nombre);
		return;
	}
	
	fwrite(&m,sizeof(int),1,fp);
	
	for(i=0;i<m;i++){
		fwrite(&ent,sizeof(char),1,fp);
		fwrite(&esp,sizeof(char),1,fp);
		fwrite(&esp,sizeof(char),1,fp);
		fwrite(&vec[i],sizeof(float),1,fp);
	}
	
	fclose(fp);
}

int identidad(float*** M, int nr, int nc){
	
	int i, min;
	
	// Veremos cuál dimensión es la más pequeña
	if(nr<nc){
		min = nr;
	}else{
		min = nc;
	}
	
	matriz Mat = createMatrix(nr,nc);
	
	if(Mat.mem == NULL || Mat.mem[0] == NULL) return 0; // No se pudo asignar memoria

	for(i=0;i<nr*nc;i++) Mat.mem[0][i] = 0;
	
	// Ponemos los unos en la diagonal hasta que llegamos al borde
	for(i=0;i<min;i++) Mat.mem[i][i] = 1; 
	
	*M = Mat.mem;

	return 1; // Todo bien
}

matriz createMatrix(int nr, int nc){
	
	matriz mat;
	int i;
	
	mat.nr = nr;
	mat.nc = nc;
	mat.mem = (float**) malloc(nr*sizeof(float*));
	mat.mem[0] = (float*) malloc(nr*nc*sizeof(float));
	
	for(i=0;i<nr;i++) mat.mem[i] = mat.mem[0] + i*nc;
	
	return mat;
}

void printMatScreen(float** mat, int nrens, int ncols){
	int i,k;
	printf("\n");
	for(i=0;i<nrens;i++){
		printf(" ");
		for(k=0;k<ncols;k++){
			printf("%d", (int) mat[i][k]);
		}
		printf("\n");
	}
}

void freeMat(float** M){
	free(M[0]);
	free(M);
}
