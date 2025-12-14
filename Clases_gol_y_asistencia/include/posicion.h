#ifndef POSICION_H
#define POSICION_H

class Posicion {
private:
    int idClub;
    char nombreClub[100];
    int partidosJugados;
    int ganados;
    int empatados;
    int perdidos;
    int golesAFavor;
    int golesEnContra;
    int puntos;

public:
    Posicion();
    void setIdClub(int id);
    void setNombre(const char *nombre);
    int getIdClub();
    const char *getNombre();
    void sumarPartido(int golesHechos, int golesRecibidos);
    int getPartidosJugados();
    int getGanados();
    int getEmpatados();
    int getPerdidos();
    int getGolesAFavor();
    int getGolesEnContra();
    int getDiferenciaGoles();
    int getPuntos();
};

#endif
