#ifndef ENTRADA_H_INCLUDED
#define ENTRADA_H_INCLUDED 1

#include <iostream>

enum class BANDERA_ENTRADA
{
    SEPARAR_ENTRADA_DATOS=C_1
};

using namespace std;

void solicitarCadena(string* cadena, string mensaje);
void solicitarEntero(int* entero, string mensaje);
void solicitarEntero(int* entero, string mensaje, int banderas);
void pausa();

void solicitarCadena(string* cadena, string mensaje)
{
    cout << mensaje;
    getline(cin, *cadena);
}

void solicitarCaracter(char* caracter, string mensaje)
{
    cout << mensaje;
    cin >> caracter;
    cin.get();
}

void solicitarEntero(int* entero, string mensaje)
{
    cout << mensaje;
    cin >> *entero;
    cin.get();
}

void solicitarEntero(int* entero, string mensaje, BANDERA_ENTRADA banderas)
{
    if (banderas == BANDERA_ENTRADA::SEPARAR_ENTRADA_DATOS)
    {
        cout << endl; // Separación de entrada de datos
    }
    cout << mensaje;
    cin >> *entero;
    cin.get();
    if (banderas == BANDERA_ENTRADA::SEPARAR_ENTRADA_DATOS)
    {
        cout << endl; // Separación de entrada de datos
    }
}

void pausa()
{
    cout << endl; // Separación de entrada de datos
    cout << "Presiona Entrar para continuar...";
    cin.get();
}

#endif // ENTRADA_H_INCLUDED
