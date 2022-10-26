#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
struct s_nodobin{
	int valor;
	struct s_nodobin* izq;
	struct s_nodobin* der;
};
typedef struct s_nodobin* t_nodobin;
t_nodobin* XOR( t_nodobin *x, t_nodobin *y) {
    return (t_nodobin*)((uintptr_t)(x) ^ (uintptr_t)(y));
}
void insertarbol(int valor,t_nodobin *arbol);
int main(){
    t_nodobin arbol=NULL;
    insertarbol(3,&arbol);
    insertarbol(6,&arbol);
    insertarbol(9,&arbol);
    
}
void insertarbol(int valor,t_nodobin **arbol){ 
	int insertado = 0;
	t_nodobin* aux = (t_nodobin)malloc(sizeof(struct s_nodobin));
    (*aux)->valor = valor;
	(*aux)->der =  XOR(*arbol, NULL);      
	(*aux)->izq = XOR(*arbol, NULL);
	printf("%d-",valor);
	if(*arbol){
	    (*arbol)->der =  XOR(aux, XOR((*arbol)->der, NULL));
	}
	
	*arbol=aux;		

}
