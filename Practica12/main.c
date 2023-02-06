#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]){
	
	Image ima = leerMatriz(argv[1]);
	
	printImage(argv[2],ima);
	
	freeImage(ima);
	
	return 0;
}
