#include "juego.h"
#include <asio.hpp>
#include <iostream>
#include <thread>

#include <SFML/Network.hpp>
#include <csignal>
#include <cstring>
#include <unistd.h>

#define PORT 2000


using asio::ip::tcp;

using namespace sf;

// Variable global para indicar si se ha recibido una señal SIGINT
bool receivedSignal = false;

// Función de manejo de señal
void signalHandler(int signum) {
    // Establece la variable global para indicar que se ha recibido la señal SIGINT
    receivedSignal = true;
}


//std::string message;

juego::juego(int resolucion_x,int resolucion_y, string titulo){

        // Configura el manejador de señales para capturar SIGINT
    std::signal(SIGINT, signalHandler);

    sf::TcpListener listener;
    sf::TcpSocket socket;
    unsigned short port = PORT;
    
    establecerConexion(listener, socket, port);

  /*  if (!establecerConexion(listener, socket, port)) {
        std::cerr << "Error al establecer la conexión" << std::endl;
     } */


  std::cout << "Iniciando hilo..." << std::endl;

  // recibirMensajes(socket);
   
   // Crear el primer proceso
    pid_t pid1 = fork();
    
    if (pid1 == 0) {
        // Estamos en el proceso hijo 1
        recibirMensajes(socket);
    }
    
  
    /*
    // Crear el segundo proceso
    pid_t pid2 = fork();
    
    if (pid2 == 0) {
        // Estamos en el proceso hijo 2
        gameLoop();
    } */
    

    /*
       std::thread hilo([&]() {
        recibirMensajes(socket);
    });   
    
    */
    
     std::cout << "segundo proceso" << std::endl;
    
   
    
    // std::thread hilo2(gameLoop);

   // recibirMensajes(socket);

       // connection();

	fps=60;
	mov=0;
	ventana1 = new RenderWindow(VideoMode(resolucion_x,resolucion_y),titulo);
	ventana1->setFramerateLimit(fps);
	
    	cargar_texturas();
	llenar_cords();
	crear_colisiones();
	
	/*
	// Crear el segundo proceso
    pid_t pid2 = fork();
    
    if (pid2 == 0) {
        // Estamos en el proceso hijo 2
        gameLoop();
	}
	
	*/
	
	/*
	   std::thread hilo2([&]() {
        gameLoop();
    }); 
    */
	
	 gameLoop();		
	//gameLoop(socket);
      

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

        /*if(buffer == "Tecla D presionada"){
        mov_player2();
        } */

        // Limpia el búfer
        std::memset(buffer, 0, sizeof(buffer));
    }
}


void juego::connection(){
 // Configura el manejador de señales para capturar SIGINT
    std::signal(SIGINT, signalHandler);

    sf::TcpListener listener;
    sf::TcpSocket socket;
    sf::IpAddress ip("127.0.0.1"); // Dirección IP local
    unsigned short port = PORT;

    // Enlaza el listener al puerto
    if (listener.listen(port) != sf::Socket::Done) {
        std::cerr << "Error al enlazar el listener al puerto " << port << std::endl;
    }

    bool connection = true;
    
    // Bucle para esperar una conexión
            while (connection==true) {
            std::cout << "Esperando una conexión..." << std::endl;

              // Acepta una conexión entrante
              if (listener.accept(socket) == sf::Socket::Done) {
              std::cout << "¡Conexión establecida!" << std::endl;
              connection = false;
              break; // Sale del bucle de espera de conexión
              }
            }
}





void juego::dibujar_pantalla()
{    	
      	ventana1->clear();
	
	ventana1->draw(smapa);
    
	
	for (auto& colision : colisiones )
        {
            ventana1->draw(colision);
        }
        animacion_red();
        animacion_blue();
        animacion_pink();
        animacion_orange();
        animacion_pacman();
        Puntos();
        //animacion_pacman_muerte();
        //ventana1->draw(sred);
        mostrar_score();
        aparicion_pastillas();
	ventana1->display();
	


}





void juego::gameLoop(){
 
 
  /* std::size_t received;
    char buffer[1024];

   	
		// Recibe datos del cliente y los muestra en pantalla
        if (socket.receive(buffer, sizeof(buffer), received) != sf::Socket::Done) {
            std::cerr << "Error al recibir los datos" << std::endl;
            return;
        }

        std::cout << "Mensaje recibido: " << buffer << std::endl;

        // Limpia el búfer
        std::memset(buffer, 0, sizeof(buffer));
 
 */


	while(ventana1->isOpen()){
		
	
            
	
	
		
		
		procesar_eventos();
		dibujar_pantalla();	
		
	}
	//socket.disconnect();

}





void juego::llenar_cords(){

	tamano={{660,16},{15,730},{660,11},{11,730},{131,252},{133,252},{38,110},{60,36},{60,36},
		{108, 60},{83, 60},{83, 36},{108, 58},{83, 60},{83, 36},{34, 182},{34, 180},{180, 36},
		{34, 110},{34, 110},{180, 34},{108, 35},{83, 35},{108, 35},{83, 35},{180, 34},{228, 35},
		{228, 35},{70, 34},{70, 34},{34, 70},{34, 70},{35, 107},{35, 107},{34, 107},{34, 107}};
	
	cords={{105,130},{105,130},{105,850},{753,130},{635,348},{105,348},{417,130},{105,708},{706,708},
	       {490, 179},{635, 180},{635, 275},{275, 180},{155, 180},{155, 275},{563, 275},{275, 275},{347, 275},
	       {563,490},{275,490},{347, 565},{490, 637},{635, 637},{275, 637},{155, 637},{347, 709},{490, 780},
	       {155, 780},{490, 349},{312, 349},{420, 312},{420, 600},{635, 637},{203, 637},{563,708},{275,708}};


}






void juego::crear_colisiones(){
	
	int col;
	// Crear 30 colisiones aleatorias
	for (int i = 0; i <= 8; i++)
    	{
        	// Crear un rectángulo con una posición y tamaño aleatorios
        	RectangleShape colision(Vector2f(tamano[i].first,tamano[i].second));
        	colision.setPosition(cords[i].first, cords[i].second);
        	colision.setFillColor(Color::Transparent);
        	colision.setOutlineThickness(1);
    		colision.setOutlineColor(Color::Red);

        	// Agregar el rectángulo al vector de colisiones
        	colisiones.push_back(colision);
        	
        	col=i;
    	}
    	
    	for(col;col<=36;col++){
    		RectangleShape obs(Vector2f(tamano[col].first,tamano[col].second));
        	obs.setPosition(cords[col].first, cords[col].second);
        	obs.setFillColor(Color::Transparent);
        	obs.setOutlineThickness(1);
    		obs.setOutlineColor(Color::Green);

        	// Agregar el rectángulo al vector de colisiones
        	colisiones.push_back(obs);
    	
    	}	
}







void juego::procesar_eventos(){

	// Crea un socket TCP con asio
    	//asio::io_context io_context;
    	//tcp::socket socket(io_context);
    	//socket.connect(tcp::endpoint(asio::ip::make_address("192.168.0.202"), 1234));

	//sf::Event event;
	while (ventana1->pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                ventana1->close();
            }
            /*else if (event.type == sf::Event::KeyPressed)
            {
                // Enviar un mensaje al servidor cuando se presiona una tecla
                std::string message;
                if (event.key.code == sf::Keyboard::Left)
                {
                    //message = "Tecla Izquierda presionada";
                }
                else if (event.key.code == sf::Keyboard::Right)
                {
                    message = "Tecla Derecha presionada";
                }
                else if (event.key.code == sf::Keyboard::Up)
                {
                    message = "Tecla Arriba presionada";
                }
                else if (event.key.code == sf::Keyboard::Down)
                {
                    message = "Tecla Abajo presionada";
                }
                else if (event.key.code == sf::Keyboard::Space)
                {
                    message = "Tecla Espacio presionada";
                }  
            } */ 
        
        mov_player1();
        //mov_player2();
        mov_player3();
        mov_player4();
        }
        /*/ Mover personaje con las teclas de flecha
        if (Keyboard::isKeyPressed(Keyboard::Left))
        {
            //spacman.move(-1, 0);
            spritePosition.x -= 1;
            mov=3;
        }
        else if (Keyboard::isKeyPressed(Keyboard::Right))
        {
            //spacman.move(1, 0);
            spritePosition.x += 1;
            mov=4;
        }
        else if (Keyboard::isKeyPressed(Keyboard::Up))
        {
            //spacman.move(0, -1);
            spritePosition.y -= 1;
            mov=1;
        }
        else if (Keyboard::isKeyPressed(Keyboard::Down))
        {
            //spacman.move(0, 1);
            spritePosition.y += 1;
            mov=2;
        }*/
        
        mov_player1();
        mov_player2();
        mov_player3();
        mov_player4();
}
