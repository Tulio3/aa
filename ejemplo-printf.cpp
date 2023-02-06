#include "Shell.cpp"

Window ventana("Proyecto Shell", 256, 144);

int main()
{
	float val = 10.0;
	int x = 10, y = 50;
	
	// imprime texto en la posicion (x,y) de la pantalla
	ventana.printf(x, y, "Hola mundo con valor %f", val);
	
	return MainLoop();
}
