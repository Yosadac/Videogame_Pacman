#include "juego.h"

void juego::animacion_pink(){


        if (clock.getElapsedTime().asMilliseconds() > 100) {
            spriteIndex = (spriteIndex + 1) % 2;
            clock.restart();
        }
        if(mov==1){
        	if (spriteIndex == 0){
        	    spinkar1.setPosition(pinkPosition);
        	    ventana1->draw(spinkar1);
        	}
        	else{
        	    spinkar2.setPosition(pinkPosition);
        	    ventana1->draw(spinkar2);
        	}
        }
        else if(mov==2){
        	if (spriteIndex == 0){
        	    spinkab1.setPosition(pinkPosition);
        	    ventana1->draw(spinkab1);
        	}
        	else{
        	    spinkab2.setPosition(pinkPosition);
        	    ventana1->draw(spinkab2);
        	}       
        }
        else if(mov==3){
        	if (spriteIndex == 0){
        	    spinki1.setPosition(pinkPosition);
        	    ventana1->draw(spinki1);
        	}
        	else{
        	    spinki2.setPosition(pinkPosition);
        	    ventana1->draw(spinki2);
        	}       
        }
        else if(mov==4 || mov==0){
        	if (spriteIndex == 0){
        	    spinkd1.setPosition(pinkPosition);
        	    ventana1->draw(spinkd1);
        	}
        	else{
        	    spinkd2.setPosition(pinkPosition);
        	    ventana1->draw(spinkd2);
        	}       
        }
}



void juego::mov_player4(){

        // Mover personaje con las teclas de flecha
        if (Keyboard::isKeyPressed(Keyboard::J))
        {
            //spacman.move(-1, 0);
            orangePosition.x -= 1;
            mov=3;
        }
        else if (Keyboard::isKeyPressed(Keyboard::L))
        {
            //spacman.move(1, 0);
            orangePosition.x += 1;
            mov=4;
        }
        else if (Keyboard::isKeyPressed(Keyboard::I))
        {
            //spacman.move(0, -1);
            orangePosition.y -= 1;
            mov=1;
        }
        else if (Keyboard::isKeyPressed(Keyboard::K))
        {
            //spacman.move(0, 1);
            orangePosition.y += 1;
            mov=2;
        }


}
