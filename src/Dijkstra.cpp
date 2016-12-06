#include "Dijkstra.h"

Dijkstra::Dijkstra(vector<Nodo> verticesAdyacentes[MAX_NODOS], int numVertices)
    : numVertices(numVertices)
{
    vector<Nodo> vertices(*verticesAdyacentes);
    for (int i = 0; i <= numVertices; ++i) {
        distancia[i] = __INT_MAX__; //inicializamos todas las distancias con valor infinito
        visitado[i] = false; //inicializamos todos los vértices como no visitados
        previo[i] = -1; //inicializamos el previo del vertice i con -1
    }
}

void Dijkstra::relajacion(int actual, int adyacente, int peso)
{
    //Si la distancia del origen al vertice actual + peso de su arista es menor a la distancia del origen al vertice adyacente
    if (distancia[actual] + peso < distancia[adyacente]) {
        distancia[adyacente] = distancia[actual] + peso; //se actualiza la distancia
        previo[adyacente] = actual;
        cola.push(Nodo(adyacente, distancia[adyacente])); //agregamos adyacente a la cola de prioridad
    }
}

void Dijkstra::imprimirCamino(int destino)
{
    if (previo[destino] != -1) //si aun existe un vertice previo
        imprimirCamino(previo[destino]); // recursivo
    cout << "\t" << destino << endl;
}

void Dijkstra::encontrarCaminos(int inicio)
{
    cout << "Procesando..." << endl;

    cola.push(Nodo(inicio, 0)); // El vertice inicial tiene peso 0
    distancia[inicio] = 0;
    int actual, ady, peso;
    while (cola.size() != 0) {
        actual = cola.top().verticeAdyacente; // Nodo con menor peso
        cola.pop();
        if (visitado[actual]) {
            continue; // Ya fue visitado antes
        }
        visitado[actual] = true;
        for (int i = 0; i < vertices[actual].size(); ++i) {
            ady = vertices[actual][i].verticeAdyacente; // Se obtiene el adyacente y su peso
            peso = vertices[actual][i].pesoArista;
            if (!visitado[ady]) {
                // SI no fue visitado se intenta relajar el peso
                relajacion(actual, ady, peso);
            }
        }
    }
}