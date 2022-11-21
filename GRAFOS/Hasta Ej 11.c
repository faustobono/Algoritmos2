#include <stdio.h>
#include <stdlib.h>
#include "tdacola.h"
#include "tdapila.h"
#define N 6

typedef struct nodo{
    struct nodo *Sig;
    int Dato;
}NODO;
typedef NODO *TLISTA;

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


void ej4(int mat[][N],int n, int grafo[][N]){
int i = 0, j=0;
    for (i = 0; i< n;i++)
        for (j=i; j< n ; j++){
            if (mat[i][j] == 1 || mat[j][i] == 1){
                grafo[i][j] = 1;
                grafo[j][i] = 1;
            }else{
                grafo[i][j] = 0;
                grafo[j][i] = 0;
            }
        }

}

int gradoSalida(int mat[][N], int n, int x){
    int cont=0;
    x--;
    for(int j=0; j<n;j++)
        if(mat[x][j])
            cont++;
    return cont;
}

int gradoEntrada(int mat[][N], int n, int x){
    int cont=0;
    x--;
    for(int i=0; i<n;i++)
        if(mat[i][x])
            cont++;
    return cont;
}

void EJ5(int mat[][N], int n, int vertice){
    int GE, GS ,GN;
        GS=gradoSalida(mat, n, vertice);
        GE=gradoEntrada(mat, n, vertice);
        GN=GS+GE-mat[vertice][vertice];
        printf("\nGS: %d",GS);
        printf("\nGE: %d",GE);
        printf("\nGrado del vertice %d: %d",vertice, GN);
}

void muestra(int grafo[][N], int n){
int i, j;
    for (i = 0; i< n ; i++){
       for (j = 0 ; j<n;j++)
            printf("%d ",grafo[i][j]);
        printf("\n");
    }

}

int gradoSalidaLista(TLISTA vec[],int n,int vertice){
int i = 0, cont =0; TLISTA aux;
    while (i<n && vec[i]->Dato != vertice - 1){
        i++;
    }
    if (i<n){
        aux = vec[i];
        while (aux != NULL){
            if (aux->Dato != vertice-1)//Controlo que no sea bucle.
                cont++;
            aux=aux->Sig;
        }
    }
return cont;
}

int gradoEntradaLista(TLISTA vec[], int n, int vertice){
int i = 0, cont =0; TLISTA aux;
while (i<n){
    if (vec[i]->Dato != vertice-1){
        aux = vec[i];
        while(aux != NULL){
            if (aux->Dato == vertice-1 )
                cont++;
            aux=aux->Sig;
        }
    }
    i++;
}
return cont;
}

void ej5Lista(TLISTA vec[], int n, int vertice){
int GS, GE, GN;
GS=gradoSalidaLista(vec,n,vertice);
GE = gradoEntradaLista(vec,n,vertice);
GN = GS + GE;

}


int ej6A(int mat[][N], int n, int vertice){
return gradoEntrada(mat,n,vertice);
}

int ej6B(TLISTA vec[], int n, int vertice){
return gradoEntradaLista(vec,n,vertice);
/*LLame a la funcion que ya habia hexcho para el ej5b*/

}

int ej6C(int mat[][N], int n, int vertice){
int i, j, cont=0;
    for (i=0;i<vertice-1;i++)
        cont+= mat[i][vertice-1];

    for (j=vertice-1;j<n;j++)
        cont+= mat[vertice-1][j];
return cont;
}

void ej8(int mat[][N], int vec[], int n, int vertice){
int i, cont =0;
if (vertice-1<n){
    for(i=0;i<n;i++)
        if (mat[i][vertice-1]>0)
            cont++;
    vec[vertice-1] = cont;
    ej8(mat,vec,n,vertice+1);
}
}

int fin(int vec[], int n){
int i=0;
while (i<n && vec[i] == 1){
    i++;
}
if (i<n)
    return 0;
else
    return 1;
}

void Ej10A(int mat[][N], int n,int origen) {
int Vv[N] ={0},c,j;
TCOLA cola;
iniciac(&cola);
ponec(&cola,origen);
Vv[origen] = 1;
printf("%d",origen);
while (!fin(Vv,n)){
    sacac(&cola,&c);
    for(int j=0;j<n;j++)
        if(mat[c][j]!=0 && Vv[j]!= 1){
            Vv[j]=1;
            printf("%d",j);
            ponec(&cola,j);
        }
}
}

void Ej10B(int mat[][N], int n, int origen){
    TPILA pila;
    int i=0,elem, cont=0, vecVis[N] = {0};
    iniciap(&pila);
    vecVis[origen]=1;
    printf("%d - ", origen);
    ponep(&pila, origen);
    consultap(pila, elem);
    while(!fin(vecVis,n)){
        while(i<n && (mat[elem][i]==0 || vecVis[i]==1))
            i++;
        if(i<n && vecVis[i]!=1){
            vecVis[i]=1;
            printf("%d - ", i+1);
            ponep(&pila, elem);
        }else
            if(i==n)
                sacap(&pila, &elem);
            consultap(pila, elem);
    }
}

int buscaNoVisitado(int Vv[],  int n){
int i = 0;
    while (i<n && Vv[i] == 1)
        i++;
    return Vv[i];
}

void Ej11(int mat[][N], int n,int origen) { //No se si esta bien.
int Vv[N] ={0},c,j, cont=0;
TCOLA cola;
iniciac(&cola);
ponec(&cola,origen);
Vv[origen] = 1;
printf("%d",origen);
while (!fin(Vv,n)){
    sacac(&cola,&c);
    for(int j=0;j<n;j++)
         if(mat[c][j]!=0 && Vv[j]!= 1){
            Vv[j]=1;
            printf("%d",j);
            ponec(&cola,j);
        }
    if (vaciac(cola) && !fin(Vv,n)){
        cont++;
        c=buscaNoVisitado(Vv,n);
        ponec(&cola,c);
        Vv[c]=1;
        printf("%d",c);
    }

}
printf("\nCantidad de no conexos %d",cont);
}

/*void Ej15A(int mat[][N], int n, int i, int j, int *alcanzable) {
int Vv[N]={0}
if (mat[i][j] == 1){
    *alcanzable = 1;
}else{

}
}*/



int main(){
int vertice = 1,n = N,grafo[N][N]={0} ,mat[N][N] = {{0,1,0,0,1,0},{0,0,0,0,1,0},{0,1,0,0,0,0},{0,0,0,0,0,1},{0,1,0,1,0,0},{1,0,1,0,0,0}};
TLISTA vec[N];
int vecV[N] = {0}, noConexo[N][N]={{0,1,0,0,0},{1,0,1,0,0},{0,1,0,0,0},{0,0,0,0,0},{0,0,0,0,0}};
    ej4(mat,n,grafo);
    muestra(grafo,n);
     /*for(int i=0;i<5;i++)
        Inserta(&vec[i]);*/
    printf("\n");
   // muestra(mat,n);
    printf("\n");
    //ej5(mat,n,vertice);
    printf("\n%d ",ej6A(grafo,n,1));
    printf("\n%d ",ej6C(grafo,n,1));
    ej8(grafo,vecV,n,vertice);
    printf("\n");
    for(int i=0;i<n;i++)
        printf("%d ",vecV[i]);
    printf("\n");
    Ej10A(grafo,n,2);
    printf("\n");
  //  Ej10B(grafo,n,2);
    printf("\n");
    Ej11(noConexo,5,0);
    return 0;
}
