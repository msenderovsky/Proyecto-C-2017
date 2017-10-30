#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "ListaOrdenada.h"
#include "trie.h"
#include <string.h>



#define FALSE 0
#define TRUE 1
#define LST_NO_INI 2
#define LST_POS_INV 3
#define LST_VAC 4
#define TRI_NO_INI 5
#define STR_NO_PER -1
#define POS_NULA NULL
#define ELE_NULO NULL

int f(void *e1,void *e2){
	TNodo a = (TNodo) e1;
	TNodo b = (TNodo) e2;
	int comp;
	if(a<b)
		comp=-1;
	if(a==b)
		comp=0;
	comp=1;
	return comp;
}

/**
* Crea un Trie vacio y lo retorna.
@return Trie vacio, con lista de hijos inicializada y vacia.
*/
TTrie crear_trie(){
    TTrie nuevo = (TTrie) malloc(sizeof(struct trie));
    TNodo raiz = (TNodo) malloc(sizeof(struct nodo));
    nuevo->cantidad_elementos=0;
    nuevo->raiz=raiz;
    raiz->contador=0;
    raiz->padre=NULL;
    raiz->rotulo=(int)NULL;
    raiz->hijos=crear_lista_ordenada(f);
    return nuevo;
}

/**
* Inserta una palabra en el trie en la posicion correspondiente.
@param Trie tr en el que se inserta, cadena de caracteres a insertar.
@return 1 si pudo insertar, 0 si no pudo.
*/
int tr_insertar(TTrie tr, char* str){
    int res;
    if(tr == NULL)
        exit(TRI_NO_INI);
    if (str==NULL)
        res=STR_NO_PER;
    res=insert_aux(str,0,strlen(str),tr->raiz);
    tr->cantidad_elementos++;
    return res;
    }
	
/**
 * \param  Letra a buscar
 * \param  La lista donde se debe buscar la letra
 * \return La posición donde se encuentra la letra
 */
TPosicion buscar_letra(TListaOrdenada lista, char letra ){
	int res=FALSE;
    TPosicion buscar = lo_primera(lista);
    while (res!=TRUE && buscar!=NULL){
		TNodo elemento = buscar->elemento;
		if (elemento->rotulo==letra)
            res=TRUE;
        else
            if (buscar!=lo_ultima(lista))
				buscar=lo_siguiente(lista,buscar);
    }
    return buscar;
}

int insert_aux(char*palabra,int i, int n, TNodo padre){
    if (i<=n){
    //Busco si la letra se encuentra en la lista de hijos
        TPosicion busco = buscar_letra(padre->hijos,palabra[i]);
		if (busco!=NULL){
            TNodo hijo=busco->elemento;
            hijo->contador++;}
        else{
			//Si no está en la lista de hijos, creo un nodo nuevo y lo agrego al trie
            TNodo nuevo = (TNodo)malloc(sizeof(struct nodo));

            //si la lista de hijos está vacía
            if(padre->hijos->cantidad_elementos==0){
                nuevo->rotulo=palabra[i];
                nuevo->contador=0;
                nuevo->padre=padre;
                nuevo->hijos=crear_lista_ordenada(f);
                lo_insertar(padre->hijos,nuevo);
                insert_aux(palabra,i+1,n,nuevo);
            }
        }
    }
	return TRUE;
}


/**
* Retorna verdadero si el string pertenece al Trie, falso en caso contrario. Retorna error si el Trie no esta inicializado.
@param Trie tr en el que se debe averiguar, cadena a buscar.
@return 1 si pertenece, 0 si no pertenece.
*/
int tr_pertenece (TTrie tr, char* str)
{
int resultado;
	if (tr==NULL)
		exit(TRI_NO_INI);
    if(str!=NULL)
		resultado=pertenece_aux(tr->raiz,str,0,strlen(str));
return resultado;
}

int pertenece_aux (TNodo padre,char*palabra,int inicio, int fin){
    int resultado=TRUE;
    if (inicio<=fin && resultado==TRUE){
        TPosicion busca=buscar_letra(padre->hijos,palabra[inicio]);
        TNodo hijo = l_recuperar(padre->hijos->lista,busca);
        if (busca!=NULL)
            resultado=pertenece_aux(hijo,palabra,inicio+1,fin);
             else
                resultado=STR_NO_PER;
            }
            return resultado;
    }

/**
* Retorna la cantidad de veces que esta un string pasado por parametro
* Retorna error si el Trie no esta inicializado
*/
int tr_recuperar (TTrie tr, char* str){
    //Creo la variable cantidad que representa cuantas veces aparece un string en el trie.
    int cantidad;
	if (tr==NULL)
		exit(TRI_NO_INI);
    else{
        if (tr_pertenece(tr,str)==TRUE){
            //Recorro hasta encontrar el nodo hoja.
           int inicio=0;
           int fin=strlen(str);
           TPosicion busco = lo_primera(tr->raiz->hijos);
           TNodo padre = busco->elemento;
           //Bucle para ir recorriendo los hijos hasta encontrar el ultimo
			while(inicio<fin){
                TListaOrdenada hijos = padre->hijos;
                padre = buscar_letra(hijos,str[inicio])->elemento;
                inicio++;
            }
            //Asigno a cantidad el contador del último hijo.
			cantidad=padre->contador;}
        }
    return cantidad;
}

int tr_size(TTrie tr){
    if (tr==NULL)
		exit(TRI_NO_INI);
    return tr->cantidad_elementos;
}

//Elimina el string str dentro del trie, liberando la memoria utilizada.
//Retorna verdadero en caso de operación exitosa, y falso en caso contrario.
int tr_eliminar(TTrie tr, char* str){
    int resultado;
    if (tr==NULL)
		exit(TRI_NO_INI);
		else
            if (tr_pertenece(tr,str)!=FALSE)
				resultado=tr_eliminar_aux(tr,str,0,strlen(str),tr->raiz);
    return resultado;
}

int tr_eliminar_aux(TTrie trie, char*palabra,int inicio,int fin ,TNodo padre){
    if (inicio<fin){
    TPosicion a_eliminar=buscar_letra(padre->hijos,palabra[inicio]);
    TNodo padre_nuevo=a_eliminar->elemento;
    if (padre_nuevo->contador<1)
        padre_nuevo->contador--;
    else
    lo_eliminar(padre->hijos,a_eliminar);
    tr_eliminar_aux(trie,palabra,inicio+1,fin,padre_nuevo);}
	return TRUE;
}
