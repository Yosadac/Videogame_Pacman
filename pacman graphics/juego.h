//#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
//#include <gif_lib.h>
#include <vector>
#include <iostream>

using namespace std;
using namespace sf;


class juego{

	public:
	
		juego(int resolucion_x,int resolucion_y, string titulo);
		void dibujar_pantalla();
		void gameLoop();
		void llenar_cords();
		void procesar_eventos();
		void detectar_colision();
		void cargar_texturas();
		void crear_colisiones();
		void Puntos(Sprite jugador, int flag);
		void mostrar_score();
		void crear_pastillas();
		void posicion_puntos();
		void Anim_pastillas();
		void colplayer(Sprite x , Sprite y);
		void animacion_redit();
		void mov_redit();
		
		void animacion_wumpus();
		void mov_wumpus();
		
		
		Vector2f colision(Sprite x, RectangleShape Obs1, Vector2f spritePosition);
	private:
	
		RenderWindow * ventana1;
		int fps,mov,iniciar,mov_red,mov_wum;
		Texture mapa,red,muerte;
		Sprite smapa,sred,smuerte;
		
		Texture mpac1,mpac2,mpac3,mpac4,mpac5,mpac6,mpac7,mpac8,mpac9,mpac10,mpac11,mpac12,pastilla;
		Sprite smpac1,smpac2,smpac3,smpac4,smpac5,smpac6,smpac7,smpac8,smpac9,smpac10,smpac11,smpac12;
		
		Texture bola1;
		
		Texture redit1,redit2,redit3,redit4,wumpus1,wumpus2,wumpus3;
		
		Sprite sredit1,sredit2,sredit3,sredit4,swumpus1,swumpus2,swumpus3;
		
		Sprite demo_redit, demo_wumpus;
		
		vector<Sprite> spastillas;	
		
		Event event;
		Vector2f redPosition,wumPosition,pinkPosition,orangePosition;
		int spriteIndex,aviso_red,aviso_wum;
		vector<RectangleShape> colisiones;
		vector<pair<int,int>> tamano;
		vector<pair<int,int>> cords;
		vector<pair<int,int>> cords_pastillas;
		Clock clock;
		//Text scoreText_red,scoreText_wam;
		
		std::string scoreString_red, scoreString_wum;
		int score_red,score_wum;
		Sound sound,inicio;
		SoundBuffer buffer,bufferInicio;

};
