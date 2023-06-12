#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <vector>
#include <iostream>

using namespace std;
using namespace sf;

int connection=1;

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




        /*=============================================================================*/
        /*Aqui va lo de yosa, recuerda sumar 1 a connection cuando se haga una conexion*/
        /*=============================================================================*/





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
