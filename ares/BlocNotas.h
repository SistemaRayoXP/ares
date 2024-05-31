#ifndef BLOCNOTAS_H_INCLUDED
#define BLOCNOTAS_H_INCLUDED 1

#include <string>
#include <fstream>
#include <sstream>
#include <cstdio>

#include "Definiciones.h"
#include "Nota.h"
#include "AdministradorGenericoVector.h"

using namespace std;

class BlocNotas : AdministradorGenericoVector<Nota>
{
private:
    int cantRegistrosModificadosOEliminados;
    int cantRegistrosAgregados;

public:
    BlocNotas()
    {
        cantRegistrosAgregados = cantRegistrosModificadosOEliminados = C_0;
    }
    bool agregarNota(string descripcion)
    {
        bool creacionCorrecta;
        Nota* nvaNota;

        nvaNota = nullptr;
        nvaNota = new Nota(descripcion);

        if (nvaNota != nullptr)
        {
            agregarElemento(nvaNota);
            creacionCorrecta = true;
            cantRegistrosAgregados++;
        }
        else
        {
            creacionCorrecta = false;
        }

        return creacionCorrecta;
    }
    Nota* obtenerNota(int indice)
    {
        return consultarElemento(indice);
    }
    int obtenerCantidadNotas()
    {
        return cantElementos;
    }
    bool modificarNota(int indice, string descripcion)
    {
        bool modificacionCorrecta;
        Nota* notaModificada;

        if (indice < cantElementos)
        {
            notaModificada = consultarElemento(indice);
            notaModificada->fijaDescripcion(descripcion);
            modificarElemento(indice, notaModificada);
            cantRegistrosModificadosOEliminados++;
            modificacionCorrecta = true;
        }
        else
        {
            modificacionCorrecta = false;
        }

        return modificacionCorrecta;
    }
    bool eliminarNota(int indice)
    {
        bool eliminacionCorrecta;

        if (eliminarElemento(indice))
        {
            cantRegistrosModificadosOEliminados++;
            eliminacionCorrecta = true;
        }
        else
        {
            eliminacionCorrecta = false;
        }

        return eliminacionCorrecta;
    }
    bool guardarNotas(string ruta)
    {
        bool guardadoCorrecto, guardarArchivoCompleto;
        int i, indiceInicial;
        ofstream archivo;

        guardadoCorrecto = false;

        guardarArchivoCompleto = (cantRegistrosModificadosOEliminados > C_0) ||
                (cantRegistrosAgregados == cantElementos);

        if (guardarArchivoCompleto)
        {
            archivo.open(ruta);
            indiceInicial = C_0;
        }
        else
        {
            archivo.open(ruta, ios::app);
            indiceInicial = cantElementos - cantRegistrosAgregados;
        }
        if (archivo.is_open())
        {
            for (i = indiceInicial; i < cantElementos; i++)
            {
                archivo << consultarElemento(i)->aCadena();
                archivo << endl;
            }
            archivo.close();
            guardadoCorrecto = true;
        }

        return guardadoCorrecto;
    }
    bool cargarNotas(string ruta)
    {
        bool cargaCorrecta;
        string cadenaNota;
        ifstream archivo;

        cargaCorrecta = false;

        archivo.open(ruta);
        if (archivo.is_open())
        {
            while (!archivo.eof())
            {
                getline(archivo, cadenaNota);

                if (cadenaNota.length() > C_0)
                {
                    agregarNota(cadenaNota);
                }
            }
            archivo.close();
        }

        return cargaCorrecta;
    }
};

#endif // BLOCNOTAS_H_INCLUDED
