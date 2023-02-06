#include "Shell.cpp"

Window ventana("Proyecto Shell", 256, 144);

int main()
{
	int resultado = (int) MessageYesNo("Presiona uno de los botones");
	
	if (resultado == 1){
		ventana.printf("El usuario presiono Yes");
	}
	else{
		ventana.printf("El usuario presiono No");
	}
	
	return MainLoop();
}
