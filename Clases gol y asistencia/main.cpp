#include <iostream>
#include "golcls.h"
#include "club.h"
#include "gestionClub.h"
using namespace std;

int main()
{
    //Prueba para visualizar datos
    golcls gol1;
    asistenciacls asistenciacls1;
    std::cout << gol1.getnroPartido() << endl;
    std::cout << gol1.getdnijugador() << endl;
    std::cout << gol1.gettipogol() << endl;
    cout << endl;
    std::cout << asistenciacls1.getnroPartido() << endl;
    std::cout << asistenciacls1.getdnijugador() << endl;

  cout << "\n\n==== PRUEBA DE CLUBES ====\n";


    GestionClub gestion;

    Club c1(1, "Club A", "Presidente A", "Ciudad A");
    Club c2(2, "Club B", "Presidente B", "Ciudad B");

    gestion.agregarClub(c1);
    gestion.agregarClub(c2);

    gestion.listarClubs();

    return 0;
}
