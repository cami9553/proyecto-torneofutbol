#ifndef GESTIONCLUB_H_INCLUDED
#define GESTIONCLUB_H_INCLUDED


#include "club.h"
using namespace std;

class GestionClub {
    private:
  Club _clubs[50];
  int _cantidad;

    public:
    void agregarClub(Club c);
    void listarClubs();
   Club* buscarClubPorId(int id);

};
#endif