#ifndef AGENDA_H_INCLUDED
#define AGENDA_H_INCLUDED 1

#include <string>
#include <fstream>
#include <sstream>
#include <cstdio>

#include "Definiciones.h"
#include "Recordatorio.h"
#include "AdministradorGenerico.h"

using namespace std;

class Agenda : AdministradorGenerico<Recordatorio>
{
private:
    int cantRegistrosModificadosOEliminados;
    int cantRegistrosAgregados;

public:
    Agenda()
    {
        cantRegistrosAgregados = cantRegistrosModificadosOEliminados = C_0;
    }
    bool agregarRecordatorio(string asunto, TipoRecordatorio tipo, string fecha, string hora)
    {
        bool creacionCorrecta;
        Recordatorio* nvoRecordatorio;

        nvoRecordatorio = new Recordatorio(asunto, tipo, fecha, hora);

        if (nvoRecordatorio != nullptr)
        {
            agregarElemento(nvoRecordatorio);
            cantRegistrosAgregados++;
            creacionCorrecta = true;
        }
        else
        {
            creacionCorrecta = false;
        }


        return creacionCorrecta;
    }
    bool agregarRecordatorio(string cadenaRecordatorio)
    {
        bool creacionCorrecta;
        Recordatorio* nvoRecordatorio;

        nvoRecordatorio = new Recordatorio(cadenaRecordatorio);

        if (nvoRecordatorio != nullptr)
        {
            agregarElemento(nvoRecordatorio);
            cantRegistrosAgregados++;
            creacionCorrecta = true;
        }
        else
        {
            creacionCorrecta = false;
        }

        return creacionCorrecta;
    }
    Recordatorio* obtenerRecordatorio(int indice)
    {
        return consultarElemento(indice);
    }
    int obtenerCantidadRecordatorios()
    {
        return cantElementos;
    }
    bool modificarRecordatorio(int indice, string asunto, TipoRecordatorio tipo, string fecha, string hora)
    {
        bool modificacionCorrecta;
        Recordatorio* recordatorioAModificar;

        recordatorioAModificar = consultarElemento(indice);

        if (recordatorioAModificar != nullptr)
        {
            recordatorioAModificar->fijaAsunto(asunto);
            recordatorioAModificar->fijaTipo(tipo);
            recordatorioAModificar->fijaFecha(fecha);
            recordatorioAModificar->fijaHora(hora);
            modificarElemento(indice, recordatorioAModificar);
            cantRegistrosModificadosOEliminados++;
            modificacionCorrecta = true;
        }
        else
        {
            modificacionCorrecta = false;
        }

        return modificacionCorrecta;
    }
    bool eliminarRecordatorio(int indice)
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
    bool guardarRecordatorios(string ruta)
    {
        bool guardadoCorrecto, guardarArchivoCompleto;
        int i, indiceInicial;
        ofstream archivo;

        guardadoCorrecto = false;

        guardarArchivoCompleto = cantRegistrosModificadosOEliminados > C_0 &&
                !(cantRegistrosAgregados == cantElementos);

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
    bool cargarRecordatorios(string ruta)
    {
        bool cargaCorrecta;
        string cadenaRecordatorio;
        ifstream archivo;

        cargaCorrecta = false;

        archivo.open(ruta);
        if (archivo.is_open())
        {
            while (!archivo.eof())
            {
                getline(archivo, cadenaRecordatorio);

                if (cadenaRecordatorio.length() > C_0)
                {
                    agregarRecordatorio(cadenaRecordatorio);
                }
            }
            archivo.close();
        }

        return cargaCorrecta;
    }
};

#endif // AGENDA_H_INCLUDED
