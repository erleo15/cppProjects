#include "Persona.hpp"

Persona::Persona(string cedula,string nombre,string apellido,bool soltera){
    this->cedula = cedula;
    this->nombre = nombre;
    this->apellido = apellido;
    this->soltera = soltera;
}

void Persona::saludar(){
    cout << "Hola, soy " << nombre << " "<< apellido << " con cedula:" << cedula << " y soltero=" << soltera <<endl;
}

bool Persona::validarCedula(){
    int digito;
    int suma = 0;
    int producto = 0;
    for(int i =0; i<this->cedula.size()-1;i++){///Tambien hay ccedula.length
        digito = ((int)cedula.at(i))-48;
        cout << digito << "|";
        if(i%2==0)
            //producto = (producto*2 > 9 )?producto*2-9 : producto*2;
            suma = (digito*2>9)?suma+digito*2-9 : suma+digito*2;
        else
        
            /* code */
            suma += digito;
        digito = ((int)cedula.at(i+1))-48;
    }
    suma = (digito ==0)?suma % 10:10-(suma %10);
    cout << endl;
    cout << "Suma Cedula: " << suma << endl;

    return suma == digito;
}
