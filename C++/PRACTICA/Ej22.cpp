#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <cstdlib>
#include <string>
#include <conio.h>
#define M 20

using namespace std;

struct MOVIMIENTO{
    char Tipo, Fecha[11];
    float Monto;
};

class cuenta {
    char CodC[5], FechaApert[11];
    int NroCuenta;
    MOVIMIENTO Mov[M];
    float Saldo, Interes;
  public:
    cuenta(char *cod,char *fecha,int nroc, float sal, float intes);
    int obt_nrocuenta(){return NroCuenta;};
    float actualizasaldo (float monto){Saldo+=monto;}
    float obt_saldo(){return Saldo;};
    int obt_codcuenta(){return NroCuenta;};
    char obt_codcliente(){return *CodC;};
    virtual void cierre() = 0;
    virtual void deposito() = 0;
    virtual void extraccion(float monto) = 0;
    virtual void resumen() = 0;
    virtual void descargas() = 0;
    virtual void muestra();
};
                        //CUENTA
cuenta::cuenta(char *cod,char *fecha,int nroc, float sal, float intes){
    FILE *arch;
    arch = fopen("arch.txt","r");
    strcpy(CodC,cod);
    strcpy(FechaApert,fecha);
    NroCuenta = nroc;
    Saldo = sal;
    Interes = intes;
    fscanf(arch,"%c %s %f\n",&Mov[0].Tipo,Mov[0].Fecha,&Mov[0].Monto);
    for (int i=1; i<3;i++) {
        fscanf(arch,"%c %s %f\n",&Mov[i].Tipo,Mov[i].Fecha,&Mov[i].Monto);
    }
    fclose(arch);
}

void cuenta::muestra() {

cout<<"\nCodigo cliente: "<<CodC<<" Fecha de Apertura "<<FechaApert<<" Nro Cuenta ";
cout<<NroCuenta<<"\nsaldo "<<Saldo<<" Interes "<<Interes<<"\n";
for (int i=0; i<3;i++){
    cout<<Mov[i].Tipo<<" "<<Mov[i].Fecha<<" "<<Mov[i].Monto<<"\n";
}
}
                                //CUENTA AHORRO
class ahorro:public cuenta{
    int CantExt;
    char DepCheq;
   public:
    ahorro(char *cod,char *fecha,int nroc, float sal, float intes,int cante ,char autch);
    void cierre() {};
    void deposito() {};
    void extraccion(float monto);
    void resumen() {};
    void descargas() {};
    void muestra();
    void mantenimiento(){};
};

ahorro::ahorro(char *cod,char *fecha,int nroc, float sal, float intes, int cante,char autch): cuenta(cod,fecha,nroc, sal,intes){
    DepCheq = autch;
    CantExt = cante;
};

void ahorro::muestra(){
cuenta::muestra();
cout<<"\nAutorizacion de Cheque "<<DepCheq<<" Cantidad de extracciones permitidas "<<CantExt<<"\n";
}

void ahorro::extraccion(float monto){
    if (monto > obt_saldo()){
        monto = obt_saldo();
    actualizasaldo(-monto);
    cout<<"El saldo actual es "<<obt_saldo();
}

                            //CUENTA CORRIENTE

class corriente:public cuenta{
    float montodes;
  public:
    corriente(char *cod,char *fecha,int nroc, float sal, float intes, float mon);
    void cierre() {};
    void deposito() {};
    void extraccion(float monto);
    void resumen();
    void descargas() {};
    void muestra();
    void mantenimiento(){};
};

corriente::corriente(char *cod,char *fecha,int nroc, float sal, float intes, float mon):cuenta(cod,fecha,nroc, sal, intes) {
    montodes = mon;
};

void corriente::extraccion(float monto){
    if (monto > obt_saldo())
        monto = obt_saldo();
    actualizasaldo(-monto);

    cout<<"El saldo actual es "<<obt_saldo();
};

void corriente::muestra() {
cuenta::muestra();
cout<<"\nMonto descubierto maximo "<<montodes;
}

//CLASE BANCO
typedef struct nodo{
    cuenta *pcue;
    struct nodo *sig;
}NODO;
typedef NODO *TLCUENTAS;

typedef struct nodo2{
    char CodCl[5], dni[12];
    struct nodo2 *sig;
}NODO2;

typedef NODO2 *TLCLIENTES;

class banco {
    TLCUENTAS lcue ;
    TLCLIENTES lcli ;
  public:
    banco();
    void apertura(){};
    void cierre(){};
    void resumen(){};
    void deposito(){};
    void extraer(int nrocuenta, float monto);
    void Listadoporsaldo();
    void elimina();
    void egreso(){};

};

banco::banco() {
lcue = NULL;
lcli = NULL;

};

void banco::extraer(int nrocuenta, float monto){
TLCUENTAS aux = lcue;
    while (aux != NULL && aux->pcue->obt_nrocuenta() < nrocuenta) {
        aux = aux->sig;
    }
    if (aux->pcue->obt_nrocuenta() == nrocuenta){
        aux->pcue->extraccion(monto);
        cout<<" La extraccion pudo concretarse";
    }else{
        cout<<"La extraccion no pudo concretarse ";
    }
}

void banco::Listadoporsaldo(){
TLCUENTAS aux = lcue;
    while (aux != NULL) {
        if (aux->pcue->obt_saldo() < 0){
            aux->pcue->muestra();
        }
    aux = aux->sig;
    }
};

void banco::elimina(char codcelim[5]) {
TLCUENTAS act = lcue, ant = NULL;
    while (act != NULL && codcelim<act->pcue->obt_codcuenta()){
        ant = act;
        act = act->sig;
    }
    if (act != NULL) {
            cliente = act->pcue->obt_codcliente();
        if (ant == NULL) {
           lcue = lcue->sig;

        }else {
            ant->sig = act->sig;
        }
        delete act->pcue;
        free(act);
    }
    act = lcue;
    while (act != NULL && strcmp(act->pcue->obt_codcliente(),cliente))
        act = act->sig;
    if (act != NULL)
        cout<<"El cliente no tiene otra cuenta ";
};

int main(){
    cout<<"hello word!\n";
    return 0;
}
