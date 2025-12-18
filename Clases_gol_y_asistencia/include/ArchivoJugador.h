#ifndef ARCHIVOJUGADOR_H_INCLUDED
#define ARCHIVOJUGADOR_H_INCLUDED

#include <string>
#include "Jugador.h"

class ArchivoJugador {
private:
    std::string _nombreArchivo;

public:
    ArchivoJugador(const std::string& nombreArchivo);

    void inicializarUltimoId();
    int getCantidadRegistros();
    Jugador leerRegistro(int posicion);
    bool guardarRegistro(const Jugador& jugador);
    bool modificarRegistro(const Jugador& jugador, int posicion);
    void leerTodos(Jugador* vector, int cantidadRegistros);
    void listarNombreApellido();
    void listarJugadorPorClub(int idClub);
    void listarRegistros();
    int buscarPorDni(int dni);
    int obtenerDni(int idJugador);
    bool eliminarRegistroFisico(int id);

};

#endif
