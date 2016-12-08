#include <cstdlib>
#include <fstream>
#include "Dijkstra.h"

using namespace std;

vector<string> estaciones; // Los nombres de las estaciones
vector<vector<Nodo> > grafo;

void abrirImagen(string path);
void initGrafo(string path);
void leerArchivo(string path);
void buscarTransbordos();
int buscarEstacion(string s);

int main(int argc, char* argv[])
{

    cout << "Planeador de viajes MRT Singapur" << endl;
    cout << "________________________________" << endl;

    short opcion;
    string inicio, destino;
    int varI;

    string argv_str(argv[0]); //Extrae el Path actual del comando de terminal
    string basePath = argv_str.substr(0, argv_str.find_last_of("/")); // Le quita carac. fin de linea

    initGrafo(basePath);

    Dijkstra d = Dijkstra(grafo);
    do {
        cout << "1. Mostrar Mapa" << endl;
        cout << "2. Iniciar Viaje" << endl;
        cout << "0. Salir del Programa..." << endl;
        cin >> opcion;
        switch (opcion) {
        case 1:
            abrirImagen(basePath);
            break;
        case 2:
            cout << "Inicio: ";
            cin >> inicio;
            cout << "Destino: ";
            cin >> destino;
            varI = buscarEstacion(inicio);
            if (varI == -1) {
                cout << "No existe la estación" << endl;
                break;
            }
            d.encontrarCaminos(varI);
            varI = buscarEstacion(destino);
            if (varI == -1) {
                cout << "No existe la estación" << endl;
                break;
            }
            d.imprimirCamino(varI);
            break;
        case 0:
            break;
        default:
            cout << "Opcion incorrecta." << endl;
        }
    } while (opcion != 0);

    return 0;
}

/**
 *  Función que devuelve un string que representa
 * el comando de terminal/consola para abrir la 
 * imagen del mapa con la aplicación predeterminada
 * del sistema.
 */
void abrirImagen(string path)
{
#ifdef _WIN32 // Windows (x64 and x86)
//El de windows
#elif __linux__
    system(path.c_str());
#elif __APPLE__
    system(path.c_str());
#endif
}

void initGrafo(string path)
{
    leerArchivo(path + "/../Lineas/CC.txt");
    leerArchivo(path + "/../Lineas/CE.txt");
    leerArchivo(path + "/../Lineas/CG.txt");
    leerArchivo(path + "/../Lineas/DT.txt");
    leerArchivo(path + "/../Lineas/EW.txt");
    leerArchivo(path + "/../Lineas/NE.txt");
    leerArchivo(path + "/../Lineas/NS.txt");
    buscarTransbordos();
}

void leerArchivo(string path)
{
    ifstream archivo;
    cout << "Cargando " << path << endl;
    archivo.open(path.c_str());
    if (archivo.is_open()) {
        string linea;
        for (int i = 0; getline(archivo, linea); ++i) {
            cout << "" << linea << endl;
            if (i > 0) {
                if (i > 1) {
                    grafo.front().push_back(Nodo(grafo.size() - 2, 3));
                    grafo[grafo.size() - 2].push_back(Nodo(estaciones.size(), 3));
                } else {
                    grafo.front().push_back(Nodo(0, 3));
                }
            }

            estaciones.push_back(linea);
        }
    } else {
        cout << "Fallo al cargar la linea de metro" << endl;
    }
}

void buscarTransbordos()
{
    for (int i = 0; i < estaciones.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (estaciones[i] == estaciones[j]) {
                cout << "Conectando transbordo en " << estaciones[i] << endl;
                grafo[i].push_back(Nodo(j, 3));
                grafo[j].push_back(Nodo(i, 3));
            }
        }
    }
}

int buscarEstacion(string s)
{
    for (int i = estaciones.size() - 1; i >= 0; --i) {
        if (estaciones[i] == s) {
            return i;
        }
    }
    return -1;
}