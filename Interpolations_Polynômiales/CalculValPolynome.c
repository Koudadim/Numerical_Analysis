#include<stdio.h>
#include<stdlib.h>

double CalculValPolynome(double* X, double* Y, double Val, int N, int choix)
{
    int k=choix;
    double valeur;
    double Lagrange(double*x,double*y,int N,double alpha);
    double Newton(double* x,double *y,int N, double alpha);
    double Aitken(double* x,double* y, int N, double alpha);
    double(* Algorithme[3])(double)={Lagrange, Newton, Aitken}; // Tableau de pointeurs sur les algorithmes
    double(* AlgoChoisi)(double* X, double* Y, int N, double Val);
    AlgoChoisi=Algorithme[k-1];
    valeur=AlgoChoisi(X, Y, N+1, Val);
    return valeur;
}
