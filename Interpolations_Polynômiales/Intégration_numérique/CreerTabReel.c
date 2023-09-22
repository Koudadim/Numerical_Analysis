#include<stdio.h>

double* CreerTabReel(int n)
{
    double* T;
    T=(double*)malloc((n+1)*sizeof(double));
    if(T==NULL)
        printf("Espace insuffisant!!!");
    else
        T--;
    return T;
}
