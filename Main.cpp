#include <iostream>
using namespace std;

void manejoAlumnos() {
    int opcion;

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
                int id;
                string nombre; string apellido; string carrera; string fecha;

                cout << "ID:"; cin >> id;
                cout << "Nombre:"; cin >> nombre;
                cout << "Apellido:"; cin >> apellido;
                cout << "Carrera:"; cin >> carrera;
                cout << "Fecha Ingreso (DD/MM/AA):"; cin >> fecha;

                Alumno* alumno = new Alumno(id, nombre, apellido, carrera, fecha);
                break;
            }
            case 2: {
                int segOpcion;
                cout << "1. Por ID" << endl << "2. Por Nombre" << endl << "Ingrese una opcion:";
                cin >> segOpcion;

                if (segOpcion == 1) {
                    int id;
                    cout << "ID:";
                    cin >> id;

                } else if (segOpcion == 2) {
                    string nombre;
                    cout << "Nombre:";
                    cin >> nombre; cout << nombre;
                }
                break;
            }
            case 3: {
                break;
            }
        }
    } while (opcion >= 1 && opcion <= 3);
}

void manejoCursos() {
    int opcion;

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
                string codigo; string nombre; string carrera; string profesor;

                cout << "Codigo:"; cin >> codigo;
                cout << "Nombre:"; cin >> nombre;
                cout << "Cantidad Maxima:"; cin >> cantMaxima;
                cout << "Carrera:"; cin >> carrera;
                cout << "Profesor:"; cin >> profesor;

                Curso* curso = new Curso(codigo, nombre, cantMaxima, carrera, profesor);
                break;
            }
            case 2: {
                int segOpcion;
                cout << "1. Por ID" << endl << "2. Por Nombre" << endl << "Ingrese una opcion:";
                cin >> segOpcion;

                if (segOpcion == 1) {
                    int id;
                    cout << "ID:";
                    cin >> id;

                } else if (segOpcion == 2) {
                    string nombre;
                    cout << "Nombre:";
                    cin >> nombre; cout << nombre;
                }
                break;
            }
            case 3: {
                break;
            }
        }
    } while(opcion >= 1 && opcion <= 3);
}

void manejoInscrip() {

}

void manejoNotas() {

}

void consultReport() {

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
                cout << "Saliste con exito!";
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