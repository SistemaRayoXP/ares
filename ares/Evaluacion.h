#ifndef EVALUACION_H_INCLUDED
#define EVALUACION_H_INCLUDED 1

// Porcentajes a considerar para la evaluación del curso
#define PUNTOS_TAREAS 7
#define PUNTOS_ACTIVIDADES 63
#define PUNTOS_EXAMENES 30
#define PORCENTAJE 100
#define TOTAL_ASISTENCIAS 34
#define CANT_RETARDOS_FALTA 3
#define PORC_MIN_ASISTENCIA 80
#define CALIFICACION_MIN 60
#define CALIFICACION_MAX 100
#define TOTAL_TAREAS 10
#define TOTAL_ACTIVIDADES 9
#define TOTAL_EXAMENES 3

class Evaluacion
{
public:
    int actividades[TOTAL_ACTIVIDADES];
    int examenes[TOTAL_EXAMENES];
    int cantFaltas;
    int cantRetardos;
    int cantTareas;
    float porcAsisClase;
    float porcTareas;
    float porcAct;
    float porcParc;
    float totalAsist;
    float califFinalTarea;
    float califFinalAct;
    float califFinalExam;
    float califFinal;
    bool tieneDerechoAOrdinario;
    bool tieneCalificacionAprobatoria;
    bool haAprobado;
};

#endif // EVALUACION_H_INCLUDED
