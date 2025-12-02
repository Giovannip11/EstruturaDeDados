#include <stdio.h>
#define TAM 10

void selectionSort(int *A,int tam){
   int i,x,min,swp;
   for (i=0;i<tam;i++){
       min=i;
       for(x=i+1;x<tam;x++){
           if(A[x]<A[min]){
               min = x;
           }
       }
       swp=A[i];
       A[i]=A[min];
       A[min]=swp;
   }
}

int main (void){
    int A[TAM]={5,2,3,1,10,9,8,7,4,6};
    int i;
    for(i=0;i<TAM;i++){
        printf("Array:%d\n",A[i]);
    }
    selectionSort(A,TAM);
    for(i=0;i<TAM;i++){
        printf("ARRAY ORDENADO:%d\n",A[i]);
    }
return 0;
}
