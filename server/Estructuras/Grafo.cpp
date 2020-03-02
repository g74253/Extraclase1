//
// Created by gretchell on 29/2/20.
//

#include "Grafo.h"

/// Iniciar: inicializa al grafo
void Grafo::iniciar() {
    graph.node = 10;
    graph.edge = 10;

    graph.ledges[1].emplace_back(2, 7);
    graph.ledges[2].emplace_back(1, 7);

    graph.ledges[2].emplace_back(5, 4);
    graph.ledges[5].emplace_back(2, 4);

    graph.ledges[5].emplace_back(8, 2);
    graph.ledges[8].emplace_back(5, 2);

    graph.ledges[8].emplace_back(9, 5);
    graph.ledges[9].emplace_back(8, 5);

    graph.ledges[9].emplace_back(6, 3);
    graph.ledges[6].emplace_back(9, 3);

    graph.ledges[6].emplace_back(7, 7);
    graph.ledges[7].emplace_back(6, 7);

    graph.ledges[7].emplace_back(4, 3);
    graph.ledges[4].emplace_back(7, 3);

    graph.ledges[4].emplace_back(3, 6);
    graph.ledges[3].emplace_back(4, 6);

    graph.ledges[3].emplace_back(1, 9);
    graph.ledges[1].emplace_back(3, 9);

    graph.ledges[3].emplace_back(6, 4);
    graph.ledges[6].emplace_back(3, 4);

    graph.ledges[6].emplace_back(5, 4);
    graph.ledges[5].emplace_back(6, 4);
}

/// ruta: se encarga de buscar y retornar la ruta mas baja del grafo.
/// Parte de este codigo se saco de https://github.com/jpieroabarcam/Dijkstra/blob/master/src/Dijkstra.cpp
/// \param start: (int)nodo inicial
/// \param finish: (int)nodo final
/// \return (str)ruta mas corta entre nodos o -1 si no existe ruta.
string Grafo::ruta(int start, int finish) {
    priority_queue<State> pq;
    vector<int> Dist(graph.node, oo);
    vector<bool> mark(graph.node, false);

    Dist[start] = 0;
    pq.push(State(start, 0, to_string(start)));
    while(!pq.empty())
    {
        State st = pq.top(); pq.pop();
        mark[st.node] = true;
        if (st.node == finish) {
            return st.rut;
        }

        int T = (int)graph.ledges[st.node].size();
        for(int i = 0; i < T; ++i)
        {
            if (!mark[graph.ledges[st.node][i].node] && ((Dist[st.node] + graph.ledges[st.node][i].cost) < Dist[graph.ledges[st.node][i].node]))
            {
                Dist[graph.ledges[st.node][i].node] = st.cost + graph.ledges[st.node][i].cost;
                pq.push(State(graph.ledges[st.node][i].node, st.cost + graph.ledges[st.node][i].cost, st.rut + " -> " + to_string(graph.ledges[st.node][i].node)));
            }
        }
    }
    return "-1";
}
