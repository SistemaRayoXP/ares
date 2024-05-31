#ifndef INTERFAZAGENDA_H_INCLUDED
#define INTERFAZAGENDA_H_INCLUDED 1

#include <iostream>
#include "Definiciones.h"
#include "Pantallas.h"
#include "Entrada.h"
#include "Menus.h"
#include "Agenda.h"

using namespace std;

class InterfazAgenda
{
private:
    const string NOMBRE_ARCHIVO_AGENDA = "Agenda.txt";
    Agenda agenda;
public:
    InterfazAgenda()
    {
        cargarRecordatorios();
    }
    void hacerAdicionRecordatorio()
    {
        char tipoRecordatorio;
        string asuntoRecordatorio, fechaRecordatorio, horaRecordatorio;
        nuevaPantalla("Agregar recordatorios");

        solicitarCadena(&asuntoRecordatorio, "Dame el asunto del recordatorio: ");
        solicitarCaracter(&tipoRecordatorio, "Dame el tipo del recordatorio: ");
        solicitarCadena(&fechaRecordatorio, "Dame la fecha del recordatorio: ");
        solicitarCadena(&horaRecordatorio, "Dame la hora del recordatorio: ");

        agenda.agregarRecordatorio(asuntoRecordatorio, (TipoRecordatorio)tipoRecordatorio,
                                   fechaRecordatorio, horaRecordatorio);
    }
    void hacerListadoRecordatorios()
    {
        nuevaPantalla("Listado de recordatorios");
        listarRecordatorios();
        pausa();
    }
    void hacerDetalladoRecordatorio()
    {
        int indiceRecordatorioSeleccionado;

        nuevaPantalla("Mostrar detalles de un recordatorio");
        indiceRecordatorioSeleccionado = obtenerSeleccionRecordatorio(
            "Selecciona un recordatorio a detallar: ");

        nuevaPantalla("Mostrar detalles de un recordatorio");
        detallarRecordatorio(indiceRecordatorioSeleccionado);
        pausa();
    }
    void hacerModificacionRecordatorio()
    {
        bool mostrarMenu = true;
        int seleccionMenuUsuario, indiceRecordatorioSeleccionado;
        char tipoRecordatorio;
        string asuntoRecordatorio, fechaRecordatorio, horaRecordatorio;
        Recordatorio* recordatorio;

        nuevaPantalla("Modificar recordatorio");
        indiceRecordatorioSeleccionado = obtenerSeleccionRecordatorio(
            "Selecciona un recordatorio a modificar: ");
        recordatorio = agenda.obtenerRecordatorio(indiceRecordatorioSeleccionado);

        do {
            pantallaMenu(MENUS::AGENDA_MODIFICACION);
            solicitarEntero(&seleccionMenuUsuario, "Opción: ",
                            BANDERA_ENTRADA::SEPARAR_ENTRADA_DATOS);
            nuevaPantalla("Modificar recordatorio");

            switch ((MENU_AGENDA_MODIF)seleccionMenuUsuario)
            {
            case MENU_AGENDA_MODIF::ASUNTO:
                solicitarCadena(&asuntoRecordatorio,
                                "Dame el nuevo asunto del recordatorio: ");
                recordatorio->fijaAsunto(asuntoRecordatorio);
                break;
            case MENU_AGENDA_MODIF::TIPO:
                solicitarCaracter(&tipoRecordatorio,
                                "Dame el nuevo tipo del recordatorio: ");
                recordatorio->fijaTipo((TipoRecordatorio)tipoRecordatorio);
                break;
            case MENU_AGENDA_MODIF::FECHA:
                solicitarCadena(&fechaRecordatorio,
                                "Dame la nueva fecha del recordatorio: ");
                recordatorio->fijaFecha(fechaRecordatorio);
                break;
            case MENU_AGENDA_MODIF::HORA:
                solicitarCadena(&horaRecordatorio,
                                "Dame la nueva hora del recordatorio: ");
                recordatorio->fijaHora(horaRecordatorio);
                break;
            case MENU_AGENDA_MODIF::TODO:
                detallarRecordatorio(indiceRecordatorioSeleccionado);
                cout <<  endl;
                solicitarCadena(&asuntoRecordatorio,
                                "Dame el nuevo asunto del recordatorio: ");
                recordatorio->fijaAsunto(asuntoRecordatorio);
                solicitarCaracter(&tipoRecordatorio,
                                "Dame el nuevo tipo del recordatorio: ");
                recordatorio->fijaTipo((TipoRecordatorio)tipoRecordatorio);
                solicitarCadena(&fechaRecordatorio,
                                "Dame la nueva fecha del recordatorio: ");
                recordatorio->fijaFecha(fechaRecordatorio);
                solicitarCadena(&horaRecordatorio,
                                "Dame la nueva hora del recordatorio: ");
                recordatorio->fijaHora(horaRecordatorio);
                break;
            case MENU_AGENDA_MODIF::VOLVER:
                mostrarMenu = false;
                break;
            default:
                cout << "Opción inválida." << endl;
                pausa();
                break;
            }
            if (mostrarMenu)
            {
                cout << endl << "Recordatorio modificado." << endl;
                pausa();
            }
        } while (mostrarMenu);
    }
    void hacerEliminacionRecordatorio()
    {
        int indiceRecordatorioSeleccionado;

        nuevaPantalla("Eliminar recordatorio");
        listarRecordatorios();
        solicitarEntero(&indiceRecordatorioSeleccionado, "Selecciona una recordatorio a eliminar: ",
                        BANDERA_ENTRADA::SEPARAR_ENTRADA_DATOS);
        indiceRecordatorioSeleccionado--;
        agenda.eliminarRecordatorio(indiceRecordatorioSeleccionado);
    }
    void hacerGuardadoRecordatorio()
    {
        agenda.guardarRecordatorios(NOMBRE_ARCHIVO_AGENDA);
    }
    int obtenerSeleccionRecordatorio(string mensaje)
    {
        int seleccion;
        listarRecordatorios();
        solicitarEntero(&seleccion, mensaje, BANDERA_ENTRADA::SEPARAR_ENTRADA_DATOS);
        seleccion--;
        return seleccion;
    }
    void listarRecordatorios()
    {
        int i, cantRecordatorios;
        string cadenaRecordatorio;

        cantRecordatorios = agenda.obtenerCantidadRecordatorios();

        for (i = C_0; i < cantRecordatorios; i++)
        {
            cadenaRecordatorio = agenda.obtenerRecordatorio(i)->aTexto();
            cout << i+C_1 << ". " << cadenaRecordatorio << "..." << endl;
        }
    }
    void detallarRecordatorio(int indiceRecordatorio)
    {
        Recordatorio* recordatorio;
        recordatorio = agenda.obtenerRecordatorio(indiceRecordatorio);
        cout << "Asunto: " << recordatorio->dameAsunto() << endl;
        cout << "Tipo: " << (char)recordatorio->dameTipo() << endl;
        cout << "Fecha: " << recordatorio->dameFecha() << endl;
        cout << "Hora: " << recordatorio->dameHora() << endl;
    }
    void cargarRecordatorios()
    {
        agenda.cargarRecordatorios(NOMBRE_ARCHIVO_AGENDA);
    }
};

#endif // INTERFAZAGENDA_H_INCLUDED
