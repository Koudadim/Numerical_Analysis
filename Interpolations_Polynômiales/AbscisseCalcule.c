#include <stdio.h>
#include <stdlib.h>

void AbscisseCalcule(double* x, double x1, double h, int n)
{
    int i;
    void AfficheTabReel(double* T, int n);
    //x--;
    for(i=1; i<=n; i++)
        x[i]=x1+(i-1)*h;
    printf("Les abscisses sont : \n");
    AfficheTabReel(x, n);
}
