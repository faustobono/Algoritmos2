#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;

class Punto{
    float x;
    float y;
  public:
    Punto();
    Punto(float c1, float c2);
    void imprimir();
    void ponedatos();
    void resta(Punto h);

};

Punto::Punto() {
    x = 0;
    y = 0;
};

Punto::Punto(float c1, float c2) {
    x = c1;
    y = c2;
};

void Punto::imprimir(){
    cout<<"Coordinada "<<x<<" "<<y<<"\n";
};

void Punto::ponedatos() {
    cout<<"Ingrese coordinada x "; scanf("%f",&x);
    cout<<"Ingrese coordinada y "; scanf("%f",&y);
};

void Punto::resta(Punto h) {
    x-=h.x;
    y-=h.y;
}

int main() {
Punto a, b(1,4),c;

a.imprimir();
b.imprimir();
//c.ponedatos();
c.imprimir();
a.resta(b);
a.imprimir();
b.resta(a);
b.imprimir();
}
