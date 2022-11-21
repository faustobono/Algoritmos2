#include <iostream>
#include <string.h>

using namespace std;

class car{
    int licencia, modelo, pasaj;
    char chofer[10], duenio[10];
public:
    car(int lic, int mod, int pas, char ch[], char due[]);
    int obtLicencia(){return licencia;};
    int obtAUTOS(){return pasaj;};
    virtual void muestraDatos();        //PREGUNTAR
    virtual void detalle(int ki, int pa)=0;
    virtual int obtCapacidad(){return pasaj;};
    virtual int obtModelo(){return modelo;};
    virtual int existedni(int dni);
};

car::car(int lic, int mod, int pas, char ch[], char due[]){
    licencia=lic;
    modelo=mod;
    pasaj=pas;
    strcpy(chofer, ch);
    strcpy(duenio, due);
}

void car::muestraDatos(){
    cout << "\nLicencia: " << licencia
        << "\nModelo: " << modelo
        << "\nAUTOS: " << pasaj
        << "\nChofer: " << chofer
        << "\nDuenio: " << duenio << endl;
}

class taxi:public car{
public:
    taxi(int lic, int mod, int pas, char ch[], char due[]);
    void detalle(int ki, int pa);
    int existedni(int dni){return 0;};
};

taxi::taxi(int lic, int mod, int pas, char ch[], char due[]):car(lic,mod,pas,ch,due){
};

void taxi::detalle(int ki, int pa){
    float precio=44.20+23.12*ki;
    cout << "\nTAXI:\n";
    cout << "\nPrecio viaje de " << ki << "kms es de " << precio << "$";
}

class remis:public car{
public:
    remis(int lic, int mod, int pas, char ch[], char due[]);
    void detalle(int ki, int pa);
    int existedni(int dni){return 0;};
};

remis::remis(int lic, int mod, int pas, char ch[], char due[]):car(lic,mod,pas,ch,due){
};

void remis::detalle(int ki, int pa){
    float precio=18.14*ki;
    cout << "\nREMIS:\n";
    cout << "\nPrecio viaje de " << ki << "kms es de " << precio << "$";
}

typedef struct nodo{
    int DNI;
    struct nodo *sig;
}NODO;
typedef NODO *DNIPASAJ;


class combi:public car{
    int capacidad;
    DNIPASAJ p;
public:
    combi(int lic, int mod, int pas, char ch[], char due[], int c);
    void detalle(int ki, int pa);
    void muestraDatos();
    int existedni(int dni);
};

combi::combi(int lic, int mod, int pas, char ch[], char due[], int c):car(lic,mod,pas,ch,due){
    capacidad=c;
    p=NULL;
};

void combi::muestraDatos(){
    DNIPASAJ aux=p;
    car::muestraDatos();
    cout << "\nCapacidad" << capacidad;
    cout << "\nDNI de pasajeros en viaje :" << endl;
    while(aux!=NULL){
        cout << "\n" << aux->DNI << endl;
    }
};

void combi::detalle(int ki, int pa){
    float precio;
    cout << "\nCOMBI:\n";
    if(ki<=100)
        if(pa<=(capacidad/2))
            cout << "\nPrecio viaje de " << ki << "kms es de 200$";
        else
            cout << "\nPrecio viaje de " << ki << "kms es de 180$";
    else
        if(ki<=200)
            cout << "\nPrecio viaje de " << ki << "kms es de 270$";
        else
            cout << "\nPrecio viaje de " << ki << "kms es de 4000$";
}

int combi::existedni(int dni){
    DNIPASAJ aux=p;
    while(aux!=NULL && aux->DNI!=dni)
        aux=aux->sig;
    if(aux!=NULL)
        return 1;
    else
        return 0;
}

typedef struct nodo1{
    car *pa;
    struct nodo1 *sig;
}NODO1;
typedef NODO1 *AUTOS;

class agencia{
    AUTOS a;
public:
    agencia(){a=NULL;};
    void muestraViaje(float K, int P, int L);
    void genteEnViaje();
    void viajaDNI(int dni);
    void eliminaAnt();
};

void agencia::muestraViaje(float K, int P, int L){
    AUTOS aux=a;
    while(aux!=NULL && aux->pa->obtLicencia()!=L)
        aux=aux->sig;
    if(aux!=NULL)
        aux->pa->detalle(K,P);
    else
        cout << "No se encontro el viaje";
}

void agencia::genteEnViaje(){
    AUTOS aux=a;
    int sumaPasaj=0;
    while(aux!=NULL){
        sumaPasaj+=aux->pa->obtCapacidad();         //Tengo dudas si esta bien por que eso devuelve la capacidad no las personas que hay y puede no estar lleno
        aux=aux->sig;
    }
    cout << "En este momento la empresa esta transportando " << sumaPasaj << "pasajeros";
}

void agencia::viajaDNI(int dni){
    AUTOS aux=a;
    while(aux!=NULL && !aux->pa->existedni(dni))
        aux=aux->sig;
    if(aux!=NULL)
        cout << "Se encontró el pasajero";
    else
        cout << "No se encontró el pasajero";
}

void agencia::eliminaAnt(){
    AUTOS aux=a, ant=NULL, act;
    while(aux!=NULL)
        if(aux->pa->obtModelo()<2015)
            if(aux==a){
                a=a->sig;
                delete aux->pa;
                free(aux);
                aux=a;
            }else{
                ant->sig=act->sig;
                delete act->pa;
                free(act);
                act=ant->sig;
            }
    ant=act; act=act->sig;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
