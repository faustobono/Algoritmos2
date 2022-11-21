#include <stdio.h>
#include <stdlib.h>
/*#include "tdacola.h"
#include "tdapila.h"*/
#define N 6

typedef struct nodo{
    struct nodo *Sig;
    int Dato;
}NODO;
typedef NODO *TLISTA;

/*Dado un grafo de orden N, hallar mediante una función recursiva la cantidad de
vértices de grado mayor a K (K dato). Realizar dos soluciones: matriz de
adyacencia y lista de adyacencia.*/

void Inserta(TLISTA *L){
    int X;
    TLISTA Ult;
    printf("Ingrese la lista\n");
    scanf("%d",&X);
    if(X!=-1){
        *L=(TLISTA)malloc(sizeof(NODO));
        (*L)->Dato=X;
        Ult=*L;

        while(scanf("%d",&X) && X!=-1){
            Ult->Sig=(TLISTA)malloc(sizeof(NODO));
            Ult->Sig->Dato=X;
            Ult=Ult->Sig;
        }
        Ult->Sig=NULL;
    }else
        *L=NULL;
}

void muestra(int grafo[][N], int n){
int i, j;
    for (i = 0; i< n ; i++){
       for (j = 0 ; j<n;j++)
            printf("%d ",grafo[i][j]);
        printf("\n");
    }

}

int Ej19A(int mat[][N], int n, int vertice,int k) {
int Gr =0, j=0;
if (vertice < n){
      while (j<n) {
        if (mat[vertice][j] == 1)
            Gr++;
        j++;
    }
    if (Gr > k)
        return 1 + Ej19A(mat,n,vertice + 1,k);
    else
        return Ej19A(mat,n,vertice + 1,k);
}else
    return 0;
}

int Ej19B(TLISTA vec[N], int n, int vertice, int k) {
TLISTA aux;
int Gr=0;
if (vertice < n) {
    aux = vec[vertice];
    while(aux != NULL) {
        Gr++;
        aux = aux->Sig;
    }
    if (Gr > k)
        return 1 + Ej19B(vec, n, vertice +1, k);
    else
        return Ej19B(vec, n, vertice +1, k);
}else
    return 0;

}

int main(){
int vertice = 0,n = 5,grafo[N][N]={{1,1,0,0,0},{1,0,1,1,0},{0,1,0,1,0},{0,1,1,0,1},{0,0,0,1,0}} ,digrafo[N][N] = {{0,1,0,0,1,0},{0,0,0,0,1,0},{0,1,0,0,0,0},{0,0,0,0,0,1},{0,1,0,1,0,0},{1,0,1,0,0,0}};
TLISTA vec[N];
int vecV[N] = {0}, noConexo[N][N]={{0,1,0,0,0},{1,0,1,0,0},{0,1,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};
    printf("Mat: La cantidad de vertices que tienen grado mayor a k es %d\n",Ej19A(grafo,n,vertice,2));
    for (int i=0;i<n;i++)
        Inserta(&vec[i]);
    printf("Lista: La cantidad de vertices que tienen grado mayor a k es %d\n",Ej19B(vec,n,vertice,2));

return 0;
}
