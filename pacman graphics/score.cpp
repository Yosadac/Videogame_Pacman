#include "juego.h"

void juego::mostrar_score(){

    // Texto y vidas REDIT
    scoreString_red = "SCORE: " + std::to_string(score_red);
    Text text_red(scoreString_red, font, 24);
    if(redLife==3){
		ventana1 -> draw(demo_redit1);
		ventana1 -> draw(demo_redit2);
		ventana1 -> draw(demo_redit3);
	}
	else if(redLife==2){
		ventana1 -> draw(demo_redit1);
		ventana1 -> draw(demo_redit2);
	}
	else if(redLife==1){ventana1 -> draw(demo_redit1);}
	else if(redLife==0 && red_alive==true){players_alive=players_alive-1;red_alive=false;}

    
    // Texto y vidas WUMPUS
    scoreString_wum = "SCORE: " + std::to_string(score_wum);
    Text text_wum(scoreString_wum, font, 24);
    text_wum.setPosition(250, 0);
    
	if(wumLife==3){
		ventana1 -> draw(demo_wumpus1);
		ventana1 -> draw(demo_wumpus2);
		ventana1 -> draw(demo_wumpus3);
	}
	else if(wumLife==2){
		ventana1 -> draw(demo_wumpus1);
		ventana1 -> draw(demo_wumpus2);
	}
	else if(wumLife==1){ventana1 -> draw(demo_wumpus1);}
	else if(wumLife==0 && wum_alive==true){players_alive=players_alive-1;wum_alive=false;}

	// Texto y vidas TUX
	scoreString_tux = "SCORE: " + std::to_string(score_tux);
	Text text_tux(scoreString_tux, font, 24);
	text_tux.setPosition(500, 0);

	if(tuxLife==3){
		ventana1 -> draw(demo_tux1);
		ventana1 -> draw(demo_tux2);
		ventana1 -> draw(demo_tux3);
	}
	else if(tuxLife==2){
		ventana1 -> draw(demo_tux1);
		ventana1 -> draw(demo_tux2);
	}
	else if (tuxLife==1){ventana1 -> draw(demo_tux1);}
	else if(tuxLife==0 && tux_alive==true){players_alive=players_alive-1;tux_alive=false;}


	// Texto y vidas ANDROID
	scoreString_and = "SCORE: " + std::to_string(score_and);
	Text text_android(scoreString_and, font, 24);
	text_android.setPosition(750, 0);

	if(andLife==3){
		ventana1 -> draw(demo_android1);
		ventana1 -> draw(demo_android2);
		ventana1 -> draw(demo_android3);
	}
	else if(andLife==2){
		ventana1 -> draw(demo_android1);
		ventana1 -> draw(demo_android2);
	}
	else if(andLife==1){ventana1 -> draw(demo_android1);}
	else if(andLife==0 && and_alive==true){players_alive=players_alive-1;and_alive=false;}


    
    ventana1 -> draw(text_red);
    ventana1 -> draw(text_wum);
	ventana1 -> draw(text_tux);
	ventana1 -> draw(text_android);


}


void juego::crear_pastillas(){
	
    posicion_puntos();
	
    for (int i = 0; i < 244; i++) {
        Sprite sprite(bola1);
        sprite.setScale(0.2f,0.2f);
        sprite.setPosition(cords_pastillas[i].first,cords_pastillas[i].second);
        spastillas.push_back(sprite);
    }

}

void juego::Puntos(Sprite jugador,int flag){

for (auto& past : spastillas) {

	 if (jugador.getGlobalBounds().intersects(past.getGlobalBounds()))
        {
                past.setPosition(2000, 2000);
                sound.play();
                if(flag==1){score_red += 10;}
                else if(flag==2){score_wum += 10;}
				else if(flag==3){score_tux += 10;}
				else if(flag==4){score_and += 10;}
        }


}
}

void juego::posicion_puntos(){
	
	cords_pastillas={{130,155},{155,155},{180,155},{205,155},{230,155},{255,155},{275,155},{300,155},{325,155},{350,155},{375,155},{400,155},{470,155},{495,155},{520,155},{545,155},{570,155},{595,155},{617,155},{640,155},{665,155},{690,155},{715,155},{735,155},
		{130,180},{255,180},{400,180},{470,180},{617,180},{735,180},
		{130,205},{255,205},{400,205},{470,205},{617,205},{735,205},
		{130,230},{255,230},{400,230},{470,230},{617,230},{735,230},
		{130,255},{155,255},{180,255},{205,255},{230,255},{255,255},{275,255},{300,255},{325,255},{350,255},{375,255},{400,255},{425,255},{450,255},{470,255},{495,255},{520,255},{545,255},{570,255},{595,255},{617,255},{640,255},{665,255},{690,255},{715,255},{735,255},
		{130,280},{255,280},{325,280},{545,280},{617,280},{735,280},
		{130,305},{255,305},{325,305},{545,305},{617,305},{735,305},
		{130,330},{155,330},{180,330},{205,330},{230,330},{255,330},{325,330},{350,330},{375,330},{400,330},{470,330},{495,330},{520,330},{545,330},{617,330},{640,330},{665,330},{690,330},{715,330},{735,330},
		{255,355},{617,355},
		{255,380},{617,380},
		{255,405},{617,405},
		{255,430},{617,430},
		{255,455},{617,455},
		{255,480},{617,480},
		{255,505},{617,505},
		{255,530},{617,530},
		{255,555},{617,555},
		{255,580},{617,580},
		{130,615},{155,615},{180,615},{205,615},{230,615},{255,615},{275,615},{300,615},{325,615},{350,615},{375,615},{400,615},{470,615},{495,615},{520,615},{545,615},{570,615},{595,615},{617,615},{640,615},{665,615},{690,615},{715,615},{735,615},
		{130,640},{255,640},{400,640},{470,640},{617,640},{735,640},
		{130,665},{255,665},{400,665},{470,665},{617,665},{735,665},
		{130,690},{155,690},{180,690},{255,690},{275,690},{300,690},{325,690},{350,690},{375,690},{400,690},{425,690},{450,690},{470,690},{495,690},{520,690},{545,690},{570,690},{595,690},{617,690},{690,690},{715,690},{735,690},
		{180,715},{255,715},{325,715},{545,715},{617,715},{690,715},
		{180,740},{255,740},{325,740},{545,740},{617,740},{690,740},
		{130,765},{155,765},{180,765},{205,765},{230,765},{255,765},{325,765},{350,765},{375,765},{400,765},{470,765},{495,765},{520,765},{545,765},{617,765},{640,765},{665,765},{690,765},{715,765},{735,765},
		{130,790},{400,790},{470,790},{735,790},
		{130,815},{400,815},{470,815},{735,815},
		{130,840},{155,840},{180,840},{205,840},{230,840},{255,840},{275,840},{300,840},{325,840},{350,840},{375,840},{400,840},{425,840},{450,840},{470,840},{495,840},{520,840},{545,840},{570,840},{595,840},{617,840},{640,840},{665,840},{690,840},{715,840},{735,840}
 
	};


}


void juego::winner(){



	if(redLife>0){
		
		string ganador = " WINNER REDDIT ";
    	Text TextWin(ganador, font, 50);
		sredit1.setScale(5.0f,5.0f);
    	sredit2.setScale(5.0f,5.0f);
    	sredit3.setScale(5.0f,5.0f);
		sredit4.setScale(5.0f,5.0f);
		TextWin.setPosition(200, 200);
		redPosition=Vector2f(500,500);
		ventana1->draw(TextWin);
		animacion_redit();
		
	}
	else if(wumLife>0){

		string ganador = " WINNER WUMPUS ";
		Text TextWin(ganador, font, 50);
		swumpus1.setScale(5.0f,5.0f);
		swumpus2.setScale(5.0f,5.0f);
		swumpus3.setScale(5.0f,5.0f);
		TextWin.setPosition(200, 200);
		wumPosition=Vector2f(500,500);
		ventana1->draw(TextWin);
		animacion_wumpus();
	}
	else if(tuxLife>0){

		string ganador = " WINNER TUX ";
		Text TextWin(ganador, font, 50);
		stux1.setScale(5.0f,5.0f);
		stux2.setScale(5.0f,5.0f);
		stux3.setScale(5.0f,5.0f);
		stux4.setScale(5.0f,5.0f);
		TextWin.setPosition(200, 200);
		tuxPosition=Vector2f(500,500);
		ventana1->draw(TextWin);
		animacion_tux();
	}
	else if(andLife>0){

		string ganador = " WINNER ANDROID ";
		Text TextWin(ganador, font, 50);
		sandroid1.setScale(5.0f,5.0f);
		sandroid2.setScale(5.0f,5.0f);
		sandroid3.setScale(5.0f,5.0f);
		sandroid4.setScale(5.0f,5.0f);
		TextWin.setPosition(200, 200);
		andPosition=Vector2f(500,500);
		ventana1->draw(TextWin);
		animacion_android();
	}

}


void juego::animacion_virus(Vector2f &Position){
	if (clock.getElapsedTime().asMilliseconds() > 80) {
            spriteIndex = (spriteIndex + 1) % 4;
            clock.restart();
            }
        	if (spriteIndex == 0){
        	    svirus1.setPosition(Position);
        	    ventana1->draw(svirus1);
        	}
        	else if(spriteIndex == 1){
        	    svirus2.setPosition(Position);
        	    ventana1->draw(svirus2);
        	}
        	else if(spriteIndex==2){
        	    svirus3.setPosition(Position);
        	    ventana1->draw(svirus3);
        	}  
        	else {
        	    svirus4.setPosition(Position);
        	    ventana1->draw(svirus4);
        	}  
}