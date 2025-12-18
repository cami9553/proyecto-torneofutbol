#ifndef ARCHIVOJUGADOR_H_INCLUDED
#define ARCHIVOJUGADOR_H_INCLUDED

#include <string>
#include "Jugador.h"

class ArchivoJugador {
private:
    std::string _nombreArchivo;

public:
    ArchivoJugador(const std::string& nombreArchivo);

    int getCantidadRegistros();
    Jugador leerRegistro(int posicion);
    bool guardarRegistro(const Jugador& jugador);
    bool modificarRegistro(const Jugador& jugador, int posicion);
    void leerTodos(Jugador* vector, int cantidadRegistros);
    void listarRegistros();
    int buscarPorDni(int dni);
    bool eliminarRegistroFisico(int id);

};

#endif
