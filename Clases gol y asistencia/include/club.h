#ifndef CLUB_H_INCLUDED
#define CLUB_H_INGLUDED

#include <string>
#include <vector>
#include <jugador.h>
using namespace std;

class Club {
    private:
    int _idClub;
    string _nombre;
    string _presidente;
    string _ciudad;
    vector<Jugador> _jugadores;

    public:
    Club();
    Club(int idClub, string nombre, string presidente, string ciudad);

    void setIdClub(int idClub);
    void setNombre(string nombre);
    void setPresidente(string presidente);
    void setCiudad(string ciudad);

    int getIdClub();
    string getNombre();
    string getPresidente();
    string getCiudad();

    void agregarJugador(Jugador j);
    void mostrar();


};
#endif