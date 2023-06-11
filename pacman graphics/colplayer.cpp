#include "juego.h"

void juego::colplayer(Sprite &x , Sprite &y, Vector2f &Position,int flag, int &lifes){
    
    if(x.getGlobalBounds().intersects(y.getGlobalBounds())){
        if(flag==1){
            Position=Vector2f(415,460);
        }
        else if(flag==2){
            Position=Vector2f(385,460);
        }
        lifes=lifes-1;
    }
}



void juego::Power_up(int &LastScore,int &diferencia,int &clockInd,Clock &clocktime, Time &Tiempo,int &seconds, string &TextTime,bool &powerupplayer,int flag,int score,bool &confirmation){

    if(powerupplayer==false){
        if(flag==1){animacion_redit();}
        else if(flag==2){animacion_wumpus();}
	}
    else{
		if(clockInd==1){
			soundpowerup.play();
			clocktime.restart();
			clockInd=0;
		}

     	Tiempo = clocktime.getElapsedTime();
       	seconds = 10 - Tiempo.asSeconds();

		if(seconds!=0){
  			TextTime="TIME:" + std::to_string(seconds);
            if(flag==1){Texto_time(TextTime, 50, 100);animacion_redit();}
            else if(flag==2){Texto_time(TextTime,300, 100);animacion_wumpus();}
       	}
	    else{
			clockInd=1;
			powerupplayer=false;
			diferenciaRed=score_red;
            diferenciaWum=score_wum;
			soundpowerdown.play();
            confirmation=false;
		}
			//colplayer(sredit1,swumpus1,wumPosition,1,wumLife);
        if(flag==1){
            colplayer(sredit1,swumpus1,wumPosition,1,wumLife);
        }
        else if(flag==2){
            colplayer(swumpus1,sredit1,redPosition,2,redLife);
        }
	}
}

