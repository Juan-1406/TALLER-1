#pragma once
#include <iostream>
using namespace std;

class Nota {
    private:
        double nota;
    public:
        Nota(double nota);
        double getNota();
        void mostrarNota();
        ~Nota(){}
};

