#ifndef INTERFAZADMINISTRADORTAREAS_H_INCLUDED
#define INTERFAZADMINISTRADORTAREAS_H_INCLUDED 1

#include <iostream>
#include "Definiciones.h"
#include "Pantallas.h"
#include "Entrada.h"
#include "Menus.h"
#include "GestorTareas.h"

using namespace std;

class InterfazGestorTareas
{
private:
    const string NOMBRE_ARCHIVO_TAREAS = "Tareas.txt";
    GestorTareas adminTareas;
public:
    InterfazGestorTareas()
    {
        cargarTareas();
    }
    void hacerAdicionTarea()
    {
        string asuntoTarea, descripcionTarea, materiaTarea;
        nuevaPantalla("Agregar tareas");

        solicitarCadena(&asuntoTarea, "Dame el asunto de la tarea: ");
        solicitarCadena(&descripcionTarea, "Dame la descripción de la tarea: ");
        solicitarCadena(&materiaTarea, "Dame el acrónimo de la materia de la tarea: ");

        adminTareas.agregarTarea(asuntoTarea, descripcionTarea, materiaTarea);
    }
    void hacerListadoTareas()
    {
        nuevaPantalla("Listado de tareas");
        listarTareas();
        pausa();
    }
    void hacerDetalladoTarea()
    {
        int indiceTareaSeleccionada;

        nuevaPantalla("Mostrar detalles de una tarea");
        indiceTareaSeleccionada = obtenerSeleccionTarea("Selecciona una tarea a detallar: ");

        nuevaPantalla("Mostrar detalles de una tarea");
        detallarTarea(indiceTareaSeleccionada);
        pausa();
    }
    void hacerModificacionTarea()
    {
        bool mostrarMenu = true;
        int seleccionMenuUsuario;
        string asuntoTarea, descripcionTarea, materiaTarea;
        Tarea* tarea;
        int indiceTareaSeleccionada;

        nuevaPantalla("Modificar tarea");
        indiceTareaSeleccionada = obtenerSeleccionTarea("Selecciona una tarea a modificar: ");
        tarea = adminTareas.obtenerTarea(indiceTareaSeleccionada);

        do {
            pantallaMenu(MENUS::TAREA_MODIFICACION);
            solicitarEntero(&seleccionMenuUsuario, "Opción: ",
                            BANDERA_ENTRADA::SEPARAR_ENTRADA_DATOS);
            nuevaPantalla("Modificar tarea");

            switch ((MENU_TAREA_MODIF)seleccionMenuUsuario)
            {
            case MENU_TAREA_MODIF::ASUNTO:
                solicitarCadena(&asuntoTarea,
                                "Dame el nuevo asunto de la tarea: ");
                tarea->fijaAsunto(asuntoTarea);
                break;
            case MENU_TAREA_MODIF::DESCRIPCION:
                solicitarCadena(&descripcionTarea,
                                "Dame la nueva descripción de la tarea: ");
                tarea->fijaDescripcion(descripcionTarea);
                break;
            case MENU_TAREA_MODIF::MATERIA:
                solicitarCadena(&materiaTarea,
                                "Dame el nuevo acrónimo de la materia de la tarea: ");
                tarea->fijaMateria(materiaTarea);
                break;
            case MENU_TAREA_MODIF::TODO:
                detallarTarea(indiceTareaSeleccionada);
                cout <<  endl;
                solicitarCadena(&asuntoTarea,
                                "Dame el nuevo asunto de la tarea: ");
                tarea->fijaAsunto(asuntoTarea);
                solicitarCadena(&descripcionTarea,
                                "Dame la nueva descripción de la tarea: ");
                tarea->fijaDescripcion(descripcionTarea);
                solicitarCadena(&materiaTarea,
                                "Dame el nuevo acrónimo de la materia de la tarea: ");
                tarea->fijaMateria(materiaTarea);
                break;
            case MENU_TAREA_MODIF::VOLVER:
                mostrarMenu = false;
                break;
            default:
                cout << "Opción inválida." << endl;
                pausa();
                break;
            }
            if (mostrarMenu)
            {
                cout << endl << "Tarea modificada." << endl;
                pausa();
            }
        } while (mostrarMenu);
    }
    void hacerEliminacionTarea()
    {
        int indiceTareaSeleccionada;
        nuevaPantalla("Eliminar tarea");
        indiceTareaSeleccionada = obtenerSeleccionTarea("Selecciona una tarea a eliminar: ");
        adminTareas.eliminarTarea(indiceTareaSeleccionada);
    }
    void hacerGuardadoTarea()
    {
        adminTareas.guardarTareas(NOMBRE_ARCHIVO_TAREAS);
    }
    int obtenerSeleccionTarea(string mensaje)
    {
        int seleccion;
        listarTareas();
        solicitarEntero(&seleccion, mensaje, BANDERA_ENTRADA::SEPARAR_ENTRADA_DATOS);
        seleccion--;
        return seleccion;
    }
    void listarTareas()
    {
        int i, cantTareas;

        cantTareas = adminTareas.obtenerCantidadTareas();

        for (i = C_0; i < cantTareas; i++)
        {
            cout << i+C_1 << ". " << adminTareas.obtenerTarea(i)->aTexto() << endl;
        }
    }
    void detallarTarea(int indiceTarea)
    {
        Tarea* tarea;
        tarea = adminTareas.obtenerTarea(indiceTarea);
        cout << "Asunto: " << tarea->dameAsunto() << endl;
        cout << "Descripción: " << endl << tarea->dameDescripcion() << endl;
        cout << "Materia: " << tarea->dameMateria() << endl;
    }
    void cargarTareas()
    {
        adminTareas.cargarTareas(NOMBRE_ARCHIVO_TAREAS);
    }
};

#endif // INTERFAZADMINISTRADORTAREAS_H_INCLUDED
