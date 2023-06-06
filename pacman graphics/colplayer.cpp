#include "juego.h"

void juego::colplayer(Sprite x , Sprite y){

if(x.getGlobalBounds().intersects(y.getGlobalBounds())){

ventana1->close();

}




}

