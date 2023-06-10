//g++ ClienteLAN.cpp ServidorLAN.cpp main.cpp -o Pacman.exe -lsfml-network -lsfml-system

#include "ServidorLAN.hpp"
#include "ClienteLAN.hpp"
#include <iostream>
#include <chrono>
#include <thread>

int main()
{
    char op;
    std::cout << "Introduce una opcion S/C: ";
    std::cin >> op;
    if(op == 's'){
        ServidorLAN servidor;
        servidor.IniciarSalaServidor();
    }else{
        ClienteLAN cliente;
        sf::IpAddress ipServer;
        std::string ipString;
        std::cout << "Ingrese la dirección IP a la que desea conectarse: ";
        std::cin >> ipString;
        ipServer = ipString;
        cliente.ConectarseASala(ipServer);
    }
    while(true){
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    return EXIT_SUCCESS;
}
