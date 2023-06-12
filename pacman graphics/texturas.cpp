#include "juego.h"

void juego::cargar_texturas(){
//1 wum, 2 red, 3 tux, 4 and
	Vector2f red(385,460),blue(415,460),pink(445,460),org(475,460);
	redPosition=red;
	wumPosition=blue;
	tuxPosition=pink;
	andPosition=org;
	spriteIndex = 0;
	score_red=0;
	score_wum=0;
	score_and=0;
	score_tux=0;
	
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
    //REDIT================================================================================================	
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
	sredit4.setScale(0.8f,0.8f);
	
	//sredit.setScale(0.03f,0.03f);
    	
	//WUMPUS================================================================================================
    	
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

	//TUX================================================================================================
	
	tux1.loadFromFile("nuevos_sprites/tux/tux1.png");
	tux2.loadFromFile("nuevos_sprites/tux/tux2.png");
	tux3.loadFromFile("nuevos_sprites/tux/tux3.png");
	tux4.loadFromFile("nuevos_sprites/tux/tux4.png");

	stux1.setTexture(tux1);
	stux2.setTexture(tux2);
	stux3.setTexture(tux3);
	stux4.setTexture(tux4);

	demo_tux1.setTexture(tux1);
	demo_tux2.setTexture(tux1);
	demo_tux3.setTexture(tux1);

	demo_tux1.setPosition(550,50);
	demo_tux2.setPosition(580,50);
	demo_tux3.setPosition(610,50);

	stux1.setScale(0.8f,0.8f);
	stux2.setScale(0.8f,0.8f);
	stux3.setScale(0.8f,0.8f);
	stux4.setScale(0.8f,0.8f);

	//ANDROID================================================================================================

	android1.loadFromFile("nuevos_sprites/android/android1.png");
	android2.loadFromFile("nuevos_sprites/android/android2.png");
	android3.loadFromFile("nuevos_sprites/android/android3.png");
	android4.loadFromFile("nuevos_sprites/android/android4.png");

	sandroid1.setTexture(android1);
	sandroid2.setTexture(android2);
	sandroid3.setTexture(android3);
	sandroid4.setTexture(android4);

	demo_android1.setTexture(android1);
	demo_android2.setTexture(android1);
	demo_android3.setTexture(android1);

	demo_android1.setPosition(800,50);
	demo_android2.setPosition(830,50);
	demo_android3.setPosition(860,50);

	sandroid1.setScale(0.7f,0.7f);
	sandroid2.setScale(0.7f,0.7f);
	sandroid3.setScale(0.7f,0.7f);
	sandroid4.setScale(0.7f,0.7f);

	//VIRUS================================================================================================

	virus1.loadFromFile("nuevos_sprites/virus/virus1.png");
	virus2.loadFromFile("nuevos_sprites/virus/virus2.png");
	virus3.loadFromFile("nuevos_sprites/virus/virus3.png");
	virus4.loadFromFile("nuevos_sprites/virus/virus4.png");

	svirus1.setTexture(virus1);
	svirus2.setTexture(virus2);
	svirus3.setTexture(virus3);
	svirus4.setTexture(virus4);
	
	demo_virus1.setTexture(virus1);
	demo_virus2.setTexture(virus1);
	demo_virus3.setTexture(virus1);
	demo_virus4.setTexture(virus1);

	svirus1.setScale(0.7f,0.7f);
	svirus2.setScale(0.7f,0.7f);
	svirus3.setScale(0.7f,0.7f);
	svirus4.setScale(0.7f,0.7f);


}

