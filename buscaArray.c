#include <stdio.h>
#define TAM 10
// Essa é a busca sequencial linear.

int main(void){
    int A[TAM]={2,5,9,8,7,6,1,4,3,10};
    int n;
    int i;
    printf("Digite o numero que deseja buscar e retornamos sua posicao:");
    scanf("%d",&n);

    for(i=0;i<=TAM;i++){
        if(A[i]==n){
            printf("A posicao e:%d\n",i+1);
        }
    }
}
