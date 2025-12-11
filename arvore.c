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
    if(*raiz!=NULL){
        em_Ordem(&(*raiz)->esq);
        printf("%d",(*raiz)->cont);
        em_Ordem(&(*raiz)->dir);
    }
}
void pos_Ordem(ArvBin *raiz){
    if(raiz==NULL){
        printf("Arvore n existe");
    }
    if(*raiz!=NULL){
        pos_Ordem(&(*raiz)->esq);
        pos_Ordem(&(*raiz)->dir);
        printf("%d",(*raiz)->cont);
    }
}
int totalNos(ArvBin *raiz){
    if(raiz==NULL){
        return 0;
    }
    if(*raiz==NULL){
        return 0;
    }

    int totalEsq=(totalNos(&(*raiz)->esq));
    int totalDir=(totalNos(&(*raiz)->dir));

    return totalEsq +totalDir+1;
}
int alturaArvBin(ArvBin *raiz){
    if(raiz==NULL){
        return 0;
    }
    if(*raiz==NULL){
        return 0;
    }
    int alt_esq=(alturaArvBin(&(*raiz)->esq));
    int alt_dir=(alturaArvBin(&(*raiz)->dir));
    if(alt_esq>alt_dir){
        return alt_esq+1;
    }else{
        return alt_dir+1;
    }
}
void liberaNo(no *no){
    if(no==NULL){
        return;
    }
    liberaNo(no->esq);
    liberaNo(no->dir);
    free(no);
    no=NULL;
}
void liberaArvBin(ArvBin *raiz){
    if(raiz==NULL){
        return;
    }
    liberaNo(*raiz);
    free(raiz);
}
int main(void) {

    ArvBin *raiz = criaArv();
    if (raiz == NULL) {
        printf("Erro ao criar árvore.\n");
        return 1;
    }


    no *n1 = (no*)malloc(sizeof(no));
    no *n2 = (no*)malloc(sizeof(no));
    no *n3 = (no*)malloc(sizeof(no));
    no *n4 = (no*)malloc(sizeof(no));
    no *n5 = (no*)malloc(sizeof(no));


    n1->cont = 10;
    n2->cont = 5;
    n3->cont = 15;
    n4->cont = 3;
    n5->cont = 7;






    *raiz = n1;

    n1->esq = n2;
    n1->dir = n3;

    n2->esq = n4;
    n2->dir = n5;

    n3->esq = NULL;
    n3->dir = NULL;

    n4->esq = NULL;
    n4->dir = NULL;

    n5->esq = NULL;
    n5->dir = NULL;

    // ===== TESTES =====

    printf("\n--- PRE ORDEM ---\n");
    pre_Ordem(raiz);

    printf("\n\n--- EM ORDEM ---\n");
    em_Ordem(raiz);

    printf("\n\n--- POS ORDEM ---\n");
    pos_Ordem(raiz);

    printf("\n\nTotal de nós: %d\n", totalNos(raiz));
    printf("Altura da árvore: %d\n", alturaArvBin(raiz));

    printf("\nLiberando árvore...\n");
    liberaArvBin(raiz);

    printf("Árvore liberada com sucesso!\n");

    return 0;
}
