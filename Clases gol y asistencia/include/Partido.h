#ifndef PARTIDO_H_INCLUDED
#define PARTIDO_H_INCLUDED
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
        Partido(int nroPartido, Fecha& fecha, int idTorneo, int idClubLocal, int idClubVisitante, int golesLocal, int golesVisitante);
        void setNroPartido(int nro);
        void setFecha(const Fecha& fecha);
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
