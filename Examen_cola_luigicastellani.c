#include<stdio.h>
#include <stdlib.h>
#include<limits.h>
#include<ctype.h>
#include <string.h>

typedef struct Carro{
	char nombre[10];
	int cantidad;
	float precio;
}Carro;

typedef struct nodo {
    Carro *dato;
    struct nodo* sig ;
}Nodo;

struct cola {
	int total;
    struct  nodo  *primero, *ultimo;
}cola;
Carro*crearCarro(char nombre[10], int cantidad, float precio){
	Carro*aux=(Carro*)malloc(sizeof(Carro));
	strcpy(aux->nombre, nombre);
	aux->cantidad=cantidad;
	aux->precio=precio;
	return aux;
}

struct  nodo *crearNodo (Carro*carro){
    Nodo*aux=(Nodo*)malloc(sizeof(Carro));
    aux->dato=carro;
    aux->sig=NULL;
}Nodo;

struct Cola  * crearCola(){
	Cola*aux+(Cola*)malloc(sizeof(Cola));
	aux->primero+aux->ultimo+NULL;
	aux->total=0;
	return aux;
}Cola;

void  enQueue ( int Carro, struct cola** aux ){

    struct nodo* nuevo =  crearNodo(Nodo);
    if((*aux )->primero == NULL){
        (*aux )->primero = (*aux )->ultimo = nuevo;
    return;
    };

    (*aux )->ultimo->sig = nuevo;
    (*aux) ->ultimo= nuevo;
}


int  deQueue( struct cola ** aux){
     if( (*aux )->primero==NULL  )  return INT_MIN;

     struct nodo *eliminado = (*aux)->primero ;
      int data = eliminado->Carro;

      (*aux) ->primero = eliminado->sig;

      if((*aux)->primero==NULL){
        (*aux)->ultimo = NULL;
      }

      free(eliminado);

      return Carro;
}

void mostrar ( struct cola ** aux){
    if ( (*aux )->primero==NULL) return ;


    printf("Primero %d \n  Ultimo : %d \n", (*aux )->primero->Carro, (*aux )->ultimo->Carro );


    struct nodo* actual  = (*aux )->primero;

    while(actual){
        printf ("%d,  ", actual->Carro);
        actual = actual ->sig;
    }

    printf ("\n----------\n ");


}

int main (){
    struct cola  * aux = crearCola();
    enQueue(6, &aux);
    enQueue(-32, &aux);
    enQueue(-2, &aux);
    enQueue(53, &aux);

    mostrar( &aux);

    for( int i = 0; i < 5 ; i++){
        printf("Eliminado %d \n", deQueue(&aux));
        mostrar(&aux);
    };

    return 0;
};
