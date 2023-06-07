/*
g++ enlace.cpp -o enlace -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network
*/
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

using asio::ip::tcp;

using namespace sf;

std::string message;

#define MAX_EVENTS 1024
#define EVENT_SIZE (sizeof (struct inotify_event))
#define EVENT_BUF_LEN (MAX_EVENTS * EVENT_SIZE)

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


void checkFileChanges(const asio::error_code& /*error*/, asio::steady_timer& timer, const std::string& filename, std::string& previousContent) {
    std::ifstream file(filename);
    if (file) {
        std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
        file.close();

        if (content != previousContent) {
            // Realizar acciones con el contenido del archivo actualizado
            std::cout << "Archivo modificado. Contenido: " << content << std::endl;
            previousContent = content;
        }
    }
}    

void juego::mov_player2(){		

    /*
    int fd, wd;
    char buffer[EVENT_BUF_LEN];
    char mensaje[256];

     fd = inotify_init();
      wd = inotify_add_watch(fd, "player2.txt", IN_MODIFY);
      read(fd, buffer, EVENT_BUF_LEN);
      std::string contenido;
      std::ifstream archivo("player2.txt");
      contenido = std::string(std::istreambuf_iterator<char>(archivo), std::istreambuf_iterator<char>());
      //std::cout << contenido << std::endl;   
    */
    
   /* std::string archivo = "player2.txt";
    std::filesystem::file_time_type ultimaModificacion = std::filesystem::last_write_time(archivo);

    while(true){
    std::this_thread::sleep_for(std::chrono::seconds(1));

        std::filesystem::file_time_type nuevaModificacion = std::filesystem::last_write_time(archivo);

        if (nuevaModificacion != ultimaModificacion) {
            ultimaModificacion = nuevaModificacion;

            std::ifstream archivoStream(archivo);
            if (archivoStream) {
                std::string contenido((std::istreambuf_iterator<char>(archivoStream)), std::istreambuf_iterator<char>());
                archivoStream.close();

                // Realizar acciones con el contenido del archivo actualizado
                std::cout << "Archivo modificado. Contenido: " << contenido << std::endl;
            }
        }
    } */
    
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
    
    
    
	if (Keyboard::isKeyPressed(Keyboard::A))
    {
        redPosition.x -= 1;
        mov=3;
        
      // connect();
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
