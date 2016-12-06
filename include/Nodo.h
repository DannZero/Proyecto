#include <vector>
#include <list>
#include <string>
#include <iostream>

using namespace std;

class Nodo {
public:
    int verticeAdyacente;
    int pesoArista;

    Nodo(int vert, int peso);
};