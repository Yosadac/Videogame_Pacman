#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
    // Crear la ventana
    RenderWindow window(VideoMode(1000, 1000), "Mi ventana");

    // Configurar la frecuencia de actualización
    window.setFramerateLimit(60);

    // Cargar imagen
    Texture mapa;
    if (!mapa.loadFromFile("mapa.png"))
    {
        // Error al cargar la imagen
        return 1;
    }

    // Crear el sprite
    Sprite smapa;
    smapa.setTexture(mapa);
    
    //EStablece el tamano del mapa
    smapa.setScale(1.2f, 1.2f);

    // Establecer la posición inicial del sprite en la parte inferior derecha de la ventana
    smapa.setPosition(smapa.getPosition().x+100,smapa.getPosition().y+125);
    
    
    
     /*/ Cargar textura del personaje
    Texture pacman;
    if (!pacman.loadFromFile("pacman.png"))
    {
        return -1;
    }

    // Crear sprite del personaje
    Sprite spacman(pacman);
    spacman.setScale(0.01f,0.01f);
    spacman.setPosition(420, 540);*/
    
        sf::Texture texture1;
    texture1.loadFromFile("pac1.png");

    sf::Texture texture2;
    texture2.loadFromFile("pac2.png");
    
        sf::Texture texture3;
    texture3.loadFromFile("pac3.png");

    sf::Sprite sprite1(texture1);
    sf::Sprite sprite2(texture2);
    sf::Sprite sprite3(texture3);
    
    sprite1.setScale(0.5f,0.5f);
    sprite2.setScale(0.5f,0.5f);
    sprite3.setScale(0.5f,0.5f);

    sf::Vector2f spritePosition(300, 300);
    int spriteIndex = 0;
    sf::Clock clock;


    

    // Crear mapa de colisiones
    
    //Arriba
    RectangleShape Arriba_col(Vector2f(660, 11));
    Arriba_col.setFillColor(Color::Transparent);
    Arriba_col.setOutlineThickness(2);
    Arriba_col.setOutlineColor(Color::Red);
    Arriba_col.setPosition(105, 130);
    
    //Izquierda
    
    RectangleShape Izq_col(Vector2f(11, 730));
    Izq_col.setFillColor(Color::Transparent);
    Izq_col.setOutlineThickness(2);
    Izq_col.setOutlineColor(Color::Red);
    Izq_col.setPosition(105, 130);
        
    //Abajo
    
    RectangleShape Abajo_col(Vector2f(660, 11));
    Abajo_col.setFillColor(Color::Transparent);
    Abajo_col.setOutlineThickness(2);
    Abajo_col.setOutlineColor(Color::Red);
    Abajo_col.setPosition(105, 850);
        
    //Derecha
    
    RectangleShape Der_col(Vector2f(11, 730));
    Der_col.setFillColor(Color::Transparent);
    Der_col.setOutlineThickness(2);
    Der_col.setOutlineColor(Color::Red);
    Der_col.setPosition(755, 130);
    
    //Laterales
    
    RectangleShape Lat_der(Vector2f(131, 250));
    Lat_der.setFillColor(Color::Transparent);
    Lat_der.setOutlineThickness(2);
    Lat_der.setOutlineColor(Color::Red);
    Lat_der.setPosition(635, 348);
    
    RectangleShape Lat_izq(Vector2f(133, 250));
    Lat_izq.setFillColor(Color::Transparent);
    Lat_izq.setOutlineThickness(2);
    Lat_izq.setOutlineColor(Color::Red);
    Lat_izq.setPosition(105, 348);
    
    
    
    
    //Obstaculos que salen de las orillas
    
    RectangleShape Orilla_1(Vector2f(35, 108));
    Orilla_1.setFillColor(Color::Transparent);
    Orilla_1.setOutlineThickness(2);
    Orilla_1.setOutlineColor(Color::Red);
    Orilla_1.setPosition(420, 130);
    
    RectangleShape Orilla_2(Vector2f(60, 34));
    Orilla_2.setFillColor(Color::Transparent);
    Orilla_2.setOutlineThickness(2);
    Orilla_2.setOutlineColor(Color::Red);
    Orilla_2.setPosition(105, 708);
        
    RectangleShape Orilla_3(Vector2f(60, 34));
    Orilla_3.setFillColor(Color::Transparent);
    Orilla_3.setOutlineThickness(2);
    Orilla_3.setOutlineColor(Color::Red);
    Orilla_3.setPosition(706, 708);
            
    //zona dentro del mapa
    
    
    
    
    
        
    RectangleShape Obs1(Vector2f(108, 58));
    Obs1.setFillColor(Color::Transparent);
    Obs1.setOutlineThickness(2);
    Obs1.setOutlineColor(Color::Green);
    Obs1.setPosition(490, 179);
            
    RectangleShape Obs2(Vector2f(83, 60));
    Obs2.setFillColor(Color::Transparent);
    Obs2.setOutlineThickness(2);
    Obs2.setOutlineColor(Color::Green);
    Obs2.setPosition(635, 180);
    
    RectangleShape Obs3(Vector2f(83, 34));
    Obs3.setFillColor(Color::Transparent);
    Obs3.setOutlineThickness(2);
    Obs3.setOutlineColor(Color::Green);
    Obs3.setPosition(635, 277);
    
    
    
    
    
       
    RectangleShape Obs4(Vector2f(108, 58));
    Obs4.setFillColor(Color::Transparent);
    Obs4.setOutlineThickness(2);
    Obs4.setOutlineColor(Color::Green);
    Obs4.setPosition(275, 180);
                
    RectangleShape Obs5(Vector2f(83, 60));
    Obs5.setFillColor(Color::Transparent);
    Obs5.setOutlineThickness(2);
    Obs5.setOutlineColor(Color::Green);
    Obs5.setPosition(155, 180);
        
    RectangleShape Obs6(Vector2f(83, 34));
    Obs6.setFillColor(Color::Transparent);
    Obs6.setOutlineThickness(2);
    Obs6.setOutlineColor(Color::Green);
    Obs6.setPosition(155, 275);
    
    
    
    
    
    RectangleShape Obs7(Vector2f(34, 180));
    Obs7.setFillColor(Color::Transparent);
    Obs7.setOutlineThickness(2);
    Obs7.setOutlineColor(Color::Green);
    Obs7.setPosition(563, 275);
    
    RectangleShape Obs8(Vector2f(34, 180));
    Obs8.setFillColor(Color::Transparent);
    Obs8.setOutlineThickness(2);
    Obs8.setOutlineColor(Color::Green);
    Obs8.setPosition(275, 275);
    
    
    
    
    
    RectangleShape Obs9(Vector2f(180, 34));
    Obs9.setFillColor(Color::Transparent);
    Obs9.setOutlineThickness(2);
    Obs9.setOutlineColor(Color::Green);
    Obs9.setPosition(347, 275);
    
    
    
    
    RectangleShape Obs10(Vector2f(34, 110));
    Obs10.setFillColor(Color::Transparent);
    Obs10.setOutlineThickness(2);
    Obs10.setOutlineColor(Color::Green);
    Obs10.setPosition(563,490);
    
    RectangleShape Obs11(Vector2f(34, 110));
    Obs11.setFillColor(Color::Transparent);
    Obs11.setOutlineThickness(2);
    Obs11.setOutlineColor(Color::Green);
    Obs11.setPosition(275,490);
    
    
    
    
    
    RectangleShape Obs12(Vector2f(180, 34));
    Obs12.setFillColor(Color::Transparent);
    Obs12.setOutlineThickness(2);
    Obs12.setOutlineColor(Color::Green);
    Obs12.setPosition(347, 565);
    
    
    
    
    RectangleShape Obs13(Vector2f(108, 35));
    Obs13.setFillColor(Color::Transparent);
    Obs13.setOutlineThickness(2);
    Obs13.setOutlineColor(Color::Green);
    Obs13.setPosition(490, 637);
            
    RectangleShape Obs14(Vector2f(83, 35));
    Obs14.setFillColor(Color::Transparent);
    Obs14.setOutlineThickness(2);
    Obs14.setOutlineColor(Color::Green);
    Obs14.setPosition(635, 637);
    
    
    
    
    RectangleShape Obs15(Vector2f(108, 35));
    Obs15.setFillColor(Color::Transparent);
    Obs15.setOutlineThickness(2);
    Obs15.setOutlineColor(Color::Green);
    Obs15.setPosition(275, 637);
            
    RectangleShape Obs16(Vector2f(83, 35));
    Obs16.setFillColor(Color::Transparent);
    Obs16.setOutlineThickness(2);
    Obs16.setOutlineColor(Color::Green);
    Obs16.setPosition(155, 637);
    
    
    
    
    RectangleShape Obs17(Vector2f(180, 34));
    Obs17.setFillColor(Color::Transparent);
    Obs17.setOutlineThickness(2);
    Obs17.setOutlineColor(Color::Green);
    Obs17.setPosition(347, 709);
    
    
    
    
    
    RectangleShape Obs18(Vector2f(228, 35));
    Obs18.setFillColor(Color::Transparent);
    Obs18.setOutlineThickness(2);
    Obs18.setOutlineColor(Color::Green);
    Obs18.setPosition(490, 780);

    RectangleShape Obs19(Vector2f(228, 35));
    Obs19.setFillColor(Color::Transparent);
    Obs19.setOutlineThickness(2);
    Obs19.setOutlineColor(Color::Green);
    Obs19.setPosition(155, 780);
    
    
    
    //Faltantes de las formas irregulares
    
    
    RectangleShape falt1(Vector2f(70, 34));
    falt1.setFillColor(Color::Transparent);
    falt1.setOutlineThickness(2);
    falt1.setOutlineColor(Color::Green);
    falt1.setPosition(490, 349);
    
    RectangleShape falt2(Vector2f(70, 34));
    falt2.setFillColor(Color::Transparent);
    falt2.setOutlineThickness(2);
    falt2.setOutlineColor(Color::Green);
    falt2.setPosition(312, 349);
    
    
    
    
    
    RectangleShape falt3(Vector2f(34, 70));
    falt3.setFillColor(Color::Transparent);
    falt3.setOutlineThickness(2);
    falt3.setOutlineColor(Color::Green);
    falt3.setPosition(420, 312);
    
    RectangleShape falt4(Vector2f(34, 70));
    falt4.setFillColor(Color::Transparent);
    falt4.setOutlineThickness(2);
    falt4.setOutlineColor(Color::Green);
    falt4.setPosition(420, 600);
    
    
    
    RectangleShape falt5(Vector2f(35, 107));
    falt5.setFillColor(Color::Transparent);
    falt5.setOutlineThickness(2);
    falt5.setOutlineColor(Color::Green);
    falt5.setPosition(635, 637);

            
    RectangleShape falt6(Vector2f(35, 107));
    falt6.setFillColor(Color::Transparent);
    falt6.setOutlineThickness(2);
    falt6.setOutlineColor(Color::Green);
    falt6.setPosition(203, 637);
    
    
    RectangleShape falt7(Vector2f(34, 107));
    falt7.setFillColor(Color::Transparent);
    falt7.setOutlineThickness(2);
    falt7.setOutlineColor(Color::Green);
    falt7.setPosition(563,708);
    
    RectangleShape falt8(Vector2f(34, 107));
    falt8.setFillColor(Color::Transparent);
    falt8.setOutlineThickness(2);
    falt8.setOutlineColor(Color::Green);
    falt8.setPosition(275,708);
    

    // Bucle principal del programa
    while (window.isOpen())
    {
	// Manejar eventos
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
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
	
	// Obtener la posición del jugador
    	FloatRect spac1 = sprite1.getGlobalBounds(),spac2 = sprite2.getGlobalBounds(),spac3 = sprite3.getGlobalBounds();

    	// Comprobar si el jugador choca con cada pared
    	if (spac1.intersects(Arriba_col.getGlobalBounds()))
    	{
    	    // Detener al jugador si choca con la pared superior
        	// Mover al jugador hacia abajo para evitar que se atasque en la pared
		//spacman.move(0, 1);
		spritePosition.y += 2;
	}
    	else if (spac1.intersects(Izq_col.getGlobalBounds()))
    	{
        	// Detener al jugador si choca con la pared izquierda
        	// Mover al jugador hacia la derecha para evitar que se atasque en la pared
        	//spacman.move(1, 0);
        	spritePosition.x += 2;
    	}
    	else if (spac1.intersects(Abajo_col.getGlobalBounds()))
    	{
    	    // Detener al jugador si choca con la pared inferior
    	    // Mover al jugador hacia arriba para evitar que se atasque en la pared
    	    //spacman.move(0, -1);
    	    spritePosition.y -= 2;
    	}
    	else if (spac1.intersects(Der_col.getGlobalBounds()))
    	{
    	    // Detener al jugador si choca con la pared derecha
    	    // Mover al jugador hacia la izquierda para evitar que se atasque en la pared
    	    //spacman.move(-1, 0);
    	    spritePosition.x -= 2;
    	}
    	else if (spac1.intersects(Lat_der.getGlobalBounds()))
    	{
        	// Detener al jugador si choca con la pared izquierda
        	// Mover al jugador hacia la derecha para evitar que se atasque en la pared
        	//spacman.move(-1, 0);
        	spritePosition.x -= 2;
    	}
    	else if (spac1.intersects(Lat_izq.getGlobalBounds()))
    	{
    	    // Detener al jugador si choca con la pared inferior
    	    // Mover al jugador hacia arriba para evitar que se atasque en la pared
    	    //spacman.move(1, 0);
    	    spritePosition.x += 2;
    	}


        // Limpiar la ventana
        window.clear(Color::Black);

        // Dibujar objetos en la ventana
        window.draw(smapa);
                        if (clock.getElapsedTime().asMilliseconds() > 50) {
            spriteIndex = (spriteIndex + 1) % 3;
            clock.restart();
        }
        if (spriteIndex == 0){
            sprite1.setPosition(spritePosition);
            window.draw(sprite1);}
        else if(spriteIndex== 1){
            sprite2.setPosition(spritePosition);
            window.draw(sprite2);
            }
        else{
            sprite3.setPosition(spritePosition);
            window.draw(sprite3);
            }
        //window.draw(spacman);
        window.draw(Arriba_col);
        window.draw(Izq_col);
        window.draw(Abajo_col);
        window.draw(Der_col);
        window.draw(Lat_der);
        window.draw(Lat_izq);
        window.draw(Orilla_1);
        window.draw(Orilla_2);
        window.draw(Orilla_3);
        window.draw(Obs1);
        window.draw(Obs2);
        window.draw(Obs3);
        window.draw(Obs4);
        window.draw(Obs5);
        window.draw(Obs6);
        window.draw(Obs7);
        window.draw(Obs8);
        window.draw(Obs9);
        window.draw(Obs10);
        window.draw(Obs11);
        window.draw(Obs12);
        window.draw(Obs13);
        window.draw(Obs14);
        window.draw(Obs15);
        window.draw(Obs16);
        window.draw(Obs17);
        window.draw(Obs18);
        window.draw(Obs19);
        window.draw(falt1);
        window.draw(falt2);
        window.draw(falt3);
        window.draw(falt4);
        window.draw(falt5);
        window.draw(falt6);
        window.draw(falt7);
        window.draw(falt8);
            
            
        // Mostrar la ventana
        window.display();
    }

    // Cerrar la ventana
    window.close();

    return 0;
}

