#include <iostream>
#include <string.h>
using namespace std;
typedef struct nodo{
    int dato;
    struct nodo *izq, *der;
    }NODO;
typedef NODO *arbol;
/**ARBOL GENERALES A ARBOL BINARIO*/
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



int calculaGrado21A(arbol A){
    int cont=0;
    while(A!=NULL && cont<=5){
        A=A->der; cont++;
    }
    return cont==5;

}
void EJ21Arecorre(arbol A, int *verifica){
    if(A!=NULL){
        if(calculaGrado21A(A))
            *verifica=1;
        else{
            EJ21Arecorre(A->izq, verifica);
            if(verifica==0)
                EJ21Arecorre(A->der, verifica);
        }
    }
}

int calculaGrado21B(arbol A) {
int cont = 0;

while (A != NULL) {
    cont++;
    A = A->der;
}
return cont;
}

void ej21B(arbol A, int *maximo) { //Preguntar si esta bien.
int control = 0;
    if (A != NULL){
        control  = calculaGrado21B(A);
        if (control > *maximo)
            *maximo = control;
        ej21B(A->izq, maximo);
        ej21B(A->der, maximo);
    }

}

void ej21C(arbol A, int *cont) { //Preguntar si esta bien.
    while(A != NULL) {
        if (A->izq == NULL){
            (*cont)++;
            ej21C(A->der,cont);
        }else{
            ej21C(A->izq,cont);
            ej21C(A->der,cont);
        }
    }
}

/*21d) Dado un árbol binario que proviene de la transformación
de un árbol general, hallar la altura del árbol original.*/
void ej21D(arbol A, int *altura) { //Preguntar si esta bien

    while (A != NULL){
        if (A->izq != NULL){
            (*altura)++;
            ej21D(A->izq,altura);
        }
        ej21D(A->der,altura);
    }
}

void ej21E(arbol A, int k, int *verifica) {
    while (A =! NULL && k >= 0 && (*verifica)==0){
        if (A->izq == NULL && k == 0)
            (*verifica) =1;
        if (A->izq != NULL){
            k--;
            ej21E(A->izq,k);
        }
        ej21E(A->der,k);
    }
}

/**BOSQUE A ARBOL BINARIO*/
void ej22A(arbol A, int *cont){
    while(A != NULL) {
        (*cont)++;
        ej22A(A->der,cont);
    }
}

int cuentaNivel(arbol A, int k) {
if (A != NULL){
    if (A->izq != NULL)
        return 1 + cuentaNivel(A->izq,k) + cuentaNivel(A->der,k);
    else
        return cuentaNivel(A->der,k);
}else
    return 0;
}

void ej22B(arbol A, int k, int *verifica) { //verifica = 0;
    while(A != NULL && *verifica != 1) {
        if (cuentaNivel(A,k) >= k)
            (*verifica) = 1;
        else
            ej22B(A->der,k,verifica);
    }
}

int verifCero(arbol A) {
if (A != NULL && A->dato != 0) {
    return verifCero(A->izq) + verifCero(A->der);
}else
    if (A == NULL)
        return 0;
    else
        return 1;
}

void ej22C(arbol A, int *todos) {
while (A != NULL) {
    if (verifCero(A->izq))
        ej22C(A->der);
    else
        *todos = 0;
}
}


void ej23(arbol A){
while ()

}

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
  /* // printf("-%d-\n",ej4(A,&A->der)->dato);
   ej5(A,vec,0);
    for (int i = 0; i<3;i++)
        printf("%d",vec[i]);
    printf("- %d -",ej6(A,3,1));
    printf("- %d -",ej7(A,3,1));
    ej7b(A,3,1,&cant);
    printf("\n%d",cant);
    //printf("\n--> %d",ej8(A,1,10));

   // ej10(A,vec,&i);
    printf("\n");
    for (int n = 0; n<i;n++)
        printf("%d ",vec[n]);
//    cout<<"\nEl nivel es "<<ej11(A);*/
    return 0;
}



