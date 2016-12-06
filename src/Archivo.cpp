#include "Archivo.h"

vector<int> Archivo::Leer()
{
    vector<int> v;
    fstream archivo("test_merge.txt", ios::in);
    if (archivo.is_open()) {
        int aux;
        while (!archivo.eof()) {
            archivo >> aux;
            v.push_back(aux);
        }
    } else
        cout << "No se pudo abrir el archivo";
    return v;
}

void Archivo::Escribir(vector<int> v)
{
    fstream archivo("test_merge_out.txt", ios::out | ios::trunc);
    if (archivo.is_open()) {
        for (int i = 0; i < v.size(); i++) {
            archivo << v[i];
            archivo << " ";
        }
        archivo.close();
    } else
        cout << "No se pudo abrir el archivo" << endl;
    return;
}
