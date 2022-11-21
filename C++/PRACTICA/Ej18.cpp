#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <cstdlib>
#include <string>
#include <conio.h>
#include <math.h>
#define PI 3.14


using namespace std;


class figura{
public:
    figura(){};
    virtual void muestra(){};
    virtual void calcula_perim(){};
    virtual void calcula_area(){};
    virtual void calcula_diametro(){};
    virtual void calcula_circunferencia(){};

};

class rectangulo:public figura{
        float altura, base;
     public:
         rectangulo(float a, float b){
             altura = a;
             base = b;
         }
         void muestra();
         void ponealtura(float a){altura = a;}
         void ponebase(float b){base = b;}
         float obt_altura(){return altura;}
         float obt_base(){return base;}
         void calcula_perim(){cout<< "\nPerimetro de Rectangulo: "<<(2*base+2*altura);}
         void calcula_area(){cout<<"\nArea de Rectangulo: "<<(base*altura);}
};

class triangulo : public figura{
        float altura, base;
    public:
         triangulo(float a, float b){
             altura =a;
             base = b;
         }
         void muestra();
         void ponealtura(float a){altura = a;}
         void ponebase(float b){base = b;}
         void calcula_perim(){cout<<"\nPerimetro de Triangulo: "<<(altura+base+(sqrt(pow(altura,2)+pow(base,2))));}
         void calcula_area(){cout<<"\nArea de Triangulo: "<<((base * altura)/2);}
};

class circulo:public figura{
    float radio;
   public:
    circulo(float r){
        radio = r;
    }
    void muestra();
    void calcula_diametro(){cout<<"\nEl diametro del circulo es "<<radio*2;}
    void calcula_circunferencia(){cout<<"\nLa circunferencia es "<<2*PI*radio;}

};

void rectangulo::muestra(){
    cout<<"\nRectangulo Altura: "<<altura << " Base: "<<base;
};
void triangulo::muestra(){
    cout<<"\nTriangulo Altura: "<<altura << " Base: "<<base;
};
void circulo::muestra(){
    cout<<"\nCirculo Radio: "<<radio;
};

int main() {
figura *rec, *tria, *circ;
rec = new rectangulo(2,3);
tria = new triangulo(4,4);
circ = new circulo(5);
rec->calcula_area();
rec->calcula_perim();
rec->muestra();
printf("\n");
tria->calcula_perim();
tria->calcula_area();
printf("\n");
circ->calcula_circunferencia();
circ->calcula_diametro();
circ->muestra();

return 0;
}

