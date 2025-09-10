#include "Nota.h"

Nota::Nota(double nota) {
    this -> nota = nota;
}

double Nota::getNota() {
    return nota;
}

void Nota::mostrarNota() {
    cout << nota << " | ";
}
