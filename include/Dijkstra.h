#include "Nodo.h"
#include <stack>
#include <queue>

#define MAX_NODOS 1000

using namespace std;

class Dijkstra {
private:
    // Para invertir el orden de la cola de prioridad
    struct cmp { 
        bool operator()(const Nodo& a, const Nodo& b)
        {
            return a.pesoArista > b.pesoArista;
        }
    };
    
public:
    vector<bool> visitado;
    vector<int> distancia;
    int numVertices;
    vector<int> previo;
    vector<vector<Nodo> > vertices; // Esto es el grafo
    priority_queue<Nodo, vector<Nodo>, cmp> cola; //Cola de prioridad para ordenar los nodos

    Dijkstra(vector<vector<Nodo> > vertices);
    void relajacion(int actual, int adyacente, int peso);
    void imprimirCamino(int destino);
    void encontrarCaminos(int inicio);

};
