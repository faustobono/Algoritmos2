#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <cstdlib>
#include <string>
#define N 10

using namespace std;


class PERSONA {
    int edad;
    char nya [40];
public:
    PERSONA (int ed, char cad1[20]){ edad = ed; strcpy(nya,cad1);}
    void Muestra() {cout <<"\n"<< edad <<" "<< nya;}
    void Pone_Nom(char *cad){strcpy(nya,cad);}
};
class PROFESOR:public PERSONA {
    int CantMaterias;
    char nom [20], ape[20];
 public:
    PROFESOR(int ed, char name[20], char last[20], int mat);
    void Muestra(){cout << "\n"<<nom <<" "<< ape<<" " << CantMaterias; PERSONA::Muestra();}
    void Pone_Mate(int m){CantMaterias = m;}
};

PROFESOR::PROFESOR(int ed, char name[20], char last[20], int mat):PERSONA(ed, name) {
        CantMaterias = mat;
        strcpy(nom,name);
        strcpy(ape,last);
}

class ALUMNO:public PERSONA {
    long int Matricula;
    char carrera [20];
 public:
    ALUMNO(int ed, char nomyape[40], int mat, char carre[20]);
    void Muestra(){cout<<"\n"<<Matricula<<" "<<carrera;PERSONA::Muestra();}
};

ALUMNO::ALUMNO(int ed, char nomyape[40], int mat, char carre[20]):PERSONA(ed,nomyape){
    Matricula = mat; strcpy(carrera,carre);
};

int main(){
PROFESOR a(44,"Rodolfo","Lopez",5); ALUMNO b(21,"Ramon Lopez",8,"lic. Sistemas");
ALUMNO *p;
p = new ALUMNO(23,"alvaro Odes",4,"Ing. Sist");
a.Muestra();
printf("\n\n");
b.Muestra();
printf("\n\n");
p->Muestra();
delete p;
}

