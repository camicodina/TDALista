#include "lista.h"
#include "pa2mm.h"
#include <stdio.h>

void probar_crear_lista_vacia(){
    lista_t* lista_inicial = NULL;

    pa2m_afirmar((lista_inicial=lista_crear()) != NULL, "Puedo crear una lista");
    pa2m_afirmar(lista_inicial->cantidad == 0, "Contiene 0 elementos");
    pa2m_afirmar(lista_inicial->nodo_inicio == NULL, "Su inicio es NULL");
    pa2m_afirmar(lista_borrar(lista_inicial) == -1, "No puedo borrar de la lista");
    pa2m_afirmar(lista_vacia(lista_inicial) == true, "Está vacía");

    lista_destruir(lista_inicial);
}


void probar_insertar_en_lista(lista_t* lista_vocales){
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

}

void probar_borrar_en_lista(lista_t* lista_vocales){
    char a='a',e='e',i='i',o='o',u='u';

    pa2m_afirmar(lista_borrar(lista_vocales) == 0, "Se borra ultimo elemento");
    pa2m_afirmar(lista_elemento_en_posicion(lista_vocales, 4) == NULL, "No hay quinto elemento");
    pa2m_afirmar(lista_vocales->cantidad == 4, "Hay cuatro elementos");
    pa2m_afirmar(lista_borrar_de_posicion(lista_vocales, 0) == 0, "Se borra primer elemento");
    pa2m_afirmar(lista_vocales->cantidad == 3, "Hay tres elementos");
    pa2m_afirmar(lista_elemento_en_posicion(lista_vocales, 0) == &e, "El primer elemento es correcto");
    pa2m_afirmar(lista_elemento_en_posicion(lista_vocales, 1) == &i, "El segundo elemento es correcto");
    pa2m_afirmar(lista_elemento_en_posicion(lista_vocales, 2) == &o, "El tercer elemento es correcto");

}


int main(){
    lista_t* lista = NULL; 
    pa2m_nuevo_grupo("PRUEBAS DE CREAR LISTA");
    probar_crear_lista_vacia();

    pa2m_nuevo_grupo("PRUEBAS DE INSERTAR A LISTA");
    probar_insertar_en_lista(lista);

    pa2m_nuevo_grupo("PRUEBAS DE BORRAR DE LISTA");
    probar_borrar_en_lista(lista);
    
    lista_destruir(lista);

    pa2m_mostrar_reporte();
}

