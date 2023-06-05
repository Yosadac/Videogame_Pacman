#include "juego.h"
#include <iostream>
#include <SFML/Network.hpp>
#include <asio.hpp>

void juego::connect() {
    sf::TcpSocket socket;
    sf::IpAddress ip("192.168.0.202"); // IP de destino en la red local
    unsigned short port = 1234; // Puerto de destino

    // Conectarse al servidor
   /* if (socket.connect(ip, port) != sf::Socket::Done) {
        std::cerr << "Error al conectar al servidor" << std::endl;
        //return 1;
    } */

    std::string message = "Hola, soy un mensaje desde SFML";

    // Enviar el mensaje al servidor
    if (socket.send(message.c_str(), message.size() + 1) != sf::Socket::Done) {
        std::cerr << "Error al enviar el mensaje" << std::endl;
        //return 1;
    }

    std::cout << "Mensaje enviado correctamente" << std::endl;

    // Cerrar la conexión
    //socket.disconnect();


   /* asio::io_context io_context;
    asio::ip::tcp::socket socket(io_context);
    socket.connect(asio::ip::tcp::endpoint(asio::ip::make_address("192.168.0.202"), 1234));

    std::string message = "Tecla Izquierda presionada";

    // Envío asíncrono del paquete sin handler ni mensaje de confirmación
    asio::async_write(socket, asio::buffer(message.data(), message.size()),
        [](const std::error_code&, std::size_t) {
            // No se realiza ninguna acción en el callback
        });

    // Llamada al método run() para iniciar el bucle de eventos de asio
    io_context.run();
    */
}
