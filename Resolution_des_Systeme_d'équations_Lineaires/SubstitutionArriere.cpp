#include<iostream>

void SubstitutionArriere(int n, double* x, double* y, double** U)
{

     int i, j, k;
     double som;
     x[n]=y[n]/U[n][n];
     for(i=n-1; i>=1; i--)
     {
          som=0.0;
          for(j=i+1; j<=n; j++)
               som+=U[i][j]*x[j];
          x[i]=(y[i]-som)/U[i][i];
     }
}
