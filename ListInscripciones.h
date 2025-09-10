#pragma once
#include "NodoInscripcion.h"
using namespace std;

class ListInscripciones {
    private:
        NodoInscripcion* cabeza;
    public:
        ListInscripciones();

        bool agregarInscripcion(Alumno* alumno, Curso* curso);
        bool eliminarInscripcion(int idAlumno, int codigoCurso); //BORRAR UN CURSO ESPECIFICO DE UN ALUMNO EN PARTICULAR
        void eliminarInscripcionAlumno(int idAlumno); //SE UTILIZARA CUANDO SE ELIMINE AL ALUMNO Y HAYA QUE BORRAR SUS DATOS DEL SISTEMA
        void eliminarInscripCurso(int codigoCurso); //SE UTILIZARA CUANDO SE ELIMINE EL CURSO Y HAYA QUE ELIMINAR LAS INSCRIPCIONES DE CADA ALUMNO AL CURSO

        Inscripcion* buscarInscripcion(int idAlumno, int codigoCurso);
        void mostrarInscripciones();

        ~ListInscripciones();
};

