#include "juego.h"

void juego::cargar_texturas(){

	Vector2f red(385,460),blue(415,460),pink(445,460),org(475,460),pac(430,535);
	redPosition=red;
	bluePosition=blue;
	pinkPosition=pink;
	orangePosition=org;
	spritePosition=pac;
	spriteIndex = 0;
	spriteIndexMuerte = 0;
	score=0;
	
	/*Font font;
	font.loadFromFile("/home/kali/Desktop/8-BIT WONDER.TTF");
	//PUNTUACION--------------------------------------------------------
	scoreText.setFont(font); // Asigna la fuente del texto
	scoreText.setCharacterSize(30); // Asigna el tamaño del texto
	scoreText.setPosition(10, 10); // Asigna la posición del texto
	scoreText.setString("Puntuacion: " + std::to_string(score)); // Asigna el valor de la puntuación
*/
	//PUNTOS------------------------------------------------------------
	pastilla.loadFromFile("puntos/pastilla.png");
	spastilla.setTexture(pastilla);
	spastilla.setScale(0.02f,0.02f);
	
	//mapa---------------------------------------------------------------
	//mapa = new Texture;
	mapa.loadFromFile("Mapa PACMAN V2.png");

    	// Crear el sprite
    	
    	//smapa = new Sprite;
	smapa.setTexture(mapa);
       	//EStablece el tamano del mapa
    	smapa.setScale(0.385f, 0.385f);
	// Establecer la posición inicial del sprite en la parte inferior derecha de la ventana
    	smapa.setPosition(smapa.getPosition().x+100,smapa.getPosition().y+125);
	
	//pacman-------------------------------------------------------------
	
	
	pac1.loadFromFile("pacman/pacman.mov.1.png");	
	pac2.loadFromFile("pacman/pacman.mov.2.png");	
	pac3.loadFromFile("pacman/pacman.mov.3.png");	
	
	spac1.setTexture(pac1);
	spac2.setTexture(pac2);
	spac3.setTexture(pac3);
	
	spac1.setScale(0.035f,0.035f);
    	spac2.setScale(0.035f,0.035f);
    	spac3.setScale(0.035f,0.035f);
    	
    	//pacman muerte----------------------------------------------------
    	
    	mpac1.loadFromFile("pacman/muerte/pacman.muerte.1.png");	
	mpac2.loadFromFile("pacman/muerte/pacman.muerte.2.png");	
	mpac3.loadFromFile("pacman/muerte/pacman.muerte.3.png");	
	mpac4.loadFromFile("pacman/muerte/pacman.muerte.4.png");	
	mpac5.loadFromFile("pacman/muerte/pacman.muerte.5.png");	
	mpac6.loadFromFile("pacman/muerte/pacman.muerte.6.png");	
	mpac7.loadFromFile("pacman/muerte/pacman.muerte.7.png");	
	mpac8.loadFromFile("pacman/muerte/pacman.muerte.8.png");
    	mpac9.loadFromFile("pacman/muerte/pacman.muerte.9.png");	
	mpac10.loadFromFile("pacman/muerte/pacman.muerte.10.png");	
	mpac11.loadFromFile("pacman/muerte/pacman.muerte.11.png");	
	mpac12.loadFromFile("pacman/muerte/pacman.muerte.12.png");	
	
	
	smpac1.setTexture(mpac1);
	smpac2.setTexture(mpac2);
	smpac3.setTexture(mpac3);
	smpac4.setTexture(mpac4);
	smpac5.setTexture(mpac5);
	smpac6.setTexture(mpac6);
	smpac7.setTexture(mpac7);
	smpac8.setTexture(mpac8);
	smpac9.setTexture(mpac9);
	smpac10.setTexture(mpac10);
	smpac11.setTexture(mpac11);
	smpac12.setTexture(mpac12);
	
	
	smpac1.setScale(0.03f,0.03f);
    	smpac2.setScale(0.03f,0.03f);
    	smpac3.setScale(0.03f,0.03f);
    	smpac4.setScale(0.03f,0.03f);
    	smpac5.setScale(0.03f,0.03f);
    	smpac6.setScale(0.03f,0.03f);
    	smpac7.setScale(0.03f,0.03f);
    	smpac8.setScale(0.03f,0.03f);
    	smpac9.setScale(0.03f,0.03f);
    	smpac10.setScale(0.03f,0.03f);
    	smpac11.setScale(0.03f,0.03f);
    	smpac12.setScale(0.03f,0.03f);

    	
    	
    	//fantasmas--------------------------------------------------------
    	
    	//RED-----------------------------------------------------------
		
	redar1.loadFromFile("fantasmas/red/fantasma.red.arr.1.png");	
	redar2.loadFromFile("fantasmas/red/fantasma.red.arr.2.png");	
	redab1.loadFromFile("fantasmas/red/fantasma.red.abj.1.png");	
	redab2.loadFromFile("fantasmas/red/fantasma.red.abj.2.png");	
	redi1.loadFromFile("fantasmas/red/fantasma.red.izq.1.png");	
	redi2.loadFromFile("fantasmas/red/fantasma.red.izq.2.png");	
	redd1.loadFromFile("fantasmas/red/fantasma.red.der.1.png");	
	redd2.loadFromFile("fantasmas/red/fantasma.red.der.2.png");
	

	sredar1.setTexture(redar1);
	sredar2.setTexture(redar2);
	sredab1.setTexture(redab1);
	sredab2.setTexture(redab2);
	sredi1.setTexture(redi1);
	sredi2.setTexture(redi2);
	sredd1.setTexture(redd1);
	sredd2.setTexture(redd2);
	
	
	sredar1.setScale(0.03f,0.03f);
    	sredar2.setScale(0.03f,0.03f);
    	sredab1.setScale(0.03f,0.03f);
    	sredab2.setScale(0.03f,0.03f);
    	sredi1.setScale(0.03f,0.03f);
    	sredi2.setScale(0.03f,0.03f);
    	sredd1.setScale(0.03f,0.03f);
    	sredd2.setScale(0.03f,0.03f);
    	
    	//BLUE-----------------------------------------------------------------
    	
    	bluear1.loadFromFile("fantasmas/blue/fantasma.blue.arr.1.png");	
	bluear2.loadFromFile("fantasmas/blue/fantasma.blue.arr.2.png");	
	blueab1.loadFromFile("fantasmas/blue/fantasma.blue.abj.1.png");	
	blueab2.loadFromFile("fantasmas/blue/fantasma.blue.abj.2.png");	
	bluei1.loadFromFile("fantasmas/blue/fantasma.blue.izq.1.png");	
	bluei2.loadFromFile("fantasmas/blue/fantasma.blue.izq.2.png");	
	blued1.loadFromFile("fantasmas/blue/fantasma.blue.der.1.png");	
	blued2.loadFromFile("fantasmas/blue/fantasma.blue.der.2.png");
	
	
	sbluear1.setTexture(bluear1);
	sbluear2.setTexture(bluear2);
	sblueab1.setTexture(blueab1);
	sblueab2.setTexture(blueab2);
	sbluei1.setTexture(bluei1);
	sbluei2.setTexture(bluei2);
	sblued1.setTexture(blued1);
	sblued2.setTexture(blued2);
	
	
	sbluear1.setScale(0.03f,0.03f);
    	sbluear2.setScale(0.03f,0.03f);
    	sblueab1.setScale(0.03f,0.03f);
    	sblueab2.setScale(0.03f,0.03f);
    	sbluei1.setScale(0.03f,0.03f);
    	sbluei2.setScale(0.03f,0.03f);
    	sblued1.setScale(0.03f,0.03f);
    	sblued2.setScale(0.03f,0.03f);
    	
    	//PINK------------------------------------------------------------------------------
	
	pinkar1.loadFromFile("fantasmas/pink/fantasma.pink.arr.1.png");	
	pinkar2.loadFromFile("fantasmas/pink/fantasma.pink.arr.2.png");	
	pinkab1.loadFromFile("fantasmas/pink/fantasma.pink.abj.1.png");	
	pinkab2.loadFromFile("fantasmas/pink/fantasma.pink.abj.2.png");	
	pinki1.loadFromFile("fantasmas/pink/fantasma.pink.izq.1.png");	
	pinki2.loadFromFile("fantasmas/pink/fantasma.pink.izq.2.png");	
	pinkd1.loadFromFile("fantasmas/pink/fantasma.pink.der.1.png");	
	pinkd2.loadFromFile("fantasmas/pink/fantasma.pink.der.2.png");
	
	
	spinkar1.setTexture(pinkar1);
	spinkar2.setTexture(pinkar2);
	spinkab1.setTexture(pinkab1);
	spinkab2.setTexture(pinkab2);
	spinki1.setTexture(pinki1);
	spinki2.setTexture(pinki2);
	spinkd1.setTexture(pinkd1);
	spinkd2.setTexture(pinkd2);
	
	
	spinkar1.setScale(0.03f,0.03f);
    	spinkar2.setScale(0.03f,0.03f);
    	spinkab1.setScale(0.03f,0.03f);
    	spinkab2.setScale(0.03f,0.03f);
    	spinki1.setScale(0.03f,0.03f);
    	spinki2.setScale(0.03f,0.03f);
    	spinkd1.setScale(0.03f,0.03f);
    	spinkd2.setScale(0.03f,0.03f);
    	
    	//ORANGE------------------------------------------------------------------------------
	
	orangear1.loadFromFile("fantasmas/orange/fantasma.orange.arr.1.png");	
	orangear2.loadFromFile("fantasmas/orange/fantasma.orange.arr.2.png");	
	orangeab1.loadFromFile("fantasmas/orange/fantasma.orange.abj.1.png");	
	orangeab2.loadFromFile("fantasmas/orange/fantasma.orange.abj.2.png");	
	orangei1.loadFromFile("fantasmas/orange/fantasma.orange.izq.1.png");	
	orangei2.loadFromFile("fantasmas/orange/fantasma.orange.izq.2.png");	
	oranged1.loadFromFile("fantasmas/orange/fantasma.orange.der.1.png");	
	oranged2.loadFromFile("fantasmas/orange/fantasma.orange.der.2.png");
	
	
	sorangear1.setTexture(orangear1);
	sorangear2.setTexture(orangear2);
	sorangeab1.setTexture(orangeab1);
	sorangeab2.setTexture(orangeab2);
	sorangei1.setTexture(orangei1);
	sorangei2.setTexture(orangei2);
	soranged1.setTexture(oranged1);
	soranged2.setTexture(oranged2);
	
	
	sorangear1.setScale(0.03f,0.03f);
    	sorangear2.setScale(0.03f,0.03f);
    	sorangeab1.setScale(0.03f,0.03f);
    	sorangeab2.setScale(0.03f,0.03f);
    	sorangei1.setScale(0.03f,0.03f);
    	sorangei2.setScale(0.03f,0.03f);
    	soranged1.setScale(0.03f,0.03f);
    	soranged2.setScale(0.03f,0.03f);

}

/*void juego::animacion_pacman(){

        if (clock.getElapsedTime().asMilliseconds() > 100) {
            spriteIndex = (spriteIndex + 1) % 3;
            clock.restart();
        }
        if (spriteIndex == 0){
            spac1.setPosition(spritePosition);
            ventana1->draw(spac1);
        }
        else if(spriteIndex== 1){
            spac2.setPosition(spritePosition);
            ventana1->draw(spac2);
        }
        else{
            spac3.setPosition(spritePosition);
            ventana1->draw(spac3);
        }

}


void juego::animacion_pacman_muerte(){

        if (clock.getElapsedTime().asMilliseconds() > 80) {
            spriteIndexMuerte = (spriteIndexMuerte + 1)%12;
            clock.restart();
        }
        if (spriteIndexMuerte == 0){
            smpac1.setPosition(spritePosition);
            ventana1->draw(smpac1);
        }
        else if(spriteIndexMuerte== 1){
            smpac2.setPosition(spritePosition);
            ventana1->draw(smpac2);
        }
        else if(spriteIndexMuerte==2){
            smpac3.setPosition(spritePosition);
            ventana1->draw(smpac3);
        }
        else if (spriteIndexMuerte == 3){
            smpac4.setPosition(spritePosition);
            ventana1->draw(smpac4);
        }
        else if(spriteIndexMuerte== 4){
            smpac5.setPosition(spritePosition);
            ventana1->draw(smpac5);
        }
        else if(spriteIndexMuerte==5){
            smpac6.setPosition(spritePosition);
            ventana1->draw(smpac6);
        }
        else if(spriteIndexMuerte== 6){
            smpac7.setPosition(spritePosition);
            ventana1->draw(smpac7);
        }
        else if(spriteIndexMuerte==7){
            smpac8.setPosition(spritePosition);
            ventana1->draw(smpac8);
        }
        else if (spriteIndexMuerte == 8){
            smpac9.setPosition(spritePosition);
            ventana1->draw(smpac9);
        }
        else if(spriteIndexMuerte== 9){
            smpac10.setPosition(spritePosition);
            ventana1->draw(smpac10);
        }
        else if(spriteIndexMuerte==10){
            smpac11.setPosition(spritePosition);
            ventana1->draw(smpac11);
        }
        else{
            smpac12.setPosition(spritePosition);
            ventana1->draw(smpac12);
        }
}
*/

/*void juego::animacion_red(){


        if (clock.getElapsedTime().asMilliseconds() > 100) {
            spriteIndex = (spriteIndex + 1) % 2;
            clock.restart();
        }
        if(mov==1){
        	if (spriteIndex == 0){
        	    sredar1.setPosition(redPosition);
        	    ventana1->draw(sredar1);
        	}
        	else{
        	    sredar2.setPosition(redPosition);
        	    ventana1->draw(sredar2);
        	}
        }
        else if(mov==2){
        	if (spriteIndex == 0){
        	    sredab1.setPosition(redPosition);
        	    ventana1->draw(sredab1);
        	}
        	else{
        	    sredab2.setPosition(redPosition);
        	    ventana1->draw(sredab2);
        	}       
        }
        else if(mov==3){
        	if (spriteIndex == 0){
        	    sredi1.setPosition(redPosition);
        	    ventana1->draw(sredi1);
        	}
        	else{
        	    sredi2.setPosition(redPosition);
        	    ventana1->draw(sredi2);
        	}       
        }
        else if(mov==4 || mov==0){
        	if (spriteIndex == 0){
        	    sredd1.setPosition(redPosition);
        	    ventana1->draw(sredd1);
        	}
        	else{
        	    sredd2.setPosition(redPosition);
        	    ventana1->draw(sredd2);
        	}       
        }
}*/


/*
void juego::animacion_blue(){


        if (clock.getElapsedTime().asMilliseconds() > 100) {
            spriteIndex = (spriteIndex + 1) % 2;
            clock.restart();
        }
        if(mov==1){
        	if (spriteIndex == 0){
        	    sbluear1.setPosition(bluePosition);
        	    ventana1->draw(sbluear1);
        	}
        	else{
        	    sbluear2.setPosition(bluePosition);
        	    ventana1->draw(sbluear2);
        	}
        }
        else if(mov==2){
        	if (spriteIndex == 0){
        	    sblueab1.setPosition(bluePosition);
        	    ventana1->draw(sblueab1);
        	}
        	else{
        	    sblueab2.setPosition(bluePosition);
        	    ventana1->draw(sblueab2);
        	}       
        }
        else if(mov==3){
        	if (spriteIndex == 0){
        	    sbluei1.setPosition(bluePosition);
        	    ventana1->draw(sbluei1);
        	}
        	else{
        	    sbluei2.setPosition(bluePosition);
        	    ventana1->draw(sbluei2);
        	}       
        }
        else if(mov==4 || mov==0){
        	if (spriteIndex == 0){
        	    sblued1.setPosition(bluePosition);
        	    ventana1->draw(sblued1);
        	}
        	else{
        	    sblued2.setPosition(bluePosition);
        	    ventana1->draw(sblued2);
        	}       
        }
}
*/
/*void juego::animacion_pink(){


        if (clock.getElapsedTime().asMilliseconds() > 100) {
            spriteIndex = (spriteIndex + 1) % 2;
            clock.restart();
        }
        if(mov==1){
        	if (spriteIndex == 0){
        	    spinkar1.setPosition(pinkPosition);
        	    ventana1->draw(spinkar1);
        	}
        	else{
        	    spinkar2.setPosition(pinkPosition);
        	    ventana1->draw(spinkar2);
        	}
        }
        else if(mov==2){
        	if (spriteIndex == 0){
        	    spinkab1.setPosition(pinkPosition);
        	    ventana1->draw(spinkab1);
        	}
        	else{
        	    spinkab2.setPosition(pinkPosition);
        	    ventana1->draw(spinkab2);
        	}       
        }
        else if(mov==3){
        	if (spriteIndex == 0){
        	    spinki1.setPosition(pinkPosition);
        	    ventana1->draw(spinki1);
        	}
        	else{
        	    spinki2.setPosition(pinkPosition);
        	    ventana1->draw(spinki2);
        	}       
        }
        else if(mov==4 || mov==0){
        	if (spriteIndex == 0){
        	    spinkd1.setPosition(pinkPosition);
        	    ventana1->draw(spinkd1);
        	}
        	else{
        	    spinkd2.setPosition(pinkPosition);
        	    ventana1->draw(spinkd2);
        	}       
        }
}*/



void juego::animacion_orange(){


        if (clock.getElapsedTime().asMilliseconds() > 100) {
            spriteIndex = (spriteIndex + 1) % 2;
            clock.restart();
        }
        if(mov==1){
        	if (spriteIndex == 0){
        	    sorangear1.setPosition(orangePosition);
        	    ventana1->draw(sorangear1);
        	}
        	else{
        	    sorangear2.setPosition(orangePosition);
        	    ventana1->draw(sorangear2);
        	}
        }
        else if(mov==2){
        	if (spriteIndex == 0){
        	    sorangeab1.setPosition(orangePosition);
        	    ventana1->draw(sorangeab1);
        	}
        	else{
        	    sorangeab2.setPosition(orangePosition);
        	    ventana1->draw(sorangeab2);
        	}       
        }
        else if(mov==3){
        	if (spriteIndex == 0){
        	    sorangei1.setPosition(orangePosition);
        	    ventana1->draw(sorangei1);
        	}
        	else{
        	    sorangei2.setPosition(orangePosition);
        	    ventana1->draw(sorangei2);
        	}       
        }
        else if(mov==4 || mov==0){
        	if (spriteIndex == 0){
        	    soranged1.setPosition(orangePosition);
        	    ventana1->draw(soranged1);
        	}
        	else{
        	    soranged2.setPosition(orangePosition);
        	    ventana1->draw(soranged2);
        	}       
        }
}


/*void juego::Puntos(){
	score++;
	scoreText.setString("Puntuacion: " + std::to_string(score)); // Actualiza el valor del texto de la puntuación
	ventana1->draw(scoreText);

}*/
