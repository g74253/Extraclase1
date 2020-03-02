#include <iostream>
#include <unistd.h>
#include <cstdio>
#include <sys/socket.h>
#include <cstdlib>
#include <netinet/in.h>
#include <cstring>
#include "Estructuras/Grafo.h"
#define PORT 8080

/// Main: mantiene el servidor abierto
/// \return (error) posibles fallos
int main() {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char cinicio[1024] = {0};
    char cfin[1024] = {0};
    Grafo grafo;

    grafo.iniciar();
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                   &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );

    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *)&address,
             sizeof(address))<0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    while(true){
        if (listen(server_fd, 3) < 0)
        {
            perror("listen");
            exit(EXIT_FAILURE);
        }
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                                 (socklen_t*)&addrlen))<0)
        {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        valread = read(new_socket , cinicio, 1024);
        valread = read(new_socket , cfin, 1024);
        int inicio = stoi(cinicio);
        int fin = stoi(cfin);
        string path = grafo.ruta(inicio, fin);
        char *cpath[path.size() + 1];
        strcpy(reinterpret_cast<char *>(cpath), path.c_str());
        send(new_socket , cpath , strlen(reinterpret_cast<const char *>(cpath)) , 0 );
        printf("Hello message sent\n");
    }
    return 0;
}
