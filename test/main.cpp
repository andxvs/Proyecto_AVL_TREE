#include<iostream>
#include"/home/andres/Proyecto1/include/avl_tree.h"
#include<string>

using namespace std;


int main()
{
  Nodo* Root = new Nodo;
  string lista;
  string id = "0";
  string name = "";
  string direccion = "../listas/";
  string nombre_lista = "lista_";
  string txt = ".txt";
  cout << "Digite la lista que desea convertir en un AVL TREE digitando el numero 10, 100, 1000, 5000 o 10000:" << endl;
  cout<< "La lista de debe ser escrita como ";
  cin >> lista;
	string path = direccion + nombre_lista + lista + txt;
  cout << "La lista escogida es:" << path << endl;
  Root = avl_tree_create(id, name, path, Root);
	delete Root;


}
