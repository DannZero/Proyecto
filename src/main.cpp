#include <cstdlib>
#include "Dijkstra.h"

string abrirImagen();

int main()
{
	cout << "Planeador de viajes MRT Singapur" << endl;
	cout << "________________________________" << endl;
    do {
        cout << "1. Mostrar Mapa" << endl;
        cout << "2. Iniciar Viaje" << endl;
        cout << "0. Salir del Programa..." << endl;
        short opcion;
        cin >> opcion;
        switch (opcion) {
        case 1:
            system(abrirImagen());
            break;
        case 2:
            //funcion que activa el dijkstra
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
string abrirImagen()
{
    string s = "";
#ifdef _WIN32 // Windows (x64 and x86)
//El de windows
#elif __linux__
    s = "xdg-open network_map.png"
#elif __APPLE__
    s = "open network_map.png"
#endif
    return s;
}
