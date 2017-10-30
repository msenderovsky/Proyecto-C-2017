/*
 * lista.h
 *
 *  Created on: 28 sep. 2017
 *      Author: Gabriel
 */

#ifndef LISTA_H_
#define LISTA_H_

typedef struct celda * TPosicion;
typedef void * TElemento;

typedef struct celda {
TElemento elemento;
struct celda * proxima_celda;
} * TCelda;

typedef struct lista {
unsigned int cantidad_elementos;
TCelda primer_celda;
} * TLista;



//Retorna una nueva lista vacia.
TLista lista_crear();

//Agrega el elemento elem en la posición anterior a pos, dentro de la lista.
int l_insertar(TLista lista, TPosicion pos, TElemento elem);

//Elimina un elemento de la lista segun la posicion pasada como parametro
//Si la posicion pasada nula, finaliza la ejecucion con error LST_POS_INV
int l_eliminar(TLista lista, TPosicion pos);

// Retorna la primer posición de la lista.
TPosicion l_primera(TLista lista);

// Retorna la última posición de la lista.
TPosicion l_ultima(TLista lista);

// Retorna la posición anterior a pos en la lista.
TPosicion l_anterior(TLista lista, TPosicion pos);

//Retorna la posición siguiente a pos en la lista.
TPosicion l_siguiente(TLista lista, TPosicion pos);

//Retorna el elemento correspondiente a la posición pos.
TElemento l_recuperar(TLista lista, TPosicion pos);

//Retorna la cantidad de elementos de la lista.
//Si la lista no esta inicializada finaliza la ejecucion con error LST_NO_INI
int lista_cantidad(TLista lista);

void l_destruir();


#endif /* LISTA_H_ */
