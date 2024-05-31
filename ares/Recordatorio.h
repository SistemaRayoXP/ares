#ifndef RECORDATORIO_H_INCLUDED
#define RECORDATORIO_H_INCLUDED 1

#include <string>
#include <sstream>
#include "Definiciones.h"
#include "TipoRecordatorio.h"

using namespace std;

class Recordatorio
{
private:
    static constexpr int TAM_VISTA_PREVIA_RECORDATORIO = 10;
    static constexpr int TAM_MAX_ASUNTO = 100;
    static constexpr int TAM_FECHA = 10;
    static constexpr int TAM_HORA = 5;

    const string ASUNTO_PREDET = "Asunto predeterminado";
    static constexpr TipoRecordatorio TIPO_PREDET = TipoRecordatorio::SIMPLE;
    const string FECHA_PREDET = "01/01/1970";
    const string HORA_PREDET = "00:00";

    string asunto;
    TipoRecordatorio tipo;
    string fecha;
    string hora;

    static constexpr char SEPARADOR_CAMPOS = '|';

    Recordatorio();
public:
    Recordatorio(string _asunto, TipoRecordatorio _tipo, string _fecha, string _hora)
    {
        if (!fijaAsunto(_asunto))
        {
            asunto = ASUNTO_PREDET;
        }
        if (!fijaTipo(_tipo))
        {
            tipo = TIPO_PREDET;
        }
        if (!fijaFecha(_fecha))
        {
            fecha = FECHA_PREDET;
        }
        if (!fijaHora(_hora))
        {
            hora = HORA_PREDET;
        }
    }
    Recordatorio(string cadenaRecordatorio)
    {
        int posInicio, posFin;
        TipoRecordatorio _tipo;
        string _asunto, _fecha, _hora;

        posInicio = C_0;
        posFin = cadenaRecordatorio.find_first_of(SEPARADOR_CAMPOS, posInicio);
        _asunto = cadenaRecordatorio.substr(posInicio, posFin-posInicio);

        posInicio = posFin+C_1;
        posFin = cadenaRecordatorio.find_first_of(SEPARADOR_CAMPOS, posInicio);
        _tipo = (TipoRecordatorio)cadenaRecordatorio[posInicio+C_1];

        posInicio = posFin+C_1;
        posFin = cadenaRecordatorio.find_first_of(SEPARADOR_CAMPOS, posInicio);
        _fecha = cadenaRecordatorio.substr(posInicio, posFin-posInicio);

        posInicio = posFin+C_1;
        _hora = cadenaRecordatorio.substr(posInicio);

        if (!fijaAsunto(_asunto))
        {
            asunto = ASUNTO_PREDET;
        }
        if (!fijaTipo(_tipo))
        {
            tipo = TIPO_PREDET;
        }
        if (!fijaFecha(_fecha))
        {
            fecha = FECHA_PREDET;
        }
        if (!fijaHora(_hora))
        {
            hora = HORA_PREDET;
        }
    }
    bool fijaAsunto(string a)
    {
        bool fijadoCorrecto = false;
        if (a.length() > C_0 && a.length() <= TAM_MAX_ASUNTO)
        {
            asunto = a;
            fijadoCorrecto = true;
        }
        return fijadoCorrecto;
    }
    bool fijaTipo(TipoRecordatorio t)
    {
        bool fijadoCorrecto;

        if (t == TipoRecordatorio::SIMPLE || t == TipoRecordatorio::REUNION)
        {
            tipo = t;
            fijadoCorrecto = true;
        }
        else
        {
            fijadoCorrecto = false;
        }
        
        return fijadoCorrecto;
    }
    bool fijaFecha(string f)
    {
        bool fijadoCorrecto = false;
        if (f.length() == TAM_FECHA)
        {
            fecha = f;
            fijadoCorrecto = true;
        }
        return fijadoCorrecto;
    }
    bool fijaHora(string h)
    {
        bool fijadoCorrecto = false;
        if (h.length() == TAM_HORA)
        {
            hora = h;
            fijadoCorrecto = true;
        }
        return fijadoCorrecto;
    }
    string dameAsunto()
    {
        return asunto;
    }
    TipoRecordatorio dameTipo()
    {
        return tipo;
    }
    string dameFecha()
    {
        return fecha;
    }
    string dameHora()
    {
        return hora;
    }
    string aTexto()
    {
        stringstream salida;
        salida << (char)tipo << " - " << asunto.substr(C_0, TAM_VISTA_PREVIA_RECORDATORIO);
        return salida.str();
    }
    string aCadena()
    {
        stringstream salida;
        salida << asunto << SEPARADOR_CAMPOS;
        salida << (char)tipo << SEPARADOR_CAMPOS;
        salida << fecha << SEPARADOR_CAMPOS;
        salida << hora;
        return salida.str();
    }
};

#endif // RECORDATORIO_H_INCLUDED
