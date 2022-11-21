#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <cstdlib>
#include <string>
#include <conio.h>
#include <math.h>
#define PI 3.14
#define MAXV 5


using namespace std;


class figura{
public:
    figura(){};
    virtual void muestra(){};
    virtual void calcula_perim(){};
    virtual void calcula_area(){};
    virtual void calcula_diametro(){};
    virtual void calcula_circunferencia(){};

    virtual ~figura(){}
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

class geometrica{
    figura *vec[MAXV];
    int n;
   public:
    geometrica(){n=0;}
    ~geometrica();
    void ponev(int resp);
    void sacav();
    void muestra();

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



void geometrica::ponev(int resp) {
float r=0,b=0,a=0;
    if (resp == 1) { //Circulo
        printf("\nIngrese radio "); scanf("%f",&r);
        vec[n++] = new circulo(r);
    } else
    if (resp != 4){
        printf("\nIngrese altura y base "); scanf("%f %f",&a,&b);
        if (resp == 2) { //Triangulo
            vec[n++] = new triangulo(a,b);
        } else { //Rectangulo
            vec[n++] = new rectangulo(a,b);
        }
    }else
        printf("\nUsted selecciono salir\n");
};

void geometrica::sacav(){
    if (n!=0){
        delete vec[n];
        n--;
    };
}

void geometrica::muestra(){
    for(int i=0;i<n;i++)
        vec[i]->muestra();
}

geometrica::~geometrica(){
    for(int i=0;i<n;i++)
        delete vec[i];
}


int main() {
figura *e; geometrica geo; int resp;

do{
    printf("\nIngrese respuesta: 1. circulo, 2. triangulo, 3. rectangulo o 4 para salir ");
    scanf("%d",&resp);
    if (resp < 4)
        geo.ponev(resp);
}while(resp != 4);
//geo.sacav();
geo.muestra();
return 0;
}

