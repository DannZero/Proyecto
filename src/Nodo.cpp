#include "Nodo.h" //se incluye la librería que acabamos de crear

Nodo::Nodo(int Dato, Nodo* Sig)
{

	this->Dato = Dato;
	this->Sig = Sig;

}


Nodo::Nodo(int Dato)
{
	this->Dato = Dato;
	this->Sig = NULL;
}

void Nodo::setDato(int Dato)
{
	this->Dato=Dato;
}

void Nodo::setSig(Nodo* Sig)
{
	this->Sig=Sig;
}

int Nodo::getDato()
{
	return this->Dato;
}

Nodo* Nodo::getSig()
{
	return this->Sig;
}






