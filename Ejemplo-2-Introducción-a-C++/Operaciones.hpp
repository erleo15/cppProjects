
#include <iostream>
#include <cstdlib>

#include <cstring>
#include <vector>

#include <sstream> // Permite manera flujos de cadenas de texto y conversión entre tipos de datos
#include <fstream> // Leer y escribir ficheros => ofstream (escritura), ifstream (lectura)

using namespace std;

struct DATA{
    int pos;
    string token;
};

class Operaciones{
    private:
        string nombreArchivo;
        
    public:
        Operaciones(string = "datos.dat");
        vector<string> split(string, char = ';');
        bool almacenar(int = 73);
        vector<long> leer(char = '\n');
        vector<DATA> leerData(char = '\n');
};
