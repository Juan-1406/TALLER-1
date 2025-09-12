#pragma once
#include "Nota.h"

class NodoNota {
    public:
        Nota* nota;
        NodoNota* sgt;
        NodoNota(Nota* n);
};
