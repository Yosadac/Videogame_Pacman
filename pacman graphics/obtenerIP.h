#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <vector>
#include <iostream>

using namespace std;
using namespace sf;


void obtenerIP(string &ip2){
char ip;
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

/*=======================================
                Parte dos
=======================================*/
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
        

IpAddress ipAddress = sf::IpAddress::getLocalAddress();
std::cout << "IP Address: " << ipAddress.toString() << std::endl;

Text IP(ipAddress.toString(),font, 24);
Text Mensaje("Tu IP es: ", font, 24);
Mensaje.setPosition(100,100);

//IP.setScale(4,4);
IP.setPosition(250,170);
        window.clear();

        window.draw(Mensaje);
        window.draw(IP);
        window.display();
        sf::sleep(sf::milliseconds(10));
}

}