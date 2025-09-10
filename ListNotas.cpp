#include "ListNotas.h"

ListNotas::ListNotas() {
    cabeza = nullptr;
}
ListNotas::~ListNotas() {
    NodoNota* actual = cabeza;
    while (actual) {
        NodoNota* temp = actual;
        actual = actual -> sgt;
        delete temp -> nota;
        delete temp;
    }
}

void ListNotas::agregarNota(double nota) {
    Nota* n = new Nota(nota);
    NodoNota* nodo = new NodoNota(n);
    nodo -> sgt = cabeza;
    cabeza = nodo;
}
 double ListNotas::promedioNotas() {
    if (!cabeza) {
        return 0.0;
    }

    NodoNota* actual = cabeza;
    double suma = 0.0;
    int cont = 0;

    while (actual) {
        suma += actual -> nota -> getNota();
        cont++;
        actual = actual -> sgt;
    }
    if (cont > 0) {
        return suma / cont;
    }

    return 0.0;

 }

void ListNotas::mostrarNotas() {
    NodoNota* actual = cabeza;

    if (!actual) {
        cout << "Sin notas registradas";
        return;
    }
    while (actual) {
        actual -> nota ->mostrarNota();
        actual = actual -> sgt;
    }
    cout << endl;
}