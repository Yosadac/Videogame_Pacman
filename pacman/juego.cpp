#include "juego.h"

juego::juego(int resolucion_x,int resolucion_y, string titulo){
	Vector2f pos(300,300);
	spritePosition=pos;
	fps=60;
	ventana1 = new RenderWindow(VideoMode(resolucion_x,resolucion_y),titulo);
	//spritePosition(300, 300);
	spriteIndex = 0;
	ventana1->setFramerateLimit(fps);
	//dibujar_pantalla();
	
	
	//mapa = new Texture;
	mapa.loadFromFile("mapa.png");

    	// Crear el sprite
    	
    	//smapa = new Sprite;
	smapa.setTexture(mapa);
       	//EStablece el tamano del mapa
    	smapa.setScale(1.2f, 1.2f);
	// Establecer la posición inicial del sprite en la parte inferior derecha de la ventana
    	smapa.setPosition(smapa.getPosition().x+100,smapa.getPosition().y+125);
	
	
	
	
	//pac1 = new Texture;
	pac1.loadFromFile("pac1.png");	
	//pac2 = new Texture;
	pac2.loadFromFile("pac2.png");	
	//pac3 = new Texture;
	pac3.loadFromFile("pac3.png");	
	
	
	//spac1 = new Sprite;
	spac1.setTexture(pac1);
	//spac2 = new Sprite;
	spac2.setTexture(pac2);
	//spac3 = new Sprite;
	spac3.setTexture(pac3);
	
	spac1.setScale(0.5f,0.5f);
    	spac2.setScale(0.5f,0.5f);
    	spac3.setScale(0.5f,0.5f);
    	
    	//evento1 = new Event;
	llenar_cords();
	crear_colisiones();
	
			
	gameLoop();


}

void juego::dibujar_pantalla()
{    	
	ventana1->clear();
	
	ventana1->draw(smapa);
	
	for (auto& colision : colisiones )
        {
            ventana1->draw(colision);
        }
	
        if (clock.getElapsedTime().asMilliseconds() > 50) {
            spriteIndex = (spriteIndex + 1) % 3;
            clock.restart();
        }
        if (spriteIndex == 0){
            spac1.setPosition(spritePosition);
            ventana1->draw(spac1);}
        else if(spriteIndex== 1){
            spac2.setPosition(spritePosition);
            ventana1->draw(spac2);
            }
        else{
            spac3.setPosition(spritePosition);
            ventana1->draw(spac3);
            }
	
	ventana1->display();


}

void juego::gameLoop(){

	while(ventana1->isOpen()){
		
		
		procesar_eventos();
		dibujar_pantalla();	
		
	}


}

void juego::llenar_cords(){

	tamano={{660,16},{15,730},{660,11},{11,730},{131,252},{133,252},{38,110},{60,36},{60,36},
		{108, 60},{83, 60},{83, 36},{108, 58},{83, 60},{83, 36},{34, 182},{34, 180},{180, 36},
		{34, 110},{34, 110},{180, 34},{108, 35},{83, 35},{108, 35},{83, 35},{180, 34},{228, 35},
		{228, 35},{70, 34},{70, 34},{34, 70},{34, 70},{35, 107},{35, 107},{34, 107},{34, 107}};
	
	cords={{105,130},{105,130},{105,850},{753,130},{635,348},{105,348},{417,130},{105,708},{706,708},
	       {490, 179},{635, 180},{635, 275},{275, 180},{155, 180},{155, 275},{563, 275},{275, 275},{347, 275},
	       {563,490},{275,490},{347, 565},{490, 637},{635, 637},{275, 637},{155, 637},{347, 709},{490, 780},
	       {155, 780},{490, 349},{312, 349},{420, 312},{420, 600},{635, 637},{203, 637},{563,708},{275,708}};


}


/*void juego::detectar_colision(){


	// Detectar colisiones entre el jugador y las colisiones
	for (auto& colision : colisiones)
	{
	    // Crear un rectángulo de colisión para la colisión actual
	    sf::FloatRect rectColision(colision.getPosition(), colision.getSize());
	
	    // Crear un rectángulo de colisión para el jugador
	    sf::FloatRect rectJugador(jugador.getPosition(), jugador.getSize());
		
	    // Detectar si ha ocurrido una colisión entre los dos rectángulos
	    if (rectJugador.intersects(rectColision))
	    {
	        // Si ha ocurrido una colisión, ajustar la posición del jugador para que esté justo al lado de la colisión
	        if (jugador.getPosition().x < colision.getPosition().x)
	        {
	            // El jugador estaba a la izquierda de la colisión, así que lo movemos a la izquierda de la colisión
	            jugador.setPosition(colision.getPosition().x - jugador.getSize().x, jugador.getPosition().y);
	        }
	        else
	        {
	            // El jugador estaba a la derecha de la colisión, así que lo movemos a la derecha de la colisión
	            jugador.setPosition(colision.getPosition().x + colision.getSize().x, jugador.getPosition().y);
	        }
	
	        if (jugador.getPosition().y < colision.getPosition().y)
	        {
	            // El jugador estaba arriba de la colisión, así que lo movemos arriba de la colisión
	            jugador.setPosition(jugador.getPosition().x, colision.getPosition().y - jugador.getSize().y);
	        }
	        else
	        {
	            // El jugador estaba abajo de la colisión, así que lo movemos abajo de la colisión
	            jugador.setPosition(jugador.getPosition().x, colision.getPosition().y + colision.getSize().y);
	        }
	    }
	}
}*/

void juego::crear_colisiones(){
	
	int col;
	// Crear 30 colisiones aleatorias
	for (int i = 0; i <= 8; i++)
    	{
        	// Crear un rectángulo con una posición y tamaño aleatorios
        	RectangleShape colision(Vector2f(tamano[i].first,tamano[i].second));
        	colision.setPosition(cords[i].first, cords[i].second);
        	colision.setFillColor(Color::Transparent);
        	colision.setOutlineThickness(1);
    		colision.setOutlineColor(Color::Red);

        	// Agregar el rectángulo al vector de colisiones
        	colisiones.push_back(colision);
        	
        	col=i;
    	}
    	
    	cout<<col<<endl;
    	
    	for(col;col<=36;col++){
    		RectangleShape obs(Vector2f(tamano[col].first,tamano[col].second));
        	obs.setPosition(cords[col].first, cords[col].second);
        	obs.setFillColor(Color::Transparent);
        	obs.setOutlineThickness(1);
    		obs.setOutlineColor(Color::Green);

        	// Agregar el rectángulo al vector de colisiones
        	colisiones.push_back(obs);
    	
    	}	
    	cout<<col<<endl;

}


void juego::procesar_eventos(){
	while (ventana1->pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                ventana1->close();
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



}

