#include <stdio.h>
#define TAM 10

void insertionSort(int *A,int tam){
    int i,x,aux;
    for(i=1;i<tam;i++){
        aux=A[i];
    x=i-1;
    }
    while(x>=0 && A[x]>aux){
        A[x+1] = A[x];
        x--;
    }

    A[x+1] = aux;

}

int main(void){
    int A[TAM]={5,2,3,1,10,9,8,7,4,6};
    int i;
    for(i=0;i<TAM;i++){
        printf("Array:%d\n",A[i]);
    }

    insertionSort(A,TAM);

    for(i=1;i<=TAM;i++){
        printf("ARRAY ORDENADO:%d\n",i);
    }
}
