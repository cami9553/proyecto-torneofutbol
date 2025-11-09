#ifndef PARTIDO_H
#define PARTIDO_H
#include "Fecha.h"

class Partido
{
    private:
        int _nroPartido;
        Fecha _fecha;
        int _idTorneo;
        int _idClubLocal;
        int _idClubVisitante;
        int _golesLocal;
        int _golesVisitante;
    

    public:
        Partido();
        void setNroPartido(int nro);
        void setFecha(Fecha fecha);
        void setIdTorneo(int id);
        void setIdClubLocal(int id);
        void setIdClubVisitante(int id);
        void setGolesLocal(int goles);
        void setGolesVisitante(int goles);
        int getNroPartido();
        Fecha getFecha();
        int getIdTorneo();
        int getIdClubLocal();
        int getIdClubVisitante();
        int getGolesLocal();
        int getGolesVisitante();
        void cargar();
        void mostrar();
            
};

#endif // PARTIDO_H
