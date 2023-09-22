#include<iostream>

void RecopieTab(int n, double* x, double* y)
{
     int i;
     for(i=1; i<=n; i++)
          x[i]=y[i];
}
