#include <iostream>
#include <limits>
#include <string>
#include "Alumno.h"
#include "ListAlumnos.h"
#include "ListCursos.h"
#include "ListNotas.h"
#include "ListInscripciones.h"
using namespace std;

ListAlumnos lista_alumnos;
ListCursos lista_cursos;
ListNotas lista_notas;
ListInscripciones lista_inscripciones;

int opcion; int segOpcion; int id; int codigo;

void limpiar() { //NECESARIO PARA QUE PUEDA FUNCIONAR CORRECTAMENTE EL GETLINE
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int verificarNum(int num, int op) { //PARA VERIFICAR QUE TANTO EL ID COMO CODIGO SEA MAYOR A 0

    if (op == 0) { //PARA CUANDO TIENE QUE VER CON LA OPCION ELEGIDA
        while (true) {
            if (cin.fail()) {
                cin.clear();
                limpiar();
                cout << "Se debe ingresar un numero" << endl;
                cout << "Reingrese una opcion:"; cin >> num;
                continue;
            }
            break;
        }
        return num;

    }

    if (op == 1) { //PARA CUANDO TIENE QUE VER CON EL ID
        while (true) {
            if (cin.fail()) {
                cin.clear();
                limpiar();
                cout << "Se debe ingresar un numero" << endl;
                cout << "Reingrese un ID:"; cin >> num;
                continue;
            }

            if (num < 1) {
                cout << "El ID debe ser mayor a 0" << endl;
                cout << "Reingrese un ID:"; cin >> num;
                continue;
            }
            break;
        }
        return num;
    }

    if (op == 2) { //PARA CUANDO TIENE QUE VER CON EL CODIGO
        while (true) {
            if (cin.fail()) {
                cin.clear();
                limpiar();
                cout << "Se debe ingresar un numero" << endl;
                cout << "Reingrese un Codigo:"; cin >> num;
                continue;
            }

            if (num < 1) {
                cout << "El codigo debe ser mayor a 0" << endl;
                cout << "Reingrese un Codigo:"; cin >> num;
                continue;
            }
            break;
        }
        return num;
    }

    if (op == 3) { //PARA CUANDO TIENE QUE VER CON LA FECHa
        while (true) {
            if (cin.fail()) {
                cin.clear();
                limpiar();
                cout << "Se debe ingresar un numero" << endl;
                cout << "Reingrese una Fecha (YEAR):"; cin >> num;
                continue;
            }

            if (num < 1) {
                cout << "La fecha debe ser mayor a 0" << endl;
                cout << "Reingrese una Fecha (YEAR):"; cin >> num;
                continue;
            }
            break;
        }
        return num;
    }

    if (op == 4) { //PARA CUANDO TIENE QUE VER CON LA CAPACIDA DMAXIMA
        while (true) {
            if (cin.fail()) {
                cin.clear();
                limpiar();
                cout << "Se debe ingresar un numero" << endl;
                cout << "Reingrese una cantidad maxima:"; cin >> num;
                continue;
            }

            if (num < 1) {
                cout << "La cantidad debe ser mayor a 0" << endl;
                cout << "Reingrese una cantidad maxima:"; cin >> num;
                continue;
            }
            break;
        }
        return num;
    }

    if (op == 5) { //PARA CUANDO TIENE QUE VER CON LA CANTIDAD DE NOTAS
        while (true) {
            if (cin.fail()) {
                cin.clear();
                limpiar();
                cout << "Se debe ingresar un numero" << endl;
                cout << "Reingrese una cantidad de notas:"; cin >> num;
                continue;
            }

            if (num < 1) {
                cout << "La cantidad debe ser mayor o igual a 1" << endl;
                cout << "Reingrese una cantidad de notas:"; cin >> num;
                continue;
            }
            break;
        }
        return num;
    }
}

void manejoAlumnos() {
    do {
        cout << endl << "--- MANEJO DE ALUMNOS ---" << endl;
        cout << "1. Crear Alumno" << endl << "2. Buscar Alumno" << endl << "3. Eliminar Alumno" << endl << "0. Salir" << endl;
        cout << "Ingrese una opcion:"; cin >> opcion;
        opcion = verificarNum(opcion, 0);

        switch(opcion) {
            case 0:
                cout << endl;
                break;

            case 1: {
                int fecha;
                string nombre; string apellido; string carrera;

                cout << "ID:"; cin >> id;
                id = verificarNum(id,1);

                if (lista_alumnos.buscarId(id)) {
                    cout << endl << "Ya existe un alumno/a con ese ID" << endl;
                    continue;
                }
                limpiar();

                cout << "Nombre:"; getline(cin, nombre);
                cout << "Apellido:"; getline(cin, apellido);
                cout << "Carrera:"; getline(cin, carrera);
                cout << "Fecha Ingreso (YEAR):"; cin >> fecha;
                fecha = verificarNum(fecha,3);

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
                    id = verificarNum(id,1);

                    if (!lista_alumnos.buscarId(id)) {
                        cout << endl << "Alumno/a no encontrado" << endl;
                        continue;
                    }

                    Alumno* alumno = lista_alumnos.buscarId(id);
                    alumno->mostrarInfo();

                } else if (segOpcion == 2) {
                    string nombre;
                    limpiar();
                    cout << "Nombre:"; getline(cin, nombre);
                    lista_alumnos.mostrarNombres(nombre);
                }
                cout << endl;
                break;
            }

            case 3: {
                cout << "Ingrese ID a eliminar:"; cin >> id;
                id = verificarNum(id,1);

                lista_inscripciones.eliminarInscripcionAlumno(id);
                lista_alumnos.eliminarAlumno(id);
                cout << endl;
                break;
            }
            default:
                cout << endl << "- Opcion invalida -" << endl << endl;
        }
    } while (opcion >= 1 && opcion <= 3);
}

void manejoCursos() {

    do {
        cout << endl << "--- MANEJO DE CURSOS ---" << endl;
        cout << "1. Crear Curso" << endl << "2. Buscar Curso" << endl << "3. Eliminar Curso" << endl << "0. Salir" << endl;
        cout << "Ingrese una opcion:"; cin >> opcion;
        opcion = verificarNum(opcion, 0);

        switch(opcion) {
            case 0:
                cout << endl;
                break;

            case 1: {
                int cantMaxima;
                string nombre; string carrera; string profesor;

                cout << "Codigo:"; cin >> codigo;
                codigo = verificarNum(codigo,2);

                if (lista_cursos.porCodigo(codigo)) {
                    cout << endl << "Ya existe un curso con ese codigo" << endl;
                    continue;
                }
                limpiar();

                cout << "Nombre:"; getline(cin, nombre);
                cout << "Cantidad Maxima:"; cin >> cantMaxima;
                cantMaxima = verificarNum(cantMaxima, 4);
                limpiar();
                cout << "Carrera:"; getline(cin, carrera);
                cout << "Profesor:"; getline(cin, profesor);

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
                    codigo = verificarNum(codigo,2);
                    if (!lista_cursos.porCodigo(codigo)) {
                        cout << endl << "Curso no encontrado" << endl;
                        continue;
                    }

                    Curso* curso = lista_cursos.porCodigo(codigo);
                    curso -> mostrarInfo();

                } else if(segOpcion == 2) {
                    string nombre;
                    limpiar();
                    cout << "Nombre:"; getline(cin, nombre);
                    lista_cursos.porNombre(nombre);
                }
                cout << endl;
                break;
            }

            case 3: {
                cout << "Ingrese CODIGO a eliminar:"; cin >> codigo;
                codigo = verificarNum(codigo,2);
                lista_inscripciones.eliminarInscripCurso(codigo);
                lista_cursos.eliminarCurso(codigo);
                cout << endl;
                break;
            }
            default:
                cout << endl << "- Opcion invalida -" << endl << endl;
        }
    } while(opcion >= 1 && opcion <= 3);
}

void manejoInscrip() {

    do {
        cout << endl << "--- MANEJO DE INSCRIPCIONES ---" << endl;
        cout << "1. Inscribir alumno a un curso" << endl << "2. Eliminar alumno de un curso" << endl << "0. Salir" << endl;
        cout << "Ingrese una opcion:"; cin >> opcion;
        opcion = verificarNum(opcion, 0);

        switch (opcion) {
            case 0:
                cout << endl;
                break;

            case 1: {
                cout << "Ingrese ID del alumno:"; cin >> id;
                id = verificarNum(id,1);
                cout << "Ingrese CODIGO del curso:"; cin >> codigo;
                codigo = verificarNum(codigo,2);

                Alumno* alumno = lista_alumnos.buscarId(id);
                Curso* curso = lista_cursos.porCodigo(codigo);

                if (alumno == nullptr) {
                    cout << endl << "El alumno/a no existe" << endl;
                    continue;
                }
                if (curso == nullptr) {
                    cout << endl << "El curso no existe" << endl;
                    continue;
                }

                if (alumno -> getCarrera() != curso -> getCarrera()) {
                    cout << endl << "Deben pertenecer a la misma carrera" << endl;
                    continue;
                }

                bool  inscrito = lista_inscripciones.agregarInscripcion(alumno, curso);
                if (inscrito) {
                    cout << endl << "Inscripcion realizada!";
                } else {
                    cout << endl << "No se pudo inscribir (Ya esta inscrito o no hay cupos)";
                }
                cout << endl;
                break;
            }

            case 2: {
                cout << "Ingrese ID del alumno:"; cin >> id;
                id = verificarNum(id,1);
                cout << "Ingrese CODIGO del curso:"; cin >> codigo;
                codigo = verificarNum(codigo,2);

                Alumno* alumno = lista_alumnos.buscarId(id);
                Curso* curso = lista_cursos.porCodigo(codigo);

                if (alumno == nullptr) {
                    cout << endl << "El alumno/a no existe" << endl;
                    continue;
                }
                if (curso == nullptr) {
                    cout << endl << "El curso no existe" << endl;
                    continue;
                }

                if (alumno -> getCarrera() != curso -> getCarrera()) {
                    cout << endl << "Deben pertenecer a la misma carrera" << endl;
                    continue;
                }

                bool  inscrito = lista_inscripciones.eliminarInscripcion(id, codigo);
                if (inscrito) {
                    cout << endl << "Inscripcion eliminada con exito!";
                } else {
                    cout << endl << "Inscripcion no encontrada";
                }
                cout << endl;
                break;
            }
            default:
                cout << endl << "- Opcion invalida -" << endl << endl;
        }

    } while (opcion >= 1 && opcion <= 2);
}

void manejoNotas() {

    do {
        cout << endl << "--- MANEJO DE NOTAS ---" << endl;
        cout << "1. Registrar Nota/s " << endl << "0. Salir" << endl;
        cout << "Ingrese la opcion:"; cin >> opcion;
        opcion = verificarNum(opcion, 0);

        switch (opcion) {
            case 0:
                cout << endl;
                break;

            case 1: {
                cout << "Ingrese ID del alumno:"; cin >> id;
                id = verificarNum(id,1);
                cout << "Ingrese CODIGO del curso:"; cin >> codigo;
                codigo = verificarNum(codigo,2);

                Inscripcion* inscripcion = lista_inscripciones.buscarInscripcion(id, codigo);

                if (!inscripcion) {
                    cout << endl << "Inscripcion no encontrada" << endl;
                    continue;
                }

                int cant = 0;
                cout << "Cantidad de notas a ingresar:"; cin >> cant;
                cant = verificarNum(cant,5);

                for (int i = 0; i < cant; i++) {
                    double nota;
                    cout << "Nota " << (i + 1) << " (1.0 a 7.0):"; cin >> nota;

                    while (true) {
                        if (cin.fail()) {
                            cin.clear();
                            limpiar();
                            cout << "Se debe ingresar un numero" << endl;
                            cout << "Reingrese la Nota:"; cin >> nota;
                            continue;
                        }
                        break;
                    }if (nota >= 1.0 && nota <= 7.0){
                        inscripcion -> notaas.agregarNota(nota);
                    } else {
                        cout << "Nota invalida";
                    }


                }
                break;
            }
            default:
                cout << endl << "- Opcion invalida -" << endl << endl;
        }
    }while (opcion == 1);
}

void consultReport() {

    do {
        cout << endl << "--- CONSULTAS Y REPORTES ---" << endl;
        cout << "1. Alumnos de una carrera " << endl << "2. Todos los cursos de un alumno" << endl << "3. Promedio de un alumno (1 curso)";
        cout << endl << "4. Promedio general de un alumno" << endl << "0. Salir" << endl;
        cout << "Ingrese una opcion:"; cin >> opcion;
        opcion = verificarNum(opcion, 0);

        switch(opcion) {
            case 0:
                cout << endl;
                break;

            case 1: {
                string carrera;
                limpiar();
                cout << "Ingrese la carrera:"; getline(cin, carrera);
                lista_alumnos.mostrarAlumnosCarrera(carrera);
                cout << endl;
                break;
            }

            case 2: {
                cout << "Ingrese ID del alumno:"; cin >> id;
                id = verificarNum(id,1);
                lista_inscripciones.cursosAlumno(id);
                break;
            }

            case 3: {
                cout << "Ingrese ID del alumno:"; cin >> id;
                id = verificarNum(id,1);
                cout << "Ingrese CODIGO del curso:"; cin >> codigo;
                codigo = verificarNum(codigo,2);

                Inscripcion* inscripcion = lista_inscripciones.buscarInscripcion(id, codigo);

                if (!inscripcion) {
                    cout << endl << "Inscripcion no encontrada" << endl;
                    continue;
                }
                inscripcion -> obtenerPromedio();
                break;
            }

            case 4: {
                cout << "Ingrese ID del alumno:"; cin >> id;
                id = verificarNum(id,1);
                double promedioGeneral = lista_inscripciones.promedioGeneral(id);
                cout << endl << "El promedio general del alumno es: " << promedioGeneral << endl;
                break;
            }
            default:
                cout << endl << "- Opcion invalida -" << endl << endl;
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
        cout << "Ingrese una opcion:"; cin >> opcion;
        opcion = verificarNum(opcion, 0);

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
            default:
                cout << endl << "- Opcion invalida -";
        }
    } while (opcion >= 1 && opcion <= 5);
    return 0;
}