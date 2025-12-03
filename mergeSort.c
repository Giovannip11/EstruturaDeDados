#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define TAM 10
void merge(int *A,int inicio,int meio,int fim){
    int i = inicio, x=meio+1, k=0;
    int tamanho = fim -inicio +1;
    int *temp = (int *)malloc(tamanho *sizeof(int));

    while(i<=meio && x <= fim){
        if(A[i]<=A[x]){
            temp[k++] = A[i++];
        }else{
            temp[k++] = A[x++];
        }
    }
    while(i<=meio){
        temp[k++] = A[i++];
    }
    while(x<=fim){
        temp[k++]= A[x++];
    }
    for(i = 0; i<tamanho;i++){
        A[inicio +i]=temp[i];
    }
    free(temp);
}

void mergeSort(int *A, int inicio, int fim){
    int meio;
    if(inicio<fim){
        meio=floor((inicio+fim)/2);
        mergeSort(A,inicio,meio);
        mergeSort(A,meio+1,fim);
        merge(A,inicio,meio,fim);
    }
}



int main(void){
    int i;
    int A[TAM]={2,4,5,1,3,7,9,8,10,6};
    printf("ARRAY N ORDENADO:\n");
    for(i=0;i<TAM;i++){
        printf("%d\n",A[i]);
    }
    mergeSort(A,0,TAM-1);
    printf("VETOR ORDENADO:\n");
    for(i=0;i<TAM;i++){
        printf("%d\n",A[i]);
    }

    return 0;
}
