#ifndef CONTREF_H_INCLUDED
#define CONTREF_H_INCLUDED
typedef struct heap{
    void *end;
    int cont;
    struct heap *prox;
}heap;

void *malloc2(int tamanho);

void altera(void *endereco,int inc);

void atrib2(void *a,void *b);

void dump();



#endif // CONTREF_H_INCLUDED
