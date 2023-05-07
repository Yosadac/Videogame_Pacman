#pragma once
#include <SFML/Graphics.hpp>
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
	
	private:
	
		RenderWindow * ventana1;
		int fps;
		Texture mapa,pac1,pac2,pac3;
		Sprite smapa,spac1,spac2,spac3;
		Event event;
		Vector2f spritePosition;
		int spriteIndex;
		vector<RectangleShape> colisiones;
		vector<pair<int,int>> tamano;
		vector<pair<int,int>> cords;
		Clock clock;



};
