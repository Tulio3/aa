#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int i,j;
	
	char** C1 = leerConfiguracion("configuracion.txt");
	
	printMatScreen(C1,SCREEN_NR,SCREEN_NC);   
	    
	return 0;
}
