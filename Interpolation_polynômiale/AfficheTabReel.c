#include <stdio.h>
#include <stdlib.h>

void AfficheTabReel(double* T, int n)
{
    int i;
    for(i=1; i<=n; i++)
        printf("X%d = %12.14f\n",i ,T[i]);
}
