#include<stdio.h>

void TabReel(double a, double b, int N, double* x)
{
    int i;
    double h;
    h=(b-a)/N;
    for(i=1; i<=N+1; i++)
        x[i]=a+(i-1)*h;
}
