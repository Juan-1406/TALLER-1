#pragma once
#include "Curso.h"

class NodoCurso {
public:
    Curso* curso;
    NodoCurso* sgt;
    NodoCurso(Curso* c);
};

