#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "funciones.h"


void leerConfiguracion(char* nombre, char** mat){
	
	int i,k;
	char var; // Basura
	
	FILE* mapa = fopen(nombre, "r");
	
	if(!mapa){
		printf("No se pudo abrir %s", nombre);
		return;
	}
	
	for(i=1;i<=SCREEN_NR;i++){
		for(k=1;k<=SCREEN_NC;k++){
			fscanf(mapa,"%c",&mat[i][k]);
		}
		// El Enter
		fscanf(mapa,"%c",&var);
		fscanf(mapa,"%c",&var);
	}
	
	fclose(mapa);
	
}


char** nuevaConfiguracion(char*** mat, char*** mat2, int nrens, int ncols){
	
	int x,y;
	for(x=1;x<ncols-1;x++){
		for(y=1;y<nrens-1;y++){
			if(decide(*mat,nrens,ncols,x,y)){
				(*mat2)[y][x] = '*';
			}else{
				(*mat2)[y][x] = ' ';
			}	
		}
	}

}

int decide(char** mat, int nr, int nc, int x, int y){
	
	int cont=0;
	
	if(isOn(mat,x-1,y-1)) cont++;
	if(isOn(mat,x,y-1)) cont++;
	if(isOn(mat,x+1,y-1)) cont++;
	if(isOn(mat,x+1,y)) cont++;
	if(isOn(mat,x+1,y+1)) cont++;
	if(isOn(mat,x,y+1)) cont++;
	if(isOn(mat,x-1,y+1)) cont++;
	if(isOn(mat,x-1,y)) cont++;
	
	if(mat[y][x] == '*'){
	
		if(cont == 2 || cont == 3) return 1; 
		else return 0;
		
	}else{
		
		if(cont == 3) return 1; 
		else return 0;
		
	}
}



/*
int decide(char** mat, int nr, int nc, int x, int y){
	
	int cont = 0;
	
	if(x == 0){
		if(y == 0){
			cont += isOn(mat,1,0);
			cont += isOn(mat,1,1);
			cont += isOn(mat,0,1);
		}else{
			if(y == nr-1){
				cont += isOn(mat,0,nr-2);
				cont += isOn(mat,1,nr-2);
				cont += isOn(mat,1,nr-1);
			}else{
				cont += isOn(mat,0,y-1);
				cont += isOn(mat,1,y-1);
				cont += isOn(mat,1,y);
				cont += isOn(mat,1,y+1);
				cont += isOn(mat,0,y+1);
			}else{
				if(y == 0){
					if(x == nc-1){
						cont += isOn(mat,nc-2,0);
						cont += isOn(mat,nc-2,1);
						cont += isOn(mat,nc-1,1);
		}else{
			cont += isOn(mat,x-1,0);
			cont += isOn(mat,x-1,1);
			cont += isOn(mat,x,1);
			cont += isOn(mat,x+1,1);
			cont += isOn(mat,x+1,0);
		}
	}else if(x == nc-1){
		if(y == nr-1){
			cont += isOn(mat,nc-2,nr-1);
			cont += isOn(mat,nc-2,nr-2);
			cont += isOn(mat,nc-1,nr-2);
		}else{
			cont += isOn(mat,nc-1,y-1);
			cont += isOn(mat,nc-2,y-1);
			cont += isOn(mat,nc-2,y);
			cont += isOn(mat,nc-2,y+1);
			cont += isOn(mat,nc-1,y+1);	
		}	
	}else if(y == nr-1){
		cont += isOn(mat,x-1,nr-1);
		cont += isOn(mat,x-1,nr-2);
		cont += isOn(mat,x,nr-2);
		cont += isOn(mat,x+1,nr-2);
		cont += isOn(mat,x+1,nr-1);	
	}else{
		
		cont += isOn(mat,x-1,y-1);	
		cont += isOn(mat,x,y-1);
		cont += isOn(mat,x+1,y-1);
		cont += isOn(mat,x+1,y);
		cont += isOn(mat,x+1,y+1);
		cont += isOn(mat,x,y+1);
		cont += isOn(mat,x-1,y+1);
		cont += isOn(mat,x-1,y);
		
	}
	
	
	printf(".");
	if(cont == 2 || cont == 4) return 1; 
	else return 0;
}
*/
int isOn(char** mat, int x, int y){
	if(mat[y][x] == '*') return 1;
	else return 0;
}

void printMatScreen(char** mat, int nrens, int ncols){
	
	gotoxy(0,0);
	
	int i,k;
	for(i=1;i<nrens-1;i++){
		for(k=1;k<ncols-1;k++){
			printf("%c",mat[i][k]);
		}
		printf("\n");
	}
}

char** createMatrix(int nr, int nc){
	int i;
	char** mat = (char**) malloc(nr*sizeof(char*));
	for(i=0;i<nr;i++) mat[i] = (char*) malloc(nc*sizeof(char)); 
	return mat;
}

void inicializa(char** mat, int nr, int nc){
	int i,k;
	for(i=0;i<nr;i++){
		for(k=0;k<nc;k++){
			mat[i][k] = ' ';
		}
	}
}

void freeMat(char** m, int r){
	int i;
	for(i=0;i<r;i++) free(m[i]);
	free(m);
}

void Delay(int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
		}
	}
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
