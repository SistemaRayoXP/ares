#ifndef EVALUADOR_H_INCLUDED
#define EVALUADOR_H_INCLUDED 1

/*****************************************************
 * Módulo incompleto, no usar
 ******************************************************/

/**
 * TODO: Implementar bien los métodos de agregar evaluación
 */

#include <string>
#include <fstream>
#include <sstream>

#include "AdministradorGenerico.h"
#include "Evaluacion_alt.h"
#include "Definiciones.h"

using namespace std;

class Evaluador : AdministradorGenerico<Evaluacion>
{
private:
    int cantRegistrosModificadosOEliminados;
    int cantRegistrosAgregados;

    bool agregar(string cadenaEvaluacion)
    {
        bool creacionCorrecta;
        Evaluacion* evalNva;

        evalNva = new Evaluacion(cadenaEvaluacion);

        if (evalNva != nullptr)
        {
            agregarElemento(evalNva);
            cantRegistrosAgregados++;
            creacionCorrecta = true;
        }
        else
        {
            creacionCorrecta = false;
        }

        return creacionCorrecta;
    }
public:
    Evaluador()
    {
        cantRegistrosAgregados = cantRegistrosModificadosOEliminados = C_0;
    }
    bool agregar(Materia* materia)
    {
        bool creacionCorrecta;
        Evaluacion* evalNva;

        evalNva = new Evaluacion(materia);

        if (evalNva != nullptr)
        {
            agregarElemento(evalNva);
            cantRegistrosAgregados++;
            creacionCorrecta = true;
        }
        else
        {
            creacionCorrecta = false;
        }

        return creacionCorrecta;
    }
    Evaluacion* consultar(int indice)
    {
        return consultarElemento(indice);
    }
    int obtenerCantidadEvaluaciones()
    {
        return cantElementos;
    }
    bool modificar(int indice, Evaluacion* nvaEvaluacion)
    {
        bool modificacionCorrecta;

        if (indice < cantElementos)
        {
            modificarElemento(indice, nvaEvaluacion);
            cantRegistrosModificadosOEliminados++;
            modificacionCorrecta = true;
        }
        else
        {
            modificacionCorrecta = false;
        }

        return modificacionCorrecta;
    }
    bool eliminar(int indice)
    {
        bool eliminacionCorrecta;
        int i;

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
    bool guardar(string ruta)
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
    bool cargar(string ruta)
    {
        bool cargaCorrecta;
        string cadenaEvaluacion;
        ifstream archivo;

        cargaCorrecta = false;

        archivo.open(ruta);
        if (archivo.is_open())
        {
            while (!archivo.eof())
            {
                getline(archivo, cadenaEvaluacion);

                if (cadenaEvaluacion.length() > C_0)
                {
                    agregar(cadenaEvaluacion);
                }
            }
            archivo.close();
        }

        return cargaCorrecta;
    }
};

#endif // EVALUADOR_H_INCLUDED
