#include <stdlib.h>
#include <iostream>
#include <string.h>
#define MAXPILA 100

/*7. Implementar la clase Stack que permita almacenar hasta 100 caracteres en un
arreglo. Debe contar con constructor y las funciones necesarias para mantener la pila.
(Recordar la necesidad de mantener la dimensión lógica del arreglo)*/

using namespace std;
class Stack{
    char p[100];
    int tope;
public:
    Stack(){
        tope = 0;
    }
    int llenap();
    int vaciap();
    char consultap();
    void ponep(char e);
    void sacap(char *e);
};

int Stack::llenap(){
    return (tope == MAXPILA);
};

int Stack::vaciap(){
    return (tope == 0);
};

char Stack::consultap(){
    if (tope != -1)
        return p[tope];
};

void Stack::ponep(char e) {
    if (tope != MAXPILA) {
        tope++;
        p[tope] = e;
    }
};

void Stack::sacap(char *e) {
    if (tope != 0) {
        *e = p[tope];
        tope--;
    }
};

int main(){
Stack cad;
    char c;

    cout<<"Ingrese Cadena= ";

    while(!cad.llenap()&&((c=getchar())!='\n')){
        cad.ponep(c);
    }
    while(!cad.vaciap()){
        cad.sacap(&c);
        cout<<"\n"<<c;
    }

    return 0;
}
