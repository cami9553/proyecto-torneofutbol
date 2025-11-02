#include <iostream>
#include "golcls.h"
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
    return 0;
}
