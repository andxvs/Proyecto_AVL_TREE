# Proyecto_AVL_TREE

En este proyecto se crear un AVL TREE, a partir de una lista formato .txt de Nombres y Cedulas.
En este proyecto se crearon tres archivos.cpp y uno .h

Archivos .cpp:
              * avl_TREE.cpp : Que corresponde al codigo en donde se encuentran todas las funciones que realizan toda la estructura de                                    datos
              * main.cpp : Que corresponde al codigo para la ejecucion del programa principal
              * unittest.cpp : Que corresponde al codigo en donde se realizan las prueba unitarias
              
El proyecto tambien incluye un archivo tipo header llamado avl_TREE.h, en donde se definen todas las librerias utilizadas en la estrutura de datos. Se definen tambien todas las funciones a utilizar por el programa y la forma en la que se crearan los nodos del arbol.

El programa en si funciona de la siguiente manera:
- Se debe acceder al directorio en donde se encuentra el makefile en ../build/makefile, y se debe de ingresar en el terminal la palabra make. Luego de esto, se van a crear los objetos para poder ser ejecutados a la hora de correr el programa en la carpeta ../obj/ , a su vez se crean los ejectuables tanto del AVL_TREE como del uni_test.

- make run: Corre el programa principal en donde se le pide al usuario que ingrese la lista que desea utilizar para la creacion del arbol.
            Luego se imprimen los nombres y cedulas de la lista, se muestran el nodo maximo y el nodo minimo y se muestra la altura del   
            arbol creado y su root.
            Luego se pide al usuario que digite un numero de cedula para buscarlo en el programa
            
- make run_unittest: Se corren las pruebas unitarias realizadas para el programa.

- make clear: Elimina todos los archivos creados en los directorios

* Los tiempos de respuesta del programa se observan en la carpeta ../datos. 
** Sin embargo para ejecutarlos desde el programa se debe de quitar los comentarios al final del codigo main.cpp. Es importante resaltar que al ejecutar estos tiempos, la terminal imprime los datos de todas las listas. (Eso se debe corregir)
