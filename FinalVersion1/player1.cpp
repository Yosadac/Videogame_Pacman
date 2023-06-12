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

std::string message;

std::string globalMessage;

void juego::mov_redit(){

        // Mover personaje con las teclas de flecha
        if (Keyboard::isKeyPressed(Keyboard::Left))
        {
            //spacman.move(-1, 0);
            //spritePosition.x -= 1.2;
            if(aviso_red==1 && mov_red!=3){
            	mov_red=3;
            	redPosition.x -= 10.0;
            	aviso_red=0;
            }
            else if(aviso_red==0){
            	mov_red=3;
            }
            //aviso=0;
        }
        else if (Keyboard::isKeyPressed(Keyboard::Right))
        {
	    if(aviso_red==1 && mov_red!=4){	
            	mov_red=4;
            	aviso_red=0;
            	redPosition.x += 10.0;
            }
            else if(aviso_red==0){
            	mov_red=4;
            }
            //aviso=0;
        }
        else if (Keyboard::isKeyPressed(Keyboard::Up))
        {
	    if(aviso_red==1 && mov_red!=1){
            	mov_red=1;
            	aviso_red=0;
            	redPosition.y -= 10.0;
            }
            else if(aviso_red==0){
            	mov_red=1;
            }
            //aviso=0;
        }
        else if (Keyboard::isKeyPressed(Keyboard::Down))
        {
            if(aviso_red==1 && mov_red!=2){
            	mov_red=2;
            	aviso_red=0;
            	redPosition.y += 10.0;
            }
            else if(aviso_red==0){
            	mov_red=2;
            }
            //	aviso=0;
        }
        
        
   if(aviso_red==0){
        // Mover personaje con las teclas de flecha
        if (mov_red==3)
        {
            redPosition.x -= 1.2;
        }
        else if (mov_red==4 || mov_red==0)
        {
            redPosition.x += 1.2;
        }
        else if (mov_red==1)
        {
            redPosition.y -= 1.2;
        }
        else if (mov_red==2)
        {
            redPosition.y += 1.2;
        }
    }

}

void checkFileChanges(const asio::error_code& /*error*/, asio::steady_timer& timer, const std::string& filename, std::string& previousContent) {
    std::ifstream file(filename);
    if (file) {
        std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
        file.close();

        if (content != previousContent) {
            // Realizar acciones con el contenido del archivo actualizado
            //std::cout << "Archivo modificado. Contenido: " << content << std::endl;
            previousContent = content;
            globalMessage = content;
        }
    }
}    


void juego::mov_redit1(){

	 asio::io_context ioContext;
    asio::steady_timer timer(ioContext);

    std::string filename = "player2.txt";
    std::string previousContent;

    // Iniciar la verificación periódica del archivo
    timer.expires_after(std::chrono::milliseconds(100));
    timer.async_wait([filename, &previousContent, &timer](const asio::error_code& error) {
        checkFileChanges(error, timer, filename, previousContent);
    });

    // Ejecutar el bucle de eventos de ASIO
    ioContext.run();
    
    trim(globalMessage);
    
    //std::cout << globalMessage << std::endl;
    std::string TecW = "Tecla S presionada";




//-----------------------------------------------------

        // Mover personaje con las teclas de flecha
        if (globalMessage == "Tecla A presionada")
        {
            //spacman.move(-1, 0);
            //spritePosition.x -= 1.2;
            if(aviso_red==1 && mov_red!=3){
            	mov_red=3;
            	redPosition.x -= 10.0;
            	aviso_red=0;
            }
            else if(aviso_red==0){
            	mov_red=3;
            }
            //aviso=0;
        }
        else if (globalMessage == "Tecla D presionada")
        {
	    if(aviso_red==1 && mov_red!=4){	
            	mov_red=4;
            	aviso_red=0;
            	redPosition.x += 10.0;
            }
            else if(aviso_red==0){
            	mov_red=4;
            }
            //aviso=0;
        }
        else if (globalMessage == "Tecla W presionada")
        {
	    if(aviso_red==1 && mov_red!=1){
            	mov_red=1;
            	aviso_red=0;
            	redPosition.y -= 10.0;
            }
            else if(aviso_red==0){
            	mov_red=1;
            }
            //aviso=0;
        }
        else if (globalMessage == "Tecla S presionada")
        {
            if(aviso_red==1 && mov_red!=2){
            	mov_red=2;
            	aviso_red=0;
            	redPosition.y += 10.0;
            }
            else if(aviso_red==0){
            	mov_red=2;
            }
            //	aviso=0;
        }
        
        
   if(aviso_red==0){
        // Mover personaje con las teclas de flecha
        if (mov_red==3)
        {
            redPosition.x -= 1.2;
        }
        else if (mov_red==4 || mov_red==0)
        {
            redPosition.x += 1.2;
        }
        else if (mov_red==1)
        {
            redPosition.y -= 1.2;
        }
        else if (mov_red==2)
        {
            redPosition.y += 1.2;
        }
    }

}




void juego::animacion_redit(){


       if (clock.getElapsedTime().asMilliseconds() > 80) {
            spriteIndex = (spriteIndex + 1) % 4;
            clock.restart();
            }
        	if (spriteIndex == 0){
        	    sredit1.setPosition(redPosition);
        	    ventana1->draw(sredit1);
        	}
        	else if(spriteIndex == 1){
        	    sredit2.setPosition(redPosition);
        	    ventana1->draw(sredit2);
        	}
        	else if(spriteIndex==2){
        	    sredit3.setPosition(redPosition);
        	    ventana1->draw(sredit3);
        	}  
        	else {
        	    sredit3.setPosition(redPosition);
        	    ventana1->draw(sredit3);
        	}  
       

}
