#include<stdlib.h>
#include<stdio.h>
double** MatriceCarreeDouble(int N)
{
    double * TabDouble(int N);
    double** A;
    int i;
    A=(double**)malloc(N*sizeof(double*));
    if(A==NULL)
        {
            printf("MatCarreeDouble; Pas assez de memoire! \n");
            exit (-1);
        }
    A--;
    for(i=1; i<=N; i++)
        A[i]=TabDouble(N);
    return A;
}

