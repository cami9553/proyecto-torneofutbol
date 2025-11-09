#ifndef ARCHIVOPARTIDO_H_INCLUDED
#define ARCHIVOPARTIDO_H_INCLUDED

#include "Partido.h"
#include <fstream>

class ArchivoPartido {
    private:
    std::string _nombreArchivo;

    public: 
    ArchivoPartido(const std::string& nombreArchivo);

    bool guardadRegistro(const Partido& p);
    Partido leerRegistro(int nroRegistro);
    int getCantidadRegistros();
};

#endif 