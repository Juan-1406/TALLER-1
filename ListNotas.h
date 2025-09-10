#pragma once
#include "NodoNota.h"

class ListNotas {
    private:
        NodoNota* cabeza;
    public:
        ListNotas();

        void agregarNota(double nota);
        double promedioNotas();
        void mostrarNotas();
        bool sinNotas();

        ~ListNotas();
};

