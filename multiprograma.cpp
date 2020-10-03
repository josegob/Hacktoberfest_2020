//
//  Ejercicio 5
//  Relacion ejercicios 7
//
//  Created by Rafael Medina Facal on 8/12/17.
//  Copyright © 2017 Rafael Medina Facal. All rights reserved.
//

#include <iostream>

using namespace std;

class SecuenciaCaracteres{
private:
    static const int TAMANIO = 50;
    char vector_privado[TAMANIO];
    int total_utilizados;
    
public:
    SecuenciaCaracteres(){
        total_utilizados = 0;
    }
    
    SecuenciaCaracteres(string s){
        int cuantos = s.size();
        int i = 0;
        total_utilizados = 0;
        while ((i < TAMANIO)&&(i < cuantos)){
            vector_privado[i] = s.at(i);
            i++;
            total_utilizados++;
        }
    }
    
    int TotalUtilizados(){
        return total_utilizados;
    }
    
    int Capacidad(){
        return TAMANIO;
    }
    
    void EliminaTodos(){
        total_utilizados = 0;
    }
    
    void Aniade(char nuevo){
        if (total_utilizados < TAMANIO){
            vector_privado[total_utilizados] = nuevo;
            total_utilizados++;
        }
    }
    
    void Modifica(int posicion, char nuevo){
        if (posicion >= 0 && posicion < total_utilizados)
            vector_privado[posicion] = nuevo;
    }
    
    char Elemento(int indice){
        return vector_privado[indice];
    }
    
    string ToString(){
        // Si el n˙mero de caracteres en memoria es muy grande,
        // es mucho m·s eficiente reservar memoria previamente
        // y usar push_back
        
        string cadena;
        
        cadena.reserve(total_utilizados);
        
        for (int i=0; i < total_utilizados; i++)
            cadena.push_back(vector_privado[i]);
        //cadena = cadena + vector_privado[i]  <- Evitarlo. Muy ineficiente para tamaÒos grandes;
        
        return cadena;
    }
    
    //a)
    int cuentaPalabras(){
        int n_palabras = 0;
        
        for (int i = 0; i < total_utilizados-1; i++){
            if (vector_privado[i] == ' ' && vector_privado[i+1] != ' ') {
                n_palabras ++;
            }
        }
        
        return n_palabras;
    }
    
    //b)
    int palabraMasLarga(){
        int cont = 0, contLarga = 0, pos = 0, posMejor = 0;
        
        for (int i = 0; i < total_utilizados; i++){
            if (vector_privado[i] != ' ') {
                cont ++;
            }
            else{
                cont = 0;
                if (vector_privado[i + 1] != ' ') {
                    pos = i + 1;
                }
            }
            if (cont > contLarga) {
                contLarga = cont;
                posMejor = pos;
            }
        }
        
        return posMejor;
    }
    
    //c)
    string palabra(int _i){
        string palabra;
        bool hayPalabra = false;
        bool continua = false;
        
        for (int i = 0; i < total_utilizados; i++){
            if (vector_privado[i] == ' ') {
                continua = false;
            }
            if (continua) {
                palabra.push_back(vector_privado[i]);
            }
            if (i == _i && vector_privado[i - 1] == ' ') {
                palabra.push_back(vector_privado[i]);
                hayPalabra = true;
                continua = true;
            }
        }
        
        if (!hayPalabra) {
            palabra = "ninguna palabra empieza por dicha posicion";
        }

        return palabra;
    }
    
    //d)
    void invierte(int inicio, int fin){
        int diferencia = fin - inicio + 1;
        char aux[diferencia];
        int cont = 0;
        
        for (int i = total_utilizados; i >= 0; i --){
            if (i >= inicio && i <= fin) {
                aux[cont] = vector_privado[i];
                cont ++;
            }
        }
        
        cont = 0;
        for (int i = 0; i < total_utilizados; i++){
            if (i >= inicio && i <= fin) {
                vector_privado[i] = aux[cont];
                cont ++;
            }
        }
    }
};

int main(){
    const char TERMINADOR = '#';
    char caracter;
    SecuenciaCaracteres secuencia(" una cadena de prueba esdrujula");
    int utilizados_en_secuencia;
    int capacidad_secuencia;
    
    capacidad_secuencia = secuencia.Capacidad();
    
    /////////////////////////////////////////////////////////
    // Recorrido para imprimir los elementos de la secuencia:
    
    utilizados_en_secuencia = secuencia.TotalUtilizados();
    
    for (int i=0; i < utilizados_en_secuencia; i++)
        cout << secuencia.Elemento(i);
    
    // O bien:
    
    cout << "\n" << secuencia.ToString() << endl;
    
    cout << "Numero total de palabras: " << secuencia.cuentaPalabras() << endl;
    
    cout << "La posicion donde comienza la palabra mas larga es: " << secuencia.palabraMasLarga() << endl;
    
    cout << "La palabra que comienza en la posicion " << 22 <<" es: " << secuencia.palabra(22) << endl;
    
    secuencia.invierte(3, 8);
    
    cout << "La secuencia invertida es: " << secuencia.ToString() << endl;
}
