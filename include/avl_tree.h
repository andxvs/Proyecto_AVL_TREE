
#include<iostream>
#include<string>
#include <fstream>
#include <cctype>
#include <string.h>
#include<stdio.h>

using namespace std;
struct Nodo
{
  uint32_t cedula;
  string nombre;
  Nodo* lc;
  Nodo* rc;
  Nodo* padre;
  int haltura;
};

//
enum Errores
{
  out_of_bonds = -1,
  division_por_0 = -2,
  segmentation = -3,
  error_paramtero = -4,
};

enum Correctos
{
  correcto = 2,
  Arhivo_encontrado = 3,
  funion_correcta = 4,
  archivo_correcto = 5,
};

//FUnciones utilizadas

int Altura(Nodo* puntero);
int Verificacion_Cedula(string ced);
int Verificacion_Nombre(string nom);
Nodo* avl_tree_create(string id, string name, string lista, Nodo *puntero);
Nodo* avl_tree_nodo(string id, string name);
Nodo* avl_tree_insert(Nodo *nuevo, Nodo* anterior);
Nodo* avl_tree_findMax(Nodo* puntero);
Nodo* avl_tree_findMin(Nodo* puntero);
Nodo* RotacionLL(Nodo* &puntero);
Nodo* RotacionL(Nodo* &puntero);
Nodo* RotacionRR(Nodo* &puntero);
Nodo* RotacionR(Nodo* &puntero);
int avl_tree_get_size(Nodo* puntero);
int search(Nodo* nodito, uint32_t id);
int avl_tree_contador_nodos(Nodo* contador);
int avl_tree_delete(Nodo* borrar);
int avl_tree_root(Nodo* puntero);
