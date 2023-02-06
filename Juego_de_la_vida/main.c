#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int i,j;
	
	char** C1 = createMatrix(SCREEN_NR+2,SCREEN_NC+2);
	char** C2 = createMatrix(SCREEN_NR+2,SCREEN_NC+2);
	
	inicializa(C1,SCREEN_NR+2,SCREEN_NC+2);
	inicializa(C2,SCREEN_NR+2,SCREEN_NC+2);
	
	leerConfiguracion("configuracion.txt",C1);
		
	while(1){
		
		printMatScreen(C1,SCREEN_NR+2,SCREEN_NC+2); 
		
		nuevaConfiguracion(&C1,&C2,SCREEN_NR+2,SCREEN_NC+2);
		
		//Delay(50);
		
		printMatScreen(C2,SCREEN_NR+2,SCREEN_NC+2); 
		
		nuevaConfiguracion(&C2,&C1,SCREEN_NR+2,SCREEN_NC+2);
		
		//Delay(50);
		
	}
	
	getchar();
	    
	return 0;
}
