#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

void createPoly(Poly* P){
	P -> coef = (double*) malloc(sizeof(double) * (P->grado + 1));
}

void freePoly(Poly* P){
	free(P -> coef);
}

Poly sumaPolys(Poly p, Poly q){
	
	int max, min, i;
	// Este apuntador guardará la dirección
	// de los coeficientes del polinomio
	// de grado mayor
	double* pt;
	Poly r; // Resultado
	
	if(p.grado >= q.grado){
		max = p.grado;
		min = q.grado;
		pt = p.coef;
	}else{
		min = p.grado;
		max = q.grado;
		pt = q.coef;
	}
	
	r.grado = max; // El grado del resultado es el mayor de los grados
	createPoly(&r);
	
	for(i=0;i<max-min;i++) r.coef[i] = pt[i];
	
	for(i=0;i<=min;i++) r.coef[max-i] = p.coef[p.grado-i] + q.coef[q.grado-i];
	
	return r;
}

void sumaPolysFILE(){
	
	int i;
	
	FILE* fp1 = fopen("Polinomios.bin", "rb");
	
	if(!fp1){
		printf("No se pudo abrir el archivo Polinomios.bin");
		return;
	}
	
	Poly P1,P2,R;
	
	fread(&P1.grado,sizeof(int),1,fp1);
	fread(&P2.grado,sizeof(int),1,fp1);

	createPoly(&P1);
	createPoly(&P2);
	
	fread(P1.coef,sizeof(double),P1.grado+1,fp1);
	fread(P2.coef,sizeof(double),P2.grado+1,fp1);

	R = sumaPolys(P1,P2);
	
	FILE* fp2 = fopen("resultado.bin", "wb");
	
	if(!fp2){
		printf("No se pudo crear el archivo resultado.bin");
		return;
	}
	
	fwrite(&R.grado,sizeof(int),1,fp2);
	fwrite(R.coef,sizeof(double),R.grado+1,fp2);
	
	freePoly(&P1);
	freePoly(&P2);
	freePoly(&R);
	
	fclose(fp1);
	fclose(fp2);
	
}
