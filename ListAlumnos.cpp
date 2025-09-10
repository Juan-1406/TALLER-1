#include "ListAlumnos.h"
#include <iostream>

ListAlumnos::ListAlumnos() {
    cabeza = nullptr;
}

ListAlumnos::~ListAlumnos() {
    NodoAlumno* actual = cabeza;
    while (actual) {
        NodoAlumno* temp = actual;
        actual = actual -> sgt;
        delete temp -> alumno;
        delete temp;
    }
}

void ListAlumnos::agregarAlumno(Alumno* a) {
    NodoAlumno* nuevo = new NodoAlumno(a);
    nuevo -> sgt = cabeza;
    cabeza = nuevo;
}

Alumno* ListAlumnos::buscarId(int id) {
    NodoAlumno* actual = cabeza;
    while (actual) {
        if (actual -> alumno -> getId() == id) {
            return actual -> alumno;
        }
        actual = actual -> sgt;
    }
    return nullptr;
}

void ListAlumnos::mostrarNombres(const string &nombre) {
    NodoAlumno* actual = cabeza;
    bool encontrado = false;

    while (actual) {
        if (actual -> alumno -> getNombre() == nombre) {
            actual -> alumno -> mostrarInfo();
            encontrado = true;
        }
        actual = actual -> sgt;

    }
    if (!encontrado) {
        cout  << endl << "No se encontraron coincidencias para " << nombre;
    }
}

void ListAlumnos::eliminarAlumno(int id) {
    NodoAlumno* actual = cabeza;
    NodoAlumno* aux = nullptr;

    while (actual) {
        if (actual -> alumno -> getId() == id) {
            if (aux != nullptr) {
                aux -> sgt = actual -> sgt;
            } else {
                cabeza = actual -> sgt;
            }
            delete actual -> alumno;
            delete actual;
            cout << endl << "Alumno eliminado con exito!";
            return;
        }
        aux = actual;
        actual = actual -> sgt;

    }
    cout << endl << "Alumno no encontrado";
}

void ListAlumnos::mostrarAlumnosCarrera(const string &carrera) {
    NodoAlumno* actual = cabeza;
    bool siHay = false;

    while (actual) {
        if (actual -> alumno-> getCarrera() == carrera) {
            actual -> alumno -> mostrarInfo();
            siHay = true;
        }
        actual = actual -> sgt;
    }

    if (!siHay) {
        cout << endl << "No hay alumnos inscritos en " << carrera;
    }
}