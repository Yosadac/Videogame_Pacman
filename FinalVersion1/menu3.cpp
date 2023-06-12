//#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "juego.h"

void mostrarMenu(int &vuelta) {
//int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Menú del Juego");

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
    sf::Text option1Text("Unirse a partida", font, 32);
    option1Text.setPosition(350.f, 250.f);
    
    sf::Text option2Text("Crear partida", font, 32);
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
            if (event.type == sf::Event::Closed)
                window.close();
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
                        // Lógica para la opción "Crear Partida"
                        //system("/home/kali/Desktop/nuevo2/./iniciar_juego.sh");
                        std::cout << "Creando Partida" << std::endl;
                        window.close();
                    }
                    else if (selectedOption == 1)
                    {
                        // Lógica para la opción "Unirse a Partida"
                        std::cout << "Accediendo a una partida..." << std::endl;
                        // Simplemente mostrar el placeholder de la dirección IP
                        std::cout << "Dirección IP: " << ipAddress << std::endl;
                        // Lógica para la opción "Unirse a Partida"
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

    //return 0;
}
