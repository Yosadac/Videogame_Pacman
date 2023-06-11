#include "juego.h"
#include "menu.h"

int main(int argc, char* args[]) {

	mostrarMenu();
    juego* partida1 = new juego(1000, 1000, "Bite The Bytes");
    return 0;
}
