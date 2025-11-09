#ifndef JUGADOR_H
#define JUGADOR_H

#include "Persona.h"


class Jugador: public Persona
{
    private:
        int _posicion;
        int _idClub;

    public:
        Jugador();
        Jugador(int posicion, int idClub, int dni, const char* apellido, const char* nombre, const char* telefono, const char* email, Fecha fechaNacimiento);
        int getPosicion();
        int getIdClub();
        void setPosicion(int posicion);
        void setIdClub(int idClub);
        //Otros metodos
        void cargar();
        void mostrar();

};

#endif // JUGADOR_H
