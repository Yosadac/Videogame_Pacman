#include "juego.h"
#include "menu.h"




juego::juego(int resolucion_x,int resolucion_y, string titulo, bool ser){

	host=ser;
	fps=60;
	mov_wum=0;
	mov_red=0;
	iniciar=0;
	diferenciaRed=0;
	powerupred=false;
	RedClock=1;
	diferenciaWum=0;
	powerupwum=false;
	WumClock=1;
	redLife=3;
	wumLife=3;
	confirmationRed=false;
	confirmationWum=false;
	diferenciaTux=0;
	poweruptux=false;
	TuxClock=1;
	tuxLife=3;
	confirmationTux=false;
	diferenciaAnd=0;
	powerupand=false;
	AndClock=1;
	andLife=3;
	confirmationAnd=false;
	players_alive=4;
	red_alive=true;
	wum_alive=true;
	tux_alive=true;
	and_alive=true;

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
	if(players_alive==1){
		winner();
	}
	else{

		ventana1->draw(smapa);
	

		/*for (auto& colision : colisiones )
	        {
	            ventana1->draw(colision);
	        }*/
	    for (auto& past : spastillas) {
	        ventana1->draw(past);
	    }

		if(redLife>0){
			LastScoreRed=score_red-diferenciaRed;
			if(LastScoreRed==100 && confirmationWum==false){
				powerupred=true;
				confirmationRed=true;
			}
			Power_up(LastScoreRed,diferenciaRed,RedClock,clockRed,TiempoRed,secondsRed,TextTimeRed,powerupred,1,score_red,confirmationRed);
		}
		if(wumLife>0){
			LastScoreWum=score_wum-diferenciaWum;
			if(LastScoreWum==100 && confirmationRed==false){
				powerupwum=true;
				confirmationWum=true;
			}
			Power_up(LastScoreWum,diferenciaWum,WumClock,clockWum,TiempoWum,secondsWum,TextTimeWum,powerupwum,2,score_wum,confirmationWum);
		}
		if(tuxLife>0){
			LastScoreTux=score_tux-diferenciaTux;
			if(LastScoreTux==100 && confirmationTux==false){
				poweruptux=true;
				confirmationTux=true;
			}
			Power_up(LastScoreTux,diferenciaTux,TuxClock,clockTux,TiempoTux,secondsTux,TextTimeTux,poweruptux,3,score_tux,confirmationTux);
		}
		if(andLife>0){
			LastScoreAnd=score_and-diferenciaAnd;
			if(LastScoreAnd==100 && confirmationAnd==false){
				powerupand=true;
				confirmationAnd=true;
			}
			Power_up(LastScoreAnd,diferenciaAnd,AndClock,clockAnd,TiempoAnd,secondsAnd,TextTimeAnd,powerupand,4,score_and,confirmationAnd);
		}
    	mostrar_score();
		//Puntos();
 	    //animacion_pacman_muerte();
    	//ventana1->draw(sred);
	}
		ventana1->display();
	
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
		mov_tuxf();
		mov_android();
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

			tuxPosition=colision(stux1,coli,tuxPosition);
			tuxPosition=colision(stux2,coli,tuxPosition);
			tuxPosition=colision(stux3,coli,tuxPosition);
			tuxPosition=colision(stux4,coli,tuxPosition);

			andPosition=colision(sandroid1,coli,andPosition);
			andPosition=colision(sandroid2,coli,andPosition);
			andPosition=colision(sandroid3,coli,andPosition);
			andPosition=colision(sandroid4,coli,andPosition);

		}	
		
		Puntos(sredit1,1);
		Puntos(sredit2,1);
		Puntos(sredit3,1);
		Puntos(sredit4,1);
		
		Puntos(swumpus1,2);
		Puntos(swumpus2,2);
		Puntos(swumpus3,2);

		Puntos(stux1,3);
		Puntos(stux2,3);
		Puntos(stux3,3);
		Puntos(stux4,3);

		Puntos(sandroid1,4);
		Puntos(sandroid2,4);
		Puntos(sandroid3,4);
		Puntos(sandroid4,4);


		
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
		{228, 35},{70, 34},{70, 34},{34, 70},{34, 70},{35, 107},{35, 107},{34, 107},{34, 107},{34, 107},
		{60,15},{15,110},{182,15},{15,110},{60,15}};
	
	cords={{105,130},{105,130},{105,855},{753,130},{635,348},{105,348},{417,130},{105,708},{706,708},
	    {490, 179},{635, 180},{635, 275},{275, 180},{155, 180},{155, 275},{563, 275},{275, 275},{347, 275},
	    {563,490},{275,490},{347, 565},{490, 637},{635, 637},{275, 637},{155, 637},{347, 709},{490, 780},
	    {155, 780},{490, 349},{312, 349},{420, 312},{420, 600},{635, 637},{203, 637},{563,708},{275,708},{420,708},
		{345,420},{345,420},{345,515},{513,420},{467,420}};


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
    	
  	for(col;col<=41;col++){
   		RectangleShape obs(Vector2f(tamano[col].first,tamano[col].second));
       	obs.setPosition(cords[col].first, cords[col].second);
       	obs.setFillColor(Color::Transparent);
       	obs.setOutlineThickness(1);
   		obs.setOutlineColor(Color::Green);

       	// Agregar el rectángulo al vector de colisiones
       	colisiones.push_back(obs);
    	
   	}	
}



void juego::Texto_time(string texto, int tam_x, int tam_y){

	Text TimeRemaining(texto, font, 20);
    TimeRemaining.setPosition(tam_x, tam_y);    
	ventana1->draw(TimeRemaining);
}


