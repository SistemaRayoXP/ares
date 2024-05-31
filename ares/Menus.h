#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED 1
#include <iostream>
#include "Pantallas.h"
#include "Definiciones.h"

#define CANT_SUBMENUS 3
#define MAX_ELEMS_SUBMENU 8
#define ELEMS_SUBMENU 8
#define ELEMS_SUBMENU_MODIF 7

enum class MENUS
{
    PRINCIPAL,
    MATERIA,
    MATERIA_MODIFICACION,
    TAREA,
    TAREA_MODIFICACION,
    AGENDA,
    AGENDA_MODIFICACION,
    BLOCNOTAS,
    BLOCNOTAS_MODIFICACION
};
enum class MENU_PRINCIPAL
{
    EVALUACION=1,
    GESTION_MATERIAS,
    CONTROL_TAREAS,
    AGENDA,
    BLOCNOTAS,
    SALIR
};
enum class MENU_ABC
{
    ALTA=1,
    LISTADO,
    CONSULTA,
    MODIFICACION,
    BAJA,
    GUARDADO,
    CARGADO,
    REGRESAR
};
enum class MENU_MATERIA_MODIF
{
    NOMBRE=1,
    ACRONIMO,
    DIASCLASE,
    HORAINICIO,
    HORAFIN,
    TODO,
    VOLVER
};
enum class MENU_TAREA_MODIF
{
    ASUNTO=1,
    DESCRIPCION,
    MATERIA,
    TODO,
    VOLVER
};
enum class MENU_AGENDA_MODIF
{
    ASUNTO=1,
    TIPO,
    FECHA,
    HORA,
    TODO,
    VOLVER
};
enum class MENU_BLOCNOTAS_MODIF
{
    DESCRIPCION=1,
    VOLVER
};

using namespace std;

void pantallaMenu(int submenuSeleccionado);
static void pantallaMenuPrincipal();
static void pantallaMenuMaterias();
static void pantallaMenuMateriasModificacion();
static void pantallaMenuTareas();
static void pantallaMenuTareasModificacion();
static void pantallaMenuAgenda();
static void pantallaMenuAgendaModificacion();
static void pantallaMenuBlocNotas();
static void pantallaMenuBlocNotasModificacion();

void pantallaMenu(MENUS submenuSeleccionado)
{
    switch (submenuSeleccionado)
    {
    case MENUS::PRINCIPAL:
        pantallaMenuPrincipal();
        break;
    case MENUS::MATERIA:
        pantallaMenuMaterias();
        break;
    case MENUS::MATERIA_MODIFICACION:
        pantallaMenuMateriasModificacion();
        break;
    case MENUS::TAREA:
        pantallaMenuTareas();
        break;
    case MENUS::TAREA_MODIFICACION:
        pantallaMenuTareasModificacion();
        break;
    case MENUS::AGENDA:
        pantallaMenuAgenda();
        break;
    case MENUS::AGENDA_MODIFICACION:
        pantallaMenuAgendaModificacion();
        break;
    case MENUS::BLOCNOTAS:
        pantallaMenuBlocNotas();
        break;
    case MENUS::BLOCNOTAS_MODIFICACION:
        pantallaMenuBlocNotasModificacion();
        break;
    default:
        nuevaPantalla("Submenú");
        break;
    }
}

static void pantallaMenuPrincipal()
{
    nuevaPantalla();
    cout << (int)MENU_PRINCIPAL::EVALUACION << ". Evaluación del curso" << endl;
    cout << (int)MENU_PRINCIPAL::GESTION_MATERIAS << ". Gestión de materias" << endl;
    cout << (int)MENU_PRINCIPAL::CONTROL_TAREAS << ". Control de tareas" << endl;
    cout << (int)MENU_PRINCIPAL::AGENDA << ". Agenda" << endl;
    cout << (int)MENU_PRINCIPAL::BLOCNOTAS << ". Bloc de notas" << endl;
    cout << (int)MENU_PRINCIPAL::SALIR << ". Salir" << endl;
}

static void pantallaMenuMaterias()
{
    nuevaPantalla("Gestión de materias");
    cout << (int)MENU_ABC::ALTA << ". Agregar materia" << endl;
    cout << (int)MENU_ABC::LISTADO << ". Listar materias" << endl;
    cout << (int)MENU_ABC::CONSULTA << ". Mostrar detalles de una materia" << endl;
    cout << (int)MENU_ABC::MODIFICACION << ". Modificar una materia" << endl;
    cout << (int)MENU_ABC::BAJA << ". Eliminar materia" << endl;
    cout << (int)MENU_ABC::GUARDADO << ". Guardar cambios" << endl;
    cout << (int)MENU_ABC::CARGADO << ". Cargar cambios desde disco" << endl;
    cout << (int)MENU_ABC::REGRESAR << ". Regresar al menú anterior" << endl;
}

static void pantallaMenuMateriasModificacion()
{
    nuevaPantalla("Modificar materia");
    cout << (int)MENU_MATERIA_MODIF::NOMBRE << ". Modificar nombre" << endl;
    cout << (int)MENU_MATERIA_MODIF::ACRONIMO << ". Modificar acrónimo" << endl;
    cout << (int)MENU_MATERIA_MODIF::DIASCLASE << ". Modificar días de clase" << endl;
    cout << (int)MENU_MATERIA_MODIF::HORAINICIO << ". Modificar hora de inicio" << endl;
    cout << (int)MENU_MATERIA_MODIF::HORAFIN << ". Modificar hora de finalización"
              << endl;
    cout << (int)MENU_MATERIA_MODIF::TODO << ". Modificar todo" << endl;
    cout << (int)MENU_MATERIA_MODIF::VOLVER << ". Volver al menú anterior" << endl;
}

static void pantallaMenuTareas()
{
    nuevaPantalla("Control de tareas");
    cout << (int)MENU_ABC::ALTA << ". Agregar tarea" << endl;
    cout << (int)MENU_ABC::LISTADO << ". Listar tarea" << endl;
    cout << (int)MENU_ABC::CONSULTA << ". Mostrar detalles de una tarea" << endl;
    cout << (int)MENU_ABC::MODIFICACION << ". Modificar una tarea" << endl;
    cout << (int)MENU_ABC::BAJA << ". Eliminar tarea" << endl;
    cout << (int)MENU_ABC::GUARDADO << ". Guardar cambios" << endl;
    cout << (int)MENU_ABC::CARGADO << ". Cargar cambios desde disco" << endl;
    cout << (int)MENU_ABC::REGRESAR << ". Regresar al menú anterior" << endl;
}

static void pantallaMenuTareasModificacion()
{
    nuevaPantalla("Modificar tarea");
    cout << (int)MENU_TAREA_MODIF::ASUNTO << ". Modificar asunto" << endl;
    cout << (int)MENU_TAREA_MODIF::DESCRIPCION << ". Modificar descripción" << endl;
    cout << (int)MENU_TAREA_MODIF::MATERIA << ". Modificar materia asociada" << endl;
    cout << (int)MENU_TAREA_MODIF::TODO << ". Modificar todo" << endl;
    cout << (int)MENU_TAREA_MODIF::VOLVER << ". Volver al menú anterior" << endl;
}

static void pantallaMenuAgenda()
{
    nuevaPantalla("Agenda");
    cout << (int)MENU_ABC::ALTA << ". Agregar recordatorio" << endl;
    cout << (int)MENU_ABC::LISTADO << ". Listar recordatorios" << endl;
    cout << (int)MENU_ABC::CONSULTA << ". Mostrar detalles de un recordatorio" << endl;
    cout << (int)MENU_ABC::MODIFICACION << ". Modificar un recordatorio" << endl;
    cout << (int)MENU_ABC::BAJA << ". Eliminar recordatorio" << endl;
    cout << (int)MENU_ABC::GUARDADO << ". Guardar cambios" << endl;
    cout << (int)MENU_ABC::CARGADO << ". Cargar cambios desde disco" << endl;
    cout << (int)MENU_ABC::REGRESAR << ". Regresar al menú anterior" << endl;
}

static void pantallaMenuAgendaModificacion()
{
    nuevaPantalla("Modificar recordatorio");
    cout << (int)MENU_AGENDA_MODIF::ASUNTO << ". Modificar asunto" << endl;
    cout << (int)MENU_AGENDA_MODIF::TIPO << ". Modificar tipo" << endl;
    cout << (int)MENU_AGENDA_MODIF::FECHA << ". Modificar fecha" << endl;
    cout << (int)MENU_AGENDA_MODIF::HORA << ". Modificar hora" << endl;
    cout << (int)MENU_AGENDA_MODIF::TODO << ". Modificar todo" << endl;
    cout << (int)MENU_AGENDA_MODIF::VOLVER << ". Volver al menú anterior" << endl;
}

static void pantallaMenuBlocNotas()
{
    nuevaPantalla("Bloc de notas");
    cout << (int)MENU_ABC::ALTA << ". Agregar nota" << endl;
    cout << (int)MENU_ABC::LISTADO << ". Listar notas" << endl;
    cout << (int)MENU_ABC::CONSULTA << ". Mostrar detalles de una nota" << endl;
    cout << (int)MENU_ABC::MODIFICACION << ". Modificar una nota" << endl;
    cout << (int)MENU_ABC::BAJA << ". Eliminar nota" << endl;
    cout << (int)MENU_ABC::GUARDADO << ". Guardar cambios" << endl;
    cout << (int)MENU_ABC::CARGADO << ". Cargar cambios desde disco" << endl;
    cout << (int)MENU_ABC::REGRESAR << ". Regresar al menú anterior" << endl;
}

static void pantallaMenuBlocNotasModificacion()
{
    nuevaPantalla("Modificar nota");
    cout << (int)MENU_BLOCNOTAS_MODIF::DESCRIPCION << ". Modificar descripción" << endl;
    cout << (int)MENU_BLOCNOTAS_MODIF::VOLVER << ". Volver al menú anterior" << endl;
}

#endif // MENUS_H_INCLUDED
