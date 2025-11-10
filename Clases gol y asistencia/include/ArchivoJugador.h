#ifndef ARCHIVOJUGADOR_H
#define ARCHIVOJUGADOR_H

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
    int buscarPorId(int dni);
};

#endif
