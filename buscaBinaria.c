#include <stdio.h>
#define TAM 10
int main (void){
    int A[TAM]={1,2,3,4,5,6,7,8,9,10};
    int i=0;
    int f = TAM-1;
    int meio;
    int n;
    printf("Digite o valor que deseja buscar:");
    scanf("%d",&n);

    while(i<=f){
        meio= i + (f - i) / 2;

        if(A[meio]==n){
            printf("A posicao eh:%d\n",A[meio-1]);
            break;
        }
        else if(A[meio] < n){
            i = meio + 1;
        }
        else if(A[meio] > n){
            f = meio - 1;
        }
        else{
            printf("Encontrou:%d",meio);
            break;
        }
    }

    return 0;

}
