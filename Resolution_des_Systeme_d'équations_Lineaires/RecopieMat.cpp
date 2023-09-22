#include<iostream>

void RecopieMat(int n, double** A, double** B)
{
     int i, j;
     for(i=1; i<=n; i++)
          for(j=1; j<=n; j++)
               A[i][j]=B[i][j];
}
