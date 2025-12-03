#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
    int cont;
    struct cel *prox;
}cel;

typedef struct cel*Lista;

Lista* criaLista(){
    Lista*li=(Lista*)malloc(sizeof(Lista));
    if(li!=NULL){
        *li=NULL;
    }return li;
}

int insereFimLista(Lista*lista,int x){
    if(lista==NULL){return 0;}

    cel *aux=(cel*)malloc(sizeof(cel));
    if(aux==NULL){
        return 0;
    }
    aux->cont = x;
    aux->prox=NULL;
    if(*lista==NULL){
        *lista =aux;
    }else{
        cel*temp;
        temp=*lista;
        while(temp->prox!=NULL){
            temp=temp->prox;
        }
        temp->prox=aux;
    }return 1;
}

void imprimeLista(Lista*lista){
    Lista aux = *lista;
    while(aux!=NULL){
        printf("%d\n",aux->cont);
        aux=aux->prox;
    }printf("\n");
}
void buscaLista(Lista *lista,int v){
    Lista aux= *lista;
    while(aux !=NULL){
        if(aux->cont==v){
            printf("%d\n",v);
        }
        aux=aux->prox;
    }
}

int main(void){
    Lista* lista = criaLista();


        for(int i = 1; i <= 10; i++){
            insereFimLista(lista, i * 10);
        }


        printf("Lista encadeada:\n");
        imprimeLista(lista);


        buscaLista(lista, 30);



}
