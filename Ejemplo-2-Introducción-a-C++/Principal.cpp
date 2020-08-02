

#include "Operaciones.hpp"

int main(int argc, char *argv[]){
    
    Operaciones *opera = new Operaciones();
    vector<string> res = opera->split("Ruby;Java;C++;Python;Perl;JavaScript");
    
    for(int i=0;i<res.size();i++){
        cout << res[i] << "|";
    }
    cout << endl;
    
    bool r = opera->almacenar();
    cout << "Almacena: " << r << endl;
    
    string cad = "23.33";
    stringstream ss;
    ss << cad;
    float x = 0.0f;
    ss >> x;
    cout << "X: " << x << endl;
    
    cout << "SS = " << ss.str() << endl;
    
    vector<long> numeros = opera->leer();
    for(int i=0;i<numeros.size();i++){
        cout << numeros[i] << "|" << (numeros[i]*10) << endl;
    }
    
    vector<DATA> datos = opera->leerData();
    DATA temp;
    for(int i=0;i<datos.size();i++){
        temp = datos[i];
        cout << temp.pos << " = " << temp.token << endl;
    }
    
    delete opera;
    
    return 0;
}
