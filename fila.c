#include <stdio.h>
#include <stdlib.h>

typedef struct cel{
    int cont;
    struct cel *prox;
}cel;

typedef struct fila{
    int quant;
    int max;
    struct cel *inicio;
    struct cel *fim;
}Fila;

Fila  *criaFila(){
    Fila* fi =(Fila*)malloc(sizeof(Fila));
    if(fi == NULL){
        fi->quant=0;
        fi->max=5;
        fi->inicio=NULL;
        fi->fim=NULL;
    }
    return fi;
}

int enqueue(Fila* fi,int x){
    if(fi==NULL || fi->quant>fi->max){
        return 0;
    }
    cel *no= (cel*)malloc(sizeof(cel));
    if(no ==NULL){
        return 0;
    }
    no->cont = x;
    no->prox=NULL;
    if(fi->inicio==NULL){
        fi->inicio=no;
    }else{
        fi->fim->prox=no;
    }
    fi->fim=no;
    fi->quant++;
    return 1;
}
int dequeue(Fila *fi){
    if(fi==NULL||fi->quant>=fi->max){
        return -1;
    }
    cel *noRemovido= fi->inicio;
    int dadoRemovido = noRemovido->cont;

    fi->inicio = noRemovido->prox;

    if(fi->inicio==NULL){
        fi->fim=NULL;
    }
    free(noRemovido);

    fi->quant--;
    return dadoRemovido;
}
void showFila(Fila* fi){
    if(fi==NULL||fi->quant>=fi->max){
        printf("Fila vazia");
    }
    cel *temp=fi->inicio;
    printf("Fila:");
    while(temp !=NULL){
        printf("%d",temp->cont);
        temp=temp->prox;
    }
    if(temp !=NULL){
        printf("->");
    }
    printf("\n");
}
void verificarFilaVazia(Fila *fi){
    if(fi==NULL|| fi->quant>=fi->max){
        printf("Fila vazia");
    }
}
int verificarFilaCheia(Fila* fi){
    if(fi==NULL){
        return 0;
    }
    if(fi->quant >=fi->max){
        return 1;
    }else{
        return 0;
    }
}
int main(void) {
    Fila *fi = criaFila();
    if (fi == NULL) {
        printf("Erro ao criar a fila\n");
        return 1;
    }

    printf("Testando fila vazia:\n");
    verificarFilaVazia(fi);
    printf("\n");

    printf("\nEnfileirando elementos:\n");
    enqueue(fi, 10);
    enqueue(fi, 20);
    enqueue(fi, 30);
    enqueue(fi, 40);
    enqueue(fi, 50);

    showFila(fi);

    printf("\nTentando enfileirar além do limite:\n");
    if (!enqueue(fi, 60)) {
        printf("Fila cheia! Não foi possível inserir 60.\n");
    }

    printf("\nVerificando se fila está cheia:\n");
    if (verificarFilaCheia(fi)) {
        printf("Fila cheia!\n");
    } else {
        printf("Ainda há espaço.\n");
    }

    printf("\nDesenfileirando 3 elementos:\n");
    printf("Removido: %d\n", dequeue(fi));
    printf("Removido: %d\n", dequeue(fi));
    printf("Removido: %d\n", dequeue(fi));

    showFila(fi);

    printf("\nVerificando fila vazia:\n");
    verificarFilaVazia(fi);
    printf("\n");

    printf("\nEsgotando a fila:\n");
    printf("Removido: %d\n", dequeue(fi));
    printf("Removido: %d\n", dequeue(fi));

    printf("Tentando remover com fila vazia:\n");
    int r = dequeue(fi);
    if (r == -1) printf("Fila vazia! Nenhum elemento para remover.\n");

    showFila(fi);

    return 0;
}
