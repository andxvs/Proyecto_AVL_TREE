#include<iostream>
#include"avl_tree.h"
#include<string>

using namespace std;


// Unitest
int main(
{
//
int pruebaCedulaGRANDE(string cedula)
{
  char* end;
  uint32_t max_cedula = 999999999;
  cout<<"Digite el valor de una cedula mayor a 999999999"<<endl;
  getline(cin, cedula);
  uint32_t id;
  id = strtol(cedula.c_str(), &end, 10);
  if( id > max_cedula)
    return out_of_bonds;
  else
    return correcto;
}

int pruebaCedulaNONUMERICA(string cedula)
{
  char prueba[100];
  int tam = cedula.size();
  for (int i = 0; tam > i; i++)
  {
    if(!isalpha(prueba[i]))
    {
      cout << "El nombre no posee un formato valido" << endl;
      return error_paramtero;
    }
  }
  cout<< "El nombre tiene un formato valido" << endl;
  return correcto;
}

int pruebaCedulaNOVALIDA(string cedula)
{
  char* end;
  string cedu;
  uint32_t min_cedula = 100000000;
  cout<<"Digite el valor de una cedula menor a 100000000"<<endl;
  getline(cin, cedula);
  uint32_t id;
  id = strtol(cedula.c_str(), &end, 10);
  if( id < min_cedula)
    return out_of_bonds;
  else
    return correcto;
}

Nodo* insert_NodoNULO(Nodo* null_node)
{
  Nodo* nuevo = new Nodo;
  nuevo -> lc = nullptr;
  nuevo -> rc = nullptr;
  nuevo -> haltura = 0;
  nuevo -> padre = nullptr;
  nuevo -> nombre = "";
  nuevo -> cedula = 0;

  return null_node;
}
