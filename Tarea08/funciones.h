#ifndef FUNCIONES_H
#define FUNCIONES_H

#define R_INI 10
#define R_FIN 18
#define C_INI 5
#define C_FIN 70
#define SCREEN_NC 80
#define SCREEN_NR 24


#define  N_COLORS 8
#define  I_NRM  0
#define  I_RED  1
#define  I_GRN  2
#define  I_YEL  3
#define  I_BLU  4
#define  I_MAG  5
#define  I_CYN  6
#define  I_WHT  7

#define N_CHARS 4

void GotoXY(int x, int y);
void clearScreen(void);
void setColor(int idxColor);

#endif
