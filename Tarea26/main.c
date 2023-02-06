#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main() {
	
	// los renglones, las columnas del mapa
	int r,c,i;
	
	gota got;
	
	// derecha es 1 e izquierda es 0
	got.dir = 1;
	
	char** mapa = guarda("map.txt",&r,&c,&got.r,&got.c);

	setColor(4);
	printMatScreen(mapa,r,c);
	
	setColor(5);
	printGota(got);
	gotoxy(0,r+2); // Para que no estorbe
	getchar();

	do{
		
		borraGota(got);
		nuevaPosicion(mapa,&got);
		
		printGota(got);
		gotoxy(0,r+2);
		getchar();
	
	}while(got.r < r-1); // Salimos del ciclo cuando la gota llega al último renglón
	
	setColor(0);
	gotoxy(0,r+2);

	freeMat(mapa,r);
	
	return 0;
}
