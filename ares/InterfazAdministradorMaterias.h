#ifndef INTERFAZADMINISTRADORMATERIAS_H_INCLUDED
#define INTERFAZADMINISTRADORMATERIAS_H_INCLUDED 1

#include <iostream>
#include "Definiciones.h"
#include "Pantallas.h"
#include "Entrada.h"
#include "Menus.h"
#include "AdministradorMaterias.h"

using namespace std;

class InterfazAdministradorMaterias
{
private:
    const string NOMBRE_ARCHIVO_MATERIAS = "Materias.txt";
    AdministradorMaterias adminMaterias;
public:
    InterfazAdministradorMaterias()
    {
        cargarMaterias();
    }
    void hacerAdicionMateria()
    {
        string nombreMateria, acronimoMateria, diasClaseMateria;
        int horaInicioMateria, horaFinMateria;
        nuevaPantalla("Agregar materias");

        solicitarCadena(&nombreMateria, "Dame el nombre de la materia: ");
        solicitarCadena(&acronimoMateria, "Dame un acrónimo para la materia: ");
        solicitarCadena(&diasClaseMateria, "Dame los días de clase de la materia: ");
        solicitarEntero(&horaInicioMateria, "Dame la hora de inicio de la materia (entero): ");
        solicitarEntero(&horaFinMateria, "Dame la hora de finalización de la materia (entero): ");

        adminMaterias.agregarMateria(nombreMateria, acronimoMateria, diasClaseMateria,
                                     horaInicioMateria, horaFinMateria);
    }
    void hacerListadoMateria()
    {
        nuevaPantalla("Listado de materias");
        listarMaterias();
        pausa();
    }
    void hacerDetalladoMateria()
    {
        int materiaSeleccionada;

        nuevaPantalla("Mostrar detalles de una materia");
        materiaSeleccionada = obtenerSeleccionMateria("Selecciona una materia a detallar: ");

        nuevaPantalla("Mostrar detalles de una materia");
        detallarMateria(materiaSeleccionada);
        pausa();
    }
    void hacerModificacionMateria()
    {
        bool mostrarMenu = true;
        int horaInicioMateria, horaFinMateria, seleccionMenuUsuario;
        string nombreMateria, acronimoMateria, diasClaseMateria;
        Materia* materia;
        int materiaSeleccionada;

        nuevaPantalla("Modificar materia");
        materiaSeleccionada = obtenerSeleccionMateria("Selecciona una materia a modificar: ");
        materia = adminMaterias.obtenerMateria(materiaSeleccionada);

        do {
            pantallaMenu(MENUS::MATERIA_MODIFICACION);
            solicitarEntero(&seleccionMenuUsuario, "Opción: ",
                            BANDERA_ENTRADA::SEPARAR_ENTRADA_DATOS);
            nuevaPantalla("Modificar materia");

            switch ((MENU_MATERIA_MODIF)seleccionMenuUsuario)
            {
            case MENU_MATERIA_MODIF::NOMBRE:
                solicitarCadena(&nombreMateria,
                                "Dame el nuevo nombre de la materia: ");
                materia->fijaNombre(nombreMateria);
                break;
            case MENU_MATERIA_MODIF::ACRONIMO:
                solicitarCadena(&acronimoMateria,
                                "Dame un nuevo acrónimo para la materia: ");
                materia->fijaAcronimo(acronimoMateria);
                break;
            case MENU_MATERIA_MODIF::DIASCLASE:
                solicitarCadena(&diasClaseMateria,
                                "Dame los nuevos días de clase de la materia: ");
                materia->fijaDiasClase(diasClaseMateria);
                break;
            case MENU_MATERIA_MODIF::HORAINICIO:
                solicitarEntero(&horaInicioMateria,
                                "Dame la nueva hora de inicio de la materia (entero): ");
                materia->fijaHoraInicio(horaInicioMateria);
                break;
            case MENU_MATERIA_MODIF::HORAFIN:
                solicitarEntero(&horaFinMateria,
                                "Dame la nueva hora de finalización de la materia (entero): ");
                materia->fijaHoraFin(horaFinMateria);
                break;
            case MENU_MATERIA_MODIF::TODO:
                detallarMateria(materiaSeleccionada);
                cout <<  endl;
                solicitarCadena(&nombreMateria,
                                "Dame el nuevo nombre de la materia: ");
                materia->fijaNombre(nombreMateria);
                solicitarCadena(&acronimoMateria,
                                "Dame un nuevo acrónimo para la materia: ");
                materia->fijaAcronimo(acronimoMateria);
                solicitarCadena(&diasClaseMateria,
                                "Dame los nuevos días de clase de la materia: ");
                materia->fijaDiasClase(diasClaseMateria);
                solicitarEntero(&horaInicioMateria,
                                "Dame la nueva hora de inicio de la materia (entero): ");
                materia->fijaHoraInicio(horaInicioMateria);
                solicitarEntero(&horaFinMateria,
                                "Dame la nueva hora de finalización de la materia (entero): ");
                materia->fijaHoraFin(horaFinMateria);
                break;
            case MENU_MATERIA_MODIF::VOLVER:
                mostrarMenu = false;
                break;
            default:
                cout << "Opción inválida." << endl;
                pausa();
                break;
            }
            if (mostrarMenu)
            {
                cout << endl << "Materia modificada." << endl;
                pausa();
            }
        } while (mostrarMenu);
    }
    void hacerEliminacionMateria()
    {
        int indiceMateriaSeleccionada;
        indiceMateriaSeleccionada = obtenerSeleccionMateria("Selecciona una materia a eliminar: ");
        adminMaterias.eliminarMateria(indiceMateriaSeleccionada);
    }
    void hacerGuardadoMateria()
    {
        adminMaterias.guardarMaterias(NOMBRE_ARCHIVO_MATERIAS);
    }
    int obtenerSeleccionMateria(string mensaje)
    {
        int seleccion;
        listarMaterias();
        solicitarEntero(&seleccion, mensaje, BANDERA_ENTRADA::SEPARAR_ENTRADA_DATOS);
        seleccion--;
        return seleccion;
    }
    void listarMaterias()
    {
        int i, cantMaterias;

        cantMaterias = adminMaterias.obtenerCantidadMaterias();

        for (i = C_0; i < cantMaterias; i++)
        {
            cout << i+C_1 << ". " << adminMaterias.obtenerMateria(i)->aTexto() << endl;
        }
    }
    void detallarMateria(int indiceMateria)
    {
        Materia* materia;
        materia = obtenerMateria(indiceMateria);
        cout << "Nombre: " << materia->dameNombre() << endl;
        cout << "Acronimo: " << materia->dameAcronimo() << endl;
        cout << "Días de clase: " << materia->dameDiasClase() << endl;
        cout << "Hora de inicio: " << materia->dameHoraInicio() << endl;
        cout << "Hora de finalización: " << materia->dameHoraFin() << endl;
    }
    Materia* obtenerMateria(int indice)
    {
        return adminMaterias.obtenerMateria(indice);
    }
    void cargarMaterias()
    {
        adminMaterias.cargarMaterias(NOMBRE_ARCHIVO_MATERIAS);
    }
    int dameCantMaterias()
    {
        return adminMaterias.obtenerCantidadMaterias();
    }
};

#endif // INTERFAZADMINISTRADORMATERIAS_H_INCLUDED
