#ifndef FUNCIONES_H
#define FUNCIONES_H

typedef struct Matriz{
	float** mem;
	int nr, nc;
} matriz;

int* leeImpares2Enteros(char* nombreArchivo, int* m);
void copia(char* nombre_1, int m, int* vec);
int identidad(float*** M, int nr, int nc);
matriz createMatrix(int nr, int nc);
void printMatScreen(float** mat, int nrens, int ncols);

#endif
