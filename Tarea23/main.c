
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "screen.h"

#define N_CABALLOS 12
#define X_META SCREEN_NC-5-4 //la coordenada X de la meta


void dibujaCaballo(int x,int y);
void borraCaballo(int x,int y);
int avanzaAleatorio(void); //usado para ver si un caballo avanza o no
void quitaCursor(void); // solo quita el curso de la pista de carrera 
void delay(void); // espera a que presiones ENTER
void dibujaPantalla(void); // pone la meta

int carrera(); // TAREA: PROGRAMAR LA CARRERA


int main(void){
	
	int semillaAleatoria;

	semillaAleatoria = -57086;
	
	int ganador = carrera(semillaAleatoria);
	
	gotoxy(1,1); printf("  El ganador es el caballo %d" , ganador +1);
	
	delay(); delay();

	return 0;
}



void delay(void){
	quitaCursor();
	getchar();	
}

void quitaCursor(void){
	gotoxy(X_META+5+1, 1);
}



void dibujaCaballo(int x,int y){
	gotoxy(x,y);	
	printf("/(~)P");
}
void borraCaballo(int x,int y){
	gotoxy(x,y);	
	printf("     ");
}

void dibujaPantalla(void){

	int y;
	clearScreen();
	
	for (y=1; y<=SCREEN_NR; y++) {
		gotoxy(X_META+5, y);
		printf("|");
		
	}
	
}

int avanzaAleatorio(void){
	return rand()%2;
}


// TAREA: PROGRAMAR LA CARRERA
int carrera(int semillaAleatoria){

	srand(semillaAleatoria);

	dibujaPantalla();
	
	// La variable g guardará al ganador
	int i, g=-1, x=0;
	int* xCaballo = (int*) malloc(N_CABALLOS*sizeof(int));
	int* yCaballo = (int*) malloc(N_CABALLOS*sizeof(int));
	// El caballo i tiene posición (xCaballo[i], yCaballo[i])
	
	for(i=0; i<N_CABALLOS; i++) xCaballo[i] = 0;
	for(i=0; i<N_CABALLOS; i++) yCaballo[i] = 2*i+3;
	
	while(g == -1){ // Mientras no haya ganador
			
			for(i=0; i<N_CABALLOS; i++){
				setColor(i%6); 
				dibujaCaballo(xCaballo[i],yCaballo[i]);
				
				if(xCaballo[i] == X_META && x == 0) {
					g = i;
					x = 1;
					// La variable x evita que se modifique el ganador una vez guardado
				}
			}
			
		setColor(I_NRM); // regresar al color normal
		quitaCursor();
		
		delay();
		for(i=0; i<N_CABALLOS; i++) borraCaballo(xCaballo[i],yCaballo[i]);
		
		// Se decide quién avanza
		for(i=0; i<N_CABALLOS; i++) xCaballo[i] += avanzaAleatorio();
	}

	return g;
		
}
