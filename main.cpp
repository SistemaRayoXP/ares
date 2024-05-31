/**
 * ARES - Aplicacion de Registro Estudiantil
*/
#include <iostream>
#include <sstream>
#include <fstream>
#include <clocale>

#include "ares/Definiciones.h"
#include "ares/Pantallas.h"
#include "ares/Entrada.h"
#include "ares/Menus.h"

#include "ares/Materia.h"
#include "ares/Evaluacion.h"

#include "ares/AdministradorMaterias.h"
#include "ares/GestorTareas.h"

#include "ares/InterfazAdministradorMaterias.h"
#include "ares/InterfazGestorTareas.h"
#include "ares/InterfazAgenda.h"
#include "ares/InterfazBlocNotas.h"

using namespace std;

void evaluador();
void cicloMaterias();
void cicloTareas();
void cicloAgenda();
void cicloBlocNotas();

void capturarCalificacionesActividades(int* arregloCalifs);
void capturarCalificacionesExamenes(int* arregloCalifs);

string calificacionesActividadesACadena(int actividades[]);
string calificacionesExamenesACadena(int examenes[]);

InterfazAdministradorMaterias adminMaterias;
InterfazGestorTareas adminTareas;
InterfazAgenda agenda;
InterfazBlocNotas blocNotas;

int main()
{
    bool mostrarMenu = true;
    int seleccionMenuUsuario;

    do {
        pantallaMenu(MENUS::PRINCIPAL);
        solicitarEntero(&seleccionMenuUsuario, "Opción: ",
                        BANDERA_ENTRADA::SEPARAR_ENTRADA_DATOS);

        switch ((MENU_PRINCIPAL)seleccionMenuUsuario)
        {
        case MENU_PRINCIPAL::EVALUACION:
            evaluador();
            break;
        case MENU_PRINCIPAL::GESTION_MATERIAS:
            cicloMaterias();
            break;
        case MENU_PRINCIPAL::CONTROL_TAREAS:
            cicloTareas();
            break;
        case MENU_PRINCIPAL::AGENDA:
            cicloAgenda();
            break;
        case MENU_PRINCIPAL::BLOCNOTAS:
            cicloBlocNotas();
            break;
        case MENU_PRINCIPAL::SALIR:
            mostrarMenu = false;
            break;
        default:
            cout << "Opción inválida." << endl;
            pausa();
            break;
        }
    } while (mostrarMenu);

    return 0;
}

void cicloMaterias()
{
    bool mostrarMenu = true;
    int seleccionMenuUsuario;

    do {
        pantallaMenu(MENUS::MATERIA);
        solicitarEntero(&seleccionMenuUsuario, "Opción: ", BANDERA_ENTRADA::SEPARAR_ENTRADA_DATOS);

        switch ((MENU_ABC)seleccionMenuUsuario)
        {
        case MENU_ABC::ALTA:
            adminMaterias.hacerAdicionMateria();
            break;
        case MENU_ABC::LISTADO:
            adminMaterias.hacerListadoMateria();
            break;
        case MENU_ABC::CONSULTA:
            adminMaterias.hacerDetalladoMateria();
            break;
        case MENU_ABC::MODIFICACION:
            adminMaterias.hacerModificacionMateria();
            break;
        case MENU_ABC::BAJA:
            adminMaterias.hacerEliminacionMateria();
            break;
        case MENU_ABC::GUARDADO:
            adminMaterias.hacerGuardadoMateria();
            break;
        case MENU_ABC::CARGADO:
            adminMaterias.cargarMaterias();
            break;
        case MENU_ABC::REGRESAR:
            mostrarMenu = false;
            break;
        default:
            cout << "Opción inválida." << endl;
            pausa();
            break;
        }
    } while (mostrarMenu);
}

void cicloTareas()
{
    bool mostrarMenu = true;
    int seleccionMenuUsuario;

    do {
        pantallaMenu(MENUS::TAREA);
        solicitarEntero(&seleccionMenuUsuario, "Opción: ", BANDERA_ENTRADA::SEPARAR_ENTRADA_DATOS);

        switch ((MENU_ABC)seleccionMenuUsuario)
        {
        case MENU_ABC::ALTA:
            adminTareas.hacerAdicionTarea();
            break;
        case MENU_ABC::LISTADO:
            adminTareas.hacerListadoTareas();
            break;
        case MENU_ABC::CONSULTA:
            adminTareas.hacerDetalladoTarea();
            break;
        case MENU_ABC::MODIFICACION:
            adminTareas.hacerModificacionTarea();
            break;
        case MENU_ABC::BAJA:
            adminTareas.hacerEliminacionTarea();
            break;
        case MENU_ABC::GUARDADO:
            adminTareas.hacerGuardadoTarea();
            break;
        case MENU_ABC::CARGADO:
            adminTareas.cargarTareas();
            break;
        case MENU_ABC::REGRESAR:
            mostrarMenu = false;
            break;
        default:
            cout << "Opción inválida." << endl;
            pausa();
            break;
        }
    } while (mostrarMenu);
}

void cicloAgenda()
{
    bool mostrarMenu = true;
    int seleccionMenuUsuario;

    do {
        pantallaMenu(MENUS::AGENDA);
        solicitarEntero(&seleccionMenuUsuario, "Opción: ", BANDERA_ENTRADA::SEPARAR_ENTRADA_DATOS);

        switch ((MENU_ABC)seleccionMenuUsuario)
        {
        case MENU_ABC::ALTA:
            agenda.hacerAdicionRecordatorio();
            break;
        case MENU_ABC::LISTADO:
            agenda.hacerListadoRecordatorios();
            break;
        case MENU_ABC::CONSULTA:
            agenda.hacerDetalladoRecordatorio();
            break;
        case MENU_ABC::MODIFICACION:
            agenda.hacerModificacionRecordatorio();
            break;
        case MENU_ABC::BAJA:
            agenda.hacerEliminacionRecordatorio();
            break;
        case MENU_ABC::GUARDADO:
            agenda.hacerGuardadoRecordatorio();
            break;
        case MENU_ABC::CARGADO:
            agenda.cargarRecordatorios();
            break;
        case MENU_ABC::REGRESAR:
            mostrarMenu = false;
            break;
        default:
            cout << "Opción inválida." << endl;
            pausa();
            break;
        }
    } while (mostrarMenu);
}

void cicloBlocNotas()
{
    bool mostrarMenu = true;
    int seleccionMenuUsuario;

    do {
        pantallaMenu(MENUS::BLOCNOTAS);
        solicitarEntero(&seleccionMenuUsuario, "Opción: ", BANDERA_ENTRADA::SEPARAR_ENTRADA_DATOS);

        switch ((MENU_ABC)seleccionMenuUsuario)
        {
        case MENU_ABC::ALTA:
            blocNotas.hacerAdicionNota();
            break;
        case MENU_ABC::LISTADO:
            blocNotas.hacerListadoNotas();
            break;
        case MENU_ABC::CONSULTA:
            blocNotas.hacerDetalladoNota();
            break;
        case MENU_ABC::MODIFICACION:
            blocNotas.hacerModificacionNota();
            break;
        case MENU_ABC::BAJA:
            blocNotas.hacerEliminacionNota();
            break;
        case MENU_ABC::GUARDADO:
            blocNotas.hacerGuardadoRecordatorio();
            break;
        case MENU_ABC::CARGADO:
            blocNotas.cargarNotas();
            break;
        case MENU_ABC::REGRESAR:
            mostrarMenu = false;
            break;
        default:
            cout << "Opción inválida." << endl;
            pausa();
            break;
        }
    } while (mostrarMenu);
}

void evaluador()
{
    // Declaración y definición por defecto de variables (a usar para entrada de datos)
    int i;
    Materia* materia;

    // Declaración de variables (para cómputo)
    Evaluacion evaluacion;
    stringstream salida;
    ofstream archivo;

    setlocale(LC_ALL, "");

    // Entrada de datos
    nuevaPantalla();
    materia = adminMaterias.obtenerMateria(C_0);
    if (adminMaterias.dameCantMaterias() == C_0)
    {
        adminMaterias.hacerAdicionMateria();
        materia = adminMaterias.obtenerMateria(C_0);
        pausa();
    }
    else
    {
        i = adminMaterias.obtenerSeleccionMateria("Selecciona una materia a evaluar: ");
        materia = adminMaterias.obtenerMateria(i);
        pausa();
    }

    nuevaPantalla(materia);
    solicitarEntero(&evaluacion.cantFaltas, "Cuántas faltas acumulaste? ");
    solicitarEntero(&evaluacion.cantRetardos, "Cuántos retardos acumulaste? ");
    solicitarEntero(&evaluacion.cantTareas, "Cuántas tareas realizaste? ");
    capturarCalificacionesActividades(evaluacion.actividades);
    capturarCalificacionesExamenes(evaluacion.examenes);

    // Cómputo de Asistencias
    evaluacion.totalAsist = TOTAL_ASISTENCIAS - evaluacion.cantFaltas;
    evaluacion.totalAsist -= ((float)evaluacion.cantRetardos / CANT_RETARDOS_FALTA);
    evaluacion.porcAsisClase = ((float)evaluacion.totalAsist / TOTAL_ASISTENCIAS) * PORCENTAJE;

    // Cómputo de Tareas
    evaluacion.califFinalTarea = ((float)evaluacion.cantTareas / TOTAL_TAREAS) * PORCENTAJE;
    evaluacion.porcTareas = (evaluacion.califFinalTarea * PUNTOS_TAREAS) / PORCENTAJE;

    // Cómputo de Actividades
    for (i = evaluacion.califFinalAct = C_0; i < TOTAL_ACTIVIDADES; i++) {
        evaluacion.califFinalAct += (float)evaluacion.actividades[i];
    }
    evaluacion.califFinalAct /= TOTAL_ACTIVIDADES;
    evaluacion.porcAct = (evaluacion.califFinalAct * PUNTOS_ACTIVIDADES) / PORCENTAJE;

    // Cómputo de Exámenes Parciales
    for (i = evaluacion.califFinalExam = C_0; i < TOTAL_EXAMENES; i++) {
        evaluacion.califFinalExam += (float)evaluacion.examenes[i];
    }
    evaluacion.califFinalExam /= TOTAL_EXAMENES;
    evaluacion.porcParc = (evaluacion.califFinalExam * PUNTOS_EXAMENES) / PORCENTAJE;

    // Cómputo de Puntos Finales
    evaluacion.califFinal = evaluacion.porcTareas + evaluacion.porcAct + evaluacion.porcParc;

    if (evaluacion.porcAsisClase >= PORC_MIN_ASISTENCIA) {
        evaluacion.tieneDerechoAOrdinario = true;
    }
    else {
        evaluacion.tieneDerechoAOrdinario = false;
    }
    evaluacion.tieneCalificacionAprobatoria = evaluacion.califFinal >= CALIFICACION_MIN ?
                                                                            true : false;
    evaluacion.haAprobado = evaluacion.tieneDerechoAOrdinario &&
                            evaluacion.tieneCalificacionAprobatoria;

    // Salida de datos
    nuevaPantalla(materia);
    salida << "Faltas acumuladas: " << evaluacion.cantFaltas << endl;
    salida << "Retardos acumulados: " << evaluacion.cantRetardos << endl;
    salida << "Tareas realizadas: " << evaluacion.cantTareas << endl;
    salida << calificacionesActividadesACadena(evaluacion.actividades);
    salida << calificacionesExamenesACadena(evaluacion.examenes);
    salida << "Tareas\tActividades\tExámenes\t" << endl;
    salida << evaluacion.porcTareas << "\t" << evaluacion.porcAct << "\t\t"
           << evaluacion.porcParc << endl;
    salida << "Total de asistencias=          " << evaluacion.totalAsist << endl;
    salida << "Porcentaje de asistencias=     " << evaluacion.porcAsisClase << "\t";
    salida << (evaluacion.tieneDerechoAOrdinario ? "Tiene derecho" : "No tiene derecho") << endl;
    salida << "Calificación final=            " << evaluacion.califFinal << "\t";
    salida << (evaluacion.tieneCalificacionAprobatoria ? "Calificación aprobatoria" :
                                              "Calificación no aprobatoria") << endl;
    salida << (evaluacion.haAprobado ? "Alumn@ aprobad@" : "Alumn@ no aprobad@") << endl;

    cout << salida.str();
    archivo.open("Evaluacion.txt");
    archivo << salida.str();
    archivo.close();

    pausa();
}

void capturarCalificacionesActividades(int* arregloCalifs)
{
    int i;

    for (i = C_0; i < TOTAL_ACTIVIDADES; i++) {
        cout << "Cuánto obtuviste en la actividad #" << i+C_1 << "? ";
        cin >> arregloCalifs[i];
        cin.get();
    }
}

void capturarCalificacionesExamenes(int* arregloCalifs)
{
    int i;

    for (i = C_0; i < TOTAL_EXAMENES; i++) {
        cout << "Cuánto obtuviste en el examen #" << i+C_1 << "? ";
        cin >> arregloCalifs[i];
        cin.get();
    }
}

string calificacionesActividadesACadena(int actividades[])
{
    stringstream salida;
    int i;
    for (i = C_0; i < TOTAL_ACTIVIDADES; i++) {
        salida << "Calificación de la actividad " << i+C_1 << ": " << actividades[i] << endl;
    }
    return salida.str();
}

string calificacionesExamenesACadena(int examenes[])
{
    stringstream salida;
    int i;
    for (i = C_0; i < TOTAL_EXAMENES; i++) {
        salida << "Calificación del examen " << i+C_1 << ": " << examenes[i] << endl;
    }
    return salida.str();
}
