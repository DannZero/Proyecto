#include "Lista.h"

//métodos constructores:

Lista::Lista()
{
	this->H=NULL;
	this->T=NULL;
}

Lista::Lista(int Dato)
{
	Nodo* aux = new Nodo(Dato);
	this->H=&aux;
	this->T=&aux;
}

bool Lista::ListaVacia()
{
	if (this->H == NULL && this-> == NULL)
		return true;
	return false;
}


void Lista::AddInicio(int Dato)
{
	Nodo* aux = new Nodo(Dato,this->H);
	if (ListaVacia())
	{
		this->T=&aux;
	}
	this->H=&aux;
}

void Lista::Show()
{
	Nodo* aux = this->H;
	while(aux!=NULL)
	{
		std::cout<<aux->getDato()<<std::endl; //se imprime el dato
		aux=aux->getSig();
	}

}



