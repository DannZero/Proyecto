#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Nodo {
public:

#define conexion pair<Nodo, vector<string> >
    string nombre;
    vector<conexion> conexiones;
    int distancia;
    bool visitado;


    Nodo();

    // Agregar: estacion.addConexion(estacion2, vector<string> estacionesIntermed = { ... , ... , ... , ... })
    void addConexion(Nodo, vector<string>);
};