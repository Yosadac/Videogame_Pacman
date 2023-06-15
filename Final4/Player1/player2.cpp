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

std::string message1;

std::string globalMessage1;

#define MAX_EVENTS 1024
#define EVENT_SIZE (sizeof (struct inotify_event))
#define EVENT_BUF_LEN (MAX_EVENTS * EVENT_SIZE)


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


void checkFileChanges1(const asio::error_code& /*error*/, asio::steady_timer& timer, const std::string& filename, std::string& previousContent) {
    std::ifstream file(filename);
    if (file) {
        std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
        file.close();

        if (content != previousContent) {
            // Realizar acciones con el contenido del archivo actualizado
            //std::cout << "Archivo modificado. Contenido: " << content << std::endl;
            previousContent = content;
            globalMessage1 = content;
        }
    }
}    

void juego::mov_wumpus1(){


	asio::io_context ioContext;
    asio::steady_timer timer(ioContext);

    std::string filename = "player2.txt";
    std::string previousContent;

    // Iniciar la verificación periódica del archivo
    timer.expires_after(std::chrono::milliseconds(100));
    timer.async_wait([filename, &previousContent, &timer](const asio::error_code& error) {
        checkFileChanges1(error, timer, filename, previousContent);
    });

    // Ejecutar el bucle de eventos de ASIO
    ioContext.run();
    
    trim(globalMessage1);
    
    if(globalMessage1 == "Tecla W presionada"){
        redPosition.y -= 1;
        mov=1;
    }
    else if(globalMessage1 == "Tecla D presionada"){
        redPosition.x += 1;
        mov=4;
    }
    else if(globalMessage1 == "Tecla A presionada"){
        redPosition.x -= 1;
        mov=3;
    }
    else if(globalMessage1 == "Tecla S presionada"){
        redPosition.y += 1;
        mov=2;
    }


//--------------------------------------------------------------------------------------------------
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
