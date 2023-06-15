#include "juego.h"



Vector2f juego::colision(Sprite x,RectangleShape Obs1, Vector2f spritePosition){
    if (spritePosition.x+30.f >= Obs1.getGlobalBounds().left && spritePosition.x <= Obs1.getGlobalBounds().left+Obs1.getGlobalBounds().width&& (spritePosition.y<=(Obs1.getGlobalBounds().top-5.f + Obs1.getGlobalBounds().height) && spritePosition.y>=Obs1.getGlobalBounds().top -23.f)) 

    {   
        spritePosition.x -= 1.5f; 
           
    }

    if (spritePosition.y <= (Obs1.getGlobalBounds().top + Obs1.getGlobalBounds().height) && spritePosition.y >= (Obs1.getGlobalBounds().top)  && (spritePosition.x<=(Obs1.getGlobalBounds().left + Obs1.getGlobalBounds().width) && spritePosition.x>=Obs1.getGlobalBounds().left -23.f)) 

    {
        spritePosition.y += 1.5f;
           
    }

    if (x.getGlobalBounds().top+x.getGlobalBounds().height >= (Obs1.getGlobalBounds().top-5.f) && x.getGlobalBounds().top+x.getGlobalBounds().height <= (Obs1.getGlobalBounds().top+Obs1.getGlobalBounds().height-5.F) && (spritePosition.x<=(Obs1.getGlobalBounds().left + Obs1.getGlobalBounds().width) && spritePosition.x>=Obs1.getGlobalBounds().left -20.f)) 

    {

        spritePosition.y -= 1.5f;
           
    }

    if (spritePosition.x+x.getGlobalBounds().width-30.f <= Obs1.getGlobalBounds().left+Obs1.getGlobalBounds().width && spritePosition.x+x.getGlobalBounds().width >= Obs1.getGlobalBounds().left && (spritePosition.y<=(Obs1.getGlobalBounds().top-5.f + Obs1.getGlobalBounds().height) && spritePosition.y>=Obs1.getGlobalBounds().top -23.f)) 

    {
        spritePosition.x += 1.5f;
            
           
    }        
    return spritePosition;
}
