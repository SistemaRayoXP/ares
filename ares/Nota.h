#ifndef NOTA_H_INCLUDED
#define NOTA_H_INCLUDED 1

#include <string>
#include <sstream>
#include "Definiciones.h"

using namespace std;

class Nota
{
private:
    static constexpr int TAM_VISTA_PREVIA_NOTA = 20;
    const string DESCRIP_PREDET = "(Nota vacía)";
    string descripcion;
    Nota();
public:
    Nota(string _descripcion)
    {
        if (!fijaDescripcion(_descripcion))
        {
            descripcion = DESCRIP_PREDET;
        }
    }
    bool fijaDescripcion(string d)
    {
        bool fijadoCorrecto = false;
        if (d.length() > C_0)
        {
            descripcion = d;
            fijadoCorrecto = true;
        }
        return fijadoCorrecto;
    }
    string dameDescripcion()
    {
        return descripcion;
    }
    string aTexto()
    {
        stringstream salida;
        salida << descripcion.substr(C_0, TAM_VISTA_PREVIA_NOTA);
        return salida.str();
    }
    string aCadena()
    {
        stringstream salida;
        salida << descripcion;
        return salida.str();
    }
};

#endif // NOTA_H_INCLUDED
