#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>

#define PORT 1234

int server_fd, new_socket;

void sigintHandler(int sig_num) {
    // Cierra los sockets
    close(new_socket);
    close(server_fd);
    
    // Elimina los procesos que están escuchando en el puerto 1234
    system("sudo fuser -k 1234/tcp");

    exit(sig_num);
}

int main(int argc, char const *argv[]) {
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};

    // Asigna el handler para la señal SIGINT (Ctrl+C)
    signal(SIGINT, sigintHandler);

    // Crea el socket del servidor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        std::cerr << "Error al crear el socket" << std::endl;
        return -1;
    }

    // Configura la dirección del servidor
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        std::cerr << "Error al configurar el socket" << std::endl;
        return -1;
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Libera el puerto si estaba ocupado
    int yes = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes)) == -1) {
        std::cerr << "Error al liberar el puerto " << PORT << std::endl;
        return -1;
    }

    // Asocia el socket del servidor con la dirección y el puerto
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        std::cerr << "Error al asociar el socket con la dirección y el puerto" << std::endl;
        return -1;
    }

    // Espera por una conexión entrante
    if (listen(server_fd, 1) < 0) {
        std::cerr << "Error al esperar por una conexión entrante" << std::endl;
        return -1;
    }

    // Acepta la conexión entrante
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
        std::cerr << "Error al aceptar la conexión entrante" << std::endl;
        return -1;
    }

    // Recibe datos del cliente y los muestra en pantalla
    int valread;
    while (true) {
        valread = read(new_socket, buffer, 1024);
        std::cout << buffer << std::endl;
        memset(buffer, 0, sizeof(buffer));
    }

    close(new_socket);
    close(server_fd);
    return 0;
}

