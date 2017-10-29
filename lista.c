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


//Retorna una nueva lista vacia.
TLista lista_crear() {

    //Asigno la cantidad de memoria necesaria.
  TLista lista=(TLista) malloc(sizeof(struct lista));
  //Creo la lista.
    lista->cantidad_elementos=0;
    lista->primer_celda=NULL;
  return lista;

}

//Agrega el elemento elem en la posición anterior a pos, dentro de la lista.
int l_insertar(TLista lista, TPosicion pos, TElemento elem){

    if (lista==NULL)
      exit(LST_NO_INI);
    else {
      if(pos==NULL) {
        TCelda nuevacelda = malloc(sizeof(struct celda));
        nuevacelda->proxima_celda=lista->primer_celda;
        nuevacelda->elemento=elem;
        lista->cantidad_elementos++;
      }
      else
      if (lista->cantidad_elementos==0){
        TCelda nuevacelda = malloc(sizeof(struct celda));
        nuevacelda->proxima_celda=lista->primer_celda;
        nuevacelda->elemento=elem;
        lista->cantidad_elementos++;
      }
        else{
            int i=FALSE;
            TCelda celdaaux = malloc(sizeof(struct celda));
            celdaaux->proxima_celda=lista->primer_celda;
            while (i==FALSE){
                if (celdaaux->proxima_celda==pos->proxima_celda){
                    TCelda nuevacelda = malloc(sizeof(struct celda));
                    celdaaux->proxima_celda=nuevacelda;
                    nuevacelda->elemento=elem;
                    nuevacelda->proxima_celda=pos->proxima_celda;
                    lista->cantidad_elementos++;
                    i=TRUE;

                }
                else
                    celdaaux->proxima_celda=celdaaux->proxima_celda->proxima_celda;
            }
        }
    }
    return TRUE;
}

//Elimina un elemento de la lista segun la posicion pasada como parametro
//Si la posicion pasada nula, finaliza la ejecucion con error LST_POS_INV
int l_eliminar(TLista lista, TPosicion pos){

    printf("aaaa");
    if(lista->cantidad_elementos==0){
        printf("a");
        exit(LST_VAC);
        }
    if (pos==NULL){
    printf("b");
        exit(POS_NULA);
        }
    else {
        TPosicion a_eliminar=l_primera(lista);
        printf("a");
        int i=FALSE;
        while (i==FALSE){
            if(a_eliminar->proxima_celda==pos->proxima_celda){
                TPosicion aux=a_eliminar->proxima_celda;
                printf("b");
                a_eliminar->proxima_celda=a_eliminar->proxima_celda->proxima_celda;
                printf("c");
                aux->elemento=NULL;
                printf("d");
                lista->cantidad_elementos--;
                free(a_eliminar);
                free(aux);
                i=TRUE;
            }
            else a_eliminar=l_siguiente(lista,a_eliminar);
        }
    }
    return TRUE;
}

// Retorna la primer posición de la lista.
TPosicion l_primera(TLista lista){
    return lista->primer_celda;
}

// Retorna la última posición de la lista.
TPosicion l_ultima(TLista lista){
    TPosicion pos;
    pos=lista->primer_celda;
    int i=FALSE;
    while (i==FALSE){
        if (pos->proxima_celda==NULL){
            i=TRUE;
            pos->proxima_celda=pos->proxima_celda->proxima_celda;
        }
    }
    return pos;
}

// Retorna la posición anterior a pos en la lista.
TPosicion l_anterior(TLista lista, TPosicion pos){
    TPosicion posaux=lista->primer_celda;
    if(pos==NULL)
        posaux=POS_NULA;
    else{
        int i=FALSE;
        while (i==FALSE){
            if (posaux->proxima_celda==pos->proxima_celda)
                i=TRUE;
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
        if(lista==NULL){
            exit(LST_NO_INI);
        }
        //Si la posicion no es valida corta la ejecucion con error.
            if(pos->proxima_celda==NULL) {
                exit(LST_POS_INV);
            };
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
