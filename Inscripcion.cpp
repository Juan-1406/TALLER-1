#include "Inscripcion.h"

Inscripcion::Inscripcion(Alumno *a, Curso *c) {
    alumno = a;
    curso = c;
}

double Inscripcion::promedio() {
    return notaas.promedioNotas();
}

void Inscripcion::mostrarInfo() {
    cout << endl << "ID Alumno: " << alumno -> getId() << " - " << alumno -> getNombre() << " " << alumno -> getApellido();
    cout << " | Curso: " << curso -> getCodigo() << " - " << curso -> getNombre() << endl << "Notas: ";
    notaas.mostrarNotas();
}

void Inscripcion::obtenerPromedio() {
    if (!notaas.sinNotas()) {
        cout << endl << "Promedio del curso " << curso -> getNombre() <<  ": " << promedio() << endl;
    }
}
