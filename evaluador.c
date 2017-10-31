#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "ListaOrdenada.h"
#include "trie.h"

#ifndef NULL
#define NULL   ((void *) 0)
#endif

#define FALSE 0
#define TRUE 1
#define LST_NO_INI 2
#define LST_POS_INV 3
#define LST_VAC 4
#define TRI_NO_INI 5
#define STR_NO_PER -1
#define POS_NULA NULL
#define ELE_NULO NULL

const int max=49;

void mostrar_aux(char* str, TTrie tr, TNodo n, int i){

	if (i< max){
		str[i]=n->rotulo;
		//caso de que encontre palabra
		if (n->contador!=0){
			str[i+1]='\0';
			printf("%s\n",str);
		}
		//
		TPosicion pos;
		TNodo aux;
		for (pos=lo_primera(n->hijos); aux!=NULL; pos=lo_siguiente(n->hijos, pos)){
            aux=pos->elemento;
			mostrar_aux( str,tr, aux,i+1);
			}
    }
}

//Muestra las palabras del Trie sin repetirlas
void mostrar_palabras(TTrie tr){

	char str [max+1];
	mostrar_aux( str, tr, lo_primera(tr->raiz->hijos)->elemento,0 );
}

//Retorna cuantas veces esta una palabra pasada por parametro en el archivo, si es que la encuentra
int consultar(TTrie tr,char*str){

	int c=FALSE;
	if (tr_pertenece(tr,str)==TRUE)
		c=tr_recuperar(tr,str);
	return c;
}

int comienza_aux(char* str, TTrie tr, TNodo n){
    int resultado;
		TPosicion pos;
		for (pos=lo_primera(n->hijos); pos!=NULL; pos=lo_siguiente(n->hijos, pos))
			if (n->contador!=0)
				resultado=1+comienza_aux(str,tr, pos->elemento);
			else
                resultado=comienza_aux(str,tr, pos->elemento);
    return resultado;
}

//Retorna cuantas palabras comienzan con la letra pasada por parametro
//Si no hay palabras que comiencen con esa letra retorna error
int comienzan_con(TTrie tr,char* str){
    TNodo elem;
	TPosicion recorro=lo_primera(tr->raiz->hijos);
	char s=str[0];
	int encontre=FALSE;
	while ((encontre==FALSE)&&(recorro!=NULL)) {
        elem = recorro->elemento;
        char y = elem->rotulo;
		if (y==s)
			encontre=TRUE;
		else recorro=lo_siguiente(tr->raiz->hijos, recorro);
		}
	int i=0;
	if (encontre==TRUE)
		i=comienza_aux(str, tr, lo_primera(elem->hijos)->elemento);
	return i;
}

//Retorna verdadero si una palabra es prefijo de al menos otra palabra, falso en caso contrario
int es_prefijo(TTrie tr,char* str){

	if (tr==NULL)
		exit (TRI_NO_INI);
	int i=FALSE;
	if (tr_recuperar(tr,str)>0)
		i=TRUE;
	else i=FALSE;
	return i;
}

//Retorna el porcentaje de palabras que contienen la cadena pasada por parametro como prefijo de ellas
float porcentaje (TTrie tr, char*str){

	if (tr==NULL)
		exit (TRI_NO_INI);
	return (((tr_recuperar(tr,str))/100)*tr_size(tr));
}

void cargar(char* file, TTrie tr){

	FILE *archivo;
	int caracter;
	char string[100];
	char*s=&string[0];
	int a=0;
	archivo = fopen(file,"r");
	if (archivo == NULL)
            printf("\n Error de apertura del archivo. \n\n");
        else{
				while(fgetc(archivo) != EOF){
					caracter = fgetc(archivo);
					char c = caracter;
					if(c!=' '){
						s[a]=(char)c;
						a++;
					}
					else{
						tr_insertar(tr,s);
						for (int i=a;i>0;i--)
							s[i]='\0';
					}
				}
        }
	fclose(archivo);
}

void destruir (TTrie tr){

	//tr_destruir(tr);
}

int main (int argc, char *argv[] ){

	TTrie tr= (TTrie) malloc (sizeof(struct trie));
	if (argc==2)
		cargar (argv[1],tr);
	printf("Ingrese un numero de operacion\n");
	char opcion;
	char palabra[50];
    int i=0;
    char c;
	scanf("%c",&opcion);
	while (opcion!='6'){
		switch(opcion) {
			case '1' :
				mostrar_palabras(tr);
				break;
			case '2' :
				while (c!='\0'){
					scanf("%c",&c);
					palabra[i++]=c;
				}
				printf("%i\n", consultar(tr,palabra));
				break;
			case '3' :
				while (c!='\0'){
					scanf("%c",&c);
					palabra[i++]=c;
				}
				printf("%i\n", comienzan_con(tr,palabra));
				break;
			case '4' :
				while (c!='\0'){
					scanf("%c",&c);
					palabra[i++]=c;
				}
				printf("%i\n", es_prefijo(tr,palabra));
				break;
			case '5' :
				while (c!='\0'){
					scanf("%c",&c);
					palabra[i++]=c;
				}
				printf("%f", porcentaje(tr,palabra));
				break;
			default :
				printf("No es una opcion valida");
				break;
		}
		scanf("%c",&opcion);
	}
	if (opcion=='6')
		destruir(tr);
	return 0;
}

