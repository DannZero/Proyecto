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
    bool visitado[MAX_NODOS];
    int distancia[MAX_NODOS];
    int numVertices;
    int previo[MAX_NODOS];
    vector<Nodo> vertices[MAX_NODOS]; // Esto es el grafo
    priority_queue<Nodo, vector<Nodo>, cmp> cola; //Cola de prioridad para ordenar los nodos

    Dijkstra(vector<Nodo> vertices[MAX_NODOS], int numVertices);
    void relajacion(int actual, int adyacente, int peso);
    void imprimirCamino(int destino);
    void encontrarCaminos(int inicio);

};
