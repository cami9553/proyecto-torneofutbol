#ifndef TORNEO_H_INCLUDED
#define TORNEO_H_INCLUDED

#include <iostream>

class Torneo {
    private:
    int _idTorneo;
    string _nombre;
    int _anio;

    public:
    Torneo();

    void setIdTorneo(int idTorneo);
    void setNombre(const string& nombre);
    void setAnio(int anio);


    int getIdTorneo();
    string getNombre();
    int getAnio();
};

#endif