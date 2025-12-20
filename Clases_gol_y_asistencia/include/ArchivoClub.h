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
        int CantidadRegistros();
        void leer(int CantidadRegistros, Club *vector);
        void listarRegistros();
        bool modificarRegistro(const Club& club, int posicion);
        Club leerRegistro(int posicion);
        Club* buscarPorId(int id);
        Club* getClubes()const;
        bool eliminarRegistroFisico(int id);


};
#endif // ARCHIVOCLUB_H
