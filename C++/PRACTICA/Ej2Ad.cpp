#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <cstdlib>
#include <string>


using namespace std;

typedef struct nodo {
    char CodLib[5], FechaRet[11];
    struct nodo *sig;
}NODO;
typedef NODO *TLISTA;
class SOCIO{
    char NroSocio[4], Nombre[12];
    int categoria, cantLibros;
    TLISTA plp;
   public:
    virtual int DiasPrestamo() = 0;
    int LibrosAdeudas();
    virtual int Habilitado() = 0;
    int Obt_cat(){return categoria;};
};

int SOCIO::LibrosAdeudas(){
TLISTA aux=plp; int cant = 0;
while (aux != NULL) {
    cant++;
    aux = aux->sig;
}
return cant;
}

class ESTUDIANTE:public SOCIO{
    int Area;
  public:
    int DiasPrestamo();
    int Habilitado();
};

int ESTUDIANTE::DiasPrestamo(){
    if (SOCIO::LibrosAdeudas()>4)
        return 0;
    else {
        if (Area == 1)
            return 3;
        else
        if (Area == 2)
            return 7;
        else
            return 5;
    }
}

int ESTUDIANTE::Habilitado() {
    if (SOCIO::LibrosAdeudas() < 10)
        if (Area == 1) {
            if (SOCIO::Obt_cat() < 3) {
                return 1;
            }else
                return 0;
        }else{
            if(Obt_cat() > 1)
                return 1;
            else return 0;
        }else return 0;
    else
        return 0;
}

class EXTERNO:public SOCIO{
    char FechaIng[11];
  public:
    int DiasPrestamo();
    int Habilitado();
};

int EXTERNO::DiasPrestamo(){
int Antiguedad;
    Antiguedad = FechaIng - FECHAACTUAL;

if (antiguedad <= 0)
    return 0;
else
    return antiguedad+2;
};

int EXTERNO::Habilitado(){
    if (SOCIO::LibrosAdeudas() < 10)
        return 1;
}

typedef struct nodo2{
    SOCIO *lps;
}NODO2;
typedef NODO2 *TLISTA2;
class BIBLIOTECA{
    TLISTA2 ls;
   public:
    void ListadoCat(int c);
};

void BIBLIOTECA::ListadoCat(int c){
TLISTA2 aux = ls;
while (aux != NULL) {

}
}

int main() {
cout<<"Hola Mundo!"<<endl;

}
