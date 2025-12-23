#ifndef JUGADOR_H
#define JUGADOR_H

#include "Persona.h"
#include <string>

class Jugador : public Persona
{
private:
    int _posicion;
    int _idClub;

public:
     Jugador();
    Jugador(int posicion, int idClub, int id, int dni,
            const char* apellido, const char* nombre,
            const char* telefono, const char* email,
            Fecha fechaNacimiento);
    int getPosicion();
    int getIdClub();
    void setPosicion(int posicion);
    void setIdClub(int idClub);

    bool cargar();
    void mostrar();

    bool esValido() const {
        return getId() > 0 && getId() < 1000000;
    }
};

#endif // JUGADOR_H

