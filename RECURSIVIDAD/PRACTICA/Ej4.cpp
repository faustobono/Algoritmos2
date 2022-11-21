#include <iostream>
#include <string.h>
using namespace std;

void muestra(int v[], int n){
    if (n>=0){
        muestra(v,n-1);
        printf("%d ",v[n]);
    }
}

int Ej4a(int v[], int n){ //n --> 3,2,1,0.
    if (n == 0){
        return v[0];
    }else{
        return v[n]+Ej4a(v,n-1);
    }
}
int Ej4b(int v[], int n){
    if (n==0)
        return v[0];
    else{
        return v[n]*Ej4b(v,n-1);
    }
}

void Ej4bv(int v[], int n, int *producto){ //n = 3,2,1,0,
    if (n>0){
        (*producto)*=v[n];
        Ej4bv(v,n-1,producto);

    }else
        (*producto)*=v[0];
}

int maximo(int v[], int n){//3 | 2 | 1 | 0
int max;
    if(n==0){
        return v[0];
    }else{
        max = maximo(v,n-1); // 6
        if (v[n]>max)
            return v[n];
        else
            return max;
    }
}
void maximov(int v[], int n, int *max) { //3 | 2 | 1 | 0 |
    if (n>=0){
        maximov(v,n-1,max);
        if (v[n]>*max)
            *max = v[n];
    }
}

int seEncuentra(int v[],int n,int e){
    if (n>=0 &&  v[n] != e){
        seEncuentra(v,n-1,e);
    }else{
        if (n>= 0)
            return 1;
        else
            return 0;
    }
}

int posicion(int v[], int n,int elem){
int pos;
    if (n>=0 && v[n]!= elem){
        posicion(v,n-1,elem);
    }else
        if (n>=0)
            return n;
        else
            return -1;
}

int posMin(int v[], int n, int *pos) { //CORREGIR PARAMETRO DE SALIDA.
int min;
    if (n==0)
        return v[0];
    else{
        min = posMin(v,n-1,pos);
        if (v[n] < min){
            (*pos) = n;
            return v[n];
        }
        else
            return min;
    }
}

int ocurrencia(int v[], int n, int elem){
int cant=0;
    if (n>=0)
         if (v[n]==elem)
            return 1+ocurrencia(v,n-1,elem);
        else
            return ocurrencia(v,n-1,elem);
    else
        return 0;
}

void ej4H(int v[], int n){
    if (n >=0){
        ej4H(v,n-1);
        printf("%d (%d)  |  ",v[n],n+1);
    }

}

int esIgual(int v[], int b[],int n){
    if (n>= 0 && v[n] == b[n]){
        esIgual(v,b,n-1);
    }else
    if (n<0)
        return 1;
    else
        return 0;
}


void prom(int v[], int n, int *suma, float *prome){
    if (n==0){
        *suma = v[n];
    }
    else{
        prom(v,n-1,suma,prome);
        *suma += v[n];
    }

    *prome = (float)(*suma)/4;
}

void intercambio(int v[], int n, int i) {
int aux;
    if (n == i){
        aux = v[i];
        v[i] = v[n];
        v[n] = aux;
    }else
        if (i< n){
            aux = v[i];
            v[i]=v[n];
            v[n]=aux;
            intercambio(v,n-1,i+1);
        }




}



int main()
{
int n = 4,v[n] = {6,4,8,1}, m = 4,b[n]={1,2,1,3},producto = 1, max = -999, e=4, pos, c[n]={6,4,8,1}, suma = 0;
float promedio = 0;
    muestra(v,n-1);
    printf("\n\nSuma: %d",Ej4a(v,n-1));
    printf("\nProducto con int: %d",Ej4b(v,n-1));
    Ej4bv(v,n-1,&producto);
    printf("\nProducto con void: %d",producto);
    printf("\nEl maximo con int es: %d",maximo(v,n-1));
    maximov(v,n-1,&max);
    printf("\nEl maximo con void es: %d",max);
    if (seEncuentra(v,n,e))
        cout<<"\nSe encontro";
    else
        cout<<"\nNo se encontro";
    cout<<"\nLa posicion es: "<<posicion(v,n-1,e);
    cout<<"\nEl minimo es: "<<posMin(v,n-1,&pos)<<" y su posicion es "<<pos;
    cout<<"\nLa ocurrencia del elemento es: "<<ocurrencia(v,n-1,e)<<"\n";
    ej4H(v,n-1);
    if (esIgual(v,c,n-1))
        cout<<"\nEs igual ";
    else
        cout<<"\nNo es igual";

    prom(v,n-1,&suma,&promedio);
    printf("\nEl promedio es %.2f",promedio);
    intercambio(v,n-1,0);
    printf("\n");
    muestra(v,n-1);
}
