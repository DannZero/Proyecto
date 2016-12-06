#include <cstdlib>
#include <fstream>
#include "Dijkstra.h"

using namespace std;

string[126] estaciones;
void abrirImagen();
vector<Nodo> initGrafo();

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
    system("xdg-open network_map.png");
#elif __APPLE__
    system("open network_map.png");
#endif
}

vector<Nodo>[126] initGrafo()
{
    vector<Nodo> vertices[126];
	int iVert = 0;
    // Linea EW
    fstream archivo("Lineas/EW.txt", ios::in);
    if (archivo.is_open()) {
        for (int i = 0; getline(archivo, estaciones[i]) && i<29 ; ++i) {
            vertices[iVert] = vector<Nodo> (Nodo(iVert, 1));
            if (i > 0) {
                vertices[iVert].push_back(vertices[iVert - 1]);
                vertices[iVert - 1].push_back(vertices[iVert]);
            }
            iVert++;
        }
        archivo.close;
    } else
        cout << "No se pudo abrir el archivo";
	// Linea CG
	archivo.open("Lineas/CG.txt", ios::in);
    if (archivo.is_open()) {
        for (int i = 0, j = 0; getline(archivo, estaciones[i]) && i<2 ; ++i) {
            vertices[iVert] = vector<Nodo> (Nodo(iVert, 1));
            if (i > 29) {
                vertices[iVert].push_back(vertices[iVert - 1]);
                vertices[iVert - 1].push_back(vertices[iVert]);
            }
			for (j = 0; j < iVert ; ++j) // si son la misma estacion se agregan a ella los nodos
			{
				if (estaciones[iVert] == estaciones[j])
				{
					vertices[j].push_back(vertices[iVert][0]);
				}
			}
            iVert++;
        }
        archivo.close;
    } else
        cout << "No se pudo abrir el archivo";
		//hjfdsahjvkf hg vh ddsadgdasfg askujyfg kajusdfg akujsygf a
    
}