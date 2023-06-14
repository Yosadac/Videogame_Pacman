#include <iostream>
#include <thread>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#define port_default 2000

class ClienteLAN {
    public:
        /**
         * Conectar con la sala servidor
         *
         * Se conecta a la sala creada por el servidor especificador.
         * Es necesario que el servidor haya sido inicializado primero.
         * Una vez realizada la conexión, se podrán usar socketIn y socketOut para enviar y recibir mensajes respectivamente.
         *
         * @param ipServer Dirección IP del servidor al que conectarse.
         * @return Indicador de exito al completar la función.
         */
        int ConectarseASala(sf::IpAddress ipServer);
        sf::TcpSocket socketIn; //Socket de entrada de mensajes con el servidor
        sf::TcpSocket socketOut; //Socket de salida de mensajes con el servidor
    protected:
        int EsperarConexion();
};
