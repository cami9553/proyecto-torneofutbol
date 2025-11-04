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
        int getPosicion();
        int getIdClub();
        void setPosicion(int posicion);
        void setIdClub(int idClub);
           
};

#endif // JUGADOR_H
