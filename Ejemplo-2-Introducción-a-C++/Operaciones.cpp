
#include "Operaciones.hpp"

Operaciones::Operaciones(string nombreArchivo){
    this->nombreArchivo = nombreArchivo;
}


vector<string> Operaciones::split(string cad, char sep){
    string token = "";
    stringstream ss;
    vector<string> datos;
    
    ss << cad; // Ruby;Java;C++;Python;Perl;JavaScript
    
    while((getline(ss,token,sep))){
        datos.push_back(token);
    }
    
    return datos;
}

bool Operaciones::almacenar(int total){
    ofstream _buffer(this->nombreArchivo, ios::out);
    
    long a = 0;
    long b = 1;
    long c = -1;
    
    _buffer << a << endl;
    _buffer << b << endl;
    
    for(int i=0;i<total;i++){
        c = a+b;
        a = b;
        b = c;
        _buffer << c << endl;
    }
    _buffer.close();
    
    return true;
}

vector<long> Operaciones::leer(char sep){
    ifstream lectura(this->nombreArchivo, ios::in);
    vector<long> datos;
    
    string token = "";
    stringstream ss;
    long numero = 0;
    
    while(getline(lectura,token,sep)){
        ss.str("");
        ss << token << endl;
        ss >> numero;
        //cout << "Token: " << token << endl;
        datos.push_back(numero);
    }
    
    lectura.close();
    return datos;
}

vector<DATA> Operaciones::leerData(char sep){
    ifstream lectura(this->nombreArchivo, ios::in);
    vector<DATA> datos;
    
    string token = "";
    stringstream ss;
    int pos = 0;
    DATA tupla;

    while(getline(lectura,token,sep)){
        ss.str("");
        ss << token << endl;
        tupla.pos = pos++;
        tupla.token = token; 
        
        datos.push_back(tupla);
    }
    
    lectura.close();
    return datos;
}
