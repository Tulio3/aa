#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "funciones.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	clearScreen();
    
    int c,color,i;
    char *chars={"-\\|/"};
    int idxChar = 0;
   
    while(1){
        
        // Dibuja una ceja
        for( c=30,color=I_NRM;c<36;c+=1,color++){   
                setColor(color%N_COLORS);
                GotoXY(c,6);
                printf("%c",chars[idxChar]);
            }
        
        // Dibuja la otra
        for( c=38;c<44;c+=1,color++){   
                setColor(color%N_COLORS);
                GotoXY(c,7);
                printf("%c",chars[idxChar]);
            }
            
        // Los siguientes 4 fors dibujan un ojo, cada uno por una hilera del ojo
        for( c=29;c<31;c+=1,color++){   
                setColor(color%N_COLORS);
                GotoXY(c,9);
                printf("%c",chars[idxChar]);
            }
            
        for( c=28;c<32;c+=3,color++){   
                setColor(color%N_COLORS);
                GotoXY(c,10);
                printf("%c",chars[idxChar]);
            }
            
        for( c=28;c<32;c+=3,color++){   
                setColor(color%N_COLORS);
                GotoXY(c,11);
                printf("%c",chars[idxChar]);
            }
            
        for( c=29;c<31;c+=1,color++){   
                setColor(color%N_COLORS);
                GotoXY(c,12);
                printf("%c",chars[idxChar]);
            }
        
        // El otro ojo
        for( c=39;c<41;c+=1,color++){   
                setColor(color%N_COLORS);
                GotoXY(c,10);
                printf("%c",chars[idxChar]);
            }
            
        for( c=38;c<42;c+=3,color++){   
                setColor(color%N_COLORS);
                GotoXY(c,11);
                printf("%c",chars[idxChar]);
            }
            
        for( c=38;c<42;c+=3,color++){   
                setColor(color%N_COLORS);
                GotoXY(c,12);
                printf("%c",chars[idxChar]);
            }
            
        for( c=39;c<41;c+=1,color++){   
                setColor(color%N_COLORS);
                GotoXY(c,13);
                printf("%c",chars[idxChar]);
            }
        
        // La boca
		for( c=30;c<38;c+=1,color++){   
                setColor(color%N_COLORS);
                GotoXY(c,15);
                printf("%c",chars[idxChar]);
            }
		
        idxChar++;
        idxChar %=  N_CHARS;
                
        setColor(I_NRM);
        GotoXY(1,1); 
        
        // Delay
        for(c=0; c<30000; c++){
			for(i=0; i<300; i++){
				}
			}
    }    

    return EXIT_SUCCESS;
}
