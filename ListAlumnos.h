#include "NodoAlumno.h"
#include <string>
using namespace std;

class ListAlumnos {
    private:
        NodoAlumno* cabeza;

    public:
        ListAlumnos();

        void agregarAlumno(Alumno* a); //LISTO
        Alumno* buscarId(int id); //LISTO
        void mostrarNombres(const string& nombre); //PARA CUANDO SE BUSCA ALUMNO POR EL NOMBRE //LISTO
        void eliminarAlumno(int id);
        void mostrarAlumnosCarrera(const string& carrera);

        ~ListAlumnos(){};
};