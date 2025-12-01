//Busca feita quando o array está ordenado
#include <stdio.h>
#define TAM 10
int main (void){
int A[TAM]={1,2,3,4,5,6,7,8,9,10};
int i;
int n;
printf("Digite o numero que deseja buscar e retornamos sua posicao:");
scanf("%d",&n);

for(i=0;i<=TAM;i++){
    if(A[i]==n){
        printf("elemento na posicao:%d\n",i);
    }
    if(n<A[i]){
        return -1;
    }
}

}
