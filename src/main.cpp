#include <cstdlib>
#include "Dijkstra.h"

using namespace std;

void abrirImagen();

int main()
{
	Nodo JooKoon=Nodo("JooKoon");
	Nodo JurongEast=Nodo("JurongEast");
	Nodo BuonaVista=Nodo("BuonaVista");
	Nodo OutramPark=Nodo("OutramPark");
	Nodo HarbourFront=Nodo("HarbourFront");
	Nodo BukitPanjang=Nodo("BukitPanjang");
	Nodo BotanicGardens=Nodo("BotanicGardens");
	Nodo Bishan=Nodo("Bishan"); 
	Nodo Newton=Nodo("Newton");
	Nodo LittleIndia=Nodo("LittleIndia");
	Nodo DhobyGhout=Nodo("DhobyGhaut");
	Nodo Chinatown=Nodo("Chinatown");
	Nodo CityHall=Nodo("CityHall");
	Nodo RafflesPlace=Nodo("RafflesPlace");
	Nodo Serangoon=Nodo("Serangoon");
	Nodo Punggol=Nodo("Punggol");
	Nodo PayaLebar=Nodo("PayLebar");
	Nodo Bugis=Nodo("PayLebar");
	Nodo Bayfront=Nodo("Bayfront");
	Nodo Promenade=Nodo("Promenade");
	Nodo MarinaBay=Nodo("MarinaBay");
	Nodo MarinaSouthPier=Nodo("MarinaSouthPier");
	Nodo TanahMerah=Nodo("TanahMerah);
	Nodo PasirRis=Nodo("PasirRis");
	Nodo ChangiAirport=Nodo("ChangiAirport");
    
    cout << "Planeador de viajes MRT Singapur" << endl;
    cout << "________________________________" << endl;

    short opcion;
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
