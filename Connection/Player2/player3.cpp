#include "juego.h"



void juego::animacion_blue(){


        if (clock.getElapsedTime().asMilliseconds() > 100) {
            spriteIndex = (spriteIndex + 1) % 2;
            clock.restart();
        }
        if(mov==1){
        	if (spriteIndex == 0){
        	    sbluear1.setPosition(bluePosition);
        	    ventana1->draw(sbluear1);
        	}
        	else{
        	    sbluear2.setPosition(bluePosition);
        	    ventana1->draw(sbluear2);
        	}
        }
        else if(mov==2){
        	if (spriteIndex == 0){
        	    sblueab1.setPosition(bluePosition);
        	    ventana1->draw(sblueab1);
        	}
        	else{
        	    sblueab2.setPosition(bluePosition);
        	    ventana1->draw(sblueab2);
        	}       
        }
        else if(mov==3){
        	if (spriteIndex == 0){
        	    sbluei1.setPosition(bluePosition);
        	    ventana1->draw(sbluei1);
        	}
        	else{
        	    sbluei2.setPosition(bluePosition);
        	    ventana1->draw(sbluei2);
        	}       
        }
        else if(mov==4 || mov==0){
        	if (spriteIndex == 0){
        	    sblued1.setPosition(bluePosition);
        	    ventana1->draw(sblued1);
        	}
        	else{
        	    sblued2.setPosition(bluePosition);
        	    ventana1->draw(sblued2);
        	}       
        }
}


void juego::mov_player3(){

        // Mover personaje con las teclas de flecha
        if (Keyboard::isKeyPressed(Keyboard::J))
        {
            //spacman.move(-1, 0);
            bluePosition.x -= 1;
            mov=3;
        }
        else if (Keyboard::isKeyPressed(Keyboard::L))
        {
            //spacman.move(1, 0);
            bluePosition.x += 1;
            mov=4;
        }
        else if (Keyboard::isKeyPressed(Keyboard::I))
        {
            //spacman.move(0, -1);
            bluePosition.y -= 1;
            mov=1;
        }
        else if (Keyboard::isKeyPressed(Keyboard::K))
        {
            //spacman.move(0, 1);
            bluePosition.y += 1;
            mov=2;
        }


}
