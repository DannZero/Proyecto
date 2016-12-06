#include <vector>
#include <string>

using namespace std;

class Nodo {
public:
    string nombre;

    Nodo();

    // Agregar: estacion.addConexion(estacion2, vector<string> estacionesIntermed = { ... , ... , ... , ... })
    void addConexion(Nodo, vector<string>);
};