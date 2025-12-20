#ifndef VALIDACIONES_H
#define VALIDACIONES_H
#include <string>

int leerEnteroConIntentos(int maxIntentos = 3);
int leerEnteroEnRango(int min, int max);
char leerOpcionSN();
bool validarSoloLetrasEspacios(const char* texto);
void leerNombreApellido(char* campo, int tamano, const char* mensaje);
void leerTextoValido(char* campo, int tamano, const char* mensaje);
bool validarTelefono(const char* texto, int minDigitos, int maxDigitos);
void leerTelefono(char* telefono, int tamano, int minDigitos, int maxDigitos);
bool validarEmail(const std::string&email);
bool validarJugadoryClub(int idJugador, int idClub);
bool volverAtras(const char* texto);

#endif
