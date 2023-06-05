#include "juego.h"
#include <asio.hpp>
#include <iostream>
#include <thread>


using asio::ip::tcp;

using namespace sf;

std::string message;


void juego::animacion_red(){


        if (clock.getElapsedTime().asMilliseconds() > 100) {
            spriteIndex = (spriteIndex + 1) % 2;
            clock.restart();
        }
        if(mov==1){
        	if (spriteIndex == 0){
        	    sredar1.setPosition(redPosition);
        	    ventana1->draw(sredar1);
        	}
        	else{
        	    sredar2.setPosition(redPosition);
        	    ventana1->draw(sredar2);
        	}
        }
        else if(mov==2){
        	if (spriteIndex == 0){
        	    sredab1.setPosition(redPosition);
        	    ventana1->draw(sredab1);
        	}
        	else{
        	    sredab2.setPosition(redPosition);
        	    ventana1->draw(sredab2);
        	}       
        }
        else if(mov==3){
        	if (spriteIndex == 0){
        	    sredi1.setPosition(redPosition);
        	    ventana1->draw(sredi1);
        	}
        	else{
        	    sredi2.setPosition(redPosition);
        	    ventana1->draw(sredi2);
        	}       
        }
        else if(mov==4 || mov==0){
        	if (spriteIndex == 0){
        	    sredd1.setPosition(redPosition);
        	    ventana1->draw(sredd1);
        	}
        	else{
        	    sredd2.setPosition(redPosition);
        	    ventana1->draw(sredd2);
        	}       
        }
}


void juego::mov_player2(){		

/*	if (Keyboard::isKeyPressed(Keyboard::A))
    {
        redPosition.x -= 1;
        mov=3;
        
       //connect();
    }
    else if (Keyboard::isKeyPressed(Keyboard::D))
    {
        redPosition.x += 1;
        mov=4;
        message = "Tecla D presionada";
    }
    else if (Keyboard::isKeyPressed(Keyboard::W))
    {
        redPosition.y -= 1;
        mov=1;
        message = "Tecla W presionada";
    }
    else if (Keyboard::isKeyPressed(Keyboard::S))
    {
        redPosition.y += 1;
        mov=2;
        message = "Tecla S presionada";
    }
*/

 // Mover personaje con las teclas de flecha
        if (Keyboard::isKeyPressed(Keyboard::Left))
        {
             redPosition.x -= 1;
        mov=3;
        }
        else if (Keyboard::isKeyPressed(Keyboard::Right))
        {
           redPosition.x += 1;
        mov=4;
        }
        else if (Keyboard::isKeyPressed(Keyboard::Up))
        {
            redPosition.y -= 1;
        mov=1;
        }
        else if (Keyboard::isKeyPressed(Keyboard::Down))
        {
           
             redPosition.y += 1;
        	mov=2;
        }


	/*
        // Mover personaje con las teclas de flecha
        if (Keyboard::isKeyPressed(Keyboard::A))
        {
            //spacman.move(-1, 0);
            redPosition.x -= 1;
            mov=3;
        }
        else if (Keyboard::isKeyPressed(Keyboard::D))
        {
            //spacman.move(1, 0);
            redPosition.x += 1;
            mov=4;
        }
        else if (Keyboard::isKeyPressed(Keyboard::W))
        {
            //spacman.move(0, -1);
            redPosition.y -= 1;
            mov=1;
        }
        else if (Keyboard::isKeyPressed(Keyboard::S))
        {
            //spacman.move(0, 1);
            redPosition.y += 1;
            mov=2;
        }
	*/

}
