#ifndef CLUBENTORNEO_H
#define CLUBENTORNEO_H

#include <string>

class ClubEnTorneo {
private:
    int idClub;
    std::string nombre;
    int PJ;  // Partidos jugados
    int G;   // Ganados
    int E;   // Empatados
    int P;   // Perdidos
    int GF;  // Goles a favor
    int GC;  // Goles en contra
    int DG;  // Diferencia de goles
    int PTS; // Puntos

public:

    ClubEnTorneo(int id = 0, const std::string& nom = "");

    int getIdClub() const;
    std::string getNombre() const;
    int getPJ() const;
    int getG() const;
    int getE() const;
    int getP() const;
    int getGF() const;
    int getGC() const;
    int getDG() const;
    int getPTS() const;

    void setNombre(const std::string& nom);
    void setPJ(int pj);
    void setG(int g);
    void setE(int e);
    void setP(int p);
    void setGF(int gf);
    void setGC(int gc);
    void setPTS(int pts);

    // metodo para actualizar resultados de un partido
    void sumarPartido(int golesAFavor, int golesEnContra);

    // metodo para correcion manual de TODOS los datos del club
    void corregirPartido(int pj, int g, int e, int p, int gf, int gc, int pts);
};

#endif
