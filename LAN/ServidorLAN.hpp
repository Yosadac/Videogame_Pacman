#include <iostream>
#include <thread>
#include <vector>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#define port_default 2000
#define max_players 4

class ServidorLAN {
    public:
        unsigned char njs; //Numero de jugadores
        unsigned short status; //Estado del servidor
        sf::TcpListener roomListener; //Escucha de la sala servidor
        sf::TcpSocket sksIn[max_players-1]; //Conexiones de entrada
        sf::TcpSocket sksOut[max_players-1]; //Conexiones de salida
        int IniciarSalaServidor();
        int IniciarPartida();
        int CerrarServidor();
    protected:
        int ConectarJugador(char id);
};