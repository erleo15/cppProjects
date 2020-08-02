// Las librerías o cabeceras que son del usuario
// se colocan entre comillas

#include "Persona.hpp"

Persona::Persona(string cedula,string nombres,string apellidos, bool soltera){
    // Se usa esta sintaxis ya que this hace referencia a un puntero
    this->cedula = cedula;
    this->nombres = nombres;
    this->apellidos = apellidos;
    this->soltera = soltera;
}

void Persona::saludar(){
    cout << "Hola, soy " << nombres << " " << apellidos << " Ced. " << cedula << " " << soltera << endl;
}

bool Persona::validarCedula(){
    int digito = 0;
    int suma = 0;
    int prod = 0;
    
    for(int i=0;i<this->cedula.size();i++){//También existe cedula.length()
        digito = ((int)cedula.at(i)) - 48; // También se puede usar [] como otros lenguajes
        if(i%2==0 && i<cedula.size()-1)
            suma = (digito*2>9)?suma+digito*2-9:suma+digito*2;
        else if (i%2!=0 && i<cedula.size()-1)
            suma+=digito;
    }
    cout << "Suma Parcial: " << suma << endl;
    suma = (digito==0)?suma%10:10-(suma%10);
    
    cout << endl;
    cout << "10 - Residuo. " << suma << endl;
    return (suma == digito);
}


