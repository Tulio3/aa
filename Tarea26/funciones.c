#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "funciones.h"


char** guarda(char* nombre, int* ren, int* col, int* gotaX, int* gotaY){
	
	int i,k;
	char var; // Basura
	
	FILE* mapa = fopen(nombre, "r");
	
	if(!mapa){
		printf("No se pudo abrir %s", nombre);
		return;
	}
	
	fscanf(mapa,"%d",ren);
	fscanf(mapa,"%d",col);
	fscanf(mapa,"%d",gotaX);
	fscanf(mapa,"%d",gotaY);
	
	// El Enter
	fscanf(mapa,"%c",&var);
	fscanf(mapa,"%c",&var);
	
	char** mat = (char**) malloc(*ren*sizeof(char*));
	for(i=0;i<*ren;i++) mat[i] = (char*) malloc(*col*sizeof(char));
	
	for(i=0;i<*ren;i++){
		for(k=0;k<*col;k++){
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

void printGota(gota g){
	gotoxy(g.c,g.r);
	printf("&");
}

void borraGota(gota g){
	gotoxy(g.c,g.r);
	printf(" ");
}

void nuevaPosicion(char** mapa, gota* g){
	
	// Primero vemos si la gota puede caer,
	// si es así aumentamos el renglón de la gota en 1
	if(mapa[g->r+1][g->c] == ' '){
		g->r++;
		return;
	}
	
	if(g->dir == 1){ // Si la gota va hacia la derecha
		if(mapa[g->r][g->c+1] == ' '){ // Si hay espacio
			g->c++;
			return;
		}else{
			g->dir = 0; // Si no, cambiamos la dirección
		}
	}
	
	// Análogamente
	if(g->dir == 0){
		if(mapa[g->r][g->c-1] == ' '){
			g->c--;
			return;
		}else{
			g->dir = 1;
		}
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
