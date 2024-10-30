/*
 
 Practica 2 DyV: Realizada por Amador Carmona Méndez y Miguel Ángel López Sánchez
 Implementación del algoritmo Básico para el problema del Frente Pareto, el Algortimo es el siguiente:
 Funcion Dominantes(L: lista de puntos con características, K: número de características):
     puntosFrontera: lista de puntos con características.
         Para cada punto pi de la lista hacer:
             Para cada otro punto pj de la lista hacer:
                si EsDominante(pi,pj) entonces:
                    añadir punto pi a puntosFrontera
     Devolvemos puntos frontera.
 
 Función esDominante (puntoi, puntoj, número de caracteristicas K):
     para cada caracteristica c dentro de las K-caracteristicas hacer:
         si pj[c]<pi[c] entonces:
            devolvemos Falso
    devolvemos Verdadero
 
 */


//

#include <cstdlib> // Para usar srand y rand
#include <chrono>
#include <iostream>
#include <fstream> // Para usar ficheros
#include <list>
//#define
int const K=10;
using namespace std;


int* paretoBasico(int L[][K], int const K);
bool esDominante(int pi, int pj);
int tamanio(int *V);


int main(int argc, char *argv[]) {
    
    int *v;
    int n, i, argumento;
    chrono::time_point<std::chrono::high_resolution_clock> t0, tf; // Para medir el tiempo de ejecución
    double tejecucion; // tiempo de ejecucion del algoritmo en ms
    unsigned long int semilla;
    ofstream fsalida;
    
    if (argc <= 3) {
        cerr<<"\nError: El programa se debe ejecutar de la siguiente forma.\n\n";
        cerr<<argv[0]<<" NombreFicheroSalida Semilla tamCaso1 tamCaso2 ... tamCasoN\n\n";
        return 0;
    }
    
    // Abrimos fichero de salida
    fsalida.open(argv[1]);
    if (!fsalida.is_open()) {
        cerr<<"Error: No se pudo abrir fichero para escritura "<<argv[1]<<"\n\n";
        return 0;
    }
    
    // Inicializamos generador de no. aleatorios
    semilla= atoi(argv[2]);
    srand(semilla);
    
    // Pasamos por cada tamaÒo de caso
    for (argumento= 3; argumento<argc; argumento++) {
        
        // Cogemos el tamanio del caso
        n= atoi(argv[argumento]);
        
        // Reservamos memoria para el vector
        int v[n][K];
        
        // Generamos vector aleatorio de prueba, con componentes entre 0 y n-1
        for (i= 0; i<n; i++)
            for(int j=0;j<K; j++)
                v[i][j]= rand()%n;
        
        cerr << "Ejecutando Algoritmo para tam. caso: " << n << endl;
        int sol[n];
        t0= std::chrono::high_resolution_clock::now(); // Cogemos el tiempo en que comienza la ejecuciÛn del algoritmo
        sol=paretoBasico(v[n][K],K);
        
        tf= std::chrono::high_resolution_clock::now(); // Cogemos el tiempo en que finaliza la ejecuciÛn del algoritmo
        
        unsigned long tejecucion= std::chrono::duration_cast<std::chrono::microseconds>(tf - t0).count();
        
        cerr << "\tTiempo de ejec. (us): " << tejecucion << " para tam. caso "<< n<<endl;
        
        // Guardamos tam. de caso y t_ejecucion a fichero de salida
        fsalida<<n<<" "<<tejecucion<<"\n";
        
        
        // Liberamos memoria del vector
        //delete [][] v;
    }
    
    // Cerramos fichero de salida
    fsalida.close();
    
    return 0;
}

//Algoritmos creados por Amador Carmona Méndez y Miguel Ángel López Sánchez
int* paretoBasico(int L[][K], int const K){
    const int tam=tamanio(L[0]);
    int final[tam];
    int tamK=0;
    int cont=0;
    for(int i=0; i<tam-1; i++){
        tamK=tamanio(L[i]);
        for(int j=0; j<tamK; j++){
            if (esDominante(L[i][j],L[i+1][j])){
                final[cont]=L[i][j];
                cont++;
            }
        }
    }
    return final;
}
int tamanio(int *V){
    int tam = sizeof(V)/sizeof(int);
    return tam;
}
bool esDominante(int pi, int pj){
    return (pi<pj);
}
#include <vector>
/*
std::vector<int> paretoBasico(int L[][K], int const K){
    const int tam=tamanio(L[0]);
    std::vector<int> final;
    for(int i=0; i<tam; i++){
        bool esPareto = true;
        int tamK = tamanio(L[i]);
        for(int j=0; j<tamK; j++){
            for(int k=0; k<tamK; k++){
                if(j != k && esDominante(L[i][j], L[i][k], K)){
                    esPareto = false;
                    break;
                }
            }
            if(!esPareto){
                break;
            }
        }
        if(esPareto){
            for(int j=0; j<tamK; j++){
                final.push_back(L[i][j]);
            }
        }
    }
    return final;
}
*/

