#ifndef ARCHIVOCLUB_H
#define ARCHIVOCLUB_H

#include <string>
#include "Club.h"
#include "Torneo.h"

class ArchivoClub{
    private:
        std::string _nombreArchivo;
        Club* clubes;
        int cantidadClubes;

    public:
        ArchivoClub(const std::string& nombreArchivo = "clubes.dat");
        ~ArchivoClub();
        void cargarDesdeArchivo();
        bool guardar(Club club);
        bool actualizar(Club club, int posicion);
        int buscar(int idClub);
        Torneo leer(int posicion);
        int cantidadRegistros();
        void leer(int cantidadRegistros, Club *vector);
        Club leerRegistro(int posicion);
        Club* buscarPorId(int id);
        Club* getClubes()const;

};
#endif // ARCHIVOCLUB_H
