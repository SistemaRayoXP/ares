#ifndef INTERFAZBLOCNOTAS_H_INCLUDED
#define INTERFAZBLOCNOTAS_H_INCLUDED 1

#include <iostream>
#include "Definiciones.h"
#include "Pantallas.h"
#include "Entrada.h"
#include "Menus.h"
#include "BlocNotas.h"

using namespace std;

class InterfazBlocNotas
{
private:
    const string NOMBRE_ARCHIVO_BLOCNOTAS = "Notas.txt";
    BlocNotas blocNotas;
public:
    InterfazBlocNotas()
    {
        cargarNotas();
    }
    void hacerAdicionNota()
    {
        string descripcionNota;
        nuevaPantalla("Agregar notas");

        solicitarCadena(&descripcionNota, "Dame la descripción de la nota: ");

        blocNotas.agregarNota(descripcionNota);
    }
    void hacerListadoNotas()
    {
        nuevaPantalla("Listado de notas");
        listarNotas();
        pausa();
    }
    void hacerDetalladoNota()
    {
        int indiceNotaSeleccionada;

        nuevaPantalla("Mostrar detalles de una nota");
        indiceNotaSeleccionada = obtenerSeleccionNota(
            "Selecciona una nota a detallar: ");

        nuevaPantalla("Mostrar detalles de una nota");
        detallarNota(indiceNotaSeleccionada);
        pausa();
    }
    void hacerModificacionNota()
    {
        bool mostrarMenu = true;
        int seleccionMenuUsuario, indiceNotaSeleccionada;
        string descripcionNota;
        Nota* nota;

        nuevaPantalla("Modificar nota");
        indiceNotaSeleccionada = obtenerSeleccionNota(
            "Selecciona una nota a modificar: ");
        nota = blocNotas.obtenerNota(indiceNotaSeleccionada);

        do {
            pantallaMenu(MENUS::BLOCNOTAS_MODIFICACION);
            solicitarEntero(&seleccionMenuUsuario, "Opción: ",
                            BANDERA_ENTRADA::SEPARAR_ENTRADA_DATOS);
            nuevaPantalla("Modificar nota");

            switch ((MENU_BLOCNOTAS_MODIF)seleccionMenuUsuario)
            {
            case MENU_BLOCNOTAS_MODIF::DESCRIPCION:
                solicitarCadena(&descripcionNota,
                                "Dame la nueva descripción de la nota: ");
                nota->fijaDescripcion(descripcionNota);
                break;
            case MENU_BLOCNOTAS_MODIF::VOLVER:
                mostrarMenu = false;
                break;
            default:
                cout << "Opción inválida." << endl;
                pausa();
                break;
            }
            if (mostrarMenu)
            {
                cout << endl << "Nota modificada." << endl;
                pausa();
            }
        } while (mostrarMenu);
    }
    void hacerEliminacionNota()
    {
        int indiceNotaSeleccionada;

        nuevaPantalla("Eliminar nota");
        listarNotas();
        solicitarEntero(&indiceNotaSeleccionada, "Selecciona una nota a eliminar: ",
                        BANDERA_ENTRADA::SEPARAR_ENTRADA_DATOS);
        indiceNotaSeleccionada--;
        blocNotas.eliminarNota(indiceNotaSeleccionada);
    }
    void hacerGuardadoRecordatorio()
    {
        blocNotas.guardarNotas(NOMBRE_ARCHIVO_BLOCNOTAS);
    }
    int obtenerSeleccionNota(string mensaje)
    {
        int seleccion;
        listarNotas();
        solicitarEntero(&seleccion, mensaje, BANDERA_ENTRADA::SEPARAR_ENTRADA_DATOS);
        seleccion--;
        return seleccion;
    }
    void listarNotas()
    {
        int i, cantNotas;
        string cadenaNota;

        cantNotas = blocNotas.obtenerCantidadNotas();

        for (i = C_0; i < cantNotas; i++)
        {
            cadenaNota = blocNotas.obtenerNota(i)->aTexto();
            cout << i + C_1 << ". " << cadenaNota << "..." << endl;
        }
    }
    void detallarNota(int indiceRecordatorio)
    {
        Nota* nota;
        nota = blocNotas.obtenerNota(indiceRecordatorio);
        cout << "Descripción: " << endl << endl << nota->dameDescripcion() << endl;
    }
    void cargarNotas()
    {
        blocNotas.cargarNotas(NOMBRE_ARCHIVO_BLOCNOTAS);
    }
};

#endif // INTERFAZBLOCNOTAS_H_INCLUDED
