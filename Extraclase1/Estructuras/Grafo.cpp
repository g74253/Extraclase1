//
// Created by gretchell on 29/2/20.
//

#include "Grafo.h"

void Grafo::iniciar() {
    graph.V = 9;
    graph.E = 10;

    graph.G[1].emplace_back(2, 7);
    graph.G[2].emplace_back(1, 7);

    graph.G[2].emplace_back(5, 4);
    graph.G[5].emplace_back(2, 4);

    graph.G[5].emplace_back(8, 2);
    graph.G[8].emplace_back(5, 2);

    graph.G[8].emplace_back(9, 5);
    graph.G[9].emplace_back(8, 5);

    graph.G[9].emplace_back(6, 3);
    graph.G[6].emplace_back(9, 3);

    graph.G[6].emplace_back(7, 7);
    graph.G[7].emplace_back(6, 7);

    graph.G[7].emplace_back(4, 3);
    graph.G[4].emplace_back(7, 3);

    graph.G[4].emplace_back(3, 6);
    graph.G[3].emplace_back(4, 6);

    graph.G[3].emplace_back(1, 9);
    graph.G[1].emplace_back(3, 9);

    graph.G[3].emplace_back(6, 4);
    graph.G[6].emplace_back(3, 4);

    graph.G[6].emplace_back(5, 4);
    graph.G[5].emplace_back(6, 4);

    cout << "Hello, World!" << endl;
}
string Grafo::ruta(int start, int finish) {
    priority_queue<State> pq; // La cola de prioridad.
    vector<int> Dist(graph.V, oo); // La distancia hacia todos los vertices. Inicialmente para cada vertice su valor es infinito.
    vector<bool> mark(graph.V, false); // Este arreglo nos permitira determinar los nodos procesados.

    Dist[start] = 0; // Valor inicial del vertice de partida.
    pq.push(State(start, 0, to_string(start))); // Agregamos el primer elemento, que no es mas que el vertice de partida.
    while(!pq.empty()) // Mientras existan vertices por procesar.
    {
        State st = pq.top(); pq.pop(); // Se desencola el elemento minimo.
        mark[st.node] = true; // Se marca el nodo como visitado.
        if (st.node == finish) {
            return st.rut; // Retornamos el valor del camino, hemos llegado al vertice destino.
        }

        int T = (int)graph.G[st.node].size();
        for(int i = 0; i < T; ++i) // Se recorren las adyacencias de "a".
        {
            // Si no ha sido procesado el vertice "vi" y la distancia hacia "vi" es menor a la distancia
            // en Dist entonces hemos encontrado un camino mas corto a "vi".
            if (!mark[graph.G[st.node][i].node] && ((Dist[st.node] + graph.G[st.node][i].cost) < Dist[graph.G[st.node][i].node]))
            {
                Dist[graph.G[st.node][i].node] = st.cost + graph.G[st.node][i].cost;
                pq.push(State(graph.G[st.node][i].node, st.cost + graph.G[st.node][i].cost, st.rut + " -> " + to_string(graph.G[st.node][i].node)));
            }
        }
    }
    return "-1";
}
