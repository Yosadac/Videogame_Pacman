#include "juego.h"

void juego::mov_tuxf(){
    //Mover personaje con las teclas
if (Keyboard::isKeyPressed(Keyboard::J))
        {
            if(aviso_tux==1 && mov_tux!=3){
            	mov_tux=3;
            	tuxPosition.x -= 10.0;
            	aviso_tux=0;
            }
            else if(aviso_tux==0){
            	mov_tux=3;
            }
        }
        else if (Keyboard::isKeyPressed(Keyboard::L))
        {
	    if(aviso_tux==1 && mov_tux!=4){	
            	mov_tux=4;
            	aviso_tux=0;
            	tuxPosition.x += 10.0;
            }
            else if(aviso_tux==0){
            	mov_tux=4;
            }
        }
        else if (Keyboard::isKeyPressed(Keyboard::I))
        {
	    if(aviso_tux==1 && mov_tux!=1){
            	mov_tux=1;
            	aviso_tux=0;
            	tuxPosition.y -= 10.0;
            }
            else if(aviso_tux==0){
            	mov_tux=1;
            }
            //aviso=0;
        }
        else if (Keyboard::isKeyPressed(Keyboard::K))
        {
            if(aviso_tux==1 && mov_tux!=2){
            	mov_tux=2;
            	aviso_tux=0;
            	tuxPosition.y += 10.0;
            }
            else if(aviso_tux==0){
            	mov_tux=2;
            }
            //	aviso=0;
        }

   if(aviso_tux==0){
        // Mover personaje con las teclas de flecha
        if (mov_tux==3)
        {
            tuxPosition.x -= 1.2;
        }
        else if (mov_tux==4 || mov_tux==0)
        {
            tuxPosition.x += 1.2;
        }
        else if (mov_tux==1)
        {
            tuxPosition.y -= 1.2;
        }
        else if (mov_tux==2)
        {
            tuxPosition.y += 1.2;
        }
    }
}


void juego::animacion_tux(){

    if (clock.getElapsedTime().asMilliseconds() > 80) {
            spriteIndex = (spriteIndex + 1) % 4;
            clock.restart();
            }
        	if (spriteIndex == 0){
        	    stux1.setPosition(tuxPosition);
        	    ventana1->draw(stux1);
        	}
        	else if(spriteIndex == 1){
        	    stux2.setPosition(tuxPosition);
        	    ventana1->draw(stux2);
        	}
        	else if(spriteIndex==2){
        	    stux3.setPosition(tuxPosition);
        	    ventana1->draw(stux3);
        	}  
        	else {
        	    stux3.setPosition(tuxPosition);
        	    ventana1->draw(stux3);
        	}  

}