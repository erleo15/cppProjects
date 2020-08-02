#include "Persona.hpp"

int main(int argc, char *argv[]){
    //Como una variable normal como objeto
    Persona persona("0105007199","Hernan ","Leon",true);
    //Como puntero
    Persona *personaPuntero = new Persona("0105007165","Henry","Leon",false);
    persona.saludar();
    personaPuntero->saludar();
    
    
    int x=23;
    int *px = &x;
    cout << "Posicion memoria: "<< (px) << " Valor: " << (*px) <<endl;  
    (*px) = 17;
    cout << "Valor nuevo de x: "<< x << endl;
    if (personaPuntero->validarCedula()){
        cout << "la cedula " << personaPuntero->nombre << " es correcta" << endl;
    }else
    {
        /* code */
        cout << "la cedula " << personaPuntero->nombre << " es incorrecta" << endl;
    }
    
    return 0;
}
 