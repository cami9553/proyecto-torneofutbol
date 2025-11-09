#ifndef TORNEO_H
#define TORNEO_H

#include <iostream>

class Torneo {
private:
    int _idTorneo;
    char _nombre[30];
    int _anio;

public:
    
    Torneo();
    Torneo(int idTorneo, const char* nombre, int anio);
    void setIdTorneo(int idTorneo);
    void setNombre(const char* nombre);
    void setAnio(int anio);
    int getIdTorneo();
    const char* getNombre();
    int getAnio();
    void cargar();
    void mostrar();
};

#endif // TORNEO_H
