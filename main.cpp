#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_ESTUDIANTES = 10; // tamaño fijo del arreglo (puede ajustarse)


// llenarDatos: recorre ambos arreglos con un for y le pide
// al usuario nombre y nota de cada estudiante. Valida que
// la nota esté entre 0 y 100 antes de aceptarla.

void llenarDatos(string nombres[], float notas[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "\n--- Estudiante " << (i + 1) << " ---\n";
        cout << "Nombre: ";
        cin.ignore(); // limpia el buffer antes de leer la línea completa
        getline(cin, nombres[i]);

        float nota;
        bool valida = false;
        do {
            cout << "Calificacion (0-100): ";
            cin >> nota;
            if (nota < 0 || nota > 100) {
                cout << "Nota fuera de rango. Intenta de nuevo.\n";
            } else {
                valida = true;
            }
        } while (!valida);

        notas[i] = nota;
    }
}


// mostrarDatos: recorre los dos arreglos en paralelo (mismo
// indice = mismo estudiante) e imprime una tabla ordenada.

void mostrarDatos(string nombres[], float notas[], int n) {
    cout << "\n===== LISTADO DE ESTUDIANTES =====\n";
    cout << left << setw(20) << "Nombre" << "Calificacion\n";
    cout << "-----------------------------------\n";
    for (int i = 0; i < n; i++) {
        cout << left << setw(20) << nombres[i] << fixed << setprecision(1) << notas[i] << "\n";
    }
}


// buscarMaximo: recorre el arreglo comparando con if para
// quedarse con el indice de la nota mas alta.

int buscarMaximo(float notas[], int n) {
    int indiceMax = 0;
    for (int i = 1; i < n; i++) {
        if (notas[i] > notas[indiceMax]) {
            indiceMax = i;
        }
    }
    return indiceMax;
}


// buscarMinimo: misma logica que buscarMaximo pero invertida.

int buscarMinimo(float notas[], int n) {
    int indiceMin = 0;
    for (int i = 1; i < n; i++) {
        if (notas[i] < notas[indiceMin]) {
            indiceMin = i;
        }
    }
    return indiceMin;
}


// calcularPromedio: suma todas las notas y divide entre n.

float calcularPromedio(float notas[], int n) {
    float suma = 0;
    for (int i = 0; i < n; i++) {
        suma += notas[i];
    }
    return suma / n;
}


// contarAprobadosReprobados: recorre el arreglo y usa if/else
// para clasificar cada nota segun la nota minima de aprobacion.

void contarAprobadosReprobados(float notas[], int n, float notaMinima, int &aprobados, int &reprobados) {
    aprobados = 0;
    reprobados = 0;
    for (int i = 0; i < n; i++) {
        if (notas[i] >= notaMinima) {
            aprobados++;
        } else {
            reprobados++;
        }
    }
}

int main() {
    string nombres[MAX_ESTUDIANTES];
    float notas[MAX_ESTUDIANTES];
    const float NOTA_MINIMA_APROBACION = 70.0;

    cout << "PROGRAMA DE GESTION DE CALIFICACIONES\n";
    cout << "Se registraran " << MAX_ESTUDIANTES << " estudiantes.\n";

    llenarDatos(nombres, notas, MAX_ESTUDIANTES);
    mostrarDatos(nombres, notas, MAX_ESTUDIANTES);

    int iMax = buscarMaximo(notas, MAX_ESTUDIANTES);
    int iMin = buscarMinimo(notas, MAX_ESTUDIANTES);
    float promedio = calcularPromedio(notas, MAX_ESTUDIANTES);

    int aprobados, reprobados;
    contarAprobadosReprobados(notas, MAX_ESTUDIANTES, NOTA_MINIMA_APROBACION, aprobados, reprobados);

    cout << "\n===== ESTADISTICAS =====\n";
    cout << "Nota mas alta: " << nombres[iMax] << " (" << notas[iMax] << ")\n";
    cout << "Nota mas baja: " << nombres[iMin] << " (" << notas[iMin] << ")\n";
    cout << fixed << setprecision(2) << "Promedio general: " << promedio << "\n";
    cout << "Aprobados: " << aprobados << " | Reprobados: " << reprobados << "\n";

    return 0;
}