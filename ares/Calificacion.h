#ifndef CALIFICACION_H_INCLUDED
#define CALIFICACION_H_INCLUDED 1

#include "Definiciones.h"

class Calificacion
{
private:
    static constexpr int PUNTOS_TAREAS = 7;
    static constexpr int PUNTOS_ACTIVIDADES = 63;
    static constexpr int PUNTOS_EXAMENES = 30;

    static constexpr int CALIFICACION_MIN = 60;
    static constexpr int CALIFICACION_MAX = 100;

    static constexpr int TOTAL_TAREAS = 10;
    static constexpr int TOTAL_ACTIVIDADES = 9;
    static constexpr int TOTAL_EXAMENES = 3;

    static constexpr int PORCIENTO = 100;

    int cantidadTareas;
    int calificacionesActividades[TOTAL_ACTIVIDADES];
    int calificacionesExamenes[TOTAL_EXAMENES];

public:
    Calificacion(int cantTareas, int actividades[], int examenes[])
    {
        if (!fijaCantidadTareas(cantTareas))
            cantidadTareas = C_0;
        if (!fijaCalificacionesActividades(actividades))
        {
            for (int i = C_0; i < TOTAL_ACTIVIDADES; i++)
            {
                actividades[i] = C_0;
            }
            
        }
        if (!fijaCalificacionesExamenes(examenes))
        {
            for (int i = 0; i < TOTAL_EXAMENES; i++)
            {
                examenes[i] = C_0;
            }
            
        }
    }
    bool fijaCantidadTareas(int c)
    {
        bool fijacionCorrecta;

        if (c >= C_0 && c <= TOTAL_TAREAS)
        {
            fijacionCorrecta = true;
            cantidadTareas = c;
        }
        else
        {
            fijacionCorrecta = false;
        }

        return fijacionCorrecta;
    }
    bool fijaCalificacionActividad(int posicion, int calificacion)
    {
        bool fijacionCorrecta;

        if (posicion >= C_0 && posicion < TOTAL_ACTIVIDADES &&
            calificacion >= C_0 && calificacion <= CALIFICACION_MAX)
        {
            fijacionCorrecta = true;
            calificacionesActividades[posicion] = calificacion;
        }
        else
        {
            fijacionCorrecta = false;
        }

        return fijacionCorrecta;
    }
    bool fijaCalificacionesActividades(int c[])
    {
        bool fijacionCorrecta;

        // Por defecto la fijación es correcta,
        // a menos de que se detecte una calificación
        // fuera de rango
        fijacionCorrecta = true;

        for (int i = C_0; i < TOTAL_ACTIVIDADES; i++)
        {
            if (c[i] >= C_0 && c[i] <= CALIFICACION_MAX)
            {
                calificacionesActividades[i] = c[i];
            }
            else
            {
                fijacionCorrecta = false;
            }
        }

        return fijacionCorrecta;
    }
    bool fijaCalificacionExamen(int indice, int calificacion)
    {
        bool fijacionCorrecta;

        if (indice >= C_0 && indice < TOTAL_EXAMENES &&
            calificacion >= C_0 && calificacion <= CALIFICACION_MAX)
        {
            fijacionCorrecta = true;
            calificacionesExamenes[indice] = calificacion;
        }
        else
        {
            fijacionCorrecta = false;
        }

        return fijacionCorrecta;
    }
    bool fijaCalificacionesExamenes(int c[])
    {
        bool fijacionCorrecta;

        // Por defecto la fijación es correcta,
        // a menos de que se detecte una calificación
        // fuera de rango
        fijacionCorrecta = true;

        for (int i = C_0; i < TOTAL_EXAMENES; i++)
        {
            if (c[i] >= C_0 && c[i] <= CALIFICACION_MAX)
            {
                calificacionesExamenes[i] = c[i];
            }
            else
            {
                fijacionCorrecta = false;
            }
        }

        return fijacionCorrecta;
    }
    float damePuntosTareas()
    {
        return dameCalificacionFinalTarea() * PUNTOS_TAREAS;
    }
    float damePuntosActividades()
    {
        return dameCalificacionFinalActividades() * PUNTOS_ACTIVIDADES;
    }
    float damePuntosExamenes()
    {
        return dameCalificacionFinalExamenes() * PUNTOS_EXAMENES;
    }
    float dameCalificacionFinalTarea()
    {
        return ((float)cantidadTareas / TOTAL_TAREAS) * PORCIENTO;
    }
    float dameCalificacionFinalActividades()
    {
        float califFinalAct;

        for (int i = califFinalAct = C_0; i < TOTAL_ACTIVIDADES; i++)
        {
            califFinalAct += calificacionesActividades[i];
        }
        califFinalAct /= TOTAL_ACTIVIDADES;

        return califFinalAct;
    }
    float dameCalificacionFinalExamenes()
    {
        float califFinalExam;

        for (int i = califFinalExam = C_0; i < TOTAL_EXAMENES; i++)
        {
            califFinalExam += calificacionesExamenes[i];
        }
        califFinalExam /= TOTAL_EXAMENES;

        return califFinalExam;
    }
    float dameCalificacionFinal()
    {
        return damePuntosTareas() +
               dameCalificacionFinalExamenes() +
               dameCalificacionFinalActividades();
    }
    bool tieneCalificacionAprobatoria()
    {
        return dameCalificacionFinal() >= CALIFICACION_MIN;
    }
};


#endif // CALIFICACION_H_INCLUDED
