#include "juego.h"

void juego::mostrar_score(){

    // Crear un objeto de fuente
    Font font;

    // Cargar la fuente desde un archivo
    if (!font.loadFromFile("8-BIT WONDER.TTF")) {
        cerr << "Error al cargar la fuente" << std::endl;
    }

    // Crear un objeto de texto
    Text text("SCORE: ", font, 24);
    
    
    ventana1 -> draw(text);


}


void juego::aparicion_pastillas(){
	
	spastilla.setPosition(300,300);
	ventana1->draw(spastilla);



}


void juego::Puntos(){
 if (spac1.getGlobalBounds().intersects(spastilla.getGlobalBounds()))
        {
                spastilla.setPosition(100, 100);
                score += 1;
                cout<<score<<endl;
        }



}
