#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Archivo 
{
public:
    static vector<int> Leer();
    static void Escribir(vector<int>);
};
