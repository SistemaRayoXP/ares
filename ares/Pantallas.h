#ifndef PANTALLAS_H_INCLUDED
#define PANTALLAS_H_INCLUDED 1

#include <iostream>
#include "Materia.h"
#include "Definiciones.h"

#define SALTOS_LINEA 25

#ifdef __WIN32
#define LIMPIAR_PANTALLA "cls"
#elif defined(__unix) || defined(__unix__) || defined(__apple) || defined(__mach)
#define LIMPIAR_PANTALLA "clear"
#else
#define LIMPIAR_PANTALLA 0
#endif // __WIN32

using namespace std;

void nuevaPantalla();
void nuevaPantalla(string subtexto);
void nuevaPantalla(Materia* materia);
void limpiarPantalla();

void nuevaPantalla()
{
    limpiarPantalla();
    cout << "Evaluador de curso v3.5" << endl << endl;
}

void nuevaPantalla(string subtexto)
{
    limpiarPantalla();
    cout << "Evaluador de curso v3.5" << endl;
    cout << "- " << subtexto << endl << endl;
}

void nuevaPantalla(Materia* materia)
{
    limpiarPantalla();
    cout << "Evaluador de curso v3.5 - ";
    cout << materia->aCadena() << endl << endl;
}

void limpiarPantalla()
{
    int i;
    if (!LIMPIAR_PANTALLA) {
        for (i = C_0; i < SALTOS_LINEA; i++) {
            cout << endl;
        }
    }
    else {
        system(LIMPIAR_PANTALLA);
    }
}

#endif // PANTALLAS_H_INCLUDED
