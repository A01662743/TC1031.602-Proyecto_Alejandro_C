# TC1031.602-Proyecto_Alejandro_C
Este proyecto esta diseñado para organizar y visualizar las redes sociales de un grupo específico en base al nivel de influencia de los individuos. Se puede presentar los individuos de la red por su nivel de influencia asi como por su nombre.

## SICT0301: Evalúa los componentes: Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.
La complejidad temporal del programa es de O(N * log(N)) debido al uso del Merge Sort

MergeSort O(N * log(N))
AVL O(N * log(N)): porque se hacen N inserciones y cada inserción tiene complegidad de log(N)
InOrder AVL O(N): se recorre nodo por nodo teniendo N nodos
Despliegue Alfabético O(N * log(N) + N): debido a que lo más complejo es debido al Merge Sort O(N * log(N)) y posteriormente se imprime por cada valor en el vector O(N).

el cuál tiene la complejidad dominante en este código, a comparación de (por ejemplo) el uso de un árbol AVL con complejidad O(log(N)) el cuál es menor.

## SICT0302: Toma decisiones: Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
En este caso utilizé Merge Sort O(N * log(N)) para organizar en orden ascendente a las personas en base a su nivel de influencia.
Se utiliza Merge Sort, implementado mediante vectores, por su velocidad y efectividad, en ese casos e utiliza para ordenar a los individuos alfabéticamente.

## Uso de árboles
Se hace uso de un árbol AVL para organizar mediante el nivel de influencia debido a su rapidez de O(log(N)) en todos los ámbitos (acceso, busqueda, inserción y eliminación) asi como por la necesidad de insertar nuevas Personas con valores variables de influencia que podrian degenerar el árbol fácilmente.
