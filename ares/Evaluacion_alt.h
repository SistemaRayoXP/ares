#ifndef EVALUACION_H_INCLUDED
#define EVALUACION_H_INCLUDED 1

/*************************************************************************
 * Módulo completo, falta migrar los que utilizan la Evaluacion anterior
 *************************************************************************/

/**
 * TODO: - Meditar el poner todas las funciones de los hijos directamente
 */

#include <string>
#include "Asistencia.h"
#include "Calificacion.h"
#include "Materia.h"

using namespace std;

class Evaluacion
{
    Asistencia* asistencia;
    Calificacion* calificacion;
    Materia* materia;

public:
    Evaluacion(Materia* materia)
    {
        if (!fijaMateria(materia))
            this->materia = nullptr;
    }
    Evaluacion(string cadenaEvaluacion)
    {
        this->materia = nullptr;
    }
    bool fijaAsistencia(Asistencia* a)
    {
        bool fijacionCorrecta;
        if (a != nullptr && sizeof(*a) >= sizeof(Asistencia))
        {
            fijacionCorrecta = true;
            asistencia = a;
        }
        else
        {
            fijacionCorrecta = false;
        }

        return fijacionCorrecta;
    }
    bool fijaCalificacion(Calificacion* c)
    {
        bool fijacionCorrecta;
        if (c != nullptr && sizeof(*c) >= sizeof(Calificacion))
        {
            fijacionCorrecta = true;
            calificacion = c;
        }
        else
        {
            fijacionCorrecta = false;
        }

        return fijacionCorrecta;
    }
    bool fijaMateria(Materia* m)
    {
        bool fijacionCorrecta;
        if (m != nullptr && sizeof(*m) >= sizeof(Materia))
        {
            fijacionCorrecta = true;
            materia = m;
        }
        else
        {
            fijacionCorrecta = false;
        }

        return fijacionCorrecta;
    }
    Asistencia* dameAsistencia()
    {
        return asistencia;
    }
    Calificacion* dameCalificacion()
    {
        return calificacion;
    }
    Materia* dameMateria()
    {
        return materia;
    }
    bool tieneDerechoAOrdinario()
    {
        bool derechoAOrdinario;
        if (asistencia != nullptr)
        {
            derechoAOrdinario = asistencia->tieneDerechoAOrdinario();
        }
        else
        {
            derechoAOrdinario = false;
        }
        return derechoAOrdinario;
    }
    bool tieneCalificacionAprobatoria()
    {
        bool califAprobatoria;
        if (calificacion != nullptr)
        {
            califAprobatoria = calificacion->tieneCalificacionAprobatoria();
        }
        else
        {
            califAprobatoria = false;
        }
        return califAprobatoria;
    }
    bool haAprobado()
    {
        return tieneDerechoAOrdinario() && tieneCalificacionAprobatoria();
    }
    string aCadena()
    {
        string cadenaEvaluacion;
        cadenaEvaluacion = "";
        return cadenaEvaluacion;
    }
};

#endif // EVALUACION_H_INCLUDED
