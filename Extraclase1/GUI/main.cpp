#include <iostream>
#include "../Estructuras/Grafo.h"

using namespace std;

int main() {
    Grafo grafo;
    grafo.iniciar();
    string srt = grafo.ruta(8, 3);

    cout << srt << endl;

    return 0;
}
