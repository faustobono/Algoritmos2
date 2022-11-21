#include <iostream>

using namespace std;

int ej10(int mat[][4], int n, int i, int j, int suma){
    if (i>n)
        return 1;
    else{
        if (j<=n)
            suma+= mat[i][j] + ej10(mat,n,i,j+1,suma);
        else{
            if (suma == (((n+1) * (n+1))))
                return ej10(mat,n,i+1,0,0);
            else
                return 0;
        }


    }
}

int ej11(int mat[][4], int n, int m, int i, int j, int suma){
int sumaAnt;
    if(i>n)
        return 1;
    else{
        if (j<=m){
            suma +=ej11(mat,n,m,i,j+1,suma);
        }else{
            if (i == 0)
                if (suma % 2 == 0)
                    ej11(mat,n,m,i+1,0,0);
                else
                    return 0;
            else{
                sumaAnt = suma;
                if (suma>sumaAnt){
                    sumaAnt = suma;
                    ej11(mat,n,m,i+1,0,0);
                }
                else
                    return 0;
            }
        }
    }

}

int ej12(int mat[][4], int n, int m, int i, int j){
    if (j>m)
        return 0;
    else{
        if (i<=n){
            if (mat[i][j] == 0)
                return 1+ej12(mat,n,m,i+1,j);
            else
                return ej12(mat,n,m,i+1,j);
        }else
            return ej12(mat,n,m,0,j+1);

    }
}

void muestraVec(int v[], int n){
    if (n>=0){
        muestraVec(v,n-1);
        printf("%d ",v[n]);
    }

}

int main()
{   int v[4]={0,0,0,0},n=4, m=4, A[][4]={{2,4,4,0},{2,4,4,1},{2,4,4,2},{2,4,4,6}}, cant=0,B[][4]={{1,4,4,12},{3,19,12,7},{10,12,-89,10},{12,1,10,18}};
    cout << "Hello world!" << endl;
    if (ej10(A,n-1,0,0,0))
        cout<<"\nCumple!";
    else
        cout<<"\No cumple!";
    return 0;
}
