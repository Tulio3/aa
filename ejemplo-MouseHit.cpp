#include "Shell.cpp"

Window ventana("Proyecto Shell", 256, 144);

int main()
{
	int x,y;
	
	while(1){
		// MouseHit() regresa 1 cuando el usuario da click izquierdo, regresa 2 para click derecho, 0 cuando no presiona nada
		// guarda en x,y la posicion donde se dio click
		int resultado = MouseHit(&x, &y);
		
		if (resultado == 1){
			ventana.printf("Click izquierdo en pos x=%d,y=%d", x,y);
		}
		else if (resultado == 2){
			ventana.printf("Click derecho en pos x=%d,y=%d", x,y);
		}
		
		Sleep(100);
	}
	
	return MainLoop();
}
