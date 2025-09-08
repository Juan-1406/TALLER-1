#pragma once
#include <string>
using namespace std;

class Curso {
    protected:
        string codigo;
        string nombre;
        int cantMaxima;
        string carrera;
        string profesor;
    public:
        Curso(const string& codigo, const string& nombre, int cantMaxima, const string& carrera, const string& profesor); //CONSTRUCTOR

        string getCodigo() const;
        string getNombre() const;
        int getCantMaxima() const;
        string getCarrera() const;
        string getProfesor() const;

        void mostrarInfo();
        ~Curso(){}
};