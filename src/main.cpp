#include <cstdlib>
#include "Dijkstra.h"

using namespace std;

void abrirImagen();
//vector<Nodo> initGrafo();

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
            //funcion que activa el dijkstra
			Dijkstra d = Dijkstra(adyacentes); // Aun hay que armar el grafo
			d.encontrarCaminos(inicio);
			
			cout << "El trayecto mas corto es:" << endl;
			d.imprimirCamino(destino);
			cout << "Que tenga buen viaje ;)" << endl;

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

/**
 *  Función que inicializa el grafo del metro
 * devuelve un vector con todas las aristas
 */
/*vector<Nodo> initGrafo()
{
    vector<Nodo> v;
	// Se agregan todos los transbordos y terminales
    v.push_back(Nodo("Joo Koon"));
    v.push_back(Nodo("Jurong East"));
    v.push_back(Nodo("Buona Vista"));
    v.push_back(Nodo("Outram Park"));
    v.push_back(Nodo("Harbour Front"));
    v.push_back(Nodo("Bukit Panjang"));
    v.push_back(Nodo("Botanic Gardens"));
    v.push_back(Nodo("Bishan"));
    v.push_back(Nodo("Newton"));
    v.push_back(Nodo("Little India"));
    v.push_back(Nodo("Dhoby Ghaut"));
    v.push_back(Nodo("Chinatown"));
    v.push_back(Nodo("CityHall"));
    v.push_back(Nodo("Raffles Place"));
    v.push_back(Nodo("Serangoon"));
    v.push_back(Nodo("Punggol"));
    v.push_back(Nodo("Pay Lebar"));
    v.push_back(Nodo("Bugis"));
    v.push_back(Nodo("Bayfront"));
    v.push_back(Nodo("Promenade"));
    v.push_back(Nodo("Marina Bay"));
    v.push_back(Nodo("Marina South Pier"));
    v.push_back(Nodo("Tanah Merah"));
    v.push_back(Nodo("Pasir Ris"));
    v.push_back(Nodo("Changi Airport"));

	list<string> s;

	// Agregar las estaciones con que conecta cada uno
	s.push_back("Pioneer");
	s.push_back("Boon Lay");
	s.push_back("Lakeside");
	s.push_back("Chinese Garden");
	v[0].addConexion(v[1], s);
	s.reverse();
	v[1].addConecion(v[0], s);
	s.clear();
	// Repetir para todas....

    return v;
}*/
