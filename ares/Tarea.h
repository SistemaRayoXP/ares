#ifndef TAREA_H_INCLUDED
#define TAREA_H_INCLUDED 1

#include "Definiciones.h"

using namespace std;

class Tarea
{
private:
    const string ASUNTO_PREDET = "(Sin asunto)";
    const string DESCRIP_PREDET = "(Sin descripción)";
    const string MATERIA_PREDET = "";

    string asunto;
    string descripcion;
    string materia;

    static constexpr char SEPARADOR_CAMPOS = '|';

    Tarea();
public:
    Tarea(string _asunto, string _descripcion, string _materia)
    {
        if (!fijaAsunto(_asunto))
        {
            asunto = ASUNTO_PREDET;
        }
        if (!fijaDescripcion(_descripcion))
        {
            descripcion = DESCRIP_PREDET;
        }
        if (!fijaMateria(_materia))
        {
            materia = MATERIA_PREDET;
        }
    }
    Tarea(string cadenaTarea)
    {
        int posInicio, posFin;
        string _asunto, _descripcion, _materia;

        posInicio = C_0;
        posFin = cadenaTarea.find_first_of(SEPARADOR_CAMPOS, posInicio);
        _asunto = cadenaTarea.substr(posInicio, posFin-posInicio);

        posInicio = posFin+C_1;
        posFin = cadenaTarea.find_first_of(SEPARADOR_CAMPOS, posInicio);
        _descripcion = cadenaTarea.substr(posInicio, posFin-posInicio);

        posInicio = posFin+C_1;
        _materia = cadenaTarea.substr(posInicio);

        if (!fijaAsunto(_asunto))
        {
            asunto = ASUNTO_PREDET;
        }
        if (!fijaDescripcion(_descripcion))
        {
            descripcion = DESCRIP_PREDET;
        }
        if (!fijaMateria(_materia))
        {
            materia = MATERIA_PREDET;
        }
    }
    bool fijaAsunto(string a)
    {
        bool valorFijado = false;
        if (a.length() > C_0)
        {
            asunto = a;
            valorFijado = true;
        }
        return valorFijado;
    }
    bool fijaDescripcion(string d)
    {
        bool valorFijado = false;
        if (d.length() > C_0)
        {
            descripcion = d;
            valorFijado = true;
        }
        return valorFijado;
    }
    bool fijaMateria(string m)
    {
        bool valorFijado = false;
        if (m.length() > C_0)
        {
            materia = m;
            valorFijado = true;
        }
        return valorFijado;
    }
    string dameAsunto()
    {
        return asunto;
    }
    string dameDescripcion()
    {
        return descripcion;
    }
    string dameMateria()
    {
        return materia;
    }
    string aTexto()
    {
        stringstream salida;
        salida << dameMateria() << " - " << dameAsunto();
        return salida.str();
    }
    string aCadena()
    {
        stringstream salida;
        salida << asunto << SEPARADOR_CAMPOS;
        salida << descripcion<< SEPARADOR_CAMPOS;
        salida << materia;
        return salida.str();
    }
};

#endif // TAREA_H_INCLUDED
