#include "NodoAlumno.h"
#include <string>
using namespace std;

class ListAlumnos {
    private:
        NodoAlumno* cabeza;

    public:
        ListAlumnos();

        void agregarAlumno(Alumno* a);
        Alumno* buscarId(int id);
        void mostrarNombres(const string& nombre);
        void eliminarAlumno(int id);
        void mostrarAlumnosCarrera(const string& carrera);

        ~ListAlumnos();
};