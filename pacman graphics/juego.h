//#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
//#include <gif_lib.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
//#include "obtenerIP.h"


using namespace std;
using namespace sf;

class juego{

	public:
	
		juego(int resolucion_x,int resolucion_y, string titulo,bool ser);
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
		void colplayer(Sprite &x , Sprite &y, Vector2f &Position,int flag, int &lifes);
		
		void animacion_redit();
		void mov_redit();
		
		void animacion_wumpus();
		void mov_wumpus();

		void animacion_tux();
		void mov_tuxf();

		void animacion_android();
		void mov_android();

		void Texto_time(string texto, int tam_x, int tam_y);

		void Power_up(int &LastScore,int &diferencia,int &clockInd,Clock &clocktime, Time &Tiempo,int &seconds, string &TextTime,bool &powerupplayer, int flag, int score, bool &confirmation);
		
		void winner();

		void animacion_virus(Vector2f &Position);

		Vector2f colision(Sprite x, RectangleShape Obs1, Vector2f spritePosition);
	
	private:
	
		RenderWindow * ventana1;
		int fps,mov,iniciar,mov_red,mov_wum,mov_tux,mov_and;
		
		Font font;
		Texture mapa;
		Sprite smapa;
		
		Texture mpac1,mpac2,mpac3,mpac4,mpac5,mpac6,mpac7,mpac8,mpac9,mpac10,mpac11,mpac12,pastilla;
		Sprite smpac1,smpac2,smpac3,smpac4,smpac5,smpac6,smpac7,smpac8,smpac9,smpac10,smpac11,smpac12;
		
		Texture bola1;
		
		Texture redit1,redit2,redit3,redit4,wumpus1,wumpus2,wumpus3,tux1,tux2,tux3,tux4,android1,android2,android3,android4;
		
		Sprite sredit1,sredit2,sredit3,sredit4,swumpus1,swumpus2,swumpus3,stux1,stux2,stux3,stux4,sandroid1,sandroid2,sandroid3,sandroid4;
		
		Sprite demo_redit1,demo_redit2, demo_redit3, demo_wumpus1, demo_wumpus2, demo_wumpus3,demo_tux1,demo_tux2,demo_tux3,demo_tux4,demo_android1,demo_android2,demo_android3,demo_android4;
		
		Texture virus1,virus2,virus3,virus4;

		Sprite svirus1,svirus2,svirus3,svirus4,demo_virus1,demo_virus2,demo_virus3,demo_virus4;

		vector<Sprite> spastillas;	
		
		Event event;
		Vector2f redPosition,wumPosition,tuxPosition,andPosition;
		int spriteIndex,aviso_red,aviso_wum,aviso_tux,aviso_android;
		vector<RectangleShape> colisiones;
		vector<pair<int,int>> tamano;
		vector<pair<int,int>> cords;
		vector<pair<int,int>> cords_pastillas;
		Clock clock;
		//Text scoreText_red,scoreText_wam;
		
		std::string scoreString_red, scoreString_wum, scoreString_tux,scoreString_and, TextTimeRed, TextTimeWum, TextTimeTux, TextTimeAnd;
		int score_red,score_wum,score_tux,score_and;
		Sound sound,inicio,soundpowerup,soundpowerdown;
		SoundBuffer buffer,bufferInicio,bufferpowerup,bufferpowerdown;
		
		
		Time TiempoRed,TiempoWum,TiempoTux,TiempoAnd;
    	int secondsRed,secondsWum,secondsTux,secondsAnd;
    	Clock clockRed,clockWum,clockTux,clockAnd;

		int diferenciaRed,RedClock,LastScoreRed,LastScoreWum,diferenciaWum, WumClock,redLife,wumLife;
		int diferenciaTux,TuxClock,LastScoreTux,diferenciaAnd,AndClock,LastScoreAnd,tuxLife,andLife;
		bool powerupred,powerupwum,poweruptux,powerupand;
		bool confirmationRed,confirmationWum,confirmationTux,confirmationAnd;

		int players_alive;
		bool red_alive,wum_alive,tux_alive,and_alive,host;
};

