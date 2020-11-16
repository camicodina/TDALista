
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

> $ gcc *.c -o lista_se -g -std=c99 -Wall -Wconversion -Wtype-limits -pedantic -Werror -O0  
> $ ./lista_se

Comandos de checkeo de memoria:

> $ valgrind --leak-check=full --track-origins=yes --show-reachable=yes ./lista_se


### Funcionamiento de la implementación... ⚙

**1. Lista:**

- La lista se crea inicialmente siendo sus nodos inicial y final NULL y teniendo una cantidad inicial de 0 nodos. 
- A la hora de agregar un nodo al final de la lista, primero reserva memoria para un nodo cuyo elemento es el pasado por parámetro y su "siguiente" apunta a NULL. Verifica si está en el estado inicial. De ser así, hace que los nodos inicial y final sean este nuevo nodo creado y la cantidad es 1. Sino, hace que el nodo final de la lista apunte al nuevo nodo en vez de a NULL y cambia el nodo final por el nuevo nodo; suma 1 a la cantidad.
- Si queremos insertar en otra posición, en caso de que la posicion sea mayor a las posiciones posibles, ejecuta la función anterior, sino, crea un nodo.<br> 
El caso más sencillo sería que la posición pedida sea 0, pero si no lo es, recorre la lista para encontrar el nodo en la posición anterior a la pedida. El nuevo nodo apuntará al nodo en la posición buscada y el nodo anterior a la misma que encontramos cambia su "siguiente" al nuevo nodo.
-  Para borrar un nodo de una posición recibida por parámetro la lógica es similar: verificamos que si la posición es mayor o igual a las posiciones posibles, debemos borrar el último llamando a la función que hace lo propio (y describo a continuación). Si la posición es válida y no es 0, recorre la lista para guardar referencia del nodo anterior y el posterior al nodo que queremos eliminar.<br>
Liberamos el nodo y hacemos que el anterior apunte al posterior.
- Borrar el último nodo copia esta lógica, asignando como posición la cantidad de nodos registrados -1 (pues las posiciones comienzan en 0 y la cantidad en 1). Sin embargo, aquí el siguiente apuntará a NULL.
- La memoria de la lista se libera con un ciclo que borra el último nodo hasta que la cantidad de nodos registrados sea 0.


**2. Pila:**
- Apilar: llama a la función de insertar un nodo al final de la lista.
- Desapilar: siguiendo la lógica de LIFO, elimina el último nodo de la lista.
- Tope: el tope es el último elemento de la lista.


**3. Cola:** 
- Encolar: como la pila, llama a la función de insertar un nodo al final de la lista.
- Desencolar: siguiendo la lógica de FIFO, elimina el primer nodo de la lista (nodo en la posición 0)


**4. Iterador externo:**
- El iterador se crea sólo si recibe una lista no vacía y su corriente apuntará al nodo inicial de la misma.
- Para avanzar, verifica si tiene o no siguiente: en caso de no tenerlo, estamos parados sobre el último elemento así que la corriente avanza a NULL y devuelve que ya no hay elementos; sino, avanza normal.

**5. Iterador interno:**
- Aumenta un contador de cantidad de elementos iterados mientras que éste sea menor a la cantidad de elementos en la lista y mientras el puntero función recibido por parámentro devuelva true.



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

La simple es una implementación con nodos donde cada uno refiere al siguiente, manteniendo referencia al primer nodo mientras que la doblementente enlazada mantiene referencia del principio y final del nodo..


* **Pilas y Colas**

1. Pilas

Son otro tipo de datos abstracto  que agrupa elementos y opera sobre ellos utilizando una lógica e Last In, Last Out (LIFO). Es decir, no podemos sacar un elemento que no esté al tope de la pila.

<p align="center"><img width=80% src="https://upload.wikimedia.org/wikipedia/commons/thumb/d/d1/Pila.svg/1200px-Pila.svg.png"></p>

Este TDA utiliza distintos métodos:
1. Crear
2. Push
3. Pop
4. Tope
5. esta_vacio
6. Destruir


2. Colas

TDA similar a las pilas pero que utiliza la lógica de First In, First Out (FIFO). Como en la cola del supermercado, el primero en llegar es el primero en ser atendido.

<p align="center"><img width=80% src="https://upload.wikimedia.org/wikipedia/commons/thumb/5/5c/ColaProg.JPG/400px-ColaProg.JPG"></p>

Este TDA utiliza distintos métodos:
1. Crear
2. Encolar
3. Desencolar
4. esta_vacio
5. Destruir

* **Iteradores**

Un iterador es un TDA que permite iterar otro TDA (por ejemplo, una lista de nodos). En vez de tener que recorrer la lista desde el comienzo hasta el elemento que quiero encontrar, el iterador nos permite acceder directamente al elemento siguiente al último que recorrí.

* **Diferencia entre Iterador Interno e Iterador Externo**

Un _iterador interno_ permite que pasemos la acción a realizar sobre cada elemento de la lista por parámetro. No necesitamos manejar memoria.

Un _iterador externo_ es una estructura con puntero a la lista. Al ocupar memoria, debe ser destruído luego de ser utilizado.


---

_Camila Codina_
