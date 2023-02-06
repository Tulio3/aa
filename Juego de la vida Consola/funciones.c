#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "funciones.h"


char** leerConfiguracion(char* nombre){
	
	int i,k;
	char var; // Basura
	
	FILE* mapa = fopen(nombre, "r");
	
	if(!mapa){
		printf("No se pudo abrir %s", nombre);
		return;
	}
	
	char** mat = (char**) malloc(SCREEN_NR*sizeof(char*));
	for(i=0;i<SCREEN_NC;i++) mat[i] = (char*) malloc(SCREEN_NC*sizeof(char));
	
	for(i=0;i<SCREEN_NC;i++){
		for(k=0;k<SCREEN_NC;k++){
			fscanf(mapa,"%c",&mat[i][k]);
		}
		// El Enter
		fscanf(mapa,"%c",&var);
		fscanf(mapa,"%c",&var);
	}
	
	fclose(mapa);
	
	return mat;
}


void printMatScreen(char** mat, int nrens, int ncols){
	int i,k;
	for(i=0;i<nrens;i++){
		for(k=0;k<ncols;k++){
			printf("%c",mat[i][k]);
		}
		printf("\n");
	}
}

void freeMat(char** m, int r){
	int i;
	for(i=0;i<r;i++) free(m[i]);
	free(m);
}

void gotoxy(int x, int y) // en windows 
{ 
	COORD coord;
	coord.X = x;
	coord.Y = y; 
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); 
}

void clearScreen(void){

	int r,c;

    for( r=0;r<SCREEN_NR;r++)
        for( c=0;c<SCREEN_NC;c++){
            gotoxy(c+1,r+1);
            printf(" ");
        }
}

void setColor(int idxColor){
    
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    /* Save current attributes */
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    
    
    switch (idxColor) {
        case I_NRM:
            SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_GREEN);
            break;
        case I_RED:
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
            break;
        case I_GRN:
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
            break;
        case I_YEL:
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
            break;
        case I_BLU:
            SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_BLUE);
            break;
        case I_MAG:
            SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
            break;
        case I_CYN:
            SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
            break;
        case I_WHT:
            SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            break;
    }

}
