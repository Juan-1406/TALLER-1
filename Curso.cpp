#include "Curso.h"
#include <iostream>
using namespace std;

Curso::Curso(int codigo, const string &nombre, int cantMaxima, const string &carrera, const string &profesor) {
    this -> codigo = codigo;
    this -> nombre = nombre;
    this -> cantMaxima = cantMaxima;
    this -> carrera = carrera;
    this -> profesor = profesor;
}

int Curso::getCodigo() const {return codigo;}
string Curso::getNombre() const {return nombre;}
int Curso::getCantMaxima() const {return cantMaxima;}
string Curso::getCarrera() const {return carrera;}
string Curso::getProfesor() const {return profesor;}

void Curso::mostrarInfo() {
    cout << endl << "Codigo: " << codigo << " | " << nombre << " | Max de Estudiantes: " << cantMaxima << " | Carrera: " << carrera << " | Profesor: " << profesor;
}






