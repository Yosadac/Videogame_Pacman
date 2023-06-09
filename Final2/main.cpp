#include "juego.h"
#include "obtenerIP.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Network.hpp>
#include <fstream>


int mostrarMenu(int vuelta);

int jugar;

int main(int argc, char* args[]) {

	
	jugar=1;
	do{
		jugar=mostrarMenu(jugar);
	    if(jugar==1){
			juego* partida1 = new juego(1000, 1000, "Bite The Bytes");
		}	
	}while(jugar==1);

	return 0;
}


int mostrarMenu(int vuelta) {
//int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Menú del Juego");
    sf::Text texto;
    std::string ipAddress;

    // Cargar la fuente
    sf::Font font;
    if (!font.loadFromFile("PixeloidMono-d94EV.ttf")) {
        std::cerr << "Error al cargar la fuente" << std::endl;
        //return 1;
    }
    
    // Crear el texto del título del menú
    sf::Text titleText("Bite the Bytes", font, 48);
    titleText.setPosition(300.f, 100.f);

    // Crear los textos de las opciones del menú
    sf::Text option1Text("Crear partida", font, 32);
    option1Text.setPosition(350.f, 250.f);
    
    sf::Text option2Text("Unirse a partida", font, 32);
    option2Text.setPosition(350.f, 300.f);

    sf::Text option3Text("Salir", font, 32);
    option3Text.setPosition(350.f, 350.f);

    /*sf::Text option4Text("Salir", font, 32);
    option3Text.setPosition(350.f, 400.f);*/

    int selectedOption = 0;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed){
                vuelta = 0;
                window.close();
            }
            else if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Up)
                {
                    selectedOption = (selectedOption - 1 + 3) % 3;
                }
                else if (event.key.code == sf::Keyboard::Down)
                {
                    selectedOption = (selectedOption + 1) % 3;
                }
                else if (event.key.code == sf::Keyboard::Enter)
                {
                    if (selectedOption == 0)
                    {
                        // Lógica para la opción "Jugar"
                        //system("/home/kali/Desktop/nuevo2/./iniciar_juego.sh");
                        std::cout << "Creando Partida..." << std::endl;
                        hostIP();
                        
                        if(connection>1){
                        std::ofstream archivo("direccion.txt");
                        archivo.is_open();
                        archivo << "HOST";
        		archivo.close();
        		std::cout << "host guardado en direccion.txt" << std::endl;
        		
        		std::ofstream archivo1("player.txt");
                        archivo1.is_open();
                        archivo1 << "player1";
        		archivo1.close();
                            window.close();
                            
                        }
                    }

                    else if (selectedOption == 1)
                    {
                        // Lógica para la opción "Unirse a Partida"
                        std::cout << "Accediendo a una partida..." << std::endl;
                        obtenerIP(ipAddress);
                        std::cout << "Dirección IP: " << ipAddress << std::endl;
                        
                         std::ofstream archivo("direccion.txt");
    			if (archivo.is_open()) {
        		// Escribir la dirección IP en el archivo
        		archivo << ipAddress;
        		archivo.close();
        		std::cout << "Dirección IP guardada correctamente en direccion.txt" << std::endl;
        		window.close();
        		}
        		
        		std::ofstream archivo1("player.txt");
                        archivo1.is_open();
                        archivo1 << "player2";
        		archivo1.close();
                    }

                    else if (selectedOption == 2)
                    {
                        // Lógica para la opción "Salir"
                        std::cout << "Saliendo del juego..." << std::endl;
                        vuelta=0;
                        window.close();
                    }
                }
            }
        }

        window.clear();

        // Dibujar los elementos del menú
        window.draw(titleText);
        window.draw(option1Text);
        window.draw(option2Text);
        window.draw(option3Text);
        //window.draw(option4Text);

        // Resaltar la opción seleccionada
        if (selectedOption == 0)
            option1Text.setFillColor(sf::Color::Red);
        else
            option1Text.setFillColor(sf::Color::White);

        if (selectedOption == 1)
            option2Text.setFillColor(sf::Color::Red);
        else
            option2Text.setFillColor(sf::Color::White);

        if (selectedOption == 2)
            option3Text.setFillColor(sf::Color::Red);
        else
            option3Text.setFillColor(sf::Color::White);
        
        /*if (selectedOption == 3)
            option4Text.setFillColor(sf::Color::Red);
        else
            option4Text.setFillColor(sf::Color::White);*/

        window.display();
    }

    //juego* partida1 = new juego(1000, 1000, "Bite The Bytes");

    return vuelta;
}
