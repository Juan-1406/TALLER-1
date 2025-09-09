#include "ListCursos.h"
#include <iostream>

ListCursos::ListCursos() {
    cabeza = nullptr;
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
        cout << "No se encontraron cursos con el nombre " << nombre << ".";
    }
}

void ListCursos::eliminarCurso(int codigo) {

}
