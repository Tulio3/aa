#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "funciones.h"

void solve(){
	
	float a,b,c;
	
	FILE* coef = fopen("coeficientes.txt", "r");
	
	if(!coef){
		printf("No se pudo abrir coeficientes.txt");
		return;
	}
	
	FILE* sol = fopen("soluciones.txt", "w");
	
	if(!sol){
		printf("No se pudo abrir soluciones.txt");
		return;
	}
	
	fscanf(coef,"%f", &a);
	fscanf(coef,"%f", &b);
	fscanf(coef,"%f", &c);
	
	// Primero verificamos cuando los coeficientes corresponden a una ecuación lineal
	// o no corresponden a una ecuación.
	if(a == 0){
		if(b == 0){
			fprintf(sol,"Solo el coeficiente constante es distinto de 0, no es una ecuación.");
		}else{
		fprintf(sol,"La ecuación es lineal y la solución es: %f\n",-(c/b));
		}
	}else{
		
		// Discriminante
		float D = b*b - 4*a*c;
	
		if(D >= 0){
		
			float x1,x2;
		
			x1 = (-b + sqrt(D)) / (2*a);
			x2 = (-b - sqrt(D)) / (2*a);
			
			fprintf(sol,"La primera solución es: %f\n",x1);
			fprintf(sol,"La segunda solución es: %f",x2);
		
		}else{
		
			Complex c1,c2;
		
			c1.r = (-b) / (2*a); 
			c1.i = sqrt(-D) / (2*a);
			c2.r = (-b) / (2*a); 
			c2.i = (-sqrt(-D)) / (2*a);
			
			// Si la parte real es 0, solo escribimos la parte imaginaria
			if(c1.r == 0){
				fprintf(sol,"La primera solución es: %.2fi\n",c1.i);
			}else{
				fprintf(sol,"La primera solución es: %.2f + %.2fi\n",c1.r,c1.i);
			}
		
			if(c1.r == 0){
				fprintf(sol,"La primera solución es: %.2fi\n",c2.i);
			}else{
				fprintf(sol,"La segunda solución es: %.2f + %.2fi\n",c2.r,c2.i);
			}
		}
	}
	
	fclose(coef);
	fclose(sol);
}

Complex** create(){
	
	int n,m,i,j;
	
	FILE* dim = fopen("dimensiones.txt", "r");
	
	if(!dim){
		printf("No se pudo abrir dimensiones.txt");
		return NULL;
	}
	
	fscanf(dim,"%d",&n);
	fscanf(dim,"%d",&m);
	
	Complex** mat = (Complex**) malloc(n*sizeof(Complex*));
	for(i=0;i<n;i++) mat[i] = (Complex*) malloc(m*sizeof(Complex));
	
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			mat[i][j].r = randomNumber();
			mat[i][j].i = randomNumber();
		}
	}
	
	fclose(dim);
	
	return mat;
}

void save(Complex** matriz, int n, int m){
	
	int i,j;
	
	FILE* M = fopen("matriz.txt", "w");
	
	if(!M){
		printf("No se pudo abrir matriz.txt");
		return;
	}
	
	for(i=0;i<n;i++){
		fprintf(M,"\n");
		for(j=0;j<m;j++){
			fprintf(M,"   %.2f+%.2fi", matriz[i][j].r, matriz[i][j].i);
		}
		fprintf(M,"\n");
	}
	
	fclose(M);
}

float randomNumber(){
	return (float) rand()/RAND_MAX;
}

void freeMatrix(Complex ** mat, int nRens){
	int i;
	for(i=0;i<nRens;i++) free(mat[i]);
	free(mat);
}
