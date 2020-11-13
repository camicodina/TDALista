#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
#include "lista.h"

/*
 * Crea la lista reservando la memoria necesaria.
 * Devuelve un puntero a la lista creada o NULL en caso de error.
 */
lista_t* lista_crear(){
    lista_t* lista = malloc(sizeof(lista_t));
    if(!lista) return NULL;
    return lista;
}

/*
 * Inserta un elemento al final de la lista.
 * Devuelve 0 si pudo insertar o -1 si no pudo.
 */

nodo_t* crear_nuevo_nodo(void* elemento){
    nodo_t* nodo = malloc(sizeof(nodo_t));
    if(!nodo) return NULL;
    nodo->elemento = elemento;
    nodo->siguiente = NULL;
    return nodo;
}


int lista_insertar(lista_t* lista, void* elemento){
    if(!lista) return -1;
    if(!elemento) return -1;
    nodo_t* nuevo_nodo = crear_nuevo_nodo(elemento);
    if (lista_vacia(lista)){
        lista->nodo_inicio = nuevo_nodo;
        lista->nodo_fin = nuevo_nodo;
    }else{
        lista->nodo_fin->siguiente = nuevo_nodo;
        lista->nodo_fin = nuevo_nodo;
    }
    (lista->cantidad)++;
    return 0;
}
/*
 * Inserta un elemento en la posicion indicada, donde 0 es insertar
 * como primer elemento y 1 es insertar luego del primer elemento.  
 * En caso de no existir la posicion indicada, lo inserta al final.
 * Devuelve 0 si pudo insertar o -1 si no pudo.
 */

int lista_insertar_en_posicion(lista_t* lista, void* elemento, size_t posicion){
    if(!lista) return -1;
    if(!elemento) return -1;
    if(!posicion) return -1;
    size_t contador = 0;
    if(posicion>=lista->cantidad || posicion<0 || lista_vacia(lista)){
        lista_insertar(lista, elemento);
    }else{
        nodo_t* nodo_a_agregar = crear_nuevo_nodo(elemento);
        if(posicion == 0){
            nodo_a_agregar->siguiente = lista->nodo_inicio;
            lista->nodo_inicio = nodo_a_agregar;
        }else{
            nodo_t* aux_buscar = lista->nodo_inicio;
            while(contador< posicion){
			        aux_buscar = aux_buscar->siguiente;
		    }
            nodo_a_agregar->siguiente = aux_buscar->siguiente;
            aux_buscar->siguiente = nodo_a_agregar;   
        }
        (lista->cantidad)++;
    };
    return 0;
}

/*
 * Quita de la lista el elemento que se encuentra en la ultima posición.
 * Devuelve 0 si pudo eliminar o -1 si no pudo.
 */
int lista_borrar(lista_t* lista){
    if(!lista) return -1;
    if(lista_vacia(lista)) return -1;
    nodo_t* aux_buscar = lista->nodo_inicio;
    while(aux_buscar->siguiente != lista->nodo_fin){
		aux_buscar = aux_buscar->siguiente;
	}
    nodo_t* borrame = malloc(sizeof(borrame));
    if(!borrame) return -1;
    borrame->siguiente = aux_buscar->siguiente;
    aux_buscar->siguiente = NULL;
    free(borrame->siguiente);
    free(borrame);
    (lista->cantidad)--;
    return 0;
}

/*
 * Quita de la lista el elemento que se encuentra en la posición
 * indicada, donde 0 es el primer elemento.  
 * En caso de no existir esa posición se intentará borrar el último
 * elemento.  
 * Devuelve 0 si pudo eliminar o -1 si no pudo.
 */

int lista_borrar_de_posicion(lista_t* lista, size_t posicion){
    if(!lista) return -1;
    if(!posicion) return -1;
    size_t contador = 0;
    if(posicion>=lista->cantidad || posicion<0 || lista_vacia(lista)){
        lista_borrar(lista);
    }else{
        nodo_t* aux_buscar = lista->nodo_inicio;
        if(posicion == 0){
            aux_buscar = aux_buscar->siguiente;
	        free(lista->nodo_inicio);
	        lista->nodo_inicio = aux_buscar;
        }else{
            while(contador< posicion){
                    aux_buscar = aux_buscar->siguiente;
                    contador++;
            }
            nodo_t* borrame = malloc(sizeof(borrame));
            if(!borrame) return -1;
            borrame->siguiente = aux_buscar->siguiente;
            aux_buscar->siguiente = (aux_buscar->siguiente)->siguiente;
            free(borrame->siguiente);
            free(borrame);
        }
        (lista->cantidad)--;   
    }
    return 0;
}
/*
 * Devuelve el elemento en la posicion indicada, donde 0 es el primer
 * elemento.
 *
 * Si no existe dicha posicion devuelve NULL.
 */

void* lista_elemento_en_posicion(lista_t* lista, size_t posicion){
    if(!lista) return NULL;
    if(!posicion) return NULL;
    size_t contador = 0;
    if(posicion>lista->cantidad || posicion<0 || lista_vacia(lista)){
        return NULL;
    }else{
        if(posicion == 0){
            return (lista->nodo_inicio->elemento);
        }else if(posicion == lista->cantidad){
            return (lista->nodo_fin->elemento);
        }else{
            nodo_t* aux_buscar = lista->nodo_inicio;
            while(contador<=posicion){
                aux_buscar = aux_buscar->siguiente;
                contador++;
            }
            return (aux_buscar->elemento);
        }
    }
}

/* 
 * Devuelve el último elemento de la lista o NULL si la lista se
 * encuentra vacía.
 */
void* lista_ultimo(lista_t* lista){
    if(!lista) return NULL;
    if(lista_vacia(lista)){
        return NULL;
    }else{
        return (lista->nodo_fin->elemento);
    }
}

/* 
 * Devuelve true si la lista está vacía o false en caso contrario.
 */
bool lista_vacia(lista_t* lista){
    bool esta_vacia = false;
    if(lista->nodo_inicio == NULL && lista->nodo_fin == NULL && lista->cantidad==0){
        esta_vacia = true;
    }
    return esta_vacia;
}

/*
 * Devuelve la cantidad de elementos almacenados en la lista.
 */
size_t lista_elementos(lista_t* lista){
    if(!lista || lista_vacia(lista)){
        return 0;
    }else{
        return (lista->cantidad);
    }
}

/* 
 * Apila un elemento.
 * Devuelve 0 si pudo o -1 en caso contrario.
 */
int lista_apilar(lista_t* lista, void* elemento){
    if(!lista) return -1;
    if(!elemento) return -1;
    nodo_t* nuevo_nodo = crear_nuevo_nodo(elemento);
    if (lista_vacia(lista)){
        lista->nodo_inicio = nuevo_nodo;
        lista->nodo_fin = nuevo_nodo;
    }else{
        nuevo_nodo->siguiente = lista->nodo_inicio;
        lista->nodo_inicio = nuevo_nodo;
    }
    (lista->cantidad)++;
    return 0;
}

/* 
 * Desapila un elemento.
 * Devuelve 0 si pudo desapilar o -1 si no pudo.
 */
int lista_desapilar(lista_t* lista){
    if(!lista) return -1;
    if (lista_vacia(lista)){
        return -1;
    }else{
        nodo_t* borrame = malloc(sizeof(borrame));
        borrame->siguiente = lista->nodo_inicio;
        lista->nodo_inicio = lista->nodo_inicio->siguiente;
        free(borrame->siguiente);
        free(borrame);
        (lista->cantidad)--;
    }
    return 0;
}

/*
 * Devuelve el elemento en el tope de la pila o NULL
 * en caso de estar vacía.
 */
void* lista_tope(lista_t* lista){
    if(!lista) return NULL;
    if (lista_vacia(lista)){
        return NULL;
    }else{
        return lista_ultimo(lista);
    }
}

/* 
 * Encola un elemento.
 * Devuelve 0 si pudo encolar o -1 si no pudo.
 */
int lista_encolar(lista_t* lista, void* elemento){
    if(!lista) return -1;
    if(!elemento) return -1;
    return lista_apilar(lista, elemento);
}

/* 
 * Desencola un elemento.
 * Devuelve 0 si pudo desencolar o -1 si no pudo.
 */
int lista_desencolar(lista_t* lista){
    if(!lista) return -1;
    return lista_borrar(lista);
}

/*
 * Devuelve el primer elemento de la cola o NULL en caso de estar
 * vacía.
 */
void* lista_primero(lista_t* lista){
    if(!lista) return NULL;
    return lista_elemento_en_posicion(lista, 0);
}
    
/*
 * Libera la memoria reservada por la lista.
 */

void lista_destruir(lista_t* lista){
    if(lista){
        if(lista_vacia(lista)){
            free(lista);
        }else{
        while(lista->nodo_inicio != lista->nodo_fin){
            lista_borrar(lista);
        }
        free(lista->nodo_inicio);
        free(lista);
    }
    }
    
}

// --------------------------------- ITERADOR -------------------------------- //

/*
 * Crea un iterador para una lista. El iterador creado es válido desde
 * el momento de su creación hasta que no haya mas elementos por
 * recorrer o se modifique la lista iterada (agregando o quitando
 * elementos de la lista). 
 *
 * Al momento de la creación, el iterador queda listo para devolver el
 * primer elemento utilizando lista_iterador_elemento_actual.
 *
 * Devuelve el puntero al iterador creado o NULL en caso de error.
 */
lista_iterador_t* lista_iterador_crear(lista_t* lista){
    if(!lista) return NULL;
    if(lista_vacia(lista)) return NULL;
    lista_iterador_t* nuevo_iterador = malloc(sizeof(lista_iterador_t));
    if(!nuevo_iterador) return NULL;
    nuevo_iterador->lista = lista;
    nuevo_iterador->corriente = lista_iterador_elemento_actual(nuevo_iterador);
    return nuevo_iterador;
}

/*
 * Devuelve true si hay mas elementos sobre los cuales iterar o false
 * si no hay mas.
 */
bool lista_iterador_tiene_siguiente(lista_iterador_t* iterador){
    bool tiene_siguiente = true;
    if(!iterador || lista_vacia(iterador->lista) || lista_iterador_elemento_actual(iterador) == iterador->lista->nodo_fin){
        tiene_siguiente = false;
    }
    return tiene_siguiente;
}

/*
 * Avanza el iterador al siguiente elemento.
 * Devuelve true si pudo avanzar el iterador o false en caso de
 * que no queden elementos o en caso de error.
 *
 * Una vez llegado al último elemento, si se invoca a
 * lista_iterador_elemento_actual, el resultado siempre será NULL.
 */
bool lista_iterador_avanzar(lista_iterador_t* iterador){
    if(!iterador) return false;
    if(lista_iterador_tiene_siguiente(iterador) == false) return false;
    if(iterador->corriente == NULL){
        iterador->corriente = iterador->lista->nodo_inicio;
    }
    iterador->corriente = iterador->corriente->siguiente;
    return true;
}

/*
 * Devuelve el elemento actual del iterador o NULL en caso de que no
 * exista dicho elemento o en caso de error.
 */
void* lista_iterador_elemento_actual(lista_iterador_t* iterador){
    if(!iterador) return NULL;
    if(!iterador->corriente) return NULL;
    return iterador->corriente;
}

/*
 * Libera la memoria reservada por el iterador.
 */
void lista_iterador_destruir(lista_iterador_t* iterador){
    if(iterador){
        free(iterador);
    }
}

/*
 * Iterador interno. Recorre la lista e invoca la funcion con cada elemento de
 * la misma. Dicha función puede devolver true si se deben seguir recorriendo
 * elementos o false si se debe dejar de iterar elementos.
 *
 * La función retorna la cantidad de elementos iterados o 0 en caso de error.
 */
size_t lista_con_cada_elemento(lista_t* lista, bool (*funcion)(void*, void*), void *contexto){
    if(!lista) return 0;
    if(!(*funcion)) return 0;
    if(!contexto) return 0;
    if(lista_vacia(lista)) return 0;
    size_t cantidad_de_elementos_iterados = 0;
    lista_iterador_t* iterador_interno = lista_iterador_crear(lista);
    if(!iterador_interno) return 0;
    while(lista_iterador_tiene_siguiente(iterador_interno)){
        (*funcion)(lista_iterador_elemento_actual(iterador_interno), contexto);
        (cantidad_de_elementos_iterados)++;
    }
    lista_iterador_destruir(iterador_interno);
    return cantidad_de_elementos_iterados;
}



