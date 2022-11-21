#include <iostream>
#include <string.h>
using namespace std;




void calculo(int n1, int n2,int *cociente, int *resto){
    if (n1 > n2){
        calculo(n1-n2,n2,cociente,resto);
        (*cociente)++;
    }else{
        if (n1 == n2){
            *cociente = 1;
            *resto = 0;
        }else{
            *cociente = 0;
            *resto = n1;

        }
        }
}
void listado(int n, int i, int j){

    if (i<= n/2){
        printf("(%d - %d)\n",i,j);
        listado(n,i+1,j-1);

    }

}

void dosc(int n){
    if (n > 0){
        printf("%d",n%10);
        dosc(n/10);
    }


}

int main()
{
int n = 6424;
//int n1 = 15, n2=3,c = 0, r = 0;
//calculo(n1,n2,&c,&r);
//printf("%d %d ",c,r);
//listado(n,1,n-1);
dosc(n);
}
