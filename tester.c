#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "ListaOrdenada.h"
#include "trie.h"

int g(void *e1,void *e2){
    TPosicion a = (TPosicion) e1;
	TPosicion b = (TPosicion) e2;
	int comp;
	if((a->elemento)<(b->elemento))
		comp=-1;
    else if((a->elemento)==(b->elemento))
		comp=0;
            else comp=1;
	return comp;
}

int h(void *e1,void *e2){
	TNodo a = (TNodo) e1;
	TNodo b = (TNodo) e2;
	int comp;
	if(a->rotulo<b->rotulo)
		comp=-1;
    else if(a->rotulo==b->rotulo)
		comp=0;
            else comp=1;
	return comp;
}

int main()
{
    //TTrie t=crear_trie();
    TListaOrdenada l= crear_lista_ordenada(g);
    printf("tamaño es: %i\n", l->cantidad_elementos);
    //printf("asdad");
    printf("voy a insertar el primer elemento, el '2' \n");
    lo_insertar(l,'2');
    printf("tamaño es: %i\n", l->cantidad_elementos);
    //printf("asdad2");
    //tr_pertenece(l,'a');
    printf("primer valor es (lo_primera) : %c\n", lo_primera(l)->elemento);
    printf("ultimo valor es (lo_ultima): %c\n", lo_ultima(l)->elemento);
    printf("voy a insertar el segundo elemento, el '1' \n");
    lo_insertar(l,'1');
    printf("tamaño es: %i\n", l->cantidad_elementos);

    printf("primer valor es: %c\n", lo_primera(l)->elemento);
    printf("1er valor es: %c\n", l->lista->primer_celda->elemento);
    printf("segundo valor es: %c\n", lo_ultima(l)->elemento);
    //printf("%i",lo_eliminar(l,lo_primera(l)));
    //printf(f(1,2));
    //printf("asdasd\n");
    //printf("%i\n", l->cantidad_elementos);
    // printf("asdad3");
    //printf("asdad4");
    /*TLista l= lista_crear();
    printf("acabo de crear y voy a insertar \n");
    printf("%i\n", lista_cantidad(l));
    l_insertar(l,l_primera(l),'2');
    printf ("inserte un 2 \n");
    //printf("primer valor es: %c\n", l_recuperar(l,l_primera(l)));
    printf("cantidad de elementos: %i\n", lista_cantidad(l));
    //l_insertar(l,l_primera(l),2);
    printf ("inserte uno \n");
    printf("el primer valor es %c \n", l_primera(l)->elemento);
    l_insertar(l,l_primera(l),'3');
    printf ("inserte un 3 \n");
    printf("cantidad de elementos: %i\n", lista_cantidad(l));
    printf("1er valor es: %c\n", l_primera(l)->elemento);
    printf("2do valor es: %c\n", l_ultima(l)->elemento);
    printf("voy a borrar:\n");
    l_eliminar(l,l_primera(l));
    printf("borro \n");
    printf("cantidad en lista: %i\n", lista_cantidad(l));*/
    return 0;

}
