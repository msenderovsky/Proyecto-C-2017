
#ifndef LISTAORDENADA_H_
#define LISTAORDENADA_H_

typedef struct lista_ordenada {
unsigned int cantidad_elementos;
TLista lista;
} * TListaOrdenada;

//Crea y retorna una lista ordenada vacía.
TListaOrdenada crear_lista_ordenada( int (*f)(void *,void *));

//Agrega el elemento elem en la posición correspondiente de la lista, de modo que la misma quede siempre ordenada de forma ascendente.
//Retorna verdadero si procede con éxito, falso en caso contrario.
int lo_insertar(TListaOrdenada lista, TElemento elem);

//Elimina el elemento en la posición pos.
//Reacomoda la lista adecuadamente al eliminar en posiciones intermedias.
//Retorna verdadero si procede con éxito, falso en caso contrario.
int lo_eliminar(TListaOrdenada lista, TPosicion pos);

// Retorna la última posición de la lista.
TPosicion lo_ultima(TListaOrdenada lista);

//Retorna la primer posición de la lista.
TPosicion lo_primera(TListaOrdenada lista);

//Retorna la posición siguiente a pos en la lista.
TPosicion lo_siguiente(TListaOrdenada lista, TPosicion pos);



#endif /* LISTAORDENADA_H_ */
