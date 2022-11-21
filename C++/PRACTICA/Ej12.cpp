#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <cstdlib>
#define N 10

using namespace std;
/*QUITE EL SCANF PARA AREA Y DE NRO DE EMPLEADO PARA HACER MAS RAPIDAS LAS PRUEBAS*/
class Empleado{
    char nombre[12];
    int nroemp;
    char ingreso[9];
    int area;
  public:
    Empleado(int numero);
    void asigndatos(char nom[12], char ing[9]);
    void mostrar();
    void obt_area();
    int obt_fecha();
};

Empleado::Empleado(int numero){
        strcpy(nombre ,"---");
        nroemp = numero+1;
        strcpy(ingreso,"00/00/00");
        area = 0;

}

void Empleado::asigndatos(char nom[12], char ing[9]) {
    strcpy(nombre,nom);
    strcpy(ingreso,ing);
    area = 7;
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
Empleado *v[N]; int prueba, n, control, pos; char nom[12], ing[9];
cout<<"\nIngrese cantidad de empleados\n";
scanf("%d",&n);
for(int i=0; i<n;i++){
    v[i] = new Empleado(i);
}

for (int i=0; i<n; i++){
    cout<<"\nIngrese Nombre, ingreso ";
    scanf("%s",nom);
    scanf("%s",ing);

    v[i]->asigndatos(nom,ing);
}

do{
    cout<<"\nMENU DE OPCIONES\n";
    cout<<"Ingrese numero segun corresponda\n";
    cout<<"0. Para salir.\n1. Para mostrar\n2. Para eliminar los empleados que ingresaron antes del 2004\n";
    scanf("%d",&control);
    if (control == 1){
        for (int i=0; i<n; i++){
            v[i]->mostrar();
        }
    }else
    if (control == 2) {
        for (int i=0; i<n; i++) {
            if ((v[i]->obt_fecha() < 4) || (v[i]->obt_fecha() > 21)) {
                delete v[i]; pos = i;
                for (pos; pos<n;pos++)
                    v[pos] = v[pos+1];
                //delete v[n]; //MI DUDA ES QUE CUANDO PONGO delete v[n] NO FUNCIONA.
                               //Con el delete v[n], eliminaria el ultimo elemento del arreglo.
                n--;
                i=-1;
            }
        }
    }
}while(control != 0);



for (int i=0; i<n; i++){
    delete v[i];
}

}
