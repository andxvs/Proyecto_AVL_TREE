// unittest.cpp - Andres Valverde Saborio - B37198

#include<iostream>
#include"../include/avl_TREE.h"


using namespace std;

// Se realizan 5 pruebas para ver diferentes funciones del programa

// Unitest
int main()
{
  Nodo* nuevo = new Nodo; 
  // Prueba 11, cedula con mas de 9 digitos
  cout << "En esta prueba se introducira una cedula con mas de 9 digitos"<< endl;
  cout << "La cedula ingresada es: 1000000000" << endl;
  Verificacion_Cedula("10000000000");
  cout << endl;
  cout << endl;

  //PRUEBA 2: CEDULA CON MENOS DE 9 digitos
  cout<< "En esta prueba se introducira una cedula con menos de 9 digitos" << endl;
  cout << "La cedula ingresada es: 10000000" << endl;

  Verificacion_Cedula("10000000");

  cout << endl;
  cout << endl;
  //PRUEBA 3: NOMBRE NO valido
  cout<< "En esta prueba se introducira un nombre invalido" << endl;
  cout<< "EL nombre ingresado es: AND1000" << endl;
  int res = Verificacion_Nombre("AND1000");
  if(res == nombre_invalido)
  {
    cout << "El nombre es invalido. " << endl;
  }
  cout << endl;
  cout << endl;

  //PRUEBA 4: NOMBRE VALIDO
  cout<< "En esta prueba se introducira un nombre invalido" << endl;
  cout<< "EL nombre ingresado es: AND1000" << endl;
  int res = Verificacion_Nombre("ANDRES VALVERDE SABORIO");
  if(res == parametro_correcto)
  {
    cout << "El nombre es valido. " << endl;
  }
  cout << endl;
  cout << endl;
  //Prueba 5: NODO NULO
  cout<< "En esta prueba se introduce un nodo nulo al arbol." << endl;
  // Se definen los valores del nodo
  string nombre = "";
  string id = "0";

  nuevo->lc = nuevo->rc = nullptr;
  nuevo->cedula = 0;
  nuevo->nombre = "";
  nuevo->haltura = 0;

  nuevo = Insert_AVL(nombre, id, nuevo);
  cout << "Se creo un nodo nulo:" << endl;
  cout << "Cedula: "<< nuevo->cedula << endl;
  cout << "Nombre: "<< nuevo->nombre << endl;
  cout << "Altura: "<< nuevo->haltura << endl;

  delete nuevo;
  return 0;

}
