#ifndef GESTIONCLUB_H_INCLUDED
#define GESTIONCLUB_H_INCLUDED

#include <vector>
#include "club.h"


using namespace std;

class GestionClub {
    private:
   std::vector<Club> _clubs;

    public:
    void agregarClub(Club c);
    void listarClubs();
   Club* buscarClubPorId(int id);

};
#endif