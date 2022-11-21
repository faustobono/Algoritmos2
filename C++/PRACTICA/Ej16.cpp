#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <cstdlib>
#include <string>
#include <conio.h>
#include <math.h>


using namespace std;


class figura{
    float altura, base;
public:
    figura(float a, float b){altura = a; base = b;}
    virtual void muestra()=0;
    virtual void calcula_perim(){}
    virtual void calcula_area(){}
    void ponealtura(float a){altura = a;}
    void ponebase(float b){base = b;}
    float obt_altura(){return altura;}
    float obt_base(){return base;}
};

class rectangulo:public figura{
     public:
         rectangulo(float a, float b):figura(a,b){
         }
         void calcula_perim(){cout<< " Perimetro de Rectangulo: "<<(2*obt_base()+2*obt_altura());}
         void calcula_area(){cout<<" Area de Rectangulo: "<<(obt_base()*obt_altura());}
};

class triangulo : public figura{
    public:
         triangulo(float a, float b):figura(a,b){
         }
         void calcula_perim(){cout<<" Perimetro de Triangulo: "<<(obt_altura()+obt_base()+(sqrt(pow(obt_altura(),2)+pow(obt_base(),2))));}
         void calcula_area(){cout<<" Area de Triangulo: "<<((obt_base() * obt_altura())/2);}
};


void figura::muestra(){
    cout<<"  Altura: "<<altura << " Base: "<<base;
};


int main() {
figura *rec, *tria;
rec = new rectangulo(2,3);
tria = new triangulo(4,4);
rec->calcula_area();
rec->calcula_perim();
rec->muestra();
printf("\n");
tria->calcula_area();
tria->calcula_perim();
tria->muestra();
return 0;
}
