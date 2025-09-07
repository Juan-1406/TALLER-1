#pragma once
#include "Alumno.h"

class NodoAlumno {
public:
    Alumno* alumno;
    NodoAlumno* sgt;
    NodoAlumno(Alumno* a);
};