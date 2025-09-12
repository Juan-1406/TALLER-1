#pragma once
#include "NodoCurso.h"
#include <string>
using namespace std;

class ListCursos {
    private:
    NodoCurso* cabeza;
    public:
        ListCursos();

        void agregarCurso(Curso* c);
        Curso* porCodigo(int codigo);
        void porNombre(const string& nombre);
        void eliminarCurso(int codigo);

        ~ListCursos();

};

