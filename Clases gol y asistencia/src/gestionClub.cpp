#include "gestionClub.h"
#include <iostream>
using namespace std;

GestionClub::GestionClub() {
    _cantidad = 0;
}

void GestionClub::agregarClub(Club c) {
    if (_cantidad < 50) {
        _clubs[_cantidad] = c;
        _cantidad++;
    } else {
        cout <<"No se pueden agregar mas clubes (limite alcanzado)"<<endl;
    }
    
}

void GestionClub::listarClubs() {
    for (int i = 0; i < _cantidad; i++) {
        _clubs[i].mostrar();
        cout << "------------------------" << endl;
}
}

Club* GestionClub::buscarClubPorId(int id) {
    for (int i = 0; i < _cantidad; i++) {
        if (_clubs[i].getIdClub() == id)
        return &_clubs[i];

    }
    return nullptr;
}
