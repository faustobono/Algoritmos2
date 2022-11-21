#include <iostream>
#include <string.h>
using namespace std;




int fibonacci(int n){
    if ((n == 1) || (n==2)){
        return 1;
    }else{
        return fibonacci(n-1) + fibonacci(n-2);
    }
}
int suma (int n){
    if (n == 0)
        return 0;
    else
        return n+ suma(n-1);
}

float potencia(float x, int n){
    if (n == 0){
        return 1.0;
    }else
    if (n == 1)
        return x;
    else{
        return x * potencia(x,n-1);
    }
}

int palindroma(char cad[], int i,int n){

    if ((i >= n) || (cad[i] != cad[n])){
        if (i >= n)
            return 1;
        else
            return 0;
    }else{
        return palindroma(cad,i+1,n-1);
    }
}

int main()
{
char cad[] = {"apapa"};
printf("\n%d",fibonacci(6));
printf("\n%d",suma(6));
printf("\n%.2f",potencia(3.6,4));
int pos = strlen(cad)-1;
if (palindroma(cad,0,pos))
    printf("\nEs palindroma");
else
    printf("\nNo es pali");
}
