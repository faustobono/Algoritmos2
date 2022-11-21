#include <iostream>

using namespace std;

int sumaM(int A[][10],int i, int j, int m){
  if(i==0 && j ==0)
    return A[i][j];
  else
    if(j==0)
      return A[i][j] + sumaM(A,i-1,m-1,m);
    else
        return A[i][j] + sumaM(A,i,j-1,m);
}

int sumaColParM(int A[][10], int i, int j,int n){
    if(j>n)
        return 0;
    else{
        if(i<=n)
            return A[i][j] + sumaColParM(A, i+1, j,n);
        else
            return sumaColParM(A, 0, j+2,n);
    }
}

int vertificaCerosM(int A[][5], int i, int j, int n, int m){
    if(j>m)
        return 1;
    else
        if(i<=n)
            if(A[i][j]!=0)
                return vertificaCerosM(A, i+1,j,n,m);
            else
                return vertificaCerosM(A, 0, j+1,n,m);
        else
            return 0;
}

int cuentaColumnasPares(int A[][5], int i, int j, int n, int m){
    if(j>m)
        return 1;
    else
        if(i<=n)
            if(A[i][j]%2==0)
                return cuentaColumnasPares(A, i+1,j,n,m);
            else
                return cuentaColumnasPares(A, 0, j+1,n,m);
        else
            if(i>n)
                return 1+cuentaColumnasPares(A, 0, j+1,n,m);
}

int Ej6(int A[][4], int i, int j, int n, int m, int elem){
    if (i>n){
        return 0;
    }else
        if (j<=m)
            if (A[i][j]==elem)
                return 1+Ej6(A,i,j+1,n,m,elem);
            else
                return Ej6(A,i,j+1,n,m,elem);
        else
            return Ej6(A,i+1,0,n,m,elem);
}

void Ej6v(int A[][4], int i, int j, int n, int m, int elem, int *cant){
    if (i<n)
        if (j<=m){
            if (A[i][j]==elem)
                (*cant)++;
            Ej6v(A,i,j+1,n,m,elem,cant);
        }else
            Ej6v(A,i+1,0,n,m,elem,cant);
}

int Ej7(int A[][4], int i, int j, int n){
int minim;
    if (i==n && j == n)
        return A[n][n];
    else{
        if (j==n)
            minim = Ej7(A,i+1,0,n);
        else
            minim = Ej7(A,i,j+1,n);
        if (A[i][j]<=minim)
            return A[i][j];
        else
            return minim;
    }
}
void ej8(int A[][4], int v[], int n, int m, int i, int j, int max){

    if (i<=n)
       if (j<=m){
            if (A[i][j] > max)
                max = A[i][j];
            ej8(A,v,n,m,i,j+1,max);
        }else{
            v[i] = max;
            ej8(A,v,n,m,i+1,0,-999);

        }

}

int ej9(int A[][4], int i, int j) {
    if (i<=j){
        if (A[i][j] == A[j][i])
            ej9(A,i+1,j-1);
        else
            return 0;
    }else
        return 1;

}

void muestraVec(int v[], int n){
    if (n>=0){
        muestraVec(v,n-1);
        printf("%d ",v[n]);
    }

}

int main()
{   int v[4]={0,0,0,0},n=4, m=4, A[][4]={{1,4,4,12},{3,19,3,7},{10,6,-89,10},{4,1,10,18}}, cant=0,B[][4]={{1,4,4,12},{3,19,12,7},{10,12,-89,10},{12,1,10,18}};
    cout << "Hello world!" << endl;
    printf("\n%d",Ej6(A,0,0,n-1,m-1,0));
    Ej6v(A,0,0,n-1,m-1,3,&cant);
    printf("\n%d",cant);
    printf("\nEl minimo es %d",Ej7(A,0,0,3));
    ej8(A,v,n-1,m-1,0,0,-999);
    printf("\n\n");
    muestraVec(v,n-1);
    if (ej9(B,0,n-1))
        cout<<"\nEs simetrica";
    else
        cout<<"\nNo es simetrica";
    return 0;
}
