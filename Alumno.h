#pragma once
#include <string>
using namespace std;

class Alumno {
    protected:
        int id;
        string nombre;
        string apellido;
        string carrera;
        string fechaIngreso;
    public:
        Alumno(int id, const string& nombre, const string& apellido, const string& carrera, const string& fechaIngreso); //CONSTRUCTOR

        int getId() const;
        string getNombre() const;
        string getApellido() const;
        string getCarrera() const;
        string getFechIngreso() const;
        void mostrarInfo();

        ~Alumno(){}
};
