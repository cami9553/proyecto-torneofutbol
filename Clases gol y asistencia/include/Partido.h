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
        bool _jugado;


    public:
        Partido();
        Partido(int nroPartido, Fecha fecha, int idTorneo, int idClubLocal, int idClubVisitante, int golesLocal, int golesVisitante, bool j);
        void setNroPartido(int nro);
        void setFecha(Fecha fecha);
        void setIdTorneo(int id);
        void setIdClubLocal(int id);
        void setIdClubVisitante(int id);
        void setGolesLocal(int goles);
        void setGolesVisitante(int goles);
        void setJugado(bool j);
        int getNroPartido();
        Fecha getFecha();
        int getIdTorneo();
        int getIdClubLocal();
        int getIdClubVisitante();
        int getGolesLocal();
        int getGolesVisitante();
        bool getJugado();
        void cargar();
        void mostrar();

};

#endif // PARTIDO_H
