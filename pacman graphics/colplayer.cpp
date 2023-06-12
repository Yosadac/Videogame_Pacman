#include "juego.h"

void juego::colplayer(Sprite &x , Sprite &y, Vector2f &Position,int flag, int &lifes){
    
    if(x.getGlobalBounds().intersects(y.getGlobalBounds())){
        if(flag==1){
            Position=Vector2f(415,460);
        }
        else if(flag==2){
            Position=Vector2f(385,460);
        }
        else if(flag==3){
            Position=Vector2f(445,460);
        }
        else if(flag==4){
            Position=Vector2f(475,460);
        }
        lifes=lifes-1;
    }
}



void juego::Power_up(int &LastScore,int &diferencia,int &clockInd,Clock &clocktime, Time &Tiempo,int &seconds, string &TextTime,bool &powerupplayer,int flag,int score,bool &confirmation){

    if(powerupplayer==false){
        if(flag==1){animacion_redit();}
        else if(flag==2){animacion_wumpus();}
        else if(flag==3){animacion_tux();}
        else if(flag==4){animacion_android();}
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
            if(flag==1){Texto_time(TextTime, 50, 100);animacion_virus(redPosition);}
            else if(flag==2){Texto_time(TextTime,300, 100);animacion_virus(wumPosition);}
            else if(flag==3){Texto_time(TextTime, 550, 100);animacion_virus(tuxPosition);}
            else if(flag==4){Texto_time(TextTime,800, 100);animacion_virus(andPosition);}
       	}
	    else{
			clockInd=1;
			powerupplayer=false;
			diferenciaRed=score_red;
            diferenciaWum=score_wum;
            diferenciaTux=score_tux;
            diferenciaAnd=score_and;
			soundpowerdown.play();
            confirmation=false;
		}
			//colplayer(sredit1,swumpus1,wumPosition,1,wumLife);
        if(flag==1){
            colplayer(svirus1,swumpus1,wumPosition,1,wumLife);
            colplayer(svirus1,stux1,tuxPosition,3,tuxLife);
            colplayer(svirus1,sandroid1,andPosition,4,andLife);
        }
        else if(flag==2){
            colplayer(svirus1,sredit1,redPosition,2,redLife);
            colplayer(svirus1,stux1,tuxPosition,3,tuxLife);
            colplayer(svirus1,sandroid1,andPosition,4,andLife);
        }
        else if(flag==3){
            colplayer(svirus1,sandroid1,andPosition,4,andLife);
            colplayer(svirus1,sredit1,redPosition,2,redLife);
            colplayer(svirus1,swumpus1,wumPosition,1,wumLife);
        }
        else if(flag==4){
            colplayer(svirus1,stux1,tuxPosition,3,tuxLife);
            colplayer(svirus1,sredit1,redPosition,2,redLife);
            colplayer(svirus1,swumpus1,wumPosition,1,wumLife);
        }
	}
}

