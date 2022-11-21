#include <iostream>
#include <string.h>
using namespace std;

void muestra(int v[], int n){
    if (n>=0){
        muestra(v,n-1);
        printf("%d ",v[n]);
    }
}

void muestrapar(int v[], int n){
    if (n>=0){

        if (n % 2 == 0){
            printf("\n\n%d",v[n]);
            muestrapar(v,n-2);
        }else
            muestrapar(v,n-1);
    }
}

int main()
{
int n = 4,v[n] = {6,4,2,5};
muestra(v,n-1);
muestrapar(v,n-1);

}
