#ifndef ADMINISTRADORTAREAS_H_INCLUDED
#define ADMINISTRADORTAREAS_H_INCLUDED 1

#include <string>
#include <fstream>
#include <sstream>
#include <cstdio>

#include "Definiciones.h"
#include "Tarea.h"
#include "AdministradorGenerico.h"

using namespace std;

class GestorTareas : AdministradorGenerico<Tarea>
{
public:
    bool agregarTarea(string asunto, string descripcion, string materia)
    {
        bool creacionCorrecta;
        Tarea* nvaTarea;

        nvaTarea = new Tarea(asunto, descripcion, materia);

        if (nvaTarea != nullptr)
        {
            agregarElemento(nvaTarea);
            creacionCorrecta = true;
        }
        else
        {
            creacionCorrecta = false;
        }

        return creacionCorrecta;
    }
    bool agregarTarea(string cadenaTarea)
    {
        bool creacionCorrecta;
        Tarea* nvaTarea;

        nvaTarea = new Tarea(cadenaTarea);

        if (nvaTarea != nullptr)
        {
            agregarElemento(nvaTarea);
            creacionCorrecta = true;
        }
        else
        {
            creacionCorrecta = false;
        }

        return creacionCorrecta;
    }
    Tarea* obtenerTarea(int indice)
    {
        return consultarElemento(indice);
    }
    int obtenerCantidadTareas()
    {
        return cantElementos;
    }
    bool modificarTarea(int indice, string asunto, string descripcion, string materia)
    {
        bool modificacionCorrecta;
        Tarea* tareaAModificar;

        tareaAModificar = consultarElemento(indice);

        if (tareaAModificar != nullptr)
        {
            tareaAModificar->fijaAsunto(asunto);
            tareaAModificar->fijaDescripcion(descripcion);
            tareaAModificar->fijaMateria(materia);
            modificarElemento(indice, tareaAModificar);
            modificacionCorrecta = true;
        }
        else
        {
            modificacionCorrecta = false;
        }

        return modificacionCorrecta;
    }
    bool eliminarTarea(int indice)
    {
        bool eliminacionCorrecta;

        if (eliminarElemento(indice))
        {
            eliminacionCorrecta = true;
        }
        else
        {
            eliminacionCorrecta = false;
        }

        return eliminacionCorrecta;
    }
    bool guardarTareas(string ruta)
    {
        bool guardadoCorrecto;
        int i;
        ofstream archivo;

        guardadoCorrecto = false;

        archivo.open(ruta);
        if (archivo.is_open())
        {
            for (i = C_0; i < cantElementos; i++)
            {
                archivo << consultarElemento(i)->aCadena();
                archivo << endl;
            }
            archivo.close();
            guardadoCorrecto = true;
        }

        return guardadoCorrecto;
    }
    bool cargarTareas(string ruta)
    {
        bool cargaCorrecta;
        string cadenaTarea;
        ifstream archivo;

        cargaCorrecta = false;

        archivo.open(ruta);
        if (archivo.is_open())
        {
            while (!archivo.eof())
            {
                getline(archivo, cadenaTarea);

                if (cadenaTarea.length())
                {
                    agregarTarea(cadenaTarea);
                }
            }
            archivo.close();
        }

        return cargaCorrecta;
    }
};

#endif // ADMINISTRADORTAREAS_H_INCLUDED
