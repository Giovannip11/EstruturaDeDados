#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
    int cont;
    struct cel *prox;
}cel;

typedef struct cel *Pilha;

Pilha criarPilha(){
    Pilha *pi =(Pilha*)malloc(sizeof(Pilha));
    if(pi != NULL){
        *pi=NULL;
    }
    return *pi;
}

Pilha push(Pilha topo,int x){
    cel* n=(cel*)malloc(sizeof(cel));
    if(n==NULL){
        return 0;
    }
    n->cont=x;
    n->prox = topo;
    return n;
}
Pilha pop(Pilha topo){
if(topo ==NULL){return 0;}

cel* temp=topo;
topo=topo->prox;
free(topo);
return topo;
}

Pilha showTop(Pilha topo){
    if(topo==NULL){return 0;}
    printf("%d",topo->cont);
    return topo;
}
void imprimir(Pilha topo){
    if(topo==NULL){printf("Pilha vazia");}
    cel* aux=topo;
    while(aux!=NULL){
        printf("%d",aux->cont);
        aux=aux->prox;
    }
}
int main (void){
    Pilha topo = NULL;
        topo = push(topo,1);
        topo = push(topo,2);
        topo = push(topo,3);
        topo = push(topo,4);
        printf("Pilha:");
        imprimir(topo);
        topo=pop(topo);
        printf("\nTopo da pilha:");
        showTop(topo);
        printf("\nPilha:");
        imprimir(topo);
        printf("\n");
        return 0;

}
