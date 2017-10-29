

#ifndef TRIE_H_
#define TRIE_H_
#endif /* TRIE_H_ */

typedef struct nodo {
char rotulo;
unsigned int contador;
struct nodo * padre;
TListaOrdenada hijos;
} * TNodo;

typedef struct trie {
unsigned int cantidad_elementos;
TNodo raiz;
} * TTrie;

//Retorna un nuevo trie vacío, esto es, con nodo raíz que mantiene rótulo nulo y contador en cero.
TTrie crear_trie();

//Inserta el string str en el trie, inicializando el valor de contador asociado en uno.
int tr_insertar(TTrie tr, char* str);

//Retorna verdadero si el string srt pertenece al trie, falso en caso contrario.
int tr_pertenece(TTrie tr, char* str);

//Retorna el entero asociado al string str, dentro del trie. Si el string no pertenece al trie, retorna STR NO PER.
int tr_recuperar(TTrie tr, char* str);

//Retorna la cantidad de palabras almacenadas en el trie.
int tr_size(TTrie tr);

//Elimina el string str dentro del trie, liberando la memoria utilizada.
//Retorna verdadero en caso de operación exitosa, y falso en caso contrario.
int tr_eliminar(TTrie tr, char* str);

