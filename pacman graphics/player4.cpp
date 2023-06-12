#include "juego.h"


void juego::mov_android(){
    //Mover personaje con las teclas
if (Keyboard::isKeyPressed(Keyboard::F))
        {
            if(aviso_android==1 && mov_and!=3){
            	mov_and=3;
            	andPosition.x -= 10.0;
            	aviso_android=0;
            }
            else if(aviso_android==0){
            	mov_and=3;
            }
        }
        else if (Keyboard::isKeyPressed(Keyboard::H))
        {
	    if(aviso_android==1 && mov_and!=4){	
            	mov_and=4;
            	aviso_android=0;
            	andPosition.x += 10.0;
            }
            else if(aviso_android==0){
            	mov_and=4;
            }
        }
        else if (Keyboard::isKeyPressed(Keyboard::T))
        {
	    if(aviso_android==1 && mov_and!=1){
            	mov_and=1;
            	aviso_android=0;
            	andPosition.y -= 10.0;
            }
            else if(aviso_android==0){
            	mov_and=1;
            }
            //aviso=0;
        }
        else if (Keyboard::isKeyPressed(Keyboard::G))
        {
            if(aviso_android==1 && mov_and!=2){
            	mov_and=2;
            	aviso_android=0;
            	andPosition.y += 10.0;
            }
            else if(aviso_android==0){
            	mov_and=2;
            }
            //	aviso=0;
        }

   if(aviso_android==0){
        // Mover personaje con las teclas de flecha
        if (mov_and==3)
        {
            andPosition.x -= 1.2;
        }
        else if (mov_and==4 || mov_and==0)
        {
            andPosition.x += 1.2;
        }
        else if (mov_and==1)
        {
            andPosition.y -= 1.2;
        }
        else if (mov_and==2)
        {
            andPosition.y += 1.2;
        }
    }
}


void juego::animacion_android(){

    if (clock.getElapsedTime().asMilliseconds() > 80) {
            spriteIndex = (spriteIndex + 1) % 4;
            clock.restart();
            }
        	if (spriteIndex == 0){
        	    sandroid1.setPosition(andPosition);
        	    ventana1->draw(sandroid1);
        	}
        	else if(spriteIndex == 1){
        	    sandroid2.setPosition(andPosition);
        	    ventana1->draw(sandroid2);
        	}
        	else if(spriteIndex==2){
        	    sandroid3.setPosition(andPosition);
        	    ventana1->draw(sandroid3);
        	}  
        	else {
        	    sandroid3.setPosition(andPosition);
        	    ventana1->draw(sandroid3);
        	}  

}