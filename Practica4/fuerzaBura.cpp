
#include <iostream>
#include <vector>

using namespace std;

vector<int> FuerzaBruta(int X, int N, vector<int> a, vector<int> p, vector<int> b, vector<int> c) {
    int mejorBeneficio = 0;
    vector<int> mejorComb;
    
    // Generar todas las combinaciones posibles
    for (int bitmask = 0; bitmask < (1 << N); bitmask++) {
        int dineroRestante = X;
        int beneficioTotal = 0;
        vector<int> combinacionActual;
        
        // Calcular la combinación actual
        for (int i = 0; i < N; i++) {
            if (bitmask & (1 << i)) {
                int accionesCompradas = min(a[i], dineroRestante / (p[i] + c[i]));
                dineroRestante -= accionesCompradas * (p[i] + c[i]);
                beneficioTotal += accionesCompradas * b[i] * p[i];
                combinacionActual.push_back(accionesCompradas);
            }
        }
        
        // Actualizar la mejor combinación
        if (beneficioTotal > mejorBeneficio) {
            mejorBeneficio = beneficioTotal;
            mejorComb = combinacionActual;
        }
    }
    
    return mejorComb;
}

int main() {
    int X = 1000;  // Cantidad de dinero disponible
    int N = 5;    // Número total de empresas
    
    // Ejemplo de datos de empresas
    vector<int> a = {10, 20, 15, 12, 8};      // Número total de acciones
    vector<int> p = {50, 30, 25, 40, 20};     // Precio de las acciones
    vector<int> b = {10, 15, 12, 8, 5};       // Beneficio esperado en porcentaje
    vector<int> c = {5, 3, 4, 2, 2};          // Comisión por acción
    
    vector<int> combinacionOptima = FuerzaBruta(X, N, a, p, b, c);
    
    // Imprimir la combinación óptima de acciones compradas
    cout << "Combinación óptima de acciones compradas:" << endl;
    for (int i = 0; i < N; i++) {
        cout << "Empresa " << (i + 1) << ": " << combinacionOptima[i] << " acciones" << endl;
    }
    cout << endl;
    
    return 0;
}
