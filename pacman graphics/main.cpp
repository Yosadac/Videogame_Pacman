#include "juego.h"
#include "menu.h"

//#include <SFML/Graphics.hpp>

//using namespace sf;

/*int main (int argc,char * args[]){

		juego * partida1;
		mostrarMenu();
		partida1 = new juego(1000,1000,"Intento");
	return 0;
}*/

int main(int argc, char* args[]) {
    mostrarMenu();
    juego* partida1 = new juego(1000, 1000, "Bite The Bytes");
    return 0;
}
