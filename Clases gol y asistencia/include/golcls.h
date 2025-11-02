#ifndef GOLCLS_H
#define GOLCLS_H
#pragma once
#include <string>

class golcls
{
    private:
    int _nroPartido,_dnijugador,_tipogol;

    public:
        golcls();
        golcls(int nroPartido, int dnijugador, int tipogol);
        int getnroPartido();
        int getdnijugador();
        int gettipogol();
        void setnroPartido(int nroPartido);
        void setdnijugador(int dnijugador);
        void settipogol(int tipogol);


};

class asistenciacls
{
    private:
    int _nroPartido,_dnijugador,_tipogol;

    public:
        asistenciacls();
        asistenciacls(int nroPartido, int dnijugador);
        int getnroPartido();
        int getdnijugador();
        void setnroPartido(int nroPartido);
        void setdnijugador(int dnijugador);


};

#endif // GOLCLS_H
