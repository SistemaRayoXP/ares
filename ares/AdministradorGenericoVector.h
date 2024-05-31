#ifndef ADMINISTRADORGENERICOVECTOR_H_INCLUDED
#define ADMINISTRADORGENERICOVECTOR_H_INCLUDED 1

#include <vector>
#include "Definiciones.h"

using namespace std;

template <typename Elemento>

class AdministradorGenericoVector
{
    static constexpr int TAM_INICIAL_ARREGLO = 3;
    static constexpr int ELEMENTO_NO_ENCONTRADO = -1;

    vector<Elemento*> lista;

protected:
    int cantElementos;

    AdministradorGenericoVector()
    {
        cantElementos = C_0;
    }
    ~AdministradorGenericoVector()
    {
        int i;

        for (i = C_0; i < cantElementos; i++)
        {
            delete lista[i];
        }
        lista.clear();
    }

    void agregarElemento(Elemento* e)
    {
        lista.push_back(e);
        cantElementos++;
    }
    bool modificarElemento(int posicion, Elemento* nvoElemento)
    {
        bool modifCorrecta;

        if (posicion >= C_0 && posicion < cantElementos)
        {
            lista[posicion] = nvoElemento;
        }
        else
        {
            modifCorrecta = false;
        }

        return modifCorrecta;
    }
    Elemento* consultarElemento(int posicion)
    {
        if (posicion >= C_0 && posicion < cantElementos)
        {
            return lista[posicion];
        }
        else
        {
            return nullptr;
        }

    }
    int buscarElemento(Elemento* e)
    {
        for (int i = 0; i < cantElementos; i++)
        {
            if (lista[i] == e)
            {
                return i;
            }
        }
        return ELEMENTO_NO_ENCONTRADO;
    }
    bool eliminarElemento(int posicion)
    {
        bool eliminadoCorrecto;

        if (posicion >= C_0 && posicion < cantElementos)
        {
            delete lista[posicion];
            lista.erase(lista.begin() + posicion);
            cantElementos--;
            eliminadoCorrecto = true;
        }
        else
        {
            eliminadoCorrecto = false;
        }

        return eliminadoCorrecto;
    }
};

#endif
