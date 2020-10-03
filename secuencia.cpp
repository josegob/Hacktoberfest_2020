//
//  Ejercicio 1
//  Relacion ejercicios 7B
//
//  Created by Rafael Medina Facal on 9/12/17.
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
    SecuenciaCaracteres extraSecuencia(int ini, int fin){
        SecuenciaCaracteres s;
        bool noEsMinuscula = false;
        bool noEsMayuscula = false;

        for (int i = 0; i < total_utilizados; i ++) {
            //bool ES_MAYUSCULA = vector_privado[i] >= 'A' && vector_privado[i] <= 'Z';
            if (vector_privado[i] < 'A' || vector_privado[i] > 'Z') {
                noEsMayuscula = true;
            }
            else{
                noEsMayuscula = false;
            }
            //bool ES_MINUSCULA = vector_privado[i] >= 'a' && vector_privado[i] <= 'z';
            if (vector_privado[i] < 'a' || vector_privado[i] > 'z') {
                noEsMinuscula = true;
            }
            else{
                noEsMinuscula = false;
            }
            
            if (i >= ini && i <= fin && noEsMinuscula && noEsMayuscula) {
                s.Aniade(vector_privado[i]);
            }
        }
        
        return s;
    }
    
    //b)
    bool contiene(SecuenciaCaracteres otra){
        bool contiene = false;
        int cont = 0;
        
        for (int i = 0; i < total_utilizados; i ++) {
            if (vector_privado[i] == otra.Elemento(cont)) {
                cont ++;
                contiene = true;
            }
            else if (cont == 1){
                cont = 0;
                contiene = false;
            }
        }
        
        return contiene;
    }
    
    //c)
    SecuenciaCaracteres interseccion(SecuenciaCaracteres otra){
        SecuenciaCaracteres s;
        
        for (int i = 0; i < total_utilizados; i ++) {
            for (int j = 0; j < otra.TotalUtilizados(); j ++) {
                if (otra.Elemento(j) == vector_privado[i]) {
                    s.Aniade(vector_privado[i]);
                }
            }
        }
        
        return s;
    }
};

int main(){
    const char TERMINADOR = '#';
    char caracter;
    SecuenciaCaracteres secuencia(" una +cadena/ de prueba *");
    SecuenciaCaracteres otra("cadena");
    int utilizados_en_secuencia;
    int capacidad_secuencia;
    
    capacidad_secuencia = secuencia.Capacidad();
    
    /////////////////////////////////////////////////////////
    // Recorrido para imprimir los elementos de la secuencia:
    
    utilizados_en_secuencia = secuencia.TotalUtilizados();
    
    for (int i=0; i < utilizados_en_secuencia; i++)
        cout << secuencia.Elemento(i);
    
    // O bien:
    
    cout << "\n" << secuencia.ToString();
    
    cout << endl;
    
    cout << "Los siguientes caracteres no son letras: " << secuencia.extraSecuencia(0, 24).ToString() << endl;
    
    cout << "La cadena secundaria contiene a la principal: " << secuencia.contiene(otra) << endl;
    
    cout << "Los siguientes caracteres son comunes en ambas secuencias: " << secuencia.interseccion(otra).ToString() << endl;
}
