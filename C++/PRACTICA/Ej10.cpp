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
    void asigndatos(char nom[12], int nempl, char ing[9], int ar);
    void mostrar();
    void obt_area();
    int obt_fecha();
};

Empleado::Empleado(){ //Un solo empleado, esto en el principal
    for(int i=0;i<N;i++) {
        strcpy(nombre ,"---");
        nroemp = 0;
        strcpy(ingreso,"00/00/00");
        area = 0;
    }
}

void Empleado::asigndatos(char nom[12], int nempl, char ing[9], int ar) {

    strcpy(nombre,nom);
    nroemp = nempl;
    strcpy(ingreso,ing);
    area = ar;
}

void Empleado::mostrar() {
    cout<<"Nombre: "<<nombre<<"  Nro empleado: "<<nroemp<<"  Fec. ingreso: "<<ingreso<<"  Area: "<<area<<"\n";
}

int Empleado::obt_fecha() {
    int fecha;
    fecha = (ingreso[6]-48) *10;
    fecha+= ingreso[7] -48;
return fecha;
}

int main(){
Empleado v[N]; int prueba, n, nemple, ar; char nom[12], ing[9];

printf("\nIngrese cantidad de empleados ");
scanf("%d",&n);
 for(int i=0; i<n;i++){
    cout<<"\nIngrese nombre, nro de empleado, fecha de ingreso y area\n";
    scanf("%s",nom);
    scanf("%d",&nemple);
    scanf("%s",ing);
    scanf("%d",&ar);
    v[i].asigndatos(nom,nemple,ing,ar);
 }

/* for(int i=0; i<n;i++)
    v[i].mostrar();*/



 for(int i=0; i<n;i++){
    if ((21 - v[i].obt_fecha())>= 10)
        v[i].mostrar();
 }
}
