#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

#define FALSE 0
#define TRUE 1
#define LST_NO_INI 2
#define LST_POS_INV 3
#define LST_VAC 4
#define TRI_NO_INI 5
#define STR_NO_PER -1
#define POS_NULA NULL
#define ELE_NULO NULL


// Retorna una nueva lista vacia.
TLista lista_crear() {

   // Asigno la cantidad de memoria necesaria.
  TLista lista=(TLista) malloc(sizeof(struct lista));
  //Creo la lista.
    lista->cantidad_elementos=0;
    lista->primer_celda=NULL;
  return lista;

}

// Agrega el elemento elem en la posición anterior a pos, dentro de la lista.
int l_insertar(TLista lista, TPosicion pos, TElemento elem){

    int encontre=FALSE;
    if (lista==NULL)
      exit(LST_NO_INI);
    else {
		//Si esta vacia o la pos es nula, inserto al inicio
        if((pos==NULL)||(lista->cantidad_elementos==0)) {
            TCelda nuevacelda = malloc(sizeof(struct celda));
            nuevacelda->proxima_celda=lista->primer_celda;
            nuevacelda->elemento=elem;
            lista->primer_celda=nuevacelda;
            lista->cantidad_elementos++;
			encontre=TRUE;
        }
        else{
            TPosicion muevo=l_primera(lista);
			//Sino, busco donde debo insertar
            while (encontre==FALSE){
                if (muevo==pos){
                    TCelda nuevacelda = malloc(sizeof(struct celda));
                    if (muevo!=lista->primer_celda)
						l_anterior(lista,muevo)->proxima_celda=nuevacelda;
					nuevacelda->proxima_celda=muevo;
                    nuevacelda->elemento=elem;
                    lista->cantidad_elementos++;
                    encontre=TRUE;
                    if (lista->primer_celda==pos)
                        lista->primer_celda=nuevacelda;
                }
                else
                    muevo->l_siguiente(lista,muevo);
            }
        }
    }
    return encontre;
}

// Elimina un elemento de la lista segun la posicion pasada como parametro
// Si la posicion pasada nula, finaliza la ejecucion con error POS_NUL
int l_eliminar(TLista lista, TPosicion pos){

    int encontre=FALSE;
    if (pos==NULL)
        exit((int)POS_NULA);
	if(lista->cantidad_elementos==0)
        exit(LST_VAC);
    else {
        TPosicion a_eliminar=l_primera(lista);
		//Si el que quiero borrar es el primero, debo reasignar el primero al su siguiente
        if (pos==l_primera(lista)){
			lista->primer_celda=l_siguiente(lista,pos);
			lista->cantidad_elementos--;
			free(pos);
			encontre==TRUE;
		}
		//Sino, recorro y borro al encontrarlo
		else while (encontre==FALSE){
				if(a_eliminar==pos){
					TPosicion celdaaux = l_anterior(lista,a_eliminar);
					celdaaux->proxima_celda=a_eliminar->proxima_celda;
					free(a_eliminar);
					lista->cantidad_elementos--;
					encontre=TRUE;
            }
            else a_eliminar=l_siguiente(lista,a_eliminar);
        }
    }
    return encontre;
}

// Retorna la primer posición de la lista.
TPosicion l_primera(TLista lista){
    return lista->primer_celda;
}

// Retorna la última posición de la lista.
TPosicion l_ultima(TLista lista){
    TCelda pos=l_primera(lista);
    int encontre=FALSE;
    while (encontre==FALSE){
        if (pos->proxima_celda==NULL)
            encontre=TRUE;
        else pos=l_siguiente(lista,pos);
    }
    return pos;
}

// Retorna la posición anterior a pos en la lista.
TPosicion l_anterior(TLista lista, TPosicion pos){
    TPosicion posaux=lista->primer_celda;
    if(pos==NULL)
        posaux=POS_NULA;
    else{
        int encontre=FALSE;
        while (encontre==FALSE){
            if (posaux->proxima_celda==pos->proxima_celda)
                encontre=TRUE;
            posaux->proxima_celda=posaux->proxima_celda->proxima_celda;
        }
    }
return posaux;
}

//Retorna la posición siguiente a pos en la lista.
TPosicion l_siguiente(TLista lista, TPosicion pos){
    TPosicion posaux;
    if(pos==NULL)
        posaux=POS_NULA;
    else
        posaux=pos->proxima_celda;
    return posaux;
}

//Retorna el elemento correspondiente a la posición pos.
TElemento l_recuperar(TLista lista, TPosicion pos){
    //Si la lista no esta inicializada salgo con error.
    if(lista==NULL)
        exit(LST_NO_INI);
    //Si la posicion no es valida corta la ejecucion con error.
    if(pos->proxima_celda==NULL)
        exit(LST_POS_INV);
    TElemento elem;
    if (pos==NULL)
        elem=ELE_NULO;
    else
        elem=pos->elemento;
    return elem;
}

//Retorna la cantidad de elementos de la lista.
//Si la lista no esta inicializada finaliza la ejecucion con error LST_NO_INI
int lista_cantidad(TLista lista) {
	//Si la lista no esta inicializada corta la ejecucion y sale con error.
	if(lista==NULL)
		exit(LST_NO_INI);
    return lista->cantidad_elementos;
}

void l_destruir (TLista l, TPosicion n){

	if (n!=NULL)
		l_destruir(l, l_siguiente(l, n));
	free(n->proxima_celda);
}
