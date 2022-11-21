#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <cstdlib>
#include <string>

using namespace std;

typedef struct nodo {
    int Trimestre,anio;
    struct nodo *sig;
}NODO;
typedef NODO *TLISTA;

class PROPIEDAD {
    char Codigo[11], Nombre[12];
    int Superficie, Zona; //Float superficie
    TLISTA pltri;
   public:
    virtual float CalculaDeuda();  //No virtual
    void CancelaDeuda(int c);
    virtual int obt_Sup(){return Superficie;};
    virtual float CalculaImpuesto(){}; //return 0
    virtual int BuscaAnioTri(int T, int A);
    int obt_zona(){return Zona;};
    char *obt_cod(){return Codigo;};
    virtual void MuestraDatos(){cout<<Codigo<<Nombre<<Superficie<<Zona;};
    int NoMoroso(){return pltri != NULL;};
};

float PROPIEDAD::CalculaDeuda() {
TLISTA aux = pltri; int cont = 0;
while (aux!=NULL){
    cont++;
    aux = aux->sig;
}
    return CalculaImpuesto()*cont;
}

int PROPIEDAD::BuscaAnioTri(int T, int A){
//AUX
    while (pltri != NULL && (pltri->anio >A) || (pltri->Trimestre > T)) //Mal.
        pltri = pltri->sig;
    if (pltri!=NULL)return 1;else return 0;
};

void PROPIEDAD::CancelaDeuda(int cant) {
TLISTA aux = pltri; int i = 0;
while(aux!=NULL && cant > i){
    pltri = aux->sig;
    free(aux);
    aux = pltri;
    i++;
}
};

class CASA:public PROPIEDAD{
    int SupCubierta,Tipo, AnioCons;
   public:
    float CalculaImpuesto();
    void MuestraDatos(){PROPIEDAD::MuestraDatos();cout<<SupCubierta<<Tipo<<AnioCons;};
};


float CASA::CalculaImpuesto() {
       return obt_Sup()/**tabla[zona]+(SupCubierta * 0.5*tabla[zona])*/;
}

class COMERCIO:public PROPIEDAD {
    int Rubro;
    char Habilit;
   public:
    float CalculaImpuesto(int Z, int T, int A);
    void MuestraDatos();
};


void COMERCIO::MuestraDatos(){
PROPIEDAD::MuestraDatos();
cout<<Rubro<<Habilit;
};

float COMERCIO::CalculaImpuesto(int Z, int T, int A) {
        if (Rubro < 4)
            return obt_Sup()*1.1;
        else
            return obt_Sup()*1.25;
    return 0;
};

typedef struct nodo2{
    PROPIEDAD *p;
    struct nodo2 *sig;
}NODO2;
typedef NODO2 *TLISTA2;

class TESORERIA {
    TLISTA2 lpro;
   public:
    void TotRecauda(int Z, int T, int A); //Z zona, T trimestre, A año.
    float PagaUno(char *c, float din);
    void EsMoroso(char *c);
};

void TESORERIA::TotRecauda(int Z, int T, int A) {
TLISTA2 aux = lpro; float deuda = 0;

    while (aux!=NULL) {
        if (aux->p->obt_zona()==Z && aux->p->BuscaAnioTri(T,A)){
            deuda+= aux->p->CalculaImpuesto();
        }
        aux = aux->sig;
    }
    cout<<"La deuda del año "<<A<<" y del trimestre "<<T<<" es "<<deuda;

};

float TESORERIA::PagaUno(char *c, float din ) {  //C es codigo de prop. Din es dinero //Hacer void.
TLISTA2 aux = lpro; int cant = 0; float restante;
while (strcmp(aux->p->obt_cod(),c))
    aux=aux->sig;
while (din-aux->p->CalculaImpuesto()){ //Asisgnar
    restante += din-aux->p->CalculaImpuesto(); //Clico no necesario
    cant++;
}
if (cant>0)
    aux->p->CancelaDeuda(cant);
return restante;
}

void TESORERIA::EsMoroso(char *c){ //Parametro que devuelva adeudado
TLISTA2 aux = lpro;
while (strcmp(aux->p->obt_cod(),c))
    aux=aux->sig;
if (aux!=NULL) { //revisar aux y NULL
    aux->p->MuestraDatos();
    if (aux->p->NoMoroso()) {
        cout<<"No Es moroso";
    }else{
        cout<<"Es moroso";
        aux->p->CalculaDeuda();
    }
}
}
int main(){
int tabla [10] = {20,25,30,40,45,55,60,80,100,120};
cout<<"Hello word!\n";

}
