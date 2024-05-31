#ifndef MATERIA_H_INCLUDED
#define MATERIA_H_INCLUDED 1

#include "Definiciones.h"

using namespace std;

class Materia
{
private:
    static constexpr int TAM_MIN_NOMBRE_MATERIA = 1;
    static constexpr int TAM_MAX_NOMBRE_MATERIA = 25;
    static constexpr int TAM_MIN_ACRONIMO_MATERIA = 3;
    static constexpr int TAM_MAX_ACRONIMO_MATERIA = 5;
    static constexpr int TAM_MIN_DIASCLASE_MATERIA = 1;
    static constexpr int TAM_MAX_DIASCLASE_MATERIA = 3;
    static constexpr int MAX_HORAS = 24;

    const string NOMBRE_PREDET = "Materia sin nombre";
    const string ACRONIMO_PREDET = "???";
    const string DIASCLASE_PREDET = "?";
    static constexpr int HORAINICIO_PREDET = 7;
    static constexpr int HORAFIN_PREDET = 9;

    static constexpr char SEPARADOR_CAMPOS = '|';

    string nombre;
    string acronimo;
    string diasClase;
    int horaInicio;
    int horaFin;
    Materia() {}

public:
    Materia(string _nombre, string _acronimo,
            string _diasClase, int _horaInicio, int _horaFin)
    {
        if (!fijaNombre(_nombre))
        {
            nombre = NOMBRE_PREDET;
        }
        if (!fijaAcronimo(_acronimo))
        {
            acronimo = ACRONIMO_PREDET;
        }
        if (!fijaDiasClase(_diasClase))
        {
            diasClase = DIASCLASE_PREDET;
        }
        if (!fijaHoraInicio(_horaInicio))
        {
            horaInicio = HORAINICIO_PREDET;
        }
        if (!fijaHoraFin(_horaFin))
        {
            horaFin = HORAFIN_PREDET;
        }
    }
    Materia(string cadenaMateria)
    {
        int posInicio, posFin, _horaInicio, _horaFin;
        string _nombre, _acronimo, _diasClase, tmp;

        posInicio = C_0;
        posFin = cadenaMateria.find_first_of(SEPARADOR_CAMPOS, posInicio);
        _nombre = cadenaMateria.substr(posInicio, posFin-posInicio);

        posInicio = posFin+C_1;
        posFin = cadenaMateria.find_first_of(SEPARADOR_CAMPOS, posInicio);
        _acronimo = cadenaMateria.substr(posInicio, posFin-posInicio);

        posInicio = posFin+C_1;
        posFin = cadenaMateria.find_first_of(SEPARADOR_CAMPOS, posInicio);
        _diasClase = cadenaMateria.substr(posInicio, posFin-posInicio);

        posInicio = posFin+C_1;
        posFin = cadenaMateria.find_first_of(SEPARADOR_CAMPOS, posInicio);
        tmp = cadenaMateria.substr(posInicio, posFin-posInicio);
        _horaInicio = tmp.length() ? stoi(tmp) : C_0;

        posInicio = posFin+C_1;
        tmp = cadenaMateria.substr(posInicio);
        _horaFin = tmp.length() ? stoi(tmp) : C_0;

        if (!fijaNombre(_nombre))
        {
            nombre = NOMBRE_PREDET;
        }
        if (!fijaAcronimo(_acronimo))
        {
            acronimo = ACRONIMO_PREDET;
        }
        if (!fijaDiasClase(_diasClase))
        {
            diasClase = DIASCLASE_PREDET;
        }
        if (!fijaHoraInicio(_horaInicio))
        {
            horaInicio = HORAINICIO_PREDET;
        }
        if (!fijaHoraFin(_horaFin))
        {
            horaFin = HORAFIN_PREDET;
        }
    }
    bool fijaNombre(string n)
    {
        bool fijacionCorrecta = false;
        if (n.length() >= TAM_MIN_NOMBRE_MATERIA && n.length() <= TAM_MAX_NOMBRE_MATERIA)
        {
            nombre = n;
            fijacionCorrecta = true;
        }
        return fijacionCorrecta;
    }
    bool fijaAcronimo(string a)
    {
        bool fijacionCorrecta = false;
        if (a.length() >= TAM_MIN_ACRONIMO_MATERIA && a.length() <= TAM_MAX_ACRONIMO_MATERIA)
        {
            acronimo = a;
            fijacionCorrecta = true;
        }
        return fijacionCorrecta;
    }
    bool fijaDiasClase(string d)
    {
        bool fijacionCorrecta = false;
        if (d.length() >= TAM_MIN_DIASCLASE_MATERIA && d.length() <= TAM_MAX_DIASCLASE_MATERIA)
        {
            diasClase = d;
            fijacionCorrecta = true;
        }
        return fijacionCorrecta;
    }
    bool fijaHoraInicio(int i)
    {
        bool fijacionCorrecta = false;
        if (i > C_0 && i <= MAX_HORAS)
        {
            horaInicio = i;
            fijacionCorrecta = true;
        }
        return fijacionCorrecta;
    }
    bool fijaHoraFin(int f)
    {
        bool fijacionCorrecta = false;
        if (f > C_0 && f <= MAX_HORAS)
        {
            horaFin = f;
            fijacionCorrecta = true;
        }
        return fijacionCorrecta;
    }
    string dameNombre()
    {
        return nombre;
    }
    string dameAcronimo()
    {
        return acronimo;
    }
    string dameDiasClase()
    {
        return diasClase;
    }
    int dameHoraInicio()
    {
        return horaInicio;
    }
    int dameHoraFin()
    {
        return horaFin;
    }
    string aTexto()
    {
        stringstream salida;
        salida << dameNombre() << " (" << dameAcronimo() << ") ";
        salida << dameDiasClase() << " ";
        salida << dameHoraInicio() << "a" << dameHoraFin();
        return salida.str();
    }
    string aCadena()
    {
        stringstream salida;
        salida << nombre << '|';
        salida << acronimo << '|';
        salida << diasClase << '|';
        salida << horaInicio << '|';
        salida << horaFin;
        return salida.str();
    }
};

#endif // MATERIA_H_INCLUDED
