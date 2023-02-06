#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

Image createImage(int nr, int nc){
	
	Image Im;
	int i;
	
	Im.nr = nr;
	Im.nc = nc;
	Im.I = (unsigned char**) malloc(nr*sizeof(unsigned char*));
	Im.I[0] = (unsigned char*) malloc(nr*nc*sizeof(unsigned char));
	
	for(i=0;i<nr;i++) Im.I[i] = Im.I[0] + i*nc;
	
	return Im;
}

Image leerMatriz(char* nombre){
	
	FILE* fp = fopen(nombre,"rb");
	int dims[2]; // Guarda las dimensiones de la imagen
	fread(dims,sizeof(int),2,fp);
	
	Image ima = createImage(dims[0],dims[1]);
	ima.nr = dims[0];
	ima.nc = dims[1];

	fread(ima.I[0],sizeof(char),ima.nr*ima.nc,fp);
	fclose(fp);

	return ima;
}

void printImage(char* out_filename, Image img){
	
	FILE* fp = fopen(out_filename,"w");
	int i,k;
	
	for(i=0;i<img.nr;i++){
		for(k=0;k<img.nc;k++){
			fprintf(fp,"%c",img.I[i][k]);
		}
		fprintf(fp,"\n");
	}
	
	fclose(fp);
}

void freeImage(Image img){
	int i;
	free(img.I[0]);
	free(img.I);
}
