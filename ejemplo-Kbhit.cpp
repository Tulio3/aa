#include "Shell.cpp"

Window ventana("Proyecto Shell", 256, 144);

int main()
{	
	unsigned int key;
	
	while(1){
		// Kbhit() regresa 1 si el usuario presiono una tecla en el teclado, regresa 0 si no presiono nada
		// guarda la tecla presionada en la variable key
		int resultado = (int) Kbhit(&key);
		
		if (resultado == 1)
			ventana.printf("presiono tecla %c", key);
	}

	
	return MainLoop();
}
