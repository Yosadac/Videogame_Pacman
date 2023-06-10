#include "ServidorLAN.hpp"

int ServidorLAN::IniciarSalaServidor(){
    status = 1;
    njs = 1;
    sf::IpAddress ipServer = sf::IpAddress::getLocalAddress();
    std::cout << "Montando servidor. IP: " << ipServer.toString() << std::endl;
    if(roomListener.listen(port_default) == sf::Socket::Done){
        std::cout << "Servidor escuchando puerto " << port_default << std::endl;
        while (status == 1 && njs < max_players) {
            sf::TcpSocket socket;
            std::cout << "Esperando jugador " << njs << std::endl;
            if (roomListener.accept(socket) == sf::Socket::Done) {
                sf::IpAddress ipJugador = socket.getRemoteAddress();
                std::cout << "Nuevo jugador conectado desde: " << ipJugador.toString() << std::endl;
                if (socket.send(&njs, sizeof(char)) != sf::Socket::Done) std::cout << "ERROR: Al enviar ID al jugador";
                socket.disconnect();
                ConectarJugador(njs);
                njs++;
            }
        }std::cout << "El servidor ya no esta esperando mas conexiones." << std::endl;
    }else std::cout << "ERROR: Al establecer escucha en " << port_default << std::endl;
    return EXIT_SUCCESS;
}

int ServidorLAN::IniciarPartida(){
    std::cout << "[Servidor] Iniciando partida..." << std::endl;
    status = 10;
    return EXIT_SUCCESS;
}

int ServidorLAN::CerrarServidor(){
    std::cout << "Cerrando servidor..." << std::endl;
    return EXIT_SUCCESS;
}

int ServidorLAN::ConectarJugador(char id){
    std::cout << "Conectando con jugador " << id << std::endl;
    sf::TcpListener listener;
    listener.listen(port_default+id);
    if(listener.accept(sksIn[id-1]) == sf::Socket::Done){
        sf::IpAddress ipJugador = sksIn[id-1].getRemoteAddress();
        std::cout << "Conexion de entrada establecida con jugador " << id << std::endl;
        if(sksOut[id-1].connect(ipJugador, port_default) == sf::Socket::Done) std::cout << "Conexion de salida establecida con " << id << std::endl;
        else std::cout << "ERROR: Al establecer la conexion de salida con jugador " << id << std::endl;
    }
    return EXIT_SUCCESS;
}