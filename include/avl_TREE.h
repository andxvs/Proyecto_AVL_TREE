// Se incluyen todas las librerias necesarias para el programa 
// Andres Valverde Saborio - B37198

#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <cstring>
#include <cctype>
#include <ctime>
#include <stdio.h>

using namespace std;

// Se define la estructura de los nodos con struct
// Dentro de los struc se definen los hijos derecho e izquierdo, cedula, nombre y altura

struct Nodo
{
    Nodo* lc; 
    Nodo* rc;
    int haltura;
    string nombre;
    uint32_t cedula;
};


enum Errores // Se definen los errores con valores numericos negativos
{
    nombre_invalido = -1,
    valor_invalido = -4,
};

enum Positivo // se definen los aciertos con  valores numericos positivos
{
    parametro_correcto = 2,
};

// Todas las funciones a utilizar
Nodo* AVL_TREE(string lista);
Nodo* Insert_AVL(string nombre, string ID, Nodo* puntero);
Nodo* AVL_CREACION_NODO(string name, string ID);
Nodo* RotacionR(Nodo* &t);
Nodo* RotacionL(Nodo* &t);
Nodo* RotacionLL(Nodo* &t);
Nodo* RotacionRR(Nodo* &t);
Nodo* Min_AVL(Nodo* t);
Nodo* Max_AVL(Nodo* t);
int Altura(Nodo* t);
int Balanceo(Nodo* puntero);
int Verificacion_Cedula(string id);
int Verificacion_Nombre(string name);
Nodo* AVL_Search(uint32_t id, Nodo* puntero);
