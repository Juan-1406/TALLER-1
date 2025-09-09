#pragma once
#include <string>
using namespace std;

class Curso {
    protected:
        int codigo;
        string nombre;
        int cantMaxima;
        string carrera;
        string profesor;
    public:
        Curso(int codigo, const string& nombre, int cantMaxima, const string& carrera, const string& profesor); //CONSTRUCTOR

        int getCodigo() const;
        string getNombre() const;
        int getCantMaxima() const;
        string getCarrera() const;
        string getProfesor() const;

        void mostrarInfo();
        ~Curso(){}
};