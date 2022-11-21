#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;

class Hora{
    int hora;
    int minuto;
    int segundo;
  public:
    Hora();
    Hora(int hor, int minu, int seg);
    void mostrar();
    void suma(Hora x, Hora y);
};


Hora::Hora(){
hora = 0;
minuto = 0;
segundo = 0;

};

Hora::Hora(int hor, int minu, int seg) {
    hora = hor;
    minuto = minu;
    segundo = seg;
};

void Hora::mostrar(){
    printf("%.2d:%.2d:%.2d\n",hora,minuto,segundo);
};

void Hora::suma(Hora x, Hora y){
    hora = x.hora+y.hora;
    minuto = x.minuto + y.minuto;
    segundo = x.segundo + y.segundo;
    if (segundo > 59){
        segundo = segundo - 60;
        minuto++;
    }
    if (minuto > 59) {
        minuto = minuto - 60;
        hora ++;
    }
    if (hora > 23){
        hora = hora - 24;
    }

}

int main(){
Hora a, b(22,55,50), c(21,10,50),d;
a.mostrar();
b.mostrar();
c.mostrar();
d.mostrar();
d.suma(b,c);
d.mostrar();
}
