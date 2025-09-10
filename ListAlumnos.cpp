#include "ListAlumnos.h"
#include <iostream>

ListAlumnos::ListAlumnos() {
    cabeza = nullptr;
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
        cout << "No se encontraron coincidencias para " << nombre << ".";
    }
}

void ListAlumnos::eliminarAlumno(int id) {
    NodoAlumno* actual = cabeza;
    NodoAlumno* aux = nullptr;
    bool encontrado = false;

    while (actual) {
        if (actual -> alumno -> getId() == id) {


            encontrado = true;
            cout << "Se elimino correctamente.";
        }
        actual = actual -> sgt;
    }
    if (!encontrado) {
        cout << "No se encontro el ID: " << id << ".";
    }
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
        cout << "No hay alumnos inscritos en " << carrera << ".";
    }

}