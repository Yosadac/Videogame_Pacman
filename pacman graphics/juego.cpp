#include "juego.h"




juego::juego(int resolucion_x,int resolucion_y, string titulo){

	fps=60;
	mov_wum=0;
	mov_red=0;
	iniciar=0;
	ContextSettings settings;
	settings.antialiasingLevel = 0;
	ventana1 = new RenderWindow(VideoMode(resolucion_x,resolucion_y),titulo);
	ventana1->setFramerateLimit(fps);

    	cargar_texturas();
    	//crear_colision_jugador();
	llenar_cords();
	crear_colisiones();
	crear_pastillas();
	//spastilla.setPosition(300,300);
	
			
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
        for (auto& past : spastillas) {
            ventana1->draw(past);
        }
        //Anim_pastillas();
        /*animacion_red();
        animacion_blue();
        animacion_pink();
        animacion_orange();*/
        //animacion_pacman();
        animacion_redit();
        animacion_wumpus();
        mostrar_score();
        //Puntos();
        //animacion_pacman_muerte();
        //ventana1->draw(sred);

	ventana1->display();
	


}





void juego::gameLoop(){

	while(ventana1->isOpen()){		
		procesar_eventos();
		dibujar_pantalla();
		for(auto& coli : colisiones){
			redPosition=colision(sredit1,coli,redPosition);
			redPosition=colision(sredit2,coli,redPosition);
			redPosition=colision(sredit3,coli,redPosition);
			redPosition=colision(sredit4,coli,redPosition);
			wumPosition=colision(swumpus1,coli,wumPosition);
			wumPosition=colision(swumpus2,coli,wumPosition);
			wumPosition=colision(swumpus3,coli,wumPosition);
			colplayer(sredit1,swumpus1);
		}	
		
		Puntos(sredit1,1);
		Puntos(sredit2,1);
		Puntos(sredit3,1);
		
		Puntos(swumpus1,2);
		Puntos(swumpus2,2);
		Puntos(swumpus3,2);
		
		if(iniciar==0){
			inicio.play();
			while (inicio.getStatus() == sf::SoundSource::Playing) {
	    			// esperar un poco antes de volver a comprobar el estado
			    	sleep(milliseconds(100));
			    	iniciar=1;
			}
		}	
		
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






void juego::crear_colisiones(){
	
	int col;
	// Crear 30 colisiones aleatorias
	for (int i = 0; i <= 9; i++)
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
    	
    	for(col;col<=36;col++){
    		RectangleShape obs(Vector2f(tamano[col].first,tamano[col].second));
        	obs.setPosition(cords[col].first, cords[col].second);
        	obs.setFillColor(Color::Transparent);
        	obs.setOutlineThickness(1);
    		obs.setOutlineColor(Color::Green);

        	// Agregar el rectángulo al vector de colisiones
        	colisiones.push_back(obs);
    	
    	}	
}







void juego::procesar_eventos(){

	while (ventana1->pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                ventana1->close();
            }
        }

        /*mov_player2();
        mov_player3();
        mov_player4();*/
        mov_redit();
        mov_wumpus();
}
