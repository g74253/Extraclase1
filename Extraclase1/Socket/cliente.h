//
// Created by gretchell on 1/3/20.
//

#ifndef EXTRACLASE1_CLIENTE_H
#define EXTRACLASE1_CLIENTE_H

#include <iostream>
#include <cstdio>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#define PORT 8080

using namespace std;

/// Cliente: socket del cliente
/// Parte de este codigo se saco de https://www.geeksforgeeks.org/socket-programming-cc/
class cliente {

public:
    string enviar(string inicio, string fin);

};


#endif //EXTRACLASE1_CLIENTE_H
