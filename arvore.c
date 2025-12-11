#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int cont;
    struct no *esq;
    struct no *dir;
}no;

typedef struct no *ArvBin;

ArvBin* criaArv(){
    ArvBin *raiz =(ArvBin*)malloc(sizeof(ArvBin));
    if(raiz!=NULL){
        *raiz=NULL;
    }
    return raiz;
}
void pre_Ordem(ArvBin *raiz){
    if(raiz==NULL){
        printf("Arvore n existe");
    }
    if(*raiz!=NULL){
        printf("%d",(*raiz)->cont);
        pre_Ordem(&(*raiz)->esq);
        pre_Ordem(&(*raiz)->dir);
    }
}
void em_Ordem(ArvBin *raiz){
    if(raiz==NULL){
        printf("Arvore n existe");
    }
}
int main(void){

}
