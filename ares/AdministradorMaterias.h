#ifndef ADMINISTRADORMATERIAS_H_INCLUDED
#define ADMINISTRADORMATERIAS_H_INCLUDED 1

#include <string>
#include <fstream>
#include <sstream>
#include <cstdio>
#include "Materia.h"
#include "Definiciones.h"

using namespace std;

class AdministradorMaterias
{
private:
    static constexpr int TAM_ARREGLO_MATERIAS = 50;
    static constexpr char SEPARADOR_REGISTROS = '&';

    Materia* materias[TAM_ARREGLO_MATERIAS];
    int cantMaterias;

public:
    AdministradorMaterias()
    {
        int i;
        cantMaterias = C_0;

        for (i = C_0; i < TAM_ARREGLO_MATERIAS; i++)
        {
            materias[i] = NULL;
        }
    }
    ~AdministradorMaterias()
    {
        int i;

        for (i = C_0; i < cantMaterias; i++)
        {
            delete materias[i];
        }
    }
    bool agregarMateria(string nombre, string acronimo,
                        string diasClase, int horaInicio, int horaFin)
    {
        bool creacionCorrecta;

        creacionCorrecta = false;

        if (cantMaterias < TAM_ARREGLO_MATERIAS)
        {
            materias[cantMaterias++] = new Materia(nombre, acronimo, diasClase,
                                                   horaInicio, horaFin);
            creacionCorrecta = true;
        }

        return creacionCorrecta;
    }
    bool agregarMateria(string cadenaMateria)
    {
        bool creacionCorrecta;

        creacionCorrecta = false;

        if (cantMaterias < TAM_ARREGLO_MATERIAS)
        {
            materias[cantMaterias++] = new Materia(cadenaMateria);
            creacionCorrecta = true;
        }

        return creacionCorrecta;
    }
    Materia* obtenerMateria(int indice)
    {
        return materias[indice];
    }
    int obtenerCantidadMaterias()
    {
        return cantMaterias;
    }
    bool modificarMateria(int indice, string nombre, string acronimo,
                          string diasClase, int horaInicio, int horaFin)
    {
        bool modificacionCorrecta;

        if (indice < cantMaterias)
        {
            materias[indice]->fijaNombre(nombre);
            materias[indice]->fijaAcronimo(acronimo);
            materias[indice]->fijaDiasClase(diasClase);
            materias[indice]->fijaHoraInicio(horaInicio);
            materias[indice]->fijaHoraFin(horaFin);
            modificacionCorrecta = true;
        }
        else
        {
            modificacionCorrecta = false;
        }

        return modificacionCorrecta;
    }
    bool eliminarMateria(int indice)
    {
        bool eliminacionCorrecta;
        int i;

        if (indice < cantMaterias)
        {
            delete materias[indice];
            for (i = indice; i < cantMaterias; i++)
            {
                materias[i] = materias[i+C_1];
                materias[i+C_1] = NULL;
            }
            cantMaterias--;
            eliminacionCorrecta = true;
        }
        else
        {
            eliminacionCorrecta = false;
        }

        return eliminacionCorrecta;
    }
    bool guardarMaterias(string ruta)
    {
        bool guardadoCorrecto;
        int i;
        ofstream archivo;

        guardadoCorrecto = false;

        archivo.open(ruta);
        if (archivo.is_open())
        {
            for (i = C_0; i < cantMaterias; i++)
            {
                archivo << materias[i]->aCadena();
                archivo << endl;
            }
            archivo.close();
            guardadoCorrecto = true;
        }

        return guardadoCorrecto;
    }
    bool cargarMaterias(string ruta)
    {
        int i;
        bool cargaCorrecta;
        size_t inicioRegistro, finRegistro;
        string cadenaMateria, cadenaArchivo;
        ifstream archivo;

        archivo.open(ruta);

        if (archivo.is_open())
        {
            cargaCorrecta = true;
            getline(archivo, cadenaArchivo);
            for (i = finRegistro = C_0;
                 i < TAM_ARREGLO_MATERIAS && finRegistro != string::npos;
                 i++)
            {
                inicioRegistro = finRegistro > C_0 ? finRegistro + C_1 : finRegistro;
                finRegistro = cadenaArchivo.find_first_of(SEPARADOR_REGISTROS,
                                                            finRegistro+C_1);
                if (materias[i] == NULL)
                {
                    cadenaMateria = cadenaArchivo.substr(inicioRegistro,
                                                        finRegistro - inicioRegistro);

                    cargaCorrecta = cargaCorrecta && agregarMateria(cadenaMateria);
                }
            }
        }
        else
        {
            cargaCorrecta = false;
        }

        return cargaCorrecta;
    }
};

#endif // ADMINISTRADORMATERIAS_H_INCLUDED
