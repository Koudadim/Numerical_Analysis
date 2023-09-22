#include<stdio.h>

double Simpson(int N, double A, double B, double* x, double(*f)(double x))
{
    int i;
    double h, S;
    h=(B-A)/N;
    S=(*f)(x[1])+(*f)(x[N+1]);
    for(i=2; i<=N; i+=2)
        S+=2*(*f)(x[i]);
    for(i=2; i<N; i+=2)
        S+=4*(*f)(x[i+1]);
    S*=(h/3);
    return S;
}
