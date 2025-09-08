#include "Alumno.h"
#include <iostream>
using namespace std;

Alumno::Alumno(int id, const string &nombre, const string &apellido, const string &carrera, const string &fechaIngreso) {
    this -> id = id;
    this -> nombre  = nombre;
    this -> apellido = apellido;
    this -> carrera = carrera;
    this -> fechaIngreso = fechaIngreso;
}

int Alumno::getId() const {return id;}
string Alumno::getNombre() const {return nombre;}
string Alumno::getApellido() const {return apellido;}
string Alumno::getCarrera() const {return carrera;}
string Alumno::getFechIngreso() const {return fechaIngreso;}

void Alumno::mostrarInfo() {
    cout << "ID: " << id << " | " << nombre << " " << apellido << " | Carrera: " << carrera << " | Fecha Ingreso: " << fechaIngreso << endl;
}