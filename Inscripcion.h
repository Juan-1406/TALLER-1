#pragma once
#include "Alumno.h"
#include "Curso.h"
#include "ListNotas.h"
using namespace std;

class Inscripcion {
    public:
        Alumno* alumno;
        Curso* curso;
        ListNotas notaas;

        Inscripcion(Alumno* a, Curso* c);
        double promedio();
        void mostrarInfo();
        void obtenerPromedio();

        ~Inscripcion(){}
};


