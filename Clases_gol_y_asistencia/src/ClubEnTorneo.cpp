#include "ClubEnTorneo.h"

ClubEnTorneo::ClubEnTorneo(int id, const std::string& nom)
    : idClub(id), nombre(nom), PJ(0), G(0), E(0), P(0), GF(0), GC(0), DG(0), PTS(0) {}

// Getters
int ClubEnTorneo::getIdClub() const { return idClub; }
std::string ClubEnTorneo::getNombre() const { return nombre; }
int ClubEnTorneo::getPJ() const { return PJ; }
int ClubEnTorneo::getG() const { return G; }
int ClubEnTorneo::getE() const { return E; }
int ClubEnTorneo::getP() const { return P; }
int ClubEnTorneo::getGF() const { return GF; }
int ClubEnTorneo::getGC() const { return GC; }
int ClubEnTorneo::getDG() const { return DG; }
int ClubEnTorneo::getPTS() const { return PTS; }

// Setters 
void ClubEnTorneo::setNombre(const std::string& nom) { nombre = nom; }
void ClubEnTorneo::setPJ(int pj) { PJ = pj; }
void ClubEnTorneo::setG(int g) { G = g; }
void ClubEnTorneo::setE(int e) { E = e; }
void ClubEnTorneo::setP(int p) { P = p; }
void ClubEnTorneo::setGF(int gf) { GF = gf; DG = GF - GC; }
void ClubEnTorneo::setGC(int gc) { GC = gc; DG = GF - GC; }
void ClubEnTorneo::setPTS(int pts) { PTS = pts; }

// Actualizar resultados de un partido
void ClubEnTorneo::sumarPartido(int golesAFavor, int golesEnContra) {
    PJ++;
    GF += golesAFavor;
    GC += golesEnContra;
    DG = GF - GC;

    if (golesAFavor > golesEnContra) {
        G++;
        PTS += 3;
    } else if (golesAFavor < golesEnContra) {
        P++;
    } else {
        E++;
        PTS += 1;
    }
}

// Corregir oartidos 
void ClubEnTorneo::corregirPartido(int pj, int g, int e, int p, int gf, int gc, int pts) {
    PJ = pj;
    G = g;
    E = e;
    P = p;
    GF = gf;
    GC = gc;
    DG = GF - GC;
    PTS = pts;
}


