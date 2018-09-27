// main.cpp - Andres Valverde Saborio - B37198

#include"../include/avl_TREE.h"


using namespace std;

int main()
{
  // Variables a utilizar en la funcion main
    Nodo* Root = new Nodo;
    Nodo* Nodo_Max = new Nodo;
    Nodo* Nodo_Min = new Nodo;
    Nodo* Search = new Nodo;
    char* prueba;
    string lista;
    string direccion = "../listas/";
    string nombre_lista = "lista_";
    string txt = ".txt";
    string cedula;
    uint32_t cedulita;

    // Se le pide al usuario que ingrese uno de los numeros de las listas disponibles.
    cout << "Digite la lista que desea convertir en un AVL TREE digitando el numero 10, 100, 1000, 5000 o 10000:" << endl;
    cout<< "La lista de debe ser escrita como: ";

    // El numero ingresado debe ser 10, 100, 1000. 5000 o 10000.
    cin >> lista;
  	string path = direccion + nombre_lista + lista + txt;
    cout << "La lista escogida es:" << path << endl;

    Root = AVL_TREE(path); // Se inicia la construccion del AVL TREE con la lista seleccionada anteriormente
    Nodo_Max = Max_AVL(Root); // Se pide el nodo mas grande 
    cout << "Valor del nodo maximo: " << Nodo_Max->cedula << endl;
    Nodo_Min = Min_AVL(Root); // Se pide el nono mas peque;o
    cout << "Valor del nodo minimo: " << Nodo_Min->cedula << endl;
    int H = Altura(Root); // se pide la altura del arbol
    cout << "La altura del arbol es: " << H << endl; 
    cout << "El Root del arbol es: " << Root->nombre << ", "<<Root->cedula << endl; // Se define el root del arbol
    cout << "Digite un numero de cedula: " << endl;
    cin >> cedula; // se le pide al usuario que digite un numero de cedula para buscarlo en el arbol
    cedulita = strtol(cedula.c_str(), &prueba, 10); // se pasa de string a uint32
    Search = AVL_Search(cedulita, Root); // se pide buscar el valor de la cedula en el arbol
    if(Search->cedula == cedulita)
    {
      cout << "Se encontro la cedula " << cedula << " y su nombre es " << Search->nombre << endl;
    }
    else
    {
      cout<< "La cedula ingresada no esta en la lista" << endl;
    }

// ALGORITMO PARA CALCULAR LOS TIEMPOS DE RESPUESTA DE CADA LISTA
// Sin embargo una vez puesto en funcionamiento se crashea la terminal por lo que no se puede ver si la busqueda 
// de la cedula se realizo de forma correcta

    // Funciones para hallar el tiempo de respuesta de cada una de las listas
/*    fstream Archivo_SALIDA("../datos/tiempos.txt", fstream :: out);
    string nombre;

    double ts;
    double te;

    cout << "Tiempo de respuesta de las listas: " << endl << endl;

    Nodo* prueba1 = new Nodo;
    ts = clock();
    nombre = "../listas/lista_10.txt";
    prueba1 = AVL_TREE(nombre);
    te = clock();
    Archivo_SALIDA << ((te-ts)/CLOCKS_PER_SEC) << endl;
    delete prueba1;

    Nodo* prueba2 = new Nodo;
    ts = clock();
    nombre = "../listas/lista_100.txt";
    prueba1 = AVL_TREE(nombre);
    te = clock();
    Archivo_SALIDA << ((te-ts)/CLOCKS_PER_SEC) << endl;
    delete prueba2;

    Nodo* prueba3 = new Nodo;
    ts = clock();
    nombre = "../listas/lista_1000.txt";
    prueba1 = AVL_TREE(nombre);
    te = clock();
    Archivo_SALIDA << ((te-ts)/CLOCKS_PER_SEC) << endl;
    delete prueba3;

    Nodo* prueba4 = new Nodo;
    ts = clock();
    nombre = "../listas/lista_5000.txt";
    prueba1 = AVL_TREE(nombre);
    te = clock();
    Archivo_SALIDA << ((te-ts)/CLOCKS_PER_SEC) << endl;
    delete prueba4;

    Nodo* prueba5 = new Nodo;
    ts = clock();
    nombre = "../listas/lista_10000.txt";
    prueba1 = AVL_TREE(nombre);
    te = clock();
    Archivo_SALIDA << ((te-ts)/CLOCKS_PER_SEC) << endl;
    delete prueba5;


    cout << "Programa Terminado" << endl;


*/
// Se eliminan todos los nodos creados para 
    delete Search;
  	delete Root;
    delete Nodo_Max;
    delete Nodo_Min;
    return 0;
}
