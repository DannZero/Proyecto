#include "Nodo.h"

class ListaRemose 
public:
	Nodo* H;
	Nodo* T;
	Lista();
	Lista(int Dato);
	bool ListaVacia();
	void AddInicio(int Dato);
	void AddFinal(int Dato);
	//void AddRef(int Dato, int Ref);
	int RemoverInicio();
	int RemoverFinal();
	//    RemoverRef(); --> definir 
	//int VaciarLista();
	Nodo* BuscarElemento();

	void Show();
	~Listas();

};

