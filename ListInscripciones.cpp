#include "ListInscripciones.h"
#include <iostream>
using namespace std;

ListInscripciones::ListInscripciones() {
    cabeza = nullptr;
}

ListInscripciones::~ListInscripciones() {
    NodoInscripcion* actual = cabeza;
    while (actual) {
        NodoInscripcion* temp = actual;
        actual = actual -> sgt;
        delete temp -> inscripcion;
        delete temp;
    }
}

bool ListInscripciones::agregarInscripcion(Alumno* alumno, Curso* curso) {
    if (alumno == nullptr || curso == nullptr) {
        return false;
    }

    if (buscarInscripcion(alumno -> getId(), curso -> getCodigo())) {
        return false;
    }

    int utilizados = 0;
    NodoInscripcion* actual = cabeza;
    while (actual) {
        if (actual -> inscripcion -> curso -> getCodigo() == curso -> getCodigo()) {
            utilizados++;
        }
        actual = actual -> sgt;
    }

    if (utilizados >= curso ->getCantMaxima()) { //VERIFICAR QUE NO SE EXCEDAN LOS CUPOS
        return false;
    }

    Inscripcion* inscripcion = new Inscripcion(alumno, curso);
    NodoInscripcion* nodo = new NodoInscripcion(inscripcion);
    nodo -> sgt = cabeza;
    cabeza = nodo;
    return true;
}

bool ListInscripciones::eliminarInscripcion(int idAlumno, int codigoCurso) {
    if (!buscarInscripcion(idAlumno, codigoCurso)) {
        return false;
    }
    NodoInscripcion* actual = cabeza;
    NodoInscripcion* aux = nullptr;
    while (actual) {
        if (actual -> inscripcion -> curso -> getCodigo() == codigoCurso && actual -> inscripcion -> alumno -> getId() == idAlumno) {
            if (aux != nullptr) {
                aux -> sgt = actual -> sgt;
            } else {
                cabeza = actual -> sgt;
            }
            delete actual -> inscripcion;
            delete actual;
            cout << endl << "Inscripcion eliminada con exito!";
            return true;
        }
        aux = actual;
        actual = actual -> sgt;
    }
    cout << endl << "Inscripcion no encontrada";
    return false;
}

void ListInscripciones::eliminarInscripcionAlumno(int idAlumno) {
    NodoInscripcion* actual = cabeza;
    NodoInscripcion* aux = nullptr;

    bool eliminado = false;

    while (actual) {
        if (actual -> inscripcion -> alumno -> getId() == idAlumno) {
            NodoInscripcion* temp = actual;
            if (aux != nullptr) {
                aux -> sgt = actual -> sgt;
            } else {
                cabeza = actual -> sgt;
            }
            actual = actual -> sgt;
            delete temp -> inscripcion;
            delete temp;
            eliminado = true;
        } else {
            aux = actual;
            actual = actual -> sgt;
        }
    }
    if (eliminado) {
        cout << endl << "Registro de cursos eliminados";
    }

}

void ListInscripciones::eliminarInscripCurso(int codigoCurso) {
    NodoInscripcion* actual = cabeza;
    NodoInscripcion* aux = nullptr;

    while (actual) {
        if (actual -> inscripcion -> curso -> getCodigo() == codigoCurso) {
            NodoInscripcion* temp = actual;
            if (aux != nullptr) {
                aux -> sgt = actual -> sgt;
            } else {
                cabeza = actual -> sgt;
            }
            actual = actual -> sgt;
            delete temp -> inscripcion;
            delete temp;
        } else {
            aux = actual;
            actual = actual -> sgt;
        }
    }
}

void ListInscripciones::mostrarInscripciones() {
    NodoInscripcion* actual = cabeza;

    if (!actual) {
        cout << endl << "No se encontraron inscripciones";
        return;
    }
    while(actual) {
        actual -> inscripcion -> mostrarInfo();
        actual = actual -> sgt;
    }

}

Inscripcion* ListInscripciones::buscarInscripcion(int idAlumno, int codigoCurso) {
    NodoInscripcion* actual = cabeza;
    while (actual) {
        if (actual -> inscripcion-> curso-> getCodigo() == codigoCurso && actual -> inscripcion-> alumno-> getId() == idAlumno) {
            return actual -> inscripcion;
        }
        actual = actual -> sgt;
    }
    return nullptr;
}