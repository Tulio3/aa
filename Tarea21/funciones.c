#include <stdlib.h>
#include <stdio.h>
#include "funciones.h"

// Estas tres funciones son para números aleatorios

int intAleatorio(int a,int b){
	int n;
	n= aleat()*(b-a)  +  a;
	return n;
}

float aleat(){
	return (float) rand() / RAND_MAX;
}

float floatAleatorio(int a, int b){
	float f;
	f= aleat()*(b-a)  +  a;
	return f;
}

// Las siguientes 6 funciones son casi iguales,
// solo que reciben diferentes tipos de dato,
// se comenta solamente la primera función

void* fun1(char* p1, char* p2, int n){
	
	int i;
	
	// Primero se da un paso a la derecha si el usuario quiere
	
	printf("Quieres dar un paso a la derecha? (1 = si, else = no) "); scanf("%d", &i);
	
	if(i==1){
		p1++;
		printf("Direccion nueva del apuntador: %x\n", p1);
	}
	
	// Luego se avanza a la derecha la cantidad de pasos que el usuario escriba,
	// si no se sobrepasa la longitud del vector
	
	printf("Avanzar a la derecha la siguiente cantidad: "); scanf("%d", &i);
	
	if(p1 + i < p2 + n){
		p1 += i;
		printf("Direccion nueva del apuntador: %x\n", p1);
	}else{
		printf("Se sale de rango.\n");
	}
	
	// Lo mismo hacia la izquierda
	
	printf("Quieres dar un paso a la izquierda? (1 = si, else = no) "); scanf("%d", &i);
	
	if(i==1 && (p1-1 >= p2)){
		p1--;
		printf("Direccion nueva del apuntador: %x\n", p1);
	}
	
	printf("Avanzar a la izquierda la siguiente cantidad: "); scanf("%d", &i);
	
	if(p1 - i >= p2){
		p1 -= i;
		printf("Direccion nueva del apuntador: %x\n", p1);
	}else{
		printf("Se sale de rango.\n");
	}
	
	fflush(stdin);
	
	return p1;
}

void* fun2(int* p1, int* p2, int n){
	
	int i;
	
	printf("Quieres dar un paso a la derecha? (1 = si, else = no) "); scanf("%d", &i);
	if(i==1){
		p1++;
		printf("Direccion nueva del apuntador: %x\n", p1);
	}
	printf("Avanzar a la derecha la siguiente cantidad: "); scanf("%d", &i);
	if(p1 + i < p2 + n){
		p1 += i;
		printf("Direccion nueva del apuntador: %x\n", p1);
	}else{
		printf("Se sale de rango.\n");
	}
	printf("Quieres dar un paso a la izquierda? (1 = si, else = no) "); scanf("%d", &i);
	if(i==1 && (p1-1 >= p2)){
		p1--;
		printf("Direccion nueva del apuntador: %x\n", p1);
	}
	printf("Avanzar a la izquierda la siguiente cantidad: "); scanf("%d", &i);
	if(p1 - i >= p2){
		p1 -= i;
		printf("Direccion nueva del apuntador: %x\n", p1);
	}else{
		printf("Se sale de rango.\n");
	}
	
	fflush(stdin);
	
	return p1;
}

void* fun3(unsigned int* p1, unsigned int* p2, int n){
	
	int i;
	
	printf("Quieres dar un paso a la derecha? (1 = si, else = no) "); scanf("%d", &i);
	if(i==1){
		p1++;
		printf("Direccion nueva del apuntador: %x\n", p1);
	}
	printf("Avanzar a la derecha la siguiente cantidad: "); scanf("%d", &i);
	if(p1 + i < p2 + n){
		p1 += i;
		printf("Direccion nueva del apuntador: %x\n", p1);
	}else{
		printf("Se sale de rango.\n");
	}
	printf("Quieres dar un paso a la izquierda? (1 = si, else = no) "); scanf("%d", &i);
	if(i==1 && (p1-1 >= p2)){
		p1--;
		printf("Direccion nueva del apuntador: %x\n", p1);
	}
	printf("Avanzar a la izquierda la siguiente cantidad: "); scanf("%d", &i);
	if(p1 - i >= p2){
		p1 -= i;
		printf("Direccion nueva del apuntador: %x\n", p1);
	}else{
		printf("Se sale de rango.\n");
	}
	
	fflush(stdin);
	
	return p1;
}

void* fun4(float* p1, float* p2, int n){
	
	int i;
	
	printf("Quieres dar un paso a la derecha? (1 = si, else = no) "); scanf("%d", &i);
	if(i==1){
		p1++;
		printf("Direccion nueva del apuntador: %x\n", p1);
	}
	printf("Avanzar a la derecha la siguiente cantidad: "); scanf("%d", &i);
	if(p1 + i < p2 + n){
		p1 += i;
		printf("Direccion nueva del apuntador: %x\n", p1);
	}else{
		printf("Se sale de rango.\n");
	}
	printf("Quieres dar un paso a la izquierda? (1 = si, else = no) "); scanf("%d", &i);
	if(i==1 && (p1-1 >= p2)){
		p1--;
		printf("Direccion nueva del apuntador: %x\n", p1);
	}
	printf("Avanzar a la izquierda la siguiente cantidad: "); scanf("%d", &i);
	if(p1 - i >= p2){
		p1 -= i;
		printf("Direccion nueva del apuntador: %x\n", p1);
	}else{
		printf("Se sale de rango.\n");
	}
	
	fflush(stdin);
	
	return p1;
}

void* fun5(double* p1, double* p2, int n){
	
	int i;
	
	printf("Quieres dar un paso a la derecha? (1 = si, else = no) "); scanf("%d", &i);
	if(i==1){
		p1++;
		printf("Direccion nueva del apuntador: %x\n", p1);
	}
	printf("Avanzar a la derecha la siguiente cantidad: "); scanf("%d", &i);
	if(p1 + i < p2 + n){
		p1 += i;
		printf("Direccion nueva del apuntador: %x\n", p1);
	}else{
		printf("Se sale de rango.\n");
	}
	printf("Quieres dar un paso a la izquierda? (1 = si, else = no) "); scanf("%d", &i);
	if(i==1 && (p1-1 >= p2)){
		p1--;
		printf("Direccion nueva del apuntador: %x\n", p1);
	}
	printf("Avanzar a la izquierda la siguiente cantidad: "); scanf("%d", &i);
	if(p1 - i >= p2){
		p1 -= i;
		printf("Direccion nueva del apuntador: %x\n", p1);
	}else{
		printf("Se sale de rango.\n");
	}
	
	fflush(stdin);
	
	return p1;
}

void* fun6(long double* p1, long double* p2, int n){
	
	int i;
	
	printf("Quieres dar un paso a la derecha? (1 = si, else = no) "); scanf("%d", &i);
	if(i==1){
		p1++;
		printf("Direccion nueva del apuntador: %x\n", p1);
	}
	printf("Avanzar a la derecha la siguiente cantidad: "); scanf("%d", &i);
	if(p1 + i < p2 + n){
		p1 += i;
		printf("Direccion nueva del apuntador: %x\n", p1);
	}else{
		printf("Se sale de rango.\n");
	}
	printf("Quieres dar un paso a la izquierda? (1 = si, else = no) "); scanf("%d", &i);
	if(i==1 && (p1-1 >= p2)){
		p1--;
		printf("Direccion nueva del apuntador: %x\n", p1);
	}
	printf("Avanzar a la izquierda la siguiente cantidad: "); scanf("%d", &i);
	if(p1 - i >= p2){
		p1 -= i;
		printf("Direccion nueva del apuntador: %x\n", p1);
	}else{
		printf("Se sale de rango.\n");
	}
	
	fflush(stdin);
	
	return p1;
}
