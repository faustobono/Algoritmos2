#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <cstdlib>
#define N 10

using namespace std;


class Empleado{
    char nombre[12];
    int nroemp;
    char ingreso[9];
    int area;
  public:
    Empleado();
    void asigndatos(char nom[12], int nroEmp,char ing[9], int ar);
    void mostrar();
    void mostrar3();
    int obt_area();
    int obt_fecha();
};

typedef struct nodo{
    Empleado *ob;
    struct nodo *sig;
    }NODO;
typedef NODO *TLISTA;

Empleado::Empleado(){
        strcpy(nombre ,"---");
        nroemp = 0;
        strcpy(ingreso,"00/00/00");
        area = 0;

}

void Empleado::asigndatos(char nom[12], int nroEmp,char ing[9], int ar) {
    strcpy(nombre,nom);
    nroemp = nroEmp;
    strcpy(ingreso,ing);
    area = ar;
}

void Empleado::mostrar() {
        cout<<"Nombre: "<<nombre<<"  Nro empleado: "<<nroemp<<"  Fec. ingreso: "<<ingreso<<"  Area: "<<area<<"\n";
}

void Empleado::mostrar3() {
    if (area == 3)
        cout<<"\nNombre: "<<nombre<<" Fec. Ingreso: "<<ingreso<<"\n";
}

int Empleado::obt_fecha() {
    int fecha;
    fecha = (ingreso[6]-48) *10;
    fecha+= ingreso[7] -48;
return fecha;
}

int Empleado::obt_area() {
    return nroemp;
}

void cargalista(TLISTA *pl) {
int n, nroEmp, ar; TLISTA nuevo, act, ant;
char nom[12], ing[9];
cout<<"\nIngrese cantidad de empleados\n";
scanf("%d",&n);
for (int i=0; i<n; i++){
    cout<<"\nIngrese Nombre, nro empleado, ingreso y area";
    scanf("%s",nom);
    scanf("%d",&nroEmp);
    scanf("%s",ing);
    scanf("%d",&ar);

    if ((*pl == NULL) || (nroEmp <= (*pl)->ob->obt_area())){
        nuevo = (TLISTA)malloc(sizeof(NODO));
        nuevo->sig = *pl;
        *pl = nuevo;
    }else{
        act = *pl;
        while (act != NULL && nroEmp > act->ob->obt_area()){
            ant = act; act= act->sig;
        }
        nuevo = (TLISTA)malloc(sizeof(NODO));
        ant->sig = nuevo; nuevo->sig = act;
    }
    nuevo->ob = new Empleado;
    nuevo->ob->asigndatos(nom,nroEmp,ing,ar);
}


}

int main(){

int prueba, n;
TLISTA pl = NULL, act, aux;

cargalista(&pl);
act = pl;
while (act != NULL) {
    act->ob->mostrar3();
    act = act->sig;
}

while (pl != NULL) {
    aux = pl;
    pl = pl->sig;
    delete aux->ob;
    free(aux);
}

if (pl == NULL)
    cout<<"Lista Nula";
}
