#ifndef FUNCIONES_H
#define FUNCIONES_H

typedef struct complex{
	float r, i;
} Complex;

void solve();
float randomNumber();
void save(Complex** matriz, int n, int m);
Complex** create();
void freeMatrix(Complex ** mat, int nRens);

#endif
