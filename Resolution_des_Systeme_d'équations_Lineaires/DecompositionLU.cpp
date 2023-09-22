#include<iostream>
using namespace std;

void DecompositionLU(int n, double* b, double* x, double** A)
{
     int i, j, k;
     double som;
     double** L;
     double** U;
     double* y;
     double* TabReel(int n);
	double** MatReelle(int n);
     void AfficheTabReel(int n, double* T);
     void AfficheMatReelle(int n, double** M);
     void SubstitutionAvant(int n, double*y, double* b, double** L);
     void SubstitutionArriere(int n, double* x, double* y, double** U);
     L=MatReelle(n);
     U=MatReelle(n);
     y=TabReel(n);
     cout<<"Methode de la decomposition LU"<<endl;
     cout<<"La matrice du systeme est: "<<endl;
     AfficheMatReelle(n, A);
     cout<<"Le second membre est: "<<endl;
     AfficheTabReel(n, b);

     for(i=1; i<=n; i++)
          for(j=1; j<=n; j++)
               U[i][j]=A[i][j];

     for(k=1; k<=n-1; k++)
     {
          for(i=1; i<k; i++)
               L[i][k]=0.0;
          L[k][k]=1;
          for(i=k+1; i<=n; i++)
               L[i][k]=U[i][k]/U[k][k];
          for(i=k+1; i<=n; i++)
               {
                    for(j=1; j<=k; j++)
                         U[i][j]=0.0;
                    for(j=k+1; j<=n; j++)
                         U[i][j]-=L[i][k]*U[k][j];
               }
     }
     for(i=1; i<=n; i++)
          L[i][n]=0.0;
     L[n][n]=1;

     cout<<"La decomposition LU de A donne:"<<endl;
     cout<<"La matrice  triangulaire inferieure L:"<<endl;
     AfficheMatReelle(n, L);
     cout<<"La matrice  triangulaire superieur U:"<<endl;
     AfficheMatReelle(n, U);
     SubstitutionAvant(n, y, b, L);
     SubstitutionArriere(n, x, y, U);
     cout<<"La solution du systeme est"<<endl;
     for(i=1; i<=n; i++)
          cout<<"x"<<i<<" = "<<x[i]<<endl;
}
