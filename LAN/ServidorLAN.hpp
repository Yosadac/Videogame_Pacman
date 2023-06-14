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
        /**
         * Iniciar la sala de espera del servidor.
         *
         * Habré un listener y queda a la espera de conexiones entrantes.
         * Despues de 4 conexiones dejara de esperar mas, o se puede forzar a que deje de esperar llamando a IniciarPartida.
         * Una vez realizada la conexión, se podrán usar sksIn y sksOut para enviar y recibir mensajes respectivamente.
         * Cada jugador que se conecte tendra asignado un numero correspondiente al orden en que se unio, con el que se podra acceder a sus respectivos sockets.
         * njs guarda el numero de jugadores que hay en la sala (incluyendo al host), por lo que incrementa cada que se une uno nuevo.
         *
         * @param ipServer Dirección IP del servidor al que conectarse.
         * @return Indicador de exito al completar la función.
         */
        int IniciarSalaServidor();
        int IniciarPartida();
        int CerrarServidor();
    protected:
        int ConectarJugador(char id);
};
