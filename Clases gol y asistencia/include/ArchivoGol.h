#ifndef ARCHIVOGOL_H
#define ARCHIVOGOL_H

#include <string>
#include "Gol.h"

class ArchivoGol {
private:
    Gol* _goles;
    int _cantidadGoles;
    std::string _nombreArchivo;

public:
    ArchivoGol(const std::string& nombreArchivo);
   bool guardarRegistro(const Gol& gol);
   Gol leerRegistro(int posicion);
   int getCantidadRegistros();
   ~ArchivoGol();

    int getCantidad() const;
    void agregarGol(const Gol& g);
    void buscarPorPartido(int idPartido);
    void cargarDesdeArchivo();
    void guardarEnArchivo();
};

#endif
