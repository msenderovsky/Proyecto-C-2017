#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "ListaOrdenada.h"


#define FALSE 0
#define TRUE 1
#define LST_NO_INI 2
#define LST_POS_INV 3
#define LST_VAC 4
#define TRI_NO_INI 5
#define STR_NO_PER -1
#define POS_NULA NULL
#define ELE_NULO NULL
int (*comp)(void *, void *);


/**
* Crea una lista ordenada vacia y la retorna
*/
TListaOrdenada crear_lista_ordenada(int (*f) (void *, void *)){

    comp=f;
	TListaOrdenada LOrdenada=(TListaOrdenada) malloc(sizeof(struct lista_ordenada));
	LOrdenada->cantidad_elementos=0;
	LOrdenada->lista = lista_crear();
	return LOrdenada;
}

/**
 * Inserto un elemento pasado por parametro en la posicion que le corresponda
 * Si la lista esta vacia lo inserto en el principio
 */
int lo_insertar (TListaOrdenada lista, TElemento elem){

    int encontre=FALSE;
	if (lista==NULL)
		exit((int)LST_POS_INV);
	if (lista->cantidad_elementos==0){
		l_insertar(lista->lista,l_primera(lista->lista),elem);
        lista->cantidad_elementos++;
    }
	else{
        TPosicion muevo=lo_primera(lista);
		if (lista->cantidad_elementos>1)
			while ((muevo!=lo_ultima(lista))&&(i==FALSE)){
				if (comp(elem, muevo->elemento)<1){
					l_insertar(lista->lista,muevo,elem);
					lista->cantidad_elementos++;
					i=TRUE;
				}
				else
					muevo=lo_siguiente(lista,muevo);
			}
        else if (comp(elem, muevo->elemento)<1){
				TCelda nuevacelda=(TCelda) malloc (sizeof (struct celda));
				nuevacelda->elemento=elem;
				nuevacelda->proxima_celda=lo_primera(lista);
				lista->lista->primer_celda=nuevacelda;
				lista->cantidad_elementos++;
				lista->lista->cantidad_elementos++;
				encontre=TRUE;
			}	
		if ((i==FALSE)||((lista->cantidad_elementos==1)&&(comp(elem, muevo->proxima_celda->elemento)>1))){
            TCelda nuevacelda= (TCelda)malloc(sizeof(struct celda));
            nuevacelda->elemento=elem;
            l_ultima(lista->lista)->proxima_celda=nuevacelda;
            nuevacelda->proxima_celda=NULL;
            lista->cantidad_elementos++;
            lista->lista->cantidad_elementos++;
			encontre=TRUE;
        }
	}
	return encontre;
}

/**
 * Elimino la posicion pasada por parametro de la lista, si es que se encuentra
 * Si la lista esta vacia retorna error de lista vacia
 * Si la posicion es nula, retorna error de posicion ivalida
 */
int lo_eliminar(TListaOrdenada lista, TPosicion pos){
	int res;
	if (pos==NULL)
		res=FALSE;
    if(lista->cantidad_elementos==0)
		exit(LST_VAC);
	else{
        l_eliminar(lista->lista,pos);
        lista->cantidad_elementos--;
        res=TRUE;
	}
	return res;
}

/**
 * Retorna el tamaño de la lista
 */
int lo_size(TListaOrdenada lista)
{
	if(lista==NULL)
		exit(LST_NO_INI);
	return lista->cantidad_elementos;
}

/**
 * Retorna el primer elemento de la lista
 * Si la lista esta vacia, retorna error de lista vacia
 * Si la lista no esta inicializada, retorna error de lista sin inicializar
 */
TPosicion lo_primera(TListaOrdenada lista)
{
	if(lista==NULL)
		exit(LST_NO_INI);
	if (lista->cantidad_elementos==0)
		exit(LST_VAC);
	return l_primera(lista->lista);
}

// Retorna el ultimo elemento de la lista
// Si la lista esta vacia, retorna error de lista vacia
//Si la lista no esta inicializada, retorna error de lista sin inicializar
TPosicion lo_ultima(TListaOrdenada lista)
{
	if(lista==NULL)
		exit(LST_NO_INI);
	if (lista->cantidad_elementos==0)
		exit(LST_VAC);
	return l_ultima(lista->lista);
}


// Retorna el elemento de la lista siguiente a una posicion pasada por parametro
// Si la lista esta vacia, retorna error de lista vacia
// Si la lista no esta inicializada, retorna error de lista sin inicializar
TPosicion lo_siguiente(TListaOrdenada lista, TPosicion pos)
{
	if(lista==NULL)
		exit(LST_NO_INI);
	if (lista->cantidad_elementos==0)
		exit(LST_VAC);
	return l_siguiente(lista->lista, pos);
}

void lo_destruir (TListaOrdenada l){
	l_destruir (l->lista, l->lista->primer_celda);
}
