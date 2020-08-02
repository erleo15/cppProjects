
// Las librerías o cabeceras que son del sistema operativo
// se colocan entre símbolos de menor y mayor que
#include <iostream>
#include <cstdlib>

#include <cstring>

using namespace std;

class Persona{
    private:
        string cedula;
    public:
        string nombres;
        string apellidos;
        bool soltera;
        Persona(string, string, string, bool = false);
        void saludar();
        bool validarCedula();
};

/*

En un archivo de cabecera pueden existir varias clases
class Vehiculo{
};

class Casa{
};
*/

