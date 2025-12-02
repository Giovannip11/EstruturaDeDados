#include <stdio.h>
#define TAM 10

void bubbleSort(int *A,int tam){
    int i,x,y,swp;
    for(i=0;i<tam;i++){
        swp=0;
    for(x=0;x<tam;x++){
        if(A[i]>A[x+1]){
            y=A[x];
            A[x]=A[x+1];
            A[x+1]=y;
            swp=1;
        }
    }
    if(swp==0){
        break;
    }
    }

}

int main (void){
    int A[TAM]={5,2,3,1,10,9,8,7,4,6};
    int i;
    for(i=0;i<TAM;i++){
        printf("Array:%d\n",A[i]);
    }
    bubbleSort(A,TAM);
    for(i=0;i<TAM;i++){
        printf("ARRAY ORDENADO:%d\n",A[i]);
    }

return 0;
}
