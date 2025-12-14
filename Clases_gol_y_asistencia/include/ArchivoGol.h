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
   ~ArchivoGol();

    //Getters
    int getCantidad() const;
    int getCantidadRegistros();

    //Operaciones principales
    bool guardarRegistro(const Gol& gol);
    Gol leerRegistro(int posicion);

    void agregarGol(const Gol& g);
    void cargarDesdeArchivo();
    void guardarEnArchivo();

    //Funcion de busqueda
    void buscarPorPartido(int idPartido);
};

#endif
