//
// Created by gretchell on 29/2/20.
//

#ifndef EXTRACLASE1_GRAFO_H
#define EXTRACLASE1_GRAFO_H

#define MAXV 100
#define oo 0x3f3f3f3f
#include <queue>
#include <utility>
#include <vector>
#include <iostream>
#include<string>

using namespace std;

/// Grafo: clase grafo
/// Parte de este codigo se saco de https://github.com/jpieroabarcam/Dijkstra/blob/master/src/Dijkstra.cpp
class Grafo {
    /// estructura de la arista
    struct Edge
    {
        int node;
        int cost;
        Edge(int _node, int _cost) : node(_node), cost(_cost) {}
        Edge() : node(-1), cost(-1) {}
    };

    /// estructura del grafo
    struct Graph
    {
        vector<Edge> ledges[MAXV];
        int node;
        int edge;
    };

    /// estructura de estado (visitado o no)
    struct State
    {
        int node;
        int cost;
        string rut;
        State(int _node, int _cost, string _rut) : node(_node), cost(_cost), rut(std::move(_rut)) {}
        bool operator <(const State &b) const
        {
            return cost > b.cost;
        }
    };

    Graph graph;

public:
    void iniciar();
    string ruta(int start, int finish);

};


#endif //EXTRACLASE1_GRAFO_H
