#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

#include <string>


class Fecha {
private:
    int _dia;
    int _mes;
    int _anio;

public:
    Fecha();
    Fecha(int dia, int mes, int anio);
    // Getters
    int getDia();
    int getMes();
    int getAnio();

    // Setters
    void setDia(int d);
    void setMes(int m);
    void setAnio(int a);
    std::string toString();

    //Otros metodos
    void cargar();
};

#endif
