#include <cstdlib>
using namespace std;

string abrirImagen();


int main()
{
    // TO DO...

    system(abrirImagen());
    return 0;
}


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