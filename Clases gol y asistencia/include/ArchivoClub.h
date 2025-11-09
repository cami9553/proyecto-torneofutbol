#ifndef ARCHIVOCLUB_H
#define ARCHIVOCLUB_H

#include <string>
#include "Club.h"

class ArchivoClub{
    private:
        std::string _nombreArchivo;
        
    public:
        ArchivoClub(std::string nombreArchivo);
        bool Guardar(Club club);
        bool Guardar(Club club, int posicion);
        int Buscar(int idClub);
        Torneo Leer(int posicion);
        int CantidadRegistros();
        void Leer(int cantidadRegistros, Club *vector);
};
#endif // ARCHIVOCLUB_H
