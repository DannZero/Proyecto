#include <cstdlib>
#include <fstream>
#include "Dijkstra.h"

using namespace std;

vector<string> estaciones; // Los nombres de las estaciones
vector<vector<Nodo> > grafo;

void abrirImagen();
void initGrafo();
void leerArchivo(string path);
void buscarTransbordos();
int buscarEstacion(string s);

int main()
{
    

    cout << "Planeador de viajes MRT Singapur" << endl;
    cout << "________________________________" << endl;

    short opcion;
    string inicio, destino;
	int varI;

	initGrafo();

    Dijkstra d = Dijkstra(grafo);
    do {
        cout << "1. Mostrar Mapa" << endl;
        cout << "2. Iniciar Viaje" << endl;
        cout << "0. Salir del Programa..." << endl;
        cin >> opcion;
        switch (opcion) {
        case 1:
            abrirImagen();
            break;
        case 2:
            cout << "Inicio: ";
            cin >> inicio;
            cout << "Destino: ";
            cin >> destino;
			varI = buscarEstacion(inicio);
            d.encontrarCaminos(varI);
			varI = buscarEstacion(destino);
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
void abrirImagen()
{
#ifdef _WIN32 // Windows (x64 and x86)
//El de windows
#elif __linux__
    system("xdg-open ../network_map.png");
#elif __APPLE__
    system("open ../network_map.png");
#endif
}

void initGrafo()
{
    leerArchivo("../Lineas/CC.txt");
    leerArchivo("../Lineas/CE.txt");
    leerArchivo("../Lineas/CG.txt");
    leerArchivo("../Lineas/DT.txt");
    leerArchivo("../Lineas/EW.txt");
    leerArchivo("../Lineas/NE.txt");
    leerArchivo("../Lineas/NS.txt");
    buscarTransbordos();
}

void leerArchivo(string path)
{
    ifstream archivo(path);
    bool comienzo = true;
    string linea;
    if (archivo.is_open()) {
        while (getline(archivo, linea)) {
		cout << "Cargando " << path << endl;
            if (!comienzo) {
                grafo[estaciones.size()-1].push_back(Nodo(estaciones.size() - 2, 3));
                grafo[estaciones.size() - 2].push_back(Nodo(estaciones.size(), 3));
            }

            estaciones.push_back(linea);
            comienzo = false;
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
                grafo[i].push_back(Nodo(j, 3));
                grafo[j].push_back(Nodo(i, 3));
            }
        }
    }
}

int buscarEstacion(string s)
{
    for (int i = estaciones.size() - 1; i > 0; --i) {
        if (estaciones[i] == s) {
            return i;
        }
    }
    return -1;
}