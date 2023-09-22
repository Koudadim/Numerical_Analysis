#include<stdio.h>
#include<stdlib.h>

void RemplissageTabReel(double* T, int n, FILE* fichier)
{
     int i;
     for(i=1; i<=n; i++)
          fscanf(fichier, "%lf", T+i);
}
