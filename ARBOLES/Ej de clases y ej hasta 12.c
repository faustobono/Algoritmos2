#include <iostream>
#include <string.h>
using namespace std;
typedef struct nodo{
    int dato;
    struct nodo *izq, *der;
    }NODO;
typedef NODO *arbol;

void Inserta (arbol *A, int X) {
    if (*A == NULL) {
        *A = (arbol) malloc (sizeof (struct nodo));
        (*A)->dato = X;
        (*A)->der = NULL;
        (*A)->izq = NULL;
    }
    else
        if (X>(*A)->dato)
        Inserta(&((*A)->der), X);
        else
        Inserta(&((*A)->izq), X);
}

void preOrden(arbol A){
 if (A != NULL) {
    printf("%d ",A->dato);
    preOrden(A->izq);
    preOrden(A->der);
 }
}
/*Cuenta nodos hojas*/
void cuentaH(arbol A, int *ch){
 if (A!=NULL){
    if (A->der == NULL && A->izq == NULL)
        (*ch)++;
    else{
        cuentaH(A->izq, ch);
        cuentaH(A->der,ch);
    }
 }
}

/*Cuenta nodos hojas con funcion*/
int CuentaH(arbol A){
    if(A!=NULL){
        if(A->der==NULL && A->izq==NULL)
            return 1;
        else
            return CuentaH(A->izq)+CuentaH(A->der);
    }else
        return 0;
}

int esta(arbol A, int x){
    if (A != NULL){
        if (A->dato == x)
            return 1;
        else
            return esta(A->izq,x) || esta(A->der,x);

    }else
        return 0;
}

int ej1A(arbol A){
int cont  = 0;
    if (A== NULL)
        return 0;
    else{
        if (A->dato < 0)
            cont = 1;
        return cont + ej1A(A->izq) + ej1A(A->der);
    }
}

int ej1B(arbol A){
    if (A == NULL)
        return 0;
    else{
        if (A->dato % 5 == 0)
            return A->dato + ej1A(A->izq) + ej1A(A->der);
        else
            return ej1A(A->izq) + ej1A(A->der);
    }
}

int ej1C(arbol A){
    if(A!=NULL){
        if(A->der==NULL && A->izq==NULL)
            return 1;
        else
            return ej1C(A->izq)+ ej1C(A->der);
    }else
        return 0;
}

void ej2(arbol A){
    if (A != NULL) {
        if (A->izq != NULL && A->der != NULL)
            printf("%d",A->dato);
        ej2(A->izq);
        ej2(A->der);
    }
}

void ej3(arbol A, int X, arbol *puntero){ //*puntero = NULL;
    if (A != NULL)
        if (A->dato == X)
            *puntero = A;
        else{
            ej3(A->izq,X,puntero);
            if (*puntero == NULL)
                ej3(A->der,X,puntero);
        }
}

arbol ej4(arbol A, arbol *puntero){
arbol x=NULL;
    if (A!= NULL) {
        if (A->der == (*puntero) || A->izq == (*puntero)){
            if (A->der == (*puntero))
                x = A->izq;
            else
                x = A->der;
            return x;
        }else
            if (x == NULL)
                return ej4(A->izq,puntero);
            else
                return ej4(A->der, puntero);
    }
}

void ej5(arbol A, int vec[], int i){
 if (A != NULL){
    vec[i]=A->dato;
    if (A->der != NULL) //Esto lo hago porque segun el enunciado, ya sebemos que es de grado 1
        ej5(A->der,vec,i+1);
    else
        ej5(A->izq,vec,i+1);
 }
}

int ej6(arbol A, int nivel, int actual) {
if (A != NULL && actual <= nivel) {
    if (actual == nivel)
        return A->dato;
    else{
        return ej6(A->izq, nivel, actual+1) + ej6(A->der, nivel, actual+1);
    }
}else
    return 0;
}

int ej7(arbol A, int nivel, int actual){
    if (A!=NULL && actual < nivel) {
        if (A->dato % 2 != 0)
            return 1 + ej7(A->izq,nivel,actual+1) + ej7(A->der,nivel,actual+1);
        else
            return ej7(A->izq,nivel,actual+1) + ej7(A->der,nivel,actual+1);
    }else
        return 0;
}

void ej7b(arbol A, int nivel, int actual, int *cant){
    if (A != NULL && actual < nivel) {
        if (A->dato % 2 != 0)
            (*cant)++;
        ej7b(A->izq,nivel,actual+1,cant);
        ej7b(A->der,nivel,actual+1,cant);
    }
}

int ej8(arbol A, int X, int Y){
    if (A != NULL) {
        if (A->dato > X && A->dato < Y)
            return 1 + ej8(A->izq,X,Y) + ej8(A->der,X,Y);
        else
        if (A->dato > Y)
            return ej8(A->izq,X,Y);
        else
        if (A->dato < X)
            return ej8(A->der,X,Y);
        else
            return 0;
    }else
    return 0;
}

void ej9(arbol A, arbol puntero, arbol *nuevo) {
    if (A != NULL){
        if (A->der == puntero || A->izq == puntero){
            if (A->der == puntero && A->izq != NULL)
                (*nuevo) = A->izq;
            else
            if (A->der != NULL)
                (*nuevo) = A->der;
        }else{
            if ((*nuevo) == NULL)
                ej9(A->izq, puntero, nuevo);
            else
                ej9(A->der,puntero,nuevo);
        }
    }
}

void ej10(arbol A, int v[], int *i){
    if (A != NULL) {
        ej10(A->der,v,i);
        v[*i] = A->dato;
        (*i)++;
        ej10(A->izq,v,i);
    }
}

int ej11(arbol A) {

if (A != NULL) {
    if ((A->der == NULL) && (A->izq == NULL))
         return 1;
    else{
        int der = ej11(A->der);
        int izq = ej11(A->izq);
        if (izq > der)
            return izq+1;
        else
            return der+1;
    }
}else
    return 0;
}

/*void ej12A(arbol A, int *maxi){
if (A != NULL){

    if (strlen(A->dato) > (*maxi))
        *max = strlen(A->dato);
    ej12A(A->izq,maxi);
    ej12A(A->der,maxi);
}

}*/

int main()
{
    arbol A=NULL; int cant = 0, i = 0;
    int vec[8];
    Inserta(&A,5);
    Inserta(&A,8);
    Inserta(&A,7);
    Inserta(&A,2);
    Inserta(&A,4);
    Inserta(&A,9);
    preOrden(A);
   // printf("-%d-\n",ej4(A,&A->der)->dato);
  /* ej5(A,vec,0);
    for (int i = 0; i<3;i++)
        printf("%d",vec[i]);*/
   /* printf("- %d -",ej6(A,3,1));
    printf("- %d -",ej7(A,3,1));
    ej7b(A,3,1,&cant);
    printf("\n%d",cant);*/
    //printf("\n--> %d",ej8(A,1,10));

    ej10(A,vec,&i);
    printf("\n");
    for (int n = 0; n<i;n++)
        printf("%d ",vec[n]);
    cout<<"\nEl nivel es "<<ej11(A);
    return 0;
}



