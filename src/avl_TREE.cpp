// avl_TREE.cpp - Andres Valverde Saborio - B37198

#include "../include/avl_TREE.h"

using namespace std;


Nodo* AVL_TREE(string lista) // Se define una funcion que recibe el nombre de la lista cuando se ejecuta el programa
{
    string Lista, Cedula, Nombre; 
    Nodo* AVL = new Nodo; // Se crea un espacio en memoria del tipo Nodo
    AVL = nullptr;
    int nodos, archivos_leidos;

    ifstream Lista_Cedulas(lista); // Se lee un archivo de texto de algunas de las listas
    if (Lista_Cedulas.is_open()) // comando para verificar que la lista se abrio de forma exitosa
    {
      while (Lista_Cedulas.good())
      {
            getline(Lista_Cedulas, Nombre, ','); // se guarda el nombre 
            getline(Lista_Cedulas, Cedula); // se guarda el numero de cedula
            // ambos pasan a funciones que revisan su validez
            Verificacion_Nombre(Nombre); 
            Verificacion_Cedula(Cedula);
            if(Verificacion_Nombre(Nombre) && Verificacion_Cedula(Cedula) == parametro_correcto)
            {
                // si ambos datos son validos, se inserta el Nodo en el arbol
              AVL = Insert_AVL(Nombre, Cedula, AVL);
              nodos++;
            }
            cout << Nombre << ", " << Cedula << endl;
            archivos_leidos ++;
        }
    Lista_Cedulas.close();
    }

    cout << "Archivo leidos: " << archivos_leidos << endl;
    cout << "Nodos creados: " << nodos << endl;

    return AVL;
}

// Funcion que inserta los nodos en el arbol
Nodo* Insert_AVL(string nombre, string ID, Nodo* puntero)
{
    uint32_t cedu;
    char* fin;

    if(puntero == nullptr)
    {
       puntero = AVL_CREACION_NODO(nombre, ID);
       return puntero;
    }

    cedu = strtol(ID.c_str(), &fin, 10);
    if(cedu < puntero->cedula)
    {
        puntero->lc = Insert_AVL(nombre, ID, puntero->lc);
        if(Altura(puntero->lc)-Altura(puntero->rc) == 2)
        {
            if(cedu < puntero->lc->cedula)
                puntero = RotacionR(puntero);
            else
                puntero = RotacionRR(puntero);

        }
    }

    if (cedu > puntero->cedula)
    {
        puntero->rc = Insert_AVL(nombre, ID, puntero->rc);
        if (Altura(puntero->rc)-Altura(puntero->lc) == 2)
        {
            if(cedu > puntero->rc->cedula)
                puntero = RotacionL(puntero);
            else
                puntero = RotacionLL(puntero);
        }
    }

    puntero->haltura = max(Altura(puntero->lc), Altura(puntero->rc))+1;
    return puntero;
}

// funcion para crear un nodo 
Nodo* AVL_CREACION_NODO(string name, string ID)
{
    Nodo* Nuevo_Nodo = new Nodo;
    char* prueba;
    uint32_t ced;

    ced = strtol(ID.c_str(), &prueba, 10);

    Nuevo_Nodo->nombre = name;
    Nuevo_Nodo->cedula = ced;
    Nuevo_Nodo->lc = nullptr;
    Nuevo_Nodo->rc = nullptr;
    Nuevo_Nodo->haltura = 0;

    return Nuevo_Nodo;
}


// Funciones para la revision del numero de cedula

int Verificacion_Cedula(string id)
{
    long int MAX_ID = 999999999;
    long int MIN_ID = 100000000;
    char* prueba;
    long int cedulita;
// Se convierte el string a variable tipo long int y luego se pasa uint32_t
    cedulita = strtol(id.c_str(), &prueba, 10);

    if (cedulita > MAX_ID)
    {
        cout << "El valor de cedula tiene mas de 9 digitos" << endl;
        return valor_invalido;
    }

    else if (cedulita < MIN_ID)
    {
        cout << "La cedula posee menos de 9 digitos" << endl;
        return valor_invalido;

    }

    else
        return parametro_correcto;
}

// Funcion para la revision del nombre
int Verificacion_Nombre(string name)
{
  int tam = name.size();

  int i = 0;
//  int u = tam -1;
  char prueba[tam];
  strcpy(prueba, name.c_str());
  while (prueba[i])
  {
    if (isalpha(prueba[i]) && prueba[i] == ' ') return parametro_correcto;
    i++;
  }
  return nombre_invalido;
  cout <<"El nombre no es valido " << endl;
}
  /*strcpy(prueba, name.c_str());

 // Revisa todo el string del nombre para ver si es valido
  for (int i = 0; i < tam; i++)
  {

    if(!isalpha(prueba[i]) && prueba[i] != ' ')
    {
      return nombre_invalido;
      cout<<"El nombre ingresado no es valido " << name << endl;
    }

    return parametro_correcto;
    cout <<"El nombre "

  }*/

// Funcion para hacer una rotacion simple a la derecha
Nodo* RotacionR(Nodo* &t)
{
    Nodo* rot = t->lc;
    t->lc = rot->rc;
    rot->rc = t;
    t->haltura = max(Altura(t->lc), Altura(t->rc))+1;
    rot->haltura = max(Altura(rot->lc), t->haltura)+1;
    return rot;
}

// Funcion para hacer una rotacion simple a la izquierda
Nodo* RotacionL(Nodo* &t)
{
    Nodo* rot = t->rc;
    t->rc = rot->lc;
    rot->lc = t;
    t->haltura = max(Altura(t->lc), Altura(t->rc))+1;
    rot->haltura = max(Altura(t->rc), t->haltura)+1 ;
    return rot;
}

// Funcion para hacer una rotacion doble a la izquierda
Nodo* RotacionLL(Nodo* &t)
{
    t->rc = RotacionR(t->rc);
    return RotacionL(t);
}

// Funcion para hacer una rotacion doble a la derecha
Nodo* RotacionRR(Nodo* &t)
{
    t->lc = RotacionL(t->lc);
    return RotacionR(t);
}

// Funcion para hallar el valor de cedula del nodo minimo
Nodo* Min_AVL(Nodo* t)
{
    if(t == nullptr)
        return nullptr;
    else if(t->lc == nullptr)
        return t;
    else
        return Min_AVL(t->lc);
}

// Funcion para hallar el valor de cedula del nodo maximo
Nodo* Max_AVL(Nodo* t)
{
    if(t == nullptr)
        return nullptr;
    else if(t->rc == nullptr)
        return t;
    else
        return Max_AVL(t->rc);
}

// Funcion para determinar la altura
int Altura(Nodo* t)
{
    if( t == nullptr)
      return -1;
    else
      return t->haltura;
}

// Funcion para determinar el factor de balanceo de un nodo
int Balanceo(Nodo* puntero)
{
    if(puntero == nullptr)
        return 0;
    else
        return Altura(puntero->lc) - Altura(puntero->rc);
}

// Funcion para buscar un numero de cedula en el arbol
Nodo* AVL_Search(uint32_t id, Nodo* puntero)
{
  Nodo* max = Max_AVL(puntero);
  Nodo* min = Min_AVL(puntero);
  if (id < min->cedula || id > max->cedula)
  {
    puntero-> cedula = 0;
    return puntero;
  }
  while(puntero!= nullptr)
  {
    if (puntero-> cedula== id)
    {
      return puntero;
    }
    if (id < puntero-> cedula)
    {
      puntero = AVL_Search(id, puntero->lc);
    }
    if(id > puntero-> cedula)
    {
      puntero = AVL_Search(id, puntero->rc);
    }
  }
  return puntero;
}
