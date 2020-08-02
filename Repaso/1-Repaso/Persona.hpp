#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

class Persona {
    private:
        string cedula;
    public:
        string nombre;
        string apellido;
        bool soltera;
        Persona(string,string,string,bool=false);
        void saludar();
        bool validarCedula();
};

