#include <iostream>
#include "Alumno.h"
#include "ListAlumnos.h"
#include "ListCursos.h"
using namespace std;

ListAlumnos lista_alumnos;
ListCursos lista_cursos;

int opcion; int segOpcion; int id; int codigo;

void manejoAlumnos() {
    do {
        cout << endl << "--- MANEJO DE ALUMNOS ---" << endl;
        cout << "1. Crear Alumno" << endl << "2. Buscar Alumno" << endl << "3. Eliminar Alumno" << endl << "0. Salir" << endl;
        cout << "Ingrese una opcion:";
        cin >> opcion;

        switch(opcion) {
            case 0:
                cout << endl;
                break;

            case 1: {
                int fecha;
                string nombre; string apellido; string carrera;

                cout << "ID:"; cin >> id;
                if (lista_alumnos.buscarId(id)) {
                    cout << endl << "Ya existe un alumno/a con ese ID" << endl;
                    continue;
                }

                cout << "Nombre:"; cin >> nombre;
                cout << "Apellido:"; cin >> apellido;
                cout << "Carrera:"; cin >> carrera;
                cout << "Fecha Ingreso (YEAR):"; cin >> fecha;

                Alumno* alumno = new Alumno(id, nombre, apellido, carrera, fecha);
                lista_alumnos.agregarAlumno(alumno);
                cout  << endl << "Alumno/a creado con exito!" << endl;
                break;
            }

            case 2: {
                cout << "1. Por ID" << endl << "2. Por Nombre" << endl << "Ingrese una opcion:";
                cin >> segOpcion;

                if (segOpcion == 1) {
                    cout << "ID:"; cin >> id;

                    if (!lista_alumnos.buscarId(id)) {
                        cout << endl << "Alumno/a no encontrado" << endl;
                        continue;
                    }

                    Alumno* alumno = lista_alumnos.buscarId(id);
                    alumno->mostrarInfo();

                } else if (segOpcion == 2) {
                    string nombre;
                    cout << "Nombre:"; cin >> nombre;
                    lista_alumnos.mostrarNombres(nombre);
                }
                cout << endl;
                break;
            }

            case 3: {
                cout << "Ingrese ID a eliminar:"; cin >> id;
                lista_alumnos.eliminarAlumno(id);

                cout << endl;
                break;
            }
        }
    } while (opcion >= 1 && opcion <= 3);
}

void manejoCursos() {
    do {
        cout << endl << "--- MANEJO DE CURSOS ---" << endl;
        cout << "1. Crear Curso" << endl << "2. Buscar Curso" << endl << "3. Eliminar Curso" << endl << "0. Salir" << endl;
        cout << "Ingrese una opcion:";
        cin >> opcion;

        switch(opcion) {
            case 0:
                cout << endl;
                break;
            case 1: {
                int cantMaxima;
                string nombre; string carrera; string profesor;

                cout << "Codigo:"; cin >> codigo;
                if (lista_cursos.porCodigo(codigo)) {
                    cout << endl << "Ya existe un curso con ese codigo" << endl;
                    continue;
                }

                cout << "Nombre:"; cin >> nombre;
                cout << "Cantidad Maxima:"; cin >> cantMaxima;
                cout << "Carrera:"; cin >> carrera;
                cout << "Profesor:"; cin >> profesor;

                Curso* curso = new Curso(codigo, nombre, cantMaxima, carrera, profesor);
                lista_cursos.agregarCurso(curso);
                cout << endl << "Curso creado con exito!" << endl;
                break;
            }

            case 2: {
                cout << "1. Por Codigo" << endl << "2. Por Nombre" << endl << "Ingrese una opcion:";
                cin >> segOpcion;

                if (segOpcion == 1) {
                    cout << "Codigo:"; cin >> codigo;
                    if (!lista_cursos.porCodigo(codigo)) {
                        cout << endl << "Curso no encontrado" << endl;
                        continue;
                    }

                    Curso* curso = lista_cursos.porCodigo(codigo);
                    curso -> mostrarInfo();

                } else if(segOpcion == 2) {
                    string nombre;
                    cout << "Nombre:"; cin >> nombre;
                    lista_cursos.porNombre(nombre);
                }
                cout << endl;
                break;
            }
            case 3: {
                cout << "Ingrese CODIGO a eliminar:"; cin >> codigo;
                lista_cursos.eliminarCurso(codigo);
                break;
            }
        }
    } while(opcion >= 1 && opcion <= 3);
}

void manejoInscrip() {

    do {
        cout << endl << "--- MANEJO DE INSCRIPCIONES ---" << endl;
        cout << "1. Inscribir alumno a un curso" << endl << "2. Eliminar alumno de un curso" << endl << "0. Salir" << endl;
        cout << "Ingrese una opcion:";
        cin >> opcion;

        switch (opcion) {
            case 0:
                cout << endl;
                break;
            case 1:
                break;
            case 2:
                break;
        }

    } while (opcion >= 1 && opcion <= 2);


}

void manejoNotas() {

}

void consultReport() {
    do {
        cout << endl << "--- CONSULTAS Y REPORTES ---" << endl;
        cout << "1. Alumnos de una carrera " << endl << "2. Todos los cursos de un alumno" << endl << "3. Promedio de un alumno (1 curso)";
        cout << endl << "4. Promedio general de un alumno" << endl << "0. Salir" << endl;
        cout << "Ingrese una opcion:";
        cin >> opcion;

        switch(opcion) {
            case 0:
                cout << endl;
                break;
            case 1: {
                string carrera;
                cout << "Ingrese la carrera:"; cin >> carrera;
                lista_alumnos.mostrarAlumnosCarrera(carrera);
                cout << endl;
                break;
            }

            case 2: {

                break;
            }
            case 3: {

            }
            case 4: {

                break;
            }

        }
    } while(opcion >= 1 && opcion <= 4);
}

int main() {
    int opcion;
    do {
        //MENU PRINCIPAL
        cout << "--- MENu PRINCIPAL ---" << endl;
        cout << "1. Manejo de Alumnos" << endl << "2. Manejo de Cursos" << endl << "3. Manejo de Inscripciones" << endl;
        cout << "4. Manejo de Notas" << endl << "5. Consultas y Reportes" << endl << "0. Salir" << endl;

        cout << "Ingrese una opcion:";
        cin >> opcion;

        switch(opcion) {
            case 0:
                cout << endl << "Saliste con exito!";
                break;
            case 1:
                manejoAlumnos();
                break;
            case 2:
                manejoCursos();
                break;
            case 3:
                manejoInscrip();
                break;
            case 4:
                manejoNotas();
                break;
            case 5:
                consultReport();
                break;
        }
    } while (opcion >= 1 && opcion <= 5);

    return 0;
}