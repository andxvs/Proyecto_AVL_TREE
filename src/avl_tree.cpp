#include<iostream>
#include<string>
#include<fstream>
#include<cctype>
#include"../include/avl_tree.h"

using namespace std;

int Altura(Nodo* puntero);

// Se inicializa la lectura del archivo.txt con la funcion llamada_lista().
// Variables de la lista
char end;

Nodo* avl_tree_create(string id, string name, string lista, Nodo *puntero)
{
  int nodos = 0, elementos = 0;
  Nodo* nuevo_nodo = new Nodo;
  nuevo_nodo = nullptr;
  Nodo* R = new Nodo;
  R = nullptr;

  ifstream Lista_Cedulas(lista);
  if (Lista_Cedulas.is_open())
  {
    while (Lista_Cedulas.good())
    {
      getline(Lista_Cedulas, id, ',');
      getline(Lista_Cedulas, name);
      Verificacion_Cedula(id);
      elementos++;
      Verificacion_Nombre(name);
// Se llama a la funcion avl_tree_insert() para insertar los valores
      nuevo_nodo = avl_tree_nodo(id, name);
      R = avl_tree_insert(nuevo_nodo, R);
      nodos++;
          //nuevo_root = avl_tree_insert(nuevo_nodo, R);
    }
  }
  Lista_Cedulas.close();
  cout << "El arbol se creo correctamente" << endl;
  cout << "El numero de elementos leidos es: " << nodos << endl;
  cout << "El numero de elementos insertados es: " << elementos << endl;
  cout << "Errores encontrados en el arbol: " << nodos - elementos << endl;

  return puntero;
}

int Verificacion_Cedula(string ced)
{
  char* end;
  long int cedulita;
  cedulita = strtol(ced.c_str(), &end, 10);
  long int max_cedula = 999999999;
  long int min_cedula = 100000000;
  if(*end != '\0' || cedulita <= 0)
    return out_of_bonds;

// Guardar variable ced como cedulita
  if(cedulita > max_cedula)
  {
    cout<<"El valor de la cedula es mayor al valido"<< endl;
    return out_of_bonds;
  }
  if(cedulita < min_cedula)
  {
    cout <<"El valor de la cedula es menor al valido"<< endl;
    return out_of_bonds;
  }
  else
  {
    cout<<"El valor de la cedula es valido"<< endl;
    return correcto;
  }
}

int Verificacion_Nombre(string nom)
{
  cout<< nom << endl;
  char prueba[nom.size()];
  int tam;
  strcpy(prueba, nom.c_str());
  tam = nom.size();

  for (int i = 0; tam > i; i++)
  {
    if(!isalpha(prueba[i]) && prueba[i]!= ' ')
    {
      cout << "El nombre no posee un formato valido" << endl;
      return error_paramtero;
    }
  }
  cout<< "El nombre tiene un formato valido" << endl;
  return correcto;
}

Nodo* avl_tree_nodo(string id, string name)
{
  char* end;
  uint32_t ced;

  ced = strtol(id.c_str(), &end, 10);
  Nodo *puntero = new Nodo;
  puntero-> nombre = name;
  puntero-> cedula = ced;
  puntero-> lc = nullptr;
  puntero-> rc = nullptr;
  puntero-> padre = nullptr;
  puntero-> haltura = 0;

  return puntero;
}


Nodo* avl_tree_insert(Nodo *nuevo, Nodo* anterior)
{
  if(anterior == nullptr)
  {
    anterior = nuevo; // SE definen iguales ambos Nodos
    return anterior;
  }
  if(anterior->cedula > nuevo->cedula)
  {
    anterior->lc = avl_tree_insert(nuevo, anterior->lc);
    if(Altura(anterior->lc)-Altura(anterior-> rc) == 2)
    {
      if(nuevo->cedula < anterior->lc->cedula)
        anterior = RotacionR(anterior);
      else
        anterior = RotacionRR(anterior);
    }
  }
  if(nuevo->cedula > anterior->cedula)
  {
    anterior-> rc = avl_tree_insert(nuevo, anterior->rc);
    if(Altura(anterior->rc)-Altura(anterior-> lc) == 2)
    {
      if(nuevo->cedula > anterior->rc->cedula)
        anterior = RotacionL(anterior);
      else
        anterior = RotacionLL(anterior);
    }
  }

  anterior->haltura = max(Altura(anterior->lc), Altura(anterior->rc))+1;
  return anterior;
}

// Rotaciones para el Balanceo

Nodo* RotacionL(Nodo* &puntero)
{
  Nodo* rot = puntero-> rc;
  puntero->rc = rot->lc;
  rot-> lc = puntero;
  puntero->haltura = max(Altura(puntero-> lc),Altura(puntero->rc))+1;
  rot->haltura = max(Altura(puntero->rc), puntero->haltura)+1;
  return rot;
}

Nodo* RotacionLL(Nodo* &puntero)
{
  puntero->rc = RotacionR(puntero->rc);
  return RotacionL(puntero);
}

Nodo* RotacionR(Nodo* &puntero)
{
  Nodo* rot = puntero-> lc;
  puntero->lc = rot->rc;
  rot->rc = puntero;
  puntero->haltura = max(Altura(puntero->lc),Altura(puntero->rc))+1;
  rot->haltura = max(Altura(puntero->lc), puntero->haltura)+1;
  return rot;
}


Nodo* RotacionRR(Nodo* &puntero)
{
  puntero->lc = RotacionL(puntero->lc);
  return RotacionR(puntero);
}

int avl_tree_altura(Nodo* puntero)
{
  if(puntero == nullptr)
    return 0;
  return puntero->haltura;
}
//Funcion para obtener el valor de root
/*int avl_tree_root(Nodo* puntero)
{
  if(puntero == nullptr)
  {
    cout<<"El root es nulo" << endl;
    return out_of_bonds;
  }

  else
  {
    cout << "El valor del root es: ";
    cout << puntero-> nombre;
    cout << "," << puntero->cedula << endl;
  }
  return archivo_correcto;
}
*/

Nodo* avl_tree_findMax(Nodo* puntero)
{
  if(puntero == nullptr)
    return NULL;
  else if (puntero->rc == nullptr)
    return puntero;
  else
    return avl_tree_findMax(puntero->rc);
}

Nodo* avl_tree_findMin(Nodo* puntero)
{
  if(puntero == nullptr)
    return NULL;
  else if (puntero->lc == nullptr)
    return puntero;
  else
    return avl_tree_findMin(puntero->lc);
}

int Altura(Nodo* puntero)
{
  if (puntero == nullptr)
    return 0;
  else
    return puntero->haltura;
}

int avl_tree_balanced(Nodo* puntero)
{
  int altura_izq, altura_der, h;
  if(puntero == nullptr)
    return 0;

  altura_izq = avl_tree_altura(puntero->lc);
  altura_der = avl_tree_altura(puntero->rc);

  h=altura_izq - altura_der;

  return h;

}

//Buscar cedula
int search(Nodo* nodito, uint32_t id)
{
  while(nodito!= nullptr){
    if(nodito->cedula== id){
      return Arhivo_encontrado;
    }
    else if(id < nodito->cedula) nodito = nodito -> lc;
    else nodito = nodito-> rc;
  }
  return out_of_bonds;
}

// FUncion para contar nodos
int avl_tree_contador_nodos(Nodo* contador)
{
  int cuenta = 1;
  if(contador->lc != nullptr)
  {
    cuenta+=avl_tree_contador_nodos(contador->lc);
  }
  if(contador->rc != nullptr)
  {
    contador+=avl_tree_contador_nodos(contador->rc);
  }
  return cuenta;
}

// Funcion para borrar el arbol
int avl_tree_delete(Nodo* borrar)
{
  Nodo* hijo_izq = borrar->lc;
  Nodo* hijo_der = borrar->rc;

  if(hijo_izq!= nullptr)
    avl_tree_delete(hijo_izq);
  if(hijo_der!= nullptr)
    avl_tree_delete(hijo_der);

  delete borrar;
	return funion_correcta;
}
