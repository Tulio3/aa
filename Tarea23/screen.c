#include "screen.h"
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

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
