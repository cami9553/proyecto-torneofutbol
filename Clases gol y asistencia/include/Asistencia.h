#ifndef ASISTENCIA_H
#define ASISTENCIA_H


class Asistencia {
private:
    int _nroPartido;
    int _dniJugador;

public:
    // Getters
    int getNroPartido();
    int getDniJugador();

    // Setters
    void setNroPartido(int nro);
    void setDniJugador(int dni);

    void cargar();
};

#endif

