#include<stdio.h>

double Trapeze(int N, double A, double B, double* x, double(*f)(double x))
{
    int i;
    double h, S;
    h=(B-A)/N;
    S=((*f)(x[1])+(*f)(x[N+1]))/2;
    for(i=2;i<=N;i++)
        S+=(*f)(x[i]);
    return h*S;
}
