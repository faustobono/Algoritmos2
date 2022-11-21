#include <stdlib.h>
#include <iostream>
#include <string.h>

using namespace std;

class ClienteBanco{
    char nombre[12];
    char PIN[5];
    float saldo;
    void mostrar_e();
    int PinCorrecto(char pin[5]);
  public:
    ClienteBanco();
    ClienteBanco(char nom[12],char pin[5], float sal);
    void depositar(float dinero);
    void extraer(float dinero);

};

ClienteBanco::ClienteBanco() {
    strcpy(nombre,"--");
    strcpy(PIN,"--");
    saldo = 0;
};

ClienteBanco::ClienteBanco(char nom[12],char pin[5], float sal) {
    strcpy(nombre,nom);
    strcpy(PIN,pin);
    saldo = sal;
    mostrar_e();
}

void ClienteBanco::mostrar_e() {
    cout<<"\nCLIENTE: "<<nombre<<" PIN: "<<PIN<<" SALDO: "<<saldo;
}

void ClienteBanco::depositar(float dinero) {
char pin[5];
    cout<<"\nIngresar PIN: "; scanf("%s",pin);
    if (PinCorrecto(pin))
        saldo+=dinero;
    else
        cout<<"Pin incorrecto\n";
    mostrar_e();
}

void ClienteBanco::extraer(float dinero) {
char pin[5];
    cout<<"\nIngresar PIN: "; scanf("%s",pin);
    if (PinCorrecto(pin))
        saldo-=dinero;
    else
        cout<<"Pin incorrecto\n";
    mostrar_e();
}

int ClienteBanco::PinCorrecto(char pin[5]) {
    if (!strcmp(PIN,pin))
        return 1;
    else
        return 0;
}

int main() {
ClienteBanco c1, c2("fausto","1234",4000);


c2.depositar(1000);
c2.extraer(500);
//c2.mostrar_e();

}
