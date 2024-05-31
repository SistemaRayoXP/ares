#ifndef ASISTENCIA_H_INCLUDED
#define ASISTENCIA_H_INCLUDED 1

#include "Definiciones.h"

class Asistencia
{
private:
    static constexpr int TOTAL_ASISTENCIAS = 34;
    static constexpr int CANT_RETARDOS_FALTA = 3;
    static constexpr int PORC_MIN_ASISTENCIA = 80;
    static constexpr int PORCENTAJE = 100;

    int faltas;
    int retardos;

    Asistencia();
public:
    Asistencia(int cantRetardos, int cantFaltas)
    {
        if (!fijaCantidadFaltas(cantFaltas))
            cantFaltas = C_0;
        if (!fijaCantidadRetardos(cantRetardos))
            cantRetardos = C_0;
    }
    bool fijaCantidadFaltas(int f)
    {
        bool fijacionCorrecta;
        if (f >= C_0)
        {
            fijacionCorrecta = true;
            faltas = f;
        }
        else
        {
            fijacionCorrecta = false;
        }
        
        return fijacionCorrecta;
    }
    bool fijaCantidadRetardos(int r)
    {
        bool fijacionCorrecta;
        if (r >= C_0)
        {
            retardos = r;
        }
        else
        {
            fijacionCorrecta = false;
        }
        return fijacionCorrecta;
    }
    int dameCantidadFaltas()
    {
        return faltas;
    }
    int dameCantidadRetardos()
    {
        return retardos;
    }
    int dameTotalAsistencias()
    {
        int totalAsistencias;

        totalAsistencias = TOTAL_ASISTENCIAS - faltas;
        totalAsistencias -= retardos / CANT_RETARDOS_FALTA;

        return totalAsistencias;
    }
    float damePorcentajeAsistencia()
    {
        float porcAsisClase;

        porcAsisClase = (float)dameTotalAsistencias() / TOTAL_ASISTENCIAS * PORCENTAJE;

        return porcAsisClase;
    }
    bool tieneDerechoAOrdinario()
    {
        return damePorcentajeAsistencia() >= PORC_MIN_ASISTENCIA;
    }
};

#endif // ASISTENCIA_H_INCLUDED
