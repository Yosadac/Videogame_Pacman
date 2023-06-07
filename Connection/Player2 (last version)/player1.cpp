#include "juego.h"

void juego::animacion_pacman(){

        if (clock.getElapsedTime().asMilliseconds() > 100) {
            spriteIndex = (spriteIndex + 1) % 3;
            clock.restart();
        }
        if (spriteIndex == 0){
            spac1.setPosition(spritePosition);
            ventana1->draw(spac1);
        }
        else if(spriteIndex== 1){
            spac2.setPosition(spritePosition);
            ventana1->draw(spac2);
        }
        else{
            spac3.setPosition(spritePosition);
            ventana1->draw(spac3);
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
            spritePosition.x -= 1;
        }
        else if (Keyboard::isKeyPressed(Keyboard::Right))
        {
            //spacman.move(1, 0);
            spritePosition.x += 1;
        }
        else if (Keyboard::isKeyPressed(Keyboard::Up))
        {
            //spacman.move(0, -1);
            spritePosition.y -= 1;
        }
        else if (Keyboard::isKeyPressed(Keyboard::Down))
        {
            //spacman.move(0, 1);
            spritePosition.y += 1;
        }


}
