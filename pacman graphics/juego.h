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
		void crear_colisiones();
		void llenar_cords();
		void procesar_eventos();
		void detectar_colision();
		void cargar_texturas();
		void animacion_pacman();
		void animacion_pacman_muerte();
		void animacion_red();
		void animacion_blue();
		void animacion_pink();
		void animacion_orange();
		void Puntos();
		void mov_player1();
		void mov_player2();
		void mov_player3();
		void mov_player4();
		void mostrar_score();
		//void aparicion_pastillas();
		void crear_pastillas();
		void posicion_puntos();
		void colision_players();
		void colision_mapa();
		void crear_colision_jugador();
	private:
	
		RenderWindow * ventana1;
		int fps,mov,score,iniciar,mov_pac;
		Texture mapa,red,muerte;
		Sprite smapa,sred,smuerte;
		
		
		Texture pacar1,pacar2,pacab1,pacab2,pacd1,pacd2,paci1,paci2,pac3;
		Sprite spacar1,spacar2,spacab1,spacab2,spacd1,spacd2,spaci1,spaci2,spac3; 
		
		Texture redar1,redar2,redab1,redab2,redi1,redi2,redd1,redd2;
		Sprite sredar1,sredar2,sredab1,sredab2,sredi1,sredi2,sredd1,sredd2;
		
		Texture bluear1,bluear2,blueab1,blueab2,bluei1,bluei2,blued1,blued2;
		Sprite sbluear1,sbluear2,sblueab1,sblueab2,sbluei1,sbluei2,sblued1,sblued2;
		
		Texture pinkar1,pinkar2,pinkab1,pinkab2,pinki1,pinki2,pinkd1,pinkd2;
		Sprite spinkar1,spinkar2,spinkab1,spinkab2,spinki1,spinki2,spinkd1,spinkd2;
		
		Texture orangear1,orangear2,orangeab1,orangeab2,orangei1,orangei2,oranged1,oranged2;
		Sprite sorangear1,sorangear2,sorangeab1,sorangeab2,sorangei1,sorangei2,soranged1,soranged2;	
		
		Texture mpac1,mpac2,mpac3,mpac4,mpac5,mpac6,mpac7,mpac8,mpac9,mpac10,mpac11,mpac12,pastilla;
		Sprite smpac1,smpac2,smpac3,smpac4,smpac5,smpac6,smpac7,smpac8,smpac9,smpac10,smpac11,smpac12;
		
		vector<Sprite> spastillas;	
		
		Event event;
		Vector2f spritePosition,redPosition,bluePosition,pinkPosition,orangePosition;
		int spriteIndex,spriteIndexMuerte,aviso;
		vector<RectangleShape> colisiones;
		vector<pair<int,int>> tamano;
		vector<pair<int,int>> cords;
		vector<pair<int,int>> cords_pastillas;
		Clock clock;
		Text scoreText;
		
		std::string scoreString;
		Sound sound,inicio,muerte_pac;
		SoundBuffer buffer,bufferInicio,bufferMuerte;
		
		FloatRect cpacar, cpacab, cpacd, cpaci;
        	//FloatRect mapColisionBounds = colisiones.getGlobalBounds();


};
