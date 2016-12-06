#include <cstdlib>
#include <fstream>
#include "Dijkstra.h"

using namespace std;

vector<string> estaciones; // Los nombres de las estaciones
vector<vector<Nodo> > grafo;

void abrirImagen();
void initGrafo();

int main()
{
    //vector<Nodo> vertices = initGrafo();

    cout << "Planeador de viajes MRT Singapur" << endl;
    cout << "________________________________" << endl;

    short opcion;
    int inicio, destino;
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
            /*
            //funcion que activa el dijkstra
			Dijkstra d = Dijkstra(vertices); // Aun hay que armar el grafo
			d.encontrarCaminos(inicio);
			
			cout << "El trayecto mas corto es:" << endl;
			d.imprimirCamino(destino);
			cout << "Que tenga buen viaje ;)" << endl;
			*/
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
    fstream archivo;
}