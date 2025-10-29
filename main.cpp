#include <iostream>
#include <string>

using namespace std;

const int CAP = 10;
char cola[CAP];
int head = 0; // índice del frente
int tail = 0; // índice del ultimo
int cnt  = 0; // cantidad de elementos

bool enqueue(char c) {
    if (cnt == CAP) return false;
    cola[tail] = c;
    tail = (tail + 1) % CAP;
    ++cnt;
    return true;
}

void mostrarCola() {
    if (cnt == 0) {
        cout << "La cola esta vacia\n";
        return;
    }
    cout << "Elementos en la cola (primero -> ultimo):\n";
    for (int i = 0; i < cnt; ++i) {
        int idx = (head + i) % CAP;
        cout << cola[idx];
        if (i + 1 < cnt) cout << ' ';
    }
    cout << '\n';
}

int leerOpcion() {
    string linea;
    cout << "\nMenu:\n";
    cout << "1. Insertar un caracter a la cola\n";
    cout << "2. Mostrar todos los elementos de la cola\n";
    cout << "3. Salir\n";
    cout << "Elija una opcion: ";
    getline(cin, linea);
    if (linea.empty()) return 0;
    return stoi(linea);
}

char leerCaracter() {
    string linea;
    while (true) {
        cout << "Ingrese un caracter: ";
        getline(cin, linea);
        if (!linea.empty()) return linea[0]; // toma el primer carácter de la línea
        cout << "Entrada vacia, intente de nuevo\n";
    }
}

int main() {
    cout << "---- Cola de caracteres ----\n";
    while (true) {
        int opt = leerOpcion();
        if (opt == 1) {
            char c = leerCaracter();
            if (enqueue(c)) cout << "Caracter '" << c << "' insertado en la cola\n";
            else cout << "La cola está llena, no se puede insertar\n";
        } else if (opt == 2) {
            mostrarCola();
        } else if (opt == 3) {
            cout << "Saliendo...\n";
            break;
        } else {
            cout << "Opcion no válida, intentelo de nuevo\n";
        }
    }
    return 0;
}