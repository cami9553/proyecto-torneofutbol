#ifndef ARCHIVOTORNEO_H
#define ARCHIVOTORNEO_H

#include <string>
#include "Torneo.h"

class ArchivoTorneo{
    private:
        std::string _nombreArchivo;

    public:
        ArchivoTorneo(std::string nombreArchivo);
        bool Guardar(Torneo torneo);
        bool Guardar(Torneo torneo, int posicion);
        int Buscar(int idTorneo);
        Torneo Leer(int posicion);
        int CantidadRegistros();
        void Leer(int cantidadRegistros, Torneo *vector);
        void crearFixture(int idTorneo = 1);
};
#endif // ARCHIVOTORNEO_H
