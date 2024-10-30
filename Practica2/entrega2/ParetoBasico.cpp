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
#include <vector>

int const K=10;

using namespace std;

struct Punto {
    vector<int> coordenadas;
};

bool esDominante(Punto pi, Punto pj, int K) {
    bool alMenosIgual = true;
    bool alMenosMayor = false;

    for (int a = 0; a < K; a++) {
        if (pj.coordenadas[a] > pi.coordenadas[a]) {
            alMenosIgual = false;
        }
        if (pj.coordenadas[a] < pi.coordenadas[a]) {
            alMenosMayor = true;
        }
    }
    if(alMenosIgual == alMenosMayor == true){
    	return true;
    }else{
    	return false;
    }
    
}

vector<Punto> paretoBasico(vector<Punto> L) {
    vector<Punto> puntosFrontera;

    for (int i = 0; i < L.size(); i++) {
        bool esNoDominado = true;
        for (int j = 0; j < L.size(); j++) {
            if (i != j && esDominante(L[j], L[i], K)) {
                esNoDominado = false;
                break;
            }
        }
        if (esNoDominado) {
            puntosFrontera.push_back(L[i]);
        }
    }

    return puntosFrontera;
}


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
        
        vector<Punto> sol; //Puntos no dominantes
        vector<Punto> puntos; //Conjunto de puntos totales
        
        // Generamos vector aleatorio de prueba, con componentes entre 0 y n-1
        for (int i = 0; i < n; i++) {
            Punto p;
            for (int j = 0; j < K; j++) {
                int num = rand() % n;
                p.coordenadas.push_back(num);
            }
            puntos.push_back(p);
        }
        
        cerr << "Ejecutando Algoritmo para tam. caso: " << n << endl;

        t0= std::chrono::high_resolution_clock::now(); // Cogemos el tiempo en que comienza la ejecuciÛn del algoritmo
        sol = paretoBasico(puntos);
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


