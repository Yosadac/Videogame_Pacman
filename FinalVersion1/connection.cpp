#include "juego.h"
#include "menu.h"
#include <asio.hpp>
#include <iostream>
#include <thread>
#include <fstream>
#include <SFML/Network.hpp>
#include <csignal>
#include <cstring>
#include <unistd.h>
#include <string>

using asio::ip::tcp;
using namespace sf;

// Variable global para indicar si se ha recibido una señal SIGINT
bool receivedSignal = false;

// Función de manejo de señal
void signalHandler(int signum) {
    // Establece la variable global para indicar que se ha recibido la señal SIGINT
    receivedSignal = true;
}


void juego::connection(){

    // Configura el manejador de señales para capturar SIGINT
    std::signal(SIGINT, signalHandler);

    sf::TcpListener listener;
    sf::TcpSocket socket;
    unsigned short port = 3000;
    
    establecerConexion(listener, socket, port);

    std::cout << "CONEXION EXITOSA REALIZADA";
    
    std::thread hilo1([&](){
	enviarMensajes();
	}); 
	
    std::thread hilo2([&](){
	recibirMensajes(socket);
	}); 

	sleep(1);

    	std::ifstream archivo("status.txt");
	std::string status;
	std::getline(archivo, status);
	archivo.close();
	trim(status);
	
	/*while(true){
	if(status == "START"){
    	break;
    	}
    	
	} */
	
	
	
  
}

void juego::trim(std::string& str) {
    str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](int ch) {
        return !std::isspace(ch);
    }));
    str.erase(std::find_if(str.rbegin(), str.rend(), [](int ch) {
        return !std::isspace(ch);
    }).base(), str.end());
}

// Función para establecer la conexión
bool juego::establecerConexion(sf::TcpListener& listener, sf::TcpSocket& socket, unsigned short port) {
    // Enlaza el listener al puerto
    if (listener.listen(port) != sf::Socket::Done) {
        std::cerr << "Error al enlazar el listener al puerto " << port << std::endl;
        return false;
    }

    // Bucle para esperar una conexión
    while (true) {
        std::cout << "Esperando una conexión..." << std::endl;

        // Acepta una conexión entrante
        if (listener.accept(socket) == sf::Socket::Done) {
            std::cout << "¡Conexión establecida!" << std::endl;
            return true;
        }
    }
}

void juego::enviarMensajes(){


// Abrir el archivo "direccion.txt" en modo de lectura
	
	while(true){
	std::ifstream archivo("direccion.txt");
	std::string direcIP;
	std::getline(archivo, direcIP);
	archivo.close();
	trim(direcIP);
	if(direcIP != "HOST"){
    	break;
    	}
	}
	
	std::ifstream archivo("direccion.txt");
	std::string direcIP;
	std::getline(archivo, direcIP);
	archivo.close();
	trim(direcIP);



    if (archivo.is_open()) {
        // Leer el contenido del archivo y guardarlo en la variable "contenido"
       // std::getline(archivo, contenido);

        //archivo.close();
       // std::cout << "Contenido del archivo direccion.txt: " << contenido << std::endl;
    }
	
	sf::TcpSocket socket;
    	sf::IpAddress ip(direcIP); // IP de destino en la red local
	 unsigned short port = 2000;
	 
	  if (socket.connect(ip, port) != sf::Socket::Done) {
        std::cerr << "Error al conectar al servidor" << std::endl;
    	}
    	
    		 // Obtener la dirección IP del dispositivo local
    sf::IpAddress ipAddress = sf::IpAddress::getLocalAddress();

    // Convertir la dirección IP a una cadena de texto
    std::string ipString = ipAddress.toString();

        socket.send(ipString.c_str(), ipString.size() + 1);

    	
    //---------------------------------------
    while(true){
    	std::string message; 
	if (Keyboard::isKeyPressed(Keyboard::Left))
        {
        	message = "Tecla A presionada";
        	socket.send(message.c_str(), message.size() + 1);
        }
        else if (Keyboard::isKeyPressed(Keyboard::Right))
        {
           	message = "Tecla D presionada";
        	socket.send(message.c_str(), message.size() + 1);
        }
        else if (Keyboard::isKeyPressed(Keyboard::Up))
        {
            	message = "Tecla W presionada";
        	socket.send(message.c_str(), message.size() + 1);
        }
        else if (Keyboard::isKeyPressed(Keyboard::Down))
        {
             	message = "Tecla S presionada";
        	socket.send(message.c_str(), message.size() + 1);
        }
    }	
    	
}

// Función para recibir y mostrar mensajes
void juego::recibirMensajes(sf::TcpSocket& socket) {

  std::cout << "Hilo iniciado" << std::endl;

    std::size_t received;
    char buffer[1024];

    // Bucle principal para recibir mensajes hasta que se reciba la señal SIGINT
    while (!receivedSignal) {
        // Recibe datos del cliente y los muestra en pantalla
        if (socket.receive(buffer, sizeof(buffer), received) != sf::Socket::Done) {
            std::cerr << "Error al recibir los datos" << std::endl;
            return;
        }

        

        std::cout << "Mensaje recibido: " << buffer << std::endl;
        
        do{
        std::ofstream archivo("direccion.txt");
                        archivo.is_open();
                        archivo << buffer;
        		archivo.close();
        }while(false);

        static std::string mensaje;      

        if(mensaje.compare(buffer) != 0){
           mensaje = buffer;

          if(mensaje == "Tecla D presionada"){
          std::ofstream archivo("player2.txt", std::ios::trunc);
          archivo << mensaje << std::endl;
          }
          
          if(mensaje == "Tecla W presionada"){
          std::ofstream archivo("player2.txt", std::ios::trunc);
          archivo << mensaje << std::endl;
          }
          
          if(mensaje == "Tecla A presionada"){
          std::ofstream archivo("player2.txt", std::ios::trunc);
          archivo << mensaje << std::endl;
          }
          
          if(mensaje == "Tecla S presionada"){
          std::ofstream archivo("player2.txt", std::ios::trunc);
          archivo << mensaje << std::endl;
          }
        }
        
       std::string contenido;
      std::ifstream archivo("player2.txt");
      contenido = std::string(std::istreambuf_iterator<char>(archivo), std::istreambuf_iterator<char>());
      std::cout << contenido << std::endl;
      

        //std::cout << "HOLAAAAAA" << std::endl;
        //mov_player2();
        

        /*if(buffer == "Tecla D presionada"){
        mov_player2();
        } */

        // Limpia el búfer
        std::memset(buffer, 0, sizeof(buffer));
    }
}
