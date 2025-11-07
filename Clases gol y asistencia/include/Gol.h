#ifndef GOL_H
#define GOL_H
#pragma once
#include <string>

class Gol
{
    private:
    int _nroPartido,_dniJugador,_tipoGol;

    public:
        Gol();
        Gol(int nroPartido, int dniJugador, int tipoGol);
        int getNroPartido();
        int getDniJugador();
        int getTipoGol();
        void setNroPartido(int nroPartido);
        void setDniJugador(int dniJugador);
        void setTipoGol(int tipoGol);


};

#endif
