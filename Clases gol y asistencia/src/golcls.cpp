#include "golcls.h"


//Asignacion de valores y armado para visualizacion
golcls::golcls()
{
    _nroPartido = 3;
    _dnijugador = 12345678;
    _tipogol = 6;
}

asistenciacls::asistenciacls()
{
    _nroPartido = 8;
    _dnijugador = 987654;
}
/*golcls::golcls(int nroPartido, int dnijugador, int tipogol)
{
    _nroPartido = nroPartido ;
    _dnijugador = dnijugador;
    _tipogol = tipogol;
}*/

int golcls::getnroPartido()
{
    return _nroPartido;
}

int golcls::getdnijugador()
{
    return _dnijugador;
}

int golcls::gettipogol()
{
    return _tipogol;
}

int asistenciacls::getnroPartido()
{
    return _nroPartido;
}

int asistenciacls::getdnijugador()
{
    return _dnijugador;
}
