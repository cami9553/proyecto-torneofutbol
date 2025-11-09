#ifndef CLUB_H
#define CLUB_H
#include <string>


class Club {
    private:
    int _idClub;
    char _nombre[30];
    char _presidente[30];
    char _ciudad[30];

    public:
    Club();

    void setIdClub(int id);
    void setNombre(std::string nombre);
    void setPresidente(std::string presidente);
    void setCiudad(std::string ciudad);

    int getIdClub();
    const char* getNombre();
    const char* getPresidente();
    const char* getCiudad();

    void cargar();
    void mostrar();
};
#endif




