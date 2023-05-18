#include "juego.h"

void juego::animacion_pacman(){


       if (clock.getElapsedTime().asMilliseconds() > 80) {
            spriteIndex = (spriteIndex + 1) % 3;
            clock.restart();
        }
        if(mov_pac==1){
        	if (spriteIndex == 0){
        	    spacar1.setPosition(spritePosition);
        	    ventana1->draw(spacar1);
        	}
        	else if(spriteIndex == 1){
        	    spacar2.setPosition(spritePosition);
        	    ventana1->draw(spacar2);
        	}
        	else {
        	    spac3.setPosition(spritePosition);
        	    ventana1->draw(spac3);
        	}  
        }
        else if(mov_pac==2){
        	if (spriteIndex == 0){
        	    spacab1.setPosition(spritePosition);
        	    ventana1->draw(spacab1);
        	}
        	else if(spriteIndex == 1){
        	    spacab2.setPosition(spritePosition);
        	    ventana1->draw(spacab2);
        	} 
        	else {
        	    spac3.setPosition(spritePosition);
        	    ventana1->draw(spac3);
        	}        
        }
        else if(mov_pac==3){
        	if (spriteIndex == 0){
        	    spaci1.setPosition(spritePosition);
        	    ventana1->draw(spaci1);
        	}
        	else if(spriteIndex == 1){
        	    spaci2.setPosition(spritePosition);
        	    ventana1->draw(spaci2);
        	}       
        	else {
        	    spac3.setPosition(spritePosition);
        	    ventana1->draw(spac3);
        	}  
        }
        else if(mov_pac==4 || mov_pac==0){
        	if (spriteIndex == 0){
        	    spacd1.setPosition(spritePosition);
        	    ventana1->draw(spacd1);
        	}
        	else if(spriteIndex == 1){
        	    spacd2.setPosition(spritePosition);
        	    ventana1->draw(spacd2);
        	} 
        	else {
        	    spac3.setPosition(spritePosition);
        	    ventana1->draw(spac3);
        	}    
        }

}


void juego::animacion_pacman_muerte(){

        if (clock.getElapsedTime().asMilliseconds() > 80) {
            spriteIndexMuerte = (spriteIndexMuerte + 1)%12;
            clock.restart();
        }
        if (spriteIndexMuerte == 0){
            smpac1.setPosition(spritePosition);
            ventana1->draw(smpac1);
        }
        else if(spriteIndexMuerte== 1){
            smpac2.setPosition(spritePosition);
            ventana1->draw(smpac2);
        }
        else if(spriteIndexMuerte==2){
            smpac3.setPosition(spritePosition);
            ventana1->draw(smpac3);
        }
        else if (spriteIndexMuerte == 3){
            smpac4.setPosition(spritePosition);
            ventana1->draw(smpac4);
        }
        else if(spriteIndexMuerte== 4){
            smpac5.setPosition(spritePosition);
            ventana1->draw(smpac5);
        }
        else if(spriteIndexMuerte==5){
            smpac6.setPosition(spritePosition);
            ventana1->draw(smpac6);
        }
        else if(spriteIndexMuerte== 6){
            smpac7.setPosition(spritePosition);
            ventana1->draw(smpac7);
        }
        else if(spriteIndexMuerte==7){
            smpac8.setPosition(spritePosition);
            ventana1->draw(smpac8);
        }
        else if (spriteIndexMuerte == 8){
            smpac9.setPosition(spritePosition);
            ventana1->draw(smpac9);
        }
        else if(spriteIndexMuerte== 9){
            smpac10.setPosition(spritePosition);
            ventana1->draw(smpac10);
        }
        else if(spriteIndexMuerte==10){
            smpac11.setPosition(spritePosition);
            ventana1->draw(smpac11);
        }
        else{
            smpac12.setPosition(spritePosition);
            ventana1->draw(smpac12);
        }
}



void juego::mov_player1(){

        // Mover personaje con las teclas de flecha
        if (Keyboard::isKeyPressed(Keyboard::Left))
        {
            //spacman.move(-1, 0);
            //spritePosition.x -= 1.2;
            if(aviso==1 && mov_pac!=3){
            	mov_pac=3;
            	spritePosition.x -= 10.0;
            	aviso=0;
            }
            else if(aviso==0){
            	mov_pac=3;
            }
            //aviso=0;
        }
        else if (Keyboard::isKeyPressed(Keyboard::Right))
        {
	    if(aviso==1 && mov_pac!=4){	
            	mov_pac=4;
            	aviso=0;
            	spritePosition.x += 10.0;
            }
            else if(aviso==0){
            	mov_pac=4;
            }
            //aviso=0;
        }
        else if (Keyboard::isKeyPressed(Keyboard::Up))
        {
	    if(aviso==1 && mov_pac!=1){
            	mov_pac=1;
            	aviso=0;
            	spritePosition.y -= 10.0;
            }
            else if(aviso==0){
            	mov_pac=1;
            }
            //aviso=0;
        }
        else if (Keyboard::isKeyPressed(Keyboard::Down))
        {
            if(aviso==1 && mov_pac!=2){
            	mov_pac=2;
            	aviso=0;
            	spritePosition.y += 10.0;
            }
            else if(aviso==0){
            	mov_pac=2;
            }
            //	aviso=0;
        }
        
        
   if(aviso==0){
        // Mover personaje con las teclas de flecha
        if (mov_pac==3)
        {
            spritePosition.x -= 1.2;
        }
        else if (mov_pac==4 || mov_pac==0)
        {
            spritePosition.x += 1.2;
        }
        else if (mov_pac==1)
        {
            spritePosition.y -= 1.2;
        }
        else if (mov_pac==2)
        {
            spritePosition.y += 1.2;
        }
    }

}
