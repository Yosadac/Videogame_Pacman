#include "ClienteLAN.hpp"

int ClienteLAN::EsperarConexion(){
    std::cout << "[IN] Esperando conexion del servidor..." << std::endl;
    sf::TcpListener listener;
    listener.listen(port_default);
    if (listener.accept(socketIn) == sf::Socket::Done){
        std::cout << "[IN] Conexion entrante extablecida exitosamente en puerto " << port_default << std::endl;
    }
    return EXIT_SUCCESS;
}

int ClienteLAN::ConectarseASala(sf::IpAddress ipServer){
    sf::TcpSocket socketSala;
    std::size_t nDatos;
    char id;
    std::cout << "Intentando conectar a servidor " << ipServer << " (" << port_default << ")..." << std::endl;
    if(socketSala.connect(ipServer, port_default) == sf::Socket::Done){
        if(socketSala.receive(&id, sizeof(char), nDatos) == sf::Socket::Done){
            std::cout << "ID: " << id << std::endl;
            socketSala.disconnect();
            std::thread esperarConexion(&ClienteLAN::EsperarConexion, this);
            std::cout << "[OUT] Intentando conectar a servidor " << ipServer << " (" << port_default+id << ")..." << std::endl;
            if(socketOut.connect(ipServer, port_default+id) == sf::Socket::Done) std::cout << "[OUT] Conexion saliente establecida exitosamente en puerto " << (port_default+id) << std::endl;
            else std::cout << "ERROR: Al establecer la conexion de salida." << std::endl;
            esperarConexion.join();
        }else std::cout << "ERROR: Al recibir el ID." << std::endl;
    }else std::cout << "ERROR: Al conectarse al servidor " << ipServer << std::endl;
    return id;
}