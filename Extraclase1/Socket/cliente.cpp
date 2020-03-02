//
// Created by gretchell on 1/3/20.
//

#include "cliente.h"
/// Cliente: Se encarga de enviar el inicio y el final de la ruta deseada.
/// \param inicio: nodo de inicio
/// \param fin: nodo final
/// \return ruta mas corta entre ellos.
string cliente::enviar(string inicio, string fin) {
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char *cinicio[inicio.size() + 1];
    strcpy(reinterpret_cast<char *>(cinicio), inicio.c_str());
    char *cfin[fin.size() + 1];
    strcpy(reinterpret_cast<char *>(cfin), fin.c_str());
    char buffer[1024] = {0};
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        return "Socket creation error";
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)
    {
        return "Invalid address/ Address not supported";
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        return "Connection Failed";
    }
    send(sock , cinicio , strlen(reinterpret_cast<const char *>(cinicio)) , 0 );
    sleep(static_cast<unsigned int>(0.5));
    send(sock , cfin , strlen(reinterpret_cast<const char *>(cfin)) , 0 );
    valread = read( sock , buffer, 1024);
    printf("%s\n", buffer );
    string path (buffer);
    return path;
}
