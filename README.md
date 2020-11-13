
<h1 align="center">TDA Lista</h1>
<p align="center"><img width=80% src="https://sites.google.com/site/programacioniiuno/_/rsrc/1472783418341/mi-cursada---turno-noche/bitacoras/30042013-clase4-tdalista/lista-enlazada-simple-c.png"></p>

<h2 align="center">Algoritmos y Programación II <br> Méndez</h2><br>


_TDA Nº1 de Algoritmos y Programación II, Cátedra Mendez, Facultad de Ingeniería de la Universidad de Buenos Aires._


## Introducción 🚀 

Implementación de una lista simplemente enlazada. Utiliza las funciones básicas de los TDAs Pila y Cola, cumpliendo así que este satisfaga el comportamiento de las tres estructuras.
Crea, también un iterador interno y uno externo para la lista.

## Sección 1
_Explicación de lo entregado, como compilarlo (línea de compilación), como ejecutarlo (línea de ejecución) y el funcionamiento particular de la implementación_

### Modo de Uso 📝

Comandos de compilación y ejecución:

> $ gcc *.c -o lista_se -g -std=c99 -Wall -Wconversion -Wtype -limits -pedantic -Werror -O0                
> $ valgrind --leak -check=full --track -origins=yes --show -reachable=yes ./lista_se


### Funcionamiento de la implementación... ⚙

...

```C
//Codigo en C
```
(no es necesario detallar función por función, solamente explicar como funciona el código) y por qué se eligió
dicha implementación.

## Sección 2

_Desarrollo los siguientes conceptos teóricos..._

* **Listas**

Tipo de dato basado en nodos enlazados que posee una sucesor (menos el último) y un predecesor(menos el primero).
Una lista es un colección ordenada de datos que contiene un número (N) de nodos. Cada nodo contiene una cantidad específica de datos y una referencia al nodo siguiente. Cuando juntamos estos nodos, creando una especie de cadena, tenemos una lista enlazada.
Estas listas utilizan distintos métodos:
1. Crear
2. Insertar (al final)
3. Insertar en posición X
4. Borrar (del final)
5. Borrar en posición X
6. Elemento en posición X (devolver)
7. Último (devolver)
8. ¿Está vacía?
9. Destruir

y tienen distintos tipos:
1. Simplemente Enlazada
2. Doblemente Enlazada
3. Circular
4. Circular doble

La simple es una implementación con nodos donde cada uno refiere al siguiente, manteniendo referencia al primer nodo mientras que la doblementente enlazada mantiene referencia del principio y final del nodo.


* **Pilas y Colas**

2. ¿Cuáles son las características fundamentales de las Pilas? ¿Y de las Colas?


* **Iteradores**
3. ¿Qué es un iterador? ¿Cuál es su función?
* **Diferencia entre Iterador Interno e Iterador Externo**
4. ¿En qué se diferencia un iterador interno de uno externo?


---

_Camila Codina_
