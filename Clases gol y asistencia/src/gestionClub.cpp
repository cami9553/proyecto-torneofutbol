#include "gestionClub.h"
#include <iostream>
using namespace std;

void GestionClub::agregarClub(Club c){
    _clubs.push_back(c);

}

void GestionClub::listarClubs(){
    for(Club &c : _clubs){
        c.mostrar();
        cout <<"-------------------"<<endl;
    }
}

Club* GestionClub::buscarClubPorId(int id){
    for(Club &c : _clubs){
        if(c.getIdClub() == id)
        return &c;
    }

return nullptr;
}