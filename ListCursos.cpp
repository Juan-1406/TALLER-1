#include "ListCursos.h"
#include <iostream>

ListCursos::ListCursos() {
    cabeza = nullptr;
}

ListCursos::~ListCursos() { //SE RECORRE NODO POR NODO BORRANDOLOS
    NodoCurso* actual = cabeza;
    while (actual) {
        NodoCurso* temp = actual;
        actual = actual -> sgt;
        delete temp -> curso;
        delete temp;
    }
}

void ListCursos::agregarCurso(Curso* c) {
    NodoCurso* nuevo = new NodoCurso(c);
    nuevo -> sgt = cabeza;
    cabeza = nuevo;
}

Curso *ListCursos::porCodigo(int codigo) {
    NodoCurso* actual = cabeza;
    while (actual) {
        if (actual -> curso -> getCodigo() == codigo) {
            return actual ->curso;
        }
        actual = actual ->sgt;
    }
    return nullptr;
}

void ListCursos::porNombre(const string &nombre) {
    NodoCurso* actual = cabeza;
    bool encontrado = false;

    while (actual) {
        if (actual -> curso -> getNombre() == nombre) {
            actual -> curso -> mostrarInfo();
            encontrado = true;
        }
        actual = actual -> sgt;
    }
    if (!encontrado) {
        cout << endl << "No se encontraron cursos con el nombre " << nombre;
    }
}

void ListCursos::eliminarCurso(int codigo) {
    NodoCurso* actual = cabeza;
    NodoCurso* aux = nullptr;

    while (actual) {
        if (actual -> curso -> getCodigo() == codigo) {
            if (aux != nullptr) {
                aux -> sgt = actual -> sgt;
            } else {
                cabeza = actual -> sgt;
            }
            delete actual -> curso;
            delete actual;
            cout << endl << "Curso eliminado con exito!";
            return;
        }
        aux = actual;
        actual = actual -> sgt;
    }
    cout << endl << "Curso no encontrado";
}
