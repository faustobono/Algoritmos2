#include <iostream>
#include <string.h>
using namespace std;
typedef struct nodo{
    int dato;
    struct nodo *izq, *der;
    }NODO;
typedef NODO *arbol;
/**ARBOL N-ARIO*/



void PreOrden (arbol A, posicion p) {
    if (!Nulo(p)) {
        printf(info(p,A));
        c = HijoMasIzq(p,A);
        while (!Nulo(c)){
            PreOrden(A,c);
            c = HnoDer(c, A);
        }
    }
}

void InOrden(arbol A, posicion p){
posicion c;
if (!Nulo(p)) {
    c = HijoMasIzq(p,A);+
    InOrden(c,A);
    printf("%d",info(p,A));
    while(!Nulo(c)) {
        c = HnoDer(c,A);
        InOrden(A,c);
    }
}
}

void PostOrden(arbol A, posicion p) {
posicion c;
}

void CantHojas(arbol A, posicion p, int *CH){
    posicion c;
    if(!nulo(p)){
        c=HijoMasIzq(p,A);
        if(Nulo(c))
            (*CH)++;
        else
            while(!nulo(c)){
                CantHojas(A,c,CH);
                c=HnoDer(c,A);
            }
    }
}

int CantHoj(arbol A, posicion p){
posicion c; int cant = 0;
    if (!Nulo(p)){
        c = HijoMasIzq(p,A);
        if (Nulo(c))
            cant = 1;
        else
            while (!nulo(c)){
                cant+=CantHoj(A,c);
                c = HnoDer(c,A);
            }
    }
    return cant;
}

void Ej23 (arbol A, posicion p, int *cn) { //Ej23(A,Raiz(A),&cant);
posicion c;
    if (!Nulo(p)) {
        (*cn)++;
        c = HijoMasIzq(p,A);
        while (!Nulo(c)){
            Ej23(A,c,cn);
            c = HnoDer(c, A);
        }
    }
}


//int cant = 0, suma = 0, promedio;
//Ej24A(A,Raiz(A),&cant,&suma);
//Promedio = suma / cant;
void Ej24A(Arbol A, posicion p, int *cant, int *suma){
    if (!Nulo(p)) {
        (*cant)++;
        (*suma)+= info(p);
        c = HijoMasIzq(p,A);
        while (!Nulo(c)){
            Ej24A(A,c,cn,cant,suma);
            c = HnoDer(c, A);
        }
    }
}


void Ej24B(arbol A, posicion p,int *cn){
posicion c, aux; int suma = 0;
    if (!Nulo(p)){

        c = HijoMasIzq(p,a);
        suma= info(c);
        aux = HnoDer(c,A)
        while(aux != NULL){
            suma+=info(aux);
            aux = HnoDer(c,A);
        }
        if (suma == p->dato)
            (*cn)++;
        while (!Nulo(c)) {
            Ej24B(A,c);
            c = HnoDer(c,A);
        }
    }
}

int cantGrado(arbol A, posicion c){
cant = 0;
    while (!Nulo(c)){
        cant ++;
        c=HnoDer(c,A);
    }
    return cant;
}

void Ej25A(arbol A,posicion p, int *verifica) {
posicion c;
    if(!nulo(p) && (*verifica == 1)){
        c=HijoMasIzq(p,A);
        if(!Nulo(c)) //No es hoja.
            if (cantGrado(A,c) != info(p))
                (*verifica)=0;
        while(!nulo(c)){
            Ej25A(A,c,verifica);
            c=HnoDer(c,A);
        }
    }
}

int Ej25Aint(arbol A,posicion p){
posicion c;
    if (!Nulo(p)){
        c = HijoMasIzq(p,A);
        if (!Nulo(c)){ //No es hoja.
            if (cantGrado(A,c) != info(p))
                return 0;
            while (!nulo(c)){
                Ej25Aint(A,c);
                c = HnoDer(c,A);
            }
        }
        else
            return 0;
    }else
        return 1;
}

void Ej25B(arbol A, posicion p, int *cont) { //Preguntar
posicion c;
    if(!nulo(p)){

        c=HijoMasIzq(p,A)=HijoMasIzq(p,A);
        if (cantGrado(A,c) % 2 != 0)
            (*Cont)++;
        while(!nulo(c)){
            Ej25B(A,c);
            c=HnoDer(c,A);
        }
    }
}

void EJ25B(arbol A, posicion p, int nivel, int *cont){
    posicion c, aux;
    int sum=0;
    if(!nulo(p)){
        c=HijoMasIzq(p,A);
        if (nivel%2 != 0){
            aux=c;
            while(!Nulo(aux)){
                sum++;
                aux=HnoDer(aux,A);
            }
            if(sum%2!=0){
                (*cont)++;
            }
        }

        while(!nulo(c)){
            EJ25B(c,A, nivel+1, cont);
            c=HnoDer(c,A);
        }
    }
}

void Ej25C(arbol A,posicion p, int *verifica) {
posicion c;
    if(!nulo(p) && (*verifica == 1)){
        c=HijoMasIzq(p,A);
        if(!Nulo(c)) //No es hoja.
            if (cantGrado(A,c) % 2 == 0)
                (*verifica)=0;
        while(!nulo(c)){
            Ej25C(A,c,verifica);
            c=HnoDer(c,A);
        }
    }
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



