#include <iostream>
#include <thread>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#define port_default 2000

class ClienteLAN {
    public:
        int ConectarseASala(sf::IpAddress ipServer);
    protected:
        sf::TcpSocket socketIn;
        sf::TcpSocket socketOut;
        int EsperarConexion();
};