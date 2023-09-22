#include<stdio.h>
#include<stdlib.h>

void RemplissageMatReelle(double** M, int n, FILE* fichier)
{
     int i, j;
     for(i=1; i<=n; i++)
          for(j=1; j<=n; j++)
                    fscanf(fichier, "%lf", M[i]+j);
}

