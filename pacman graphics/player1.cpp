#include "juego.h"

void juego::mov_redit(){

    std::string texto;
    std::string messageC;
    std::ifstream archivo("player.txt");
    if (archivo.is_open()) {
        std::cout << "Contenido del archivo:" << std::endl;
        while (std::getline(archivo, texto)) {
            std::cout << texto << std::endl;
        }
        archivo.close();
    } else {
        std::cout << "No se pudo abrir el archivo." << std::endl;
    }

    std::ifstream archivo2("mensaje.txt");
    if (archivo2.is_open()) {
        std::cout << "Contenido del archivo:" << std::endl;
        while (std::getline(archivo2, texto)) {
            std::cout << texto << std::endl;
        }
        archivo2.close();
    } else {
        std::cout << "No se pudo abrir el archivo." << std::endl;
    }

    if(texto=="HOST"){
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
    }
    else
    {
        // Mover personaje con las teclas de flecha
        if (messageC=="Tecla A presionada")
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
        else if (messageC=="Tecla D presionada")
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
        else if (messageC=="Tecla W presionada")
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
        else if (messageC=="Tecla S presionada")
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
        	    sredit4.setPosition(redPosition);
        	    ventana1->draw(sredit4);
        	}  
       

}
