#include <iostream>
#include <vector>
using namespace std;

vector<int> ProgramacionDinamica(int X, int N, vector<int>& a, vector<int>& p, vector<int>& b, vector<int>& c) {
    // Inicialización
    vector< vector<int> > DP(N + 1, vector<int>(X + 1, 0));
    
    for (int i = 1; i <= N; i++) {
        for (int x = 1; x <= X; x++) {
            // Casos base
            if (i == 0 || x == 0) {
                DP[i][x] = 0;
            } else if (a[i - 1] <= x) {
                // Ecuación recurrente
                DP[i][x] = max(DP[i - 1][x], DP[i - 1][x - (p[i - 1] + c[i - 1])] + b[i - 1] * p[i - 1]);
            } else {
                DP[i][x] = DP[i - 1][x];
            }
            
            // Imprimir traza de ejecución
            cout << "DP[" << i << "][" << x << "] = " << DP[i][x] <<  "\n";
            cout << "a[" << i - 1 << "] = " << a[i - 1] << "\n";
            cout << "p[" << i - 1 << "] = " << p[i - 1] << "\n";
            cout << "b[" << i - 1 << "] = " << b[i - 1] << "\n";
            cout << "c[" << i - 1 << "] = " << c[i - 1] << "\n";
        }
        cout<<endl;
    }
    
    // Recuperación de la solución óptima
    int mejorBeneficio = DP[N][X];
    vector<int> combinacionOptima;
    int x = X;
    
    for (int i = N; i >= 1; i--) {
        if (DP[i][x] != DP[i - 1][x]) {
            int accionesCompradas = min(a[i - 1], x / (p[i - 1] + c[i - 1]));
            combinacionOptima.push_back(accionesCompradas);
            x -= accionesCompradas * (p[i - 1] + c[i - 1]);
        }
    }
    
    return combinacionOptima;
}
/*
int main() {
    int X = 1000;  // Cantidad de dinero disponible
    int N = 20;    // Número total de empresas
    
    // Ejemplo de datos de empresas
    vector<int> a = {10, 20, 15, 12, 8, 18, 7, 14, 9, 11, 10, 20, 15, 12, 8, 18, 7, 14, 9, 11};  // Número total de acciones
    vector<int> p = {50, 30, 25, 40, 20, 35, 45, 60, 55, 50, 50, 30, 25, 40, 20, 35, 45, 60, 55, 50};  // Precio de las acciones
    vector<int> b = {10, 15, 12, 8, 5, 9, 7, 14, 11, 13, 10, 15, 12, 8, 5, 9, 7, 14, 11, 13};  // Beneficio esperado en porcentaje
    vector<int> c = {5, 3, 4, 2, 2, 4, 3, 5, 4, 3, 5, 3, 4, 2, 2, 4, 3, 5, 4, 3};  // Comisión por acción
    
    vector<int> combinacionOptima = ProgramacionDinamica(X, N, a, p, b, c);
    
    // Imprimir la combinación óptima de acciones compradas
    cout << "Combinación óptima de acciones compradas:" << endl;
    for (int i = 0; i < N; i++) {
        cout << "Empresa " << (i + 1) << ": " << combinacionOptima[i] << " acciones" << endl;
    }
    cout << endl;
    
    return 0;
}

*/
 int main() {
 int X = 1000;  // Cantidad de dinero disponible
 int N = 5;    // Número total de empresas
 
 // Ejemplo de datos de empresas
 vector<int> a = {10, 20, 15, 12, 8};      // Número total de acciones
 vector<int> p = {50, 30, 25, 40, 20};     // Precio de las acciones
 vector<int> b = {10, 15, 12, 8, 5};       // Beneficio esperado en porcentaje
 vector<int> c = {5, 3, 4, 2, 2};          // Comisión por acción
 
 vector<int> combinacionOptima = ProgramacionDinamica(X, N, a, p, b, c);
 
 // Imprimir la combinación óptima de acciones compradas
 cout << "Combinación óptima de acciones compradas:" << endl;
 for (int i = 0; i < N; i++) {
 cout << "Empresa " << (i + 1) << ": " << combinacionOptima[i] << " acciones" << endl;
 }
 cout << endl;
 
 return 0;
 }


