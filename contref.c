#include "contref.h"
#include <stdio.h>
#include <stdlib.h>
heap *lista = 0;

void *malloc2(int tamanho){
    heap *aux=malloc(sizeof(heap));
    aux->end=malloc(tamanho);
    aux->cont=1;

    if(lista==NULL){
        lista=aux;
    }
    else{
        aux->prox=lista;
        lista=aux;
    }
    return aux->end;
}

void altera(void *endereco,int inc){
    heap *aux=lista;
    while(aux!=NULL && aux->end!=endereco){
        aux=aux->prox;
    }

    if(aux!=NULL && aux->end==endereco){
        aux->cont = aux->cont+inc;
    }
}

void atrib2(void *a,void *b){
    heap *aux=lista;
       while(aux!=NULL){
            if(aux->end==a){
                altera(aux->end,-1);
            }else if(aux->end==b){
                altera(aux->end,1);
            }
            aux=aux->prox;
        }
    a=b;
}

void dump(){
    heap *ant=lista;
    heap *aux=ant->prox;
    if(ant->cont==0){
        lista=aux;
        free(ant);
    }else{
        while(aux!=NULL){
            if(aux!=NULL && aux->cont==0){
                ant->prox=aux->prox;
                free(aux);
            }
            ant=aux;
            aux=aux->prox;
        }
    }
}
