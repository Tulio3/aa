#ifndef FUNCIONES_H
#define FUNCIONES_H

typedef struct image{
	unsigned char** I;
	int nr, nc;
} Image;

Image createImage(int nr, int nc);
Image leerMatriz(char* nombre);
void freeImage(Image img);
void printImage(char* out_filename, Image img);


#endif
