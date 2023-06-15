#include "juego.h"

#include <asio.hpp>
#include <iostream>
#include <thread>
//#include <sys/inotify.h>
#include <fstream>

#include <filesystem>
#include <chrono>
#include <thread>

#include <string>
#include <functional>

#include <algorithm>
#include <cctype>

using asio::ip::tcp;

using namespace sf;

//std::string message;

//std::string globalMessage;

void juego::mov_wumpus(){

        // Mover personaje con las teclas de flecha
        if (Keyboard::isKeyPressed(Keyboard::Left))
        {
            if(aviso_wum==1 && mov_wum!=3){
            	mov_wum=3;
            	wumPosition.x -= 10.0;
            	aviso_wum=0;
            }
            else if(aviso_wum==0){
            	mov_wum=3;
            }
        }
        else if (Keyboard::isKeyPressed(Keyboard::Right))
        {
	    if(aviso_wum==1 && mov_wum!=4){	
            	mov_wum=4;
            	aviso_wum=0;
            	wumPosition.x += 10.0;
            }
            else if(aviso_wum==0){
            	mov_wum=4;
            }
        }
        else if (Keyboard::isKeyPressed(Keyboard::Up))
        {
	    if(aviso_wum==1 && mov_wum!=1){
            	mov_wum=1;
            	aviso_wum=0;
            	wumPosition.y -= 10.0;
            }
            else if(aviso_wum==0){
            	mov_wum=1;
            }
            //aviso=0;
        }
        else if (Keyboard::isKeyPressed(Keyboard::Down))
        {
            if(aviso_wum==1 && mov_wum!=2){
            	mov_wum=2;
            	aviso_wum=0;
            	wumPosition.y += 10.0;
            }
            else if(aviso_wum==0){
            	mov_wum=2;
            }
            //	aviso=0;
        }
        
        
   if(aviso_wum==0){
        // Mover personaje con las teclas de flecha
        if (mov_wum==3)
        {
            wumPosition.x -= 1.2;
        }
        else if (mov_wum==4 || mov_wum==0)
        {
            wumPosition.x += 1.2;
        }
        else if (mov_wum==1)
        {
            wumPosition.y -= 1.2;
        }
        else if (mov_wum==2)
        {
            wumPosition.y += 1.2;
        }
    }

}

void juego::mov_wumpus1(){

        // Mover personaje con las teclas de flecha
        if (Keyboard::isKeyPressed(Keyboard::A))
        {
            if(aviso_wum==1 && mov_wum!=3){
            	mov_wum=3;
            	wumPosition.x -= 10.0;
            	aviso_wum=0;
            }
            else if(aviso_wum==0){
            	mov_wum=3;
            }
        }
        else if (Keyboard::isKeyPressed(Keyboard::D))
        {
	    if(aviso_wum==1 && mov_wum!=4){	
            	mov_wum=4;
            	aviso_wum=0;
            	wumPosition.x += 10.0;
            }
            else if(aviso_wum==0){
            	mov_wum=4;
            }
        }
        else if (Keyboard::isKeyPressed(Keyboard::W))
        {
	    if(aviso_wum==1 && mov_wum!=1){
            	mov_wum=1;
            	aviso_wum=0;
            	wumPosition.y -= 10.0;
            }
            else if(aviso_wum==0){
            	mov_wum=1;
            }
            //aviso=0;
        }
        else if (Keyboard::isKeyPressed(Keyboard::S))
        {
            if(aviso_wum==1 && mov_wum!=2){
            	mov_wum=2;
            	aviso_wum=0;
            	wumPosition.y += 10.0;
            }
            else if(aviso_wum==0){
            	mov_wum=2;
            }
            //	aviso=0;
        }
        
        
   if(aviso_wum==0){
        // Mover personaje con las teclas de flecha
        if (mov_wum==3)
        {
            wumPosition.x -= 1.2;
        }
        else if (mov_wum==4 || mov_wum==0)
        {
            wumPosition.x += 1.2;
        }
        else if (mov_wum==1)
        {
            wumPosition.y -= 1.2;
        }
        else if (mov_wum==2)
        {
            wumPosition.y += 1.2;
        }
    }

}




void juego::animacion_wumpus(){


       if (clock.getElapsedTime().asMilliseconds() > 80) {
            spriteIndex = (spriteIndex + 1) % 4;
            clock.restart();
            }
        	if (spriteIndex == 0){
        	    swumpus1.setPosition(wumPosition);
        	    ventana1->draw(swumpus1);
        	}
        	else if(spriteIndex == 1){
        	    swumpus2.setPosition(wumPosition);
        	    ventana1->draw(swumpus2);
        	}
        	else if(spriteIndex==2){
        	    swumpus3.setPosition(wumPosition);
        	    ventana1->draw(swumpus3);
        	}  
        	else {
        	    swumpus3.setPosition(wumPosition);
        	    ventana1->draw(swumpus3);
        	}  
       

}
