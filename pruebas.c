#include "lista.h"
#include "pa2mm.h"
#include <stdio.h>

// -------------------------- PRUEBAS LISTA -------------------------- //

void probar_crear_lista_vacia(){
    lista_t* lista_inicial = NULL;

    pa2m_afirmar((lista_inicial=lista_crear()) != NULL, "Puedo crear una lista");
    pa2m_afirmar(lista_inicial->cantidad == 0, "Contiene 0 elementos");
    pa2m_afirmar(lista_inicial->nodo_inicio == NULL, "Su inicio es NULL");
    pa2m_afirmar(lista_borrar(lista_inicial) == -1, "No puedo borrar de la lista");
    pa2m_afirmar(lista_vacia(lista_inicial) == true, "Está vacía");

    lista_destruir(lista_inicial);
}


lista_t* probar_insertar_en_lista(lista_t* lista_vocales){
    char a='a',e='e',i='i',o='o',u='u';

    pa2m_afirmar((lista_vocales=lista_crear()) != NULL, "Se crea lista");
    pa2m_afirmar(lista_insertar(lista_vocales, &a) == 0, "Se inserta primer elemento");
    pa2m_afirmar(lista_vocales->cantidad == 1, "Hay un nodo");
    pa2m_afirmar(lista_insertar_en_posicion(lista_vocales, &e, 100)==0, "Si inserto en posición 100 está bien");
    pa2m_afirmar(lista_vocales->cantidad == 2, "Hay dos nodos");
    pa2m_afirmar(lista_insertar(lista_vocales, &o) == 0, "Se inserta tercer elemento");
    pa2m_afirmar(lista_vocales->cantidad == 3, "Hay tres nodos");
    pa2m_afirmar(lista_insertar_en_posicion(lista_vocales, &i, 2)==0, "Si inserto en posición 2 está bien");
    pa2m_afirmar(lista_vocales->cantidad == 4, "Hay cuatro nodos");
    pa2m_afirmar(lista_insertar(lista_vocales, &u) == 0, "Se inserta quinto elemento");
    pa2m_afirmar(lista_vocales->cantidad == 5, "Hay cinco nodos");
    pa2m_afirmar(lista_vacia(lista_vocales) == false, "No está vacía");
    pa2m_afirmar(lista_elemento_en_posicion(lista_vocales, 0) == &a, "El primer elemento es correcto");
    pa2m_afirmar(lista_elemento_en_posicion(lista_vocales, 1) == &e, "El segundo elemento es correcto");
    pa2m_afirmar(lista_elemento_en_posicion(lista_vocales, 2) == &i, "El tercer elemento es correcto");
    pa2m_afirmar(lista_elemento_en_posicion(lista_vocales, 3) == &o, "El cuarto elemento es correcto");
    pa2m_afirmar(lista_elemento_en_posicion(lista_vocales, 4) == &u, "El quinto elemento es correcto");

    return lista_vocales;
}

lista_t* probar_borrar_en_lista(lista_t* lista_vocales){
    char a='a',e='e',i='i',o='o',u='u';

    pa2m_afirmar(lista_vocales->cantidad == 5, "Hay cinco nodos");
    pa2m_afirmar(lista_elemento_en_posicion(lista_vocales, 0) == &a, "El primer elemento es correcto");
    pa2m_afirmar(lista_elemento_en_posicion(lista_vocales, 1) == &e, "El segundo elemento es correcto");
    pa2m_afirmar(lista_elemento_en_posicion(lista_vocales, 2) == &i, "El tercer elemento es correcto");
    pa2m_afirmar(lista_elemento_en_posicion(lista_vocales, 3) == &o, "El cuarto elemento es correcto");
    pa2m_afirmar(lista_elemento_en_posicion(lista_vocales, 4) == &u, "El quinto elemento es correcto");
    pa2m_afirmar(lista_borrar(lista_vocales) == 0, "Se borra ultimo elemento");
    pa2m_afirmar(lista_elemento_en_posicion(lista_vocales, 4) == NULL, "No hay quinto elemento");
    pa2m_afirmar(lista_vocales->cantidad == 4, "Hay cuatro elementos");
    pa2m_afirmar(lista_borrar_de_posicion(lista_vocales, 0) == 0, "Se borra primer elemento");
    pa2m_afirmar(lista_vocales->cantidad == 3, "Hay tres elementos");
    pa2m_afirmar(lista_elemento_en_posicion(lista_vocales, 0) == &e, "El primer elemento es correcto");
    pa2m_afirmar(lista_elemento_en_posicion(lista_vocales, 1) == &i, "El segundo elemento es correcto");
    pa2m_afirmar(lista_elemento_en_posicion(lista_vocales, 2) == &o, "El tercer elemento es correcto");

    return lista_vocales;
}


// -------------------------- PRUEBAS COLA -------------------------- //

void probar_encolar(){
    lista_t* cola = NULL;
    int a=100,b=200,c=300,d=400,e=500,f=999;

    pa2m_afirmar((cola=lista_crear()) != NULL, "Se crea cola");
    pa2m_afirmar(cola->cantidad == 0, "Contiene 0 elementos");
    pa2m_afirmar(cola->nodo_inicio == NULL, "Su inicio es NULL");
    pa2m_afirmar(lista_borrar(cola) == -1, "No puedo borrar de la cola vacía");
    pa2m_afirmar(lista_vacia(cola) == true, "Está vacía");

    pa2m_afirmar(lista_encolar(cola, &a) == 0, "Se inserta primer elemento");
    pa2m_afirmar(cola->cantidad == 1, "Hay un nodo");

    pa2m_afirmar(lista_encolar(cola, &b) == 0, "Se encola segundo elemento");
    pa2m_afirmar(lista_encolar(cola, &c) == 0, "Se encola tercer elemento");
    pa2m_afirmar(lista_encolar(cola, &d) == 0, "Se encola cuarto elemento");
    pa2m_afirmar(lista_encolar(cola, &e) == 0, "Se encola quinto elemento");
    pa2m_afirmar(lista_encolar(cola, &f) == 0, "Se encola sexto elemento");
    pa2m_afirmar(cola->cantidad == 6, "Hay seis nodos");

    pa2m_afirmar(lista_primero(cola) == &a, "El principio de la cola es correcto");
    pa2m_afirmar(lista_elemento_en_posicion(cola, 1) == &b, "El segundo elemento es correcto");
    pa2m_afirmar(lista_elemento_en_posicion(cola, 2) == &c, "El tercer elemento es correcto");
    pa2m_afirmar(lista_elemento_en_posicion(cola, 3) == &d, "El cuarto elemento es correcto");
    pa2m_afirmar(lista_elemento_en_posicion(cola, 4) == &e, "El quinto elemento es correcto");
    pa2m_afirmar(lista_elemento_en_posicion(cola, 5) == &f, "El sexto elemento es correcto");

    pa2m_afirmar(lista_desencolar(cola) == 0, "Se desencola");
    pa2m_afirmar(cola->cantidad == 5, "Hay cinco nodos");
    pa2m_afirmar(lista_primero(cola) == &b, "El principio de la cola es correcto");

    lista_destruir(cola);
}

// -------------------------- PRUEBAS PILA -------------------------- //

void probar_apilar(){
    lista_t* pila = NULL;
    int a=100,b=200,c=300,d=400,e=500,f=999;

    pa2m_afirmar((pila=lista_crear()) != NULL, "Se crea pila");
    pa2m_afirmar(pila->cantidad == 0, "Contiene 0 elementos");
    pa2m_afirmar(pila->nodo_inicio == NULL, "Su inicio es NULL");
    pa2m_afirmar(lista_borrar(pila) == -1, "No puedo borrar de la pila vacía");
    pa2m_afirmar(lista_vacia(pila) == true, "Está vacía");

    pa2m_afirmar(lista_apilar(pila, &a) == 0, "Se inserta primer elemento");
    pa2m_afirmar(pila->cantidad == 1, "Hay un nodo");

    pa2m_afirmar(lista_apilar(pila, &b) == 0, "Se apila segundo elemento");
    pa2m_afirmar(lista_apilar(pila, &c) == 0, "Se apila tercer elemento");
    pa2m_afirmar(lista_apilar(pila, &d) == 0, "Se apila cuarto elemento");
    pa2m_afirmar(lista_apilar(pila, &e) == 0, "Se apila quinto elemento");
    pa2m_afirmar(lista_apilar(pila, &f) == 0, "Se apila sexto elemento");
    pa2m_afirmar(pila->cantidad == 6, "Hay seis nodos");

    pa2m_afirmar(lista_elemento_en_posicion(pila, 0) == &a, "El primer elemento es correcto");
    pa2m_afirmar(lista_elemento_en_posicion(pila, 1) == &b, "El segundo elemento es correcto");
    pa2m_afirmar(lista_elemento_en_posicion(pila, 2) == &c, "El tercer elemento es correcto");
    pa2m_afirmar(lista_elemento_en_posicion(pila, 3) == &d, "El cuarto elemento es correcto");
    pa2m_afirmar(lista_elemento_en_posicion(pila, 4) == &e, "El quinto elemento es correcto");
    pa2m_afirmar(lista_tope(pila) == &f, "El tope de la pila es correcto");

    pa2m_afirmar(lista_desapilar(pila) == 0, "Se desapila");
    pa2m_afirmar(pila->cantidad == 5, "Hay cinco nodos");
    pa2m_afirmar(lista_tope(pila) == &e, "El tope de la pila es correcto");

    lista_destruir(pila);
}


// -------------------------- PRUEBAS ITERADOR EXTERNO -------------------------- //

void pruebas_iterador_externo_lista_vacia(){
	lista_t* lista = NULL;
	lista_iterador_t* it = NULL;

    pa2m_afirmar((lista=lista_crear()) != NULL, "Puedo crear una lista vacía");
    pa2m_afirmar(lista_vacia(lista) == true, "Está vacía");
	pa2m_afirmar((it = lista_iterador_crear(lista)) != NULL, "Puedo crear iterador de lista vacía");
	pa2m_afirmar(lista_iterador_tiene_siguiente(it) == false, "No tiene siguiente");
	pa2m_afirmar(lista_iterador_elemento_actual(it) == NULL, "No puede avanzar");

	lista_iterador_destruir(it);
    lista_destruir(lista);

}

lista_iterador_t* pruebas_iterador_externo(lista_iterador_t* iterador,lista_t* lista_vocales){

    pa2m_afirmar((iterador=lista_iterador_crear(lista_vocales))!= NULL, "Puedo crear iterador de lista no vacía");
    pa2m_afirmar(lista_iterador_tiene_siguiente(iterador) == true, "Tiene siguiente");
    pa2m_afirmar(lista_iterador_avanzar(iterador) == true, "Puede avanzar");
    pa2m_afirmar(lista_iterador_tiene_siguiente(iterador) == true, "Tiene siguiente");
    pa2m_afirmar(lista_iterador_avanzar(iterador) == true, "Puede avanzar");
    pa2m_afirmar(lista_iterador_avanzar(iterador) == false, "No puede avanzar");

    return iterador;
}

// -------------------------- PRUEBAS ITERADOR INTERNO -------------------------- //


bool mostrar(void* elemento, void* contador){
    if(elemento && contador)
        printf("Elemento %i: %c \n", (*(int*)contador)++, *(char*)elemento);
    return true;
}

void prueba_iterador_interno(){

    /* Declaro las variables a utilizar*/
    lista_t* lista = NULL;
    char c='c',a='a',m='m',i='i',l='l';

    pa2m_afirmar((lista=lista_crear()) != NULL, "Se crea lista");
    pa2m_afirmar(lista_insertar(lista, &c) == 0, "Se inserta primer elemento");
    pa2m_afirmar(lista_insertar(lista, &a) == 0, "Se inserta segundo elemento");
    pa2m_afirmar(lista_insertar(lista, &m) == 0, "Se inserta tercer elemento");
    pa2m_afirmar(lista_insertar(lista, &i) == 0, "Se inserta cuarto elemento");
    pa2m_afirmar(lista_insertar(lista, &l) == 0, "Se inserta quinto elemento");
    pa2m_afirmar(lista_insertar(lista, &a) == 0, "Se inserta sexto elemento");
    
    int contador=0;
    
    pa2m_afirmar(lista_con_cada_elemento(lista, mostrar, (void*)&contador) == 6, "El valor del contador es correcto");

    lista_destruir(lista);
}

int main(){
    lista_t* lista = NULL; 
    lista_iterador_t* it = NULL;
    

    pa2m_nuevo_grupo("PRUEBAS DE CREAR LISTA");
    probar_crear_lista_vacia(lista_vacia);

    pa2m_nuevo_grupo("PRUEBAS DE INSERTAR A LISTA");
    lista = probar_insertar_en_lista(lista);

    pa2m_nuevo_grupo("PRUEBAS DE BORRAR DE LISTA");
    lista = probar_borrar_en_lista(lista);

    pa2m_nuevo_grupo("PRUEBAS DE PILA");
    probar_encolar();

    pa2m_nuevo_grupo("PRUEBAS DE COLA");
    probar_apilar();

    pa2m_nuevo_grupo("PRUEBAS DE ITERADOR EXTERNO");
    pruebas_iterador_externo_lista_vacia();
    it = pruebas_iterador_externo(it,lista);

    lista_destruir(lista);
    lista_iterador_destruir(it);
    
    pa2m_nuevo_grupo("PRUEBAS DE ITERADOR INTERNO");
    prueba_iterador_interno();

    pa2m_mostrar_reporte();
}

