#ifndef ADMINISTRADORGENERICO_H_INCLUDED
#define ADMINISTRADORGENERICO_H_INCLUDED 1

#include "Definiciones.h"

template <typename Elemento>

class AdministradorGenerico
{
    static constexpr int TAM_INICIAL_ARREGLO = 3;

    Elemento** lista;
    int tamArreglo;

    void realocarArreglo(int cantCeldas)
    {
        int i;
        Elemento** tmpLista;
        tmpLista = new Elemento*[cantCeldas];

        for (i = C_0; i < tamArreglo; i++)
        {
            tmpLista[i] = lista[i];
        }

        delete[] lista;

        lista = tmpLista;
        tamArreglo = cantCeldas;
    }
protected:
    int cantElementos;

    AdministradorGenerico()
    {
        int i;
        tamArreglo = cantElementos = C_0;

        realocarArreglo(TAM_INICIAL_ARREGLO);

        for (i = C_0; i < tamArreglo; i++)
        {
            lista[i] = nullptr;
        }
    }
    ~AdministradorGenerico()
    {
        int i;

        for (i = C_0; i < cantElementos; i++)
        {
            delete lista[i];
        }
        delete[] lista;
    }

    void agregarElemento(Elemento* e)
    {
        if (cantElementos == tamArreglo)
        {
            realocarArreglo(tamArreglo+C_1);
        }

        lista[cantElementos] = e;
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

            for (int i = posicion; i < tamArreglo; i++)
            {
                lista[i] = lista[i + C_1];
                lista[i + C_1] = nullptr;
            }

            cantElementos--;
            eliminadoCorrecto = true;
        }
        else
        {
            eliminadoCorrecto = false;
        }

        return eliminadoCorrecto;
    }

public:

    static constexpr int ELEMENTO_NO_ENCONTRADO = -1;
};

#endif
