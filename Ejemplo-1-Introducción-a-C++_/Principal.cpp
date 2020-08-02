
#include "Persona.hpp"


int main(int argc, char *argv[]){

    // Se instancia la clase como una variable normal, no como puntero
    Persona objSandra("0105804488","Sandra","Peñaranda",true);
    objSandra.saludar();
    
    // Instancia de una clase como puntero
    Persona *objAdri = new Persona("1104240815","Adriana","Castillo",true);
    objAdri->saludar();
    bool r = objAdri->validarCedula();
    cout << "Cédula Correcta: " << r << endl;
    
    int x = 23;
    int *pX = &x;
    
    cout << "Posición de Memoria: " << (pX) << " Valor: " << (*pX) << endl;
    
    (*pX) = 17;
    
    cout << "Valor de X = " << x << endl;
    
    delete objAdri;

    return 0;
}
