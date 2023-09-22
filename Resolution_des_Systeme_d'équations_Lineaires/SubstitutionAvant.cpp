#include<iostream>

using namespace std;

void SubstitutionAvant(int n, double*y, double* b, double** L)
{
     int i, j;
     double som;
     y[1]=b[1]/L[1][1];
     for(i=2; i<=n; i++)
     {
          som=0.0;
          for(j=1; j<=i-1; j++)
               som+=L[i][j]*y[j];
          y[i]=(b[i]-som)/L[i][i];
     }
}
