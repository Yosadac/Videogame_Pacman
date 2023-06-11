#include "juego.h"

void juego::cargar_texturas(){

	Vector2f red(385,460),blue(415,460),pink(445,460),org(475,460),pac(430,535);
	redPosition=red;
	wumPosition=blue;
	pinkPosition=pink;
	orangePosition=org;
	spriteIndex = 0;
	score_red=0;
	score_wum=0;
	
	    // Cargar la fuente desde un archivo
    if (!font.loadFromFile("8-BIT WONDER.TTF")) {
        cerr << "Error al cargar la fuente" << std::endl;
    }

	
	//PUNTOS------------------------------------------------------------
	bola1.loadFromFile("puntos/bola1.png");
	
	//SONIDO----------------------------------------------------------------PUNTOS
	buffer.loadFromFile("Puntos.wav");
	sound.setBuffer(buffer);

	//SONIDO----------------------------------------------------------------POWERUP
	bufferpowerup.loadFromFile("power_up.wav");
	soundpowerup.setBuffer(bufferpowerup);

	//SONIDO----------------------------------------------------------------POWERDOWN
	bufferpowerdown.loadFromFile("power_up_reverse.wav");
	soundpowerdown.setBuffer(bufferpowerdown);
	
	
	bufferInicio.loadFromFile("SONIDO-DE-INICIO-DEL-JUEGO-PACMAN-AUDIO-HD.wav");
	inicio.setBuffer(bufferInicio);
	
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
    	
    	//Nuevos sprites===============================================================================
    	
    redit1.loadFromFile("nuevos_sprites/redditor/redditor1.png");
    redit2.loadFromFile("nuevos_sprites/redditor/redditor2.png");
    redit3.loadFromFile("nuevos_sprites/redditor/redditor3.png");
    redit4.loadFromFile("nuevos_sprites/redditor/redditor4.png");	
	
	sredit1.setTexture(redit1);
	sredit2.setTexture(redit2);
	sredit3.setTexture(redit3);
	sredit4.setTexture(redit4);
	
	demo_redit1.setTexture(redit1);
	demo_redit2.setTexture(redit1);
	demo_redit3.setTexture(redit1);
	
	demo_redit1.setPosition(50,50);
	demo_redit2.setPosition(80,50);
	demo_redit3.setPosition(110,50);
	
	sredit1.setPosition(redPosition);
    sredit2.setPosition(redPosition);
    sredit3.setPosition(redPosition);
    
    	
    sredit1.setScale(0.8f,0.8f);
    sredit2.setScale(0.8f,0.8f);
    sredit3.setScale(0.8f,0.8f);
	
	//sredit.setScale(0.03f,0.03f);
    	
    	
    	
    wumpus1.loadFromFile("nuevos_sprites/wumpus/wumpus1.png");
    wumpus2.loadFromFile("nuevos_sprites/wumpus/wumpus2.png");
    wumpus3.loadFromFile("nuevos_sprites/wumpus/wumpus3.png");
	
	swumpus1.setTexture(wumpus1);
	swumpus2.setTexture(wumpus2);
	swumpus3.setTexture(wumpus3);
	
	demo_wumpus1.setTexture(wumpus1);
	demo_wumpus2.setTexture(wumpus1);
	demo_wumpus3.setTexture(wumpus1);

	demo_wumpus1.setPosition(300,50);
	demo_wumpus2.setPosition(330,50);
	demo_wumpus3.setPosition(360,50);
	
	swumpus1.setScale(0.8f,0.8f);
    swumpus2.setScale(0.8f,0.8f);
    swumpus3.setScale(0.8f,0.8f);

}

