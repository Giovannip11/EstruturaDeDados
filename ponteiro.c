#include <stdio.h>

int main(void){
/*    int c = 10;

    int *p;

    p=&c;

    printf("O conteudo apontado por p:%d\n",*p);

    *p=12;
    printf("O conteudo apontado por p:%d\n",*p);
    printf("O conteudo de c:%d\n",c);
*/
/*
int *p;
int c =10;
p=&c;

(*p)++;
*p= (*p) * 10;

printf("O conteudo de *p:%d\n",*p);

*/

int *p,*p1,x,y;
p=&x;

p1=&y;
if(p==p1){
    printf("Os ponteiros sao iguais\n");
}else{
    printf("Os ponteiros sao diferentes\n");
}
}
