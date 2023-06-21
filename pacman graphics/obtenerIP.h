#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <vector>
#include <iostream>
#include <thread>
#include <fstream>

using namespace std;
using namespace sf;

vector <string> ipClient;


std::vector<sf::TcpSocket*> clients;
sf::TcpSocket socketClient;

int connection=1;
bool server=false;

std::string messageC;
std::string messageH;
const unsigned short PORT = 2000;

bool host;

bool partida_iniciada=false;


/*=======================================
                Parte cero
=======================================*/


/*Creacion del server para el creador de la sala*/


void receiveMessagesHost(sf::TcpSocket* client) {
    while (true) {
        sf::Packet packet;
        if (client->receive(packet) == sf::Socket::Done) {
            packet >> messageH;
            std::cout << "Cliente " << client->getRemoteAddress() << " recibió: " << messageH << std::endl;
            //crear un nuevo archivo txt y abrirlo y escribir
            std::ofstream player("player.txt");
            if (player.is_open()) {
                player << messageH;
                player.close();
            } else {
                std::cout << "No se pudo abrir el archivo txt." << std::endl;
            }
        } else {
            std::cout << "No se pudo abrir el archivo." << std::endl;
        }
    }
}


void serverThread() {
    sf::TcpListener listener;

    if (listener.listen(PORT) != sf::Socket::Done) {
        std::cout << "Error al iniciar el servidor." << std::endl;
        return;
    }

    std::cout << "Servidor iniciado. Esperando clientes..." << std::endl;

    for (int i = 0; i <1; i++) {

        sf::TcpSocket* client = new sf::TcpSocket();
        if (listener.accept(*client) == sf::Socket::Done) {
            //std::cout << "Cliente " << i + 1 << " conectado." << std::endl;
            connection=connection+1;
            ipClient.push_back(client->getRemoteAddress().toString());
            clients.push_back(client);
            std::thread clientThread(receiveMessagesHost, client);
            clientThread.detach();
        } else {
            std::cout << "Error al conectar con el cliente " << i + 1 << std::endl;
            delete client;
        }
    }

    std::string message,messageAux="";;
    while (true) {
        /*std::cout << "Mensaje (Host): ";
        std::getline(std::cin, message);*/
 
	    if (Keyboard::isKeyPressed(Keyboard::Left))
        {
        	message = "Tecla A presionada";
        }
        else if (Keyboard::isKeyPressed(Keyboard::Right))
        {
           	message = "Tecla D presionada";
        }
        else if (Keyboard::isKeyPressed(Keyboard::Up))
        {
            	message = "Tecla W presionada";
        }
        else if (Keyboard::isKeyPressed(Keyboard::Down))
        {
             	message = "Tecla S presionada";
        }
        else if (Keyboard::isKeyPressed(Keyboard::Enter))
        {
             	message = "Enter";
        }

        if(messageAux!=message){
            messageAux=message;
            for (sf::TcpSocket* client : clients) {
                sf::Packet packet;
                packet << message;
                cout<<message<<endl;
                if (client->send(packet) != sf::Socket::Done) {
                    std::cout << "Error al enviar mensaje a un cliente." << std::endl;
                }
            }
        }
    }
     listener.close();
}

void iniciar_server(){
    std::thread server(serverThread);
    server.detach();
}


/*Funciones para el cliente o los siguientes jugadores*/

void enviar_mensaje(TcpSocket &socket){
    std::string message,messageAux="";
    while (true) {
        /*std::cout << "Mensaje: ";
        std::getline(std::cin, message);

        sf::Packet packet;
        packet << message;

        if (socket.send(packet) != sf::Socket::Done) {
            std::cout << "Error al enviar mensaje al servidor." << std::endl;
        }*/

        
	    if (Keyboard::isKeyPressed(Keyboard::Left))
        {
        	message = "Tecla A presionada";
        }
        else if (Keyboard::isKeyPressed(Keyboard::Right))
        {
           	message = "Tecla D presionada";
        }
        else if (Keyboard::isKeyPressed(Keyboard::Up))
        {
            message = "Tecla W presionada";
        }
        else if (Keyboard::isKeyPressed(Keyboard::Down))
        {
            message = "Tecla S presionada";
        }

        sf::Packet packet;
        packet << message;
        if(messageAux!=message){
            messageAux=message;
            if (socket.send(packet) != sf::Socket::Done) {
                std::cout << "Error al enviar mensaje al servidor." << std::endl;
            }
        }
    }
}


void receiveMessages(sf::TcpSocket& socket) {

    while (true) {
        sf::Packet packet;
        if (socket.receive(packet) == sf::Socket::Done) {
            packet >> messageC;
            cout<<messageC<<endl;
            std::ofstream player("Host.txt");
            if (player.is_open()) {
                player << messageC;
                player.close();
            } else {
                std::cout << "No se pudo abrir el archivo txt." << std::endl;
            }
            if(messageC=="Enter"){
                partida_iniciada=true;
            }  
        } else {
            std::cout << "No se pudo abrir el archivo." << std::endl;
        }
    }
}



void cliente(string SERVER_IP) {
    //sf::TcpSocket socketClient;
    if (socketClient.connect(SERVER_IP, PORT) != sf::Socket::Done) {
        std::cout << "Error al conectar al servidor." << std::endl;
        return ;
    }

    std::cout << "Conexión exitosa al servidor." << std::endl;

    std::thread receiveThread(receiveMessages, std::ref(socketClient));
    receiveThread.detach();

    /*std::thread sendThread(enviar_mensaje, std::ref(socket));
    sendThread.detach();*/

    //enviar_mensaje(socket);
    
}

/*=======================================
                Parte uno
=======================================*/


/*Funcion para obtener la ip del equipo, esto aparecera al host*/

void obtenerIP(string &ip2){
    char ip;

    ip2="";

    string ipAdres;
    Font font;
    font.loadFromFile("consolas.TTF");
    RenderWindow window(VideoMode(600,300),"Ingresar IP");

    sf::sleep(sf::milliseconds(100));
    while(window.isOpen()){

        Event event;



        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
        
            if (Keyboard::isKeyPressed(Keyboard::Num1))
            {
                ip='1';
                ip2=ip2+ip;
                ipAdres = /*"Coloque la ip "*/ipAdres + ip;
            }
            else if (Keyboard::isKeyPressed(Keyboard::Num2))
            {
                ip='2';
                ip2=ip2+ip;
                ipAdres = /*"Coloque la ip "*/ipAdres + ip;
            }
            else if (Keyboard::isKeyPressed(Keyboard::Num3))
            {
                ip='3';
                ip2=ip2+ip;
                ipAdres = /*"Coloque la ip "*/ipAdres + ip;
            }
            else if (Keyboard::isKeyPressed(Keyboard::Num4))
            {
                ip='4';
                ip2=ip2+ip;
                ipAdres = /*"Coloque la ip "*/ipAdres + ip;
            }   
            else if (Keyboard::isKeyPressed(Keyboard::Num5))
            {
                ip='5';
                ip2=ip2+ip;
                ipAdres = /*"Coloque la ip "*/ipAdres + ip;
            }
            else if (Keyboard::isKeyPressed(Keyboard::Num6))
            {
                ip='6';
                ip2=ip2+ip;
                ipAdres = /*"Coloque la ip "*/ipAdres + ip;
            }
            else if (Keyboard::isKeyPressed(Keyboard::Num7))
            {
                ip='7';
                ip2=ip2+ip;
                ipAdres = /*"Coloque la ip "*/ipAdres + ip;
            }
            else if (Keyboard::isKeyPressed(Keyboard::Num8))
            {
                ip='8';
                ip2=ip2+ip;
                ipAdres = /*"Coloque la ip "*/ipAdres + ip;
            }
            else if (Keyboard::isKeyPressed(Keyboard::Num9))
            {
                ip='9';
                ip2=ip2+ip;
                ipAdres = /*"Coloque la ip "*/ipAdres + ip;
            }
            else if (Keyboard::isKeyPressed(Keyboard::Num0))
            {
                ip='0';
                ip2=ip2+ip;
                ipAdres = /*"Coloque la ip "*/ipAdres + ip;
            }
            else if (Keyboard::isKeyPressed(Keyboard::Period))
            {
                ip='.';
                ip2=ip2+ip;
                ipAdres = /*"Coloque la ip "*/ipAdres + ip;
            }
            else if (Keyboard::isKeyPressed(Keyboard::Enter))
            {
                window.close();
            }
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace)) {
            	if (!ip2.empty()) {
            		ip2.pop_back();
        	        ipAdres.pop_back(); // Opcional: también eliminar el último carácter de ipAdres
        		}
            }


    	    Text IP(ipAdres,font, 24);
	        Text Mensaje("Ingrese la IP del Host:", font, 24);
	        Mensaje.setPosition(100,100);
	
    	    //IP.setScale(4,4);
	        IP.setPosition(250,170);
	        window.clear();
    	    window.draw(Mensaje);
	        window.draw(IP);
	        window.display();
    	    sf::sleep(sf::milliseconds(80));
	    }

    }
}

/*=======================================
                Parte dos
=======================================*/

/*Funcion para obtener la ip del equipo, esto aparecera al host*/
void hostIP(){
    char ip;
    string ipAdres;
    Font font;
    font.loadFromFile("consolas.TTF");
    RenderWindow window(VideoMode(600,300),"Ingresar IP");
    while(window.isOpen()){
        Event event;

        sf::sleep(sf::milliseconds(100));


        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
        }
        if(connection>1){
            if (Keyboard::isKeyPressed(Keyboard::Enter))
                {
                    window.close();
                }
        }



        //crear_juego();
        /*=============================================================================*/
        /*Aqui va lo de yosa, recuerda sumar 1 a connection cuando se haga una conexion*/
        /*=============================================================================*/

        /*Inicia el host*/
        if(server==false){
        	iniciar_server();
        	server=true;
        }



        IpAddress ipAddress = sf::IpAddress::getLocalAddress();

        Text IP(ipAddress.toString(),font, 24);
        Text Mensaje("Tu IP es: ", font, 24);
        Mensaje.setPosition(100,100);

        //IP.setScale(4,4);
        IP.setPosition(250,170);

        Text Mensaje_salida("Presiona ENTER para iniciar...", font, 24);
        Mensaje_salida.setPosition(100,200);

        Text Mensaje_espera("Esperando jugadores...", font, 24);
        Mensaje_espera.setPosition(100,200);
        window.clear();

        if(connection>1){
            window.draw(Mensaje_salida);
        }
        else{
            window.draw(Mensaje_espera);
        }
        window.draw(Mensaje);
        window.draw(IP);
        window.display();
        sf::sleep(sf::milliseconds(10));

    }



}
