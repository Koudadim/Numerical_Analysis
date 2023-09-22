#include<iostream>
#include<math.h>
using namespace std;

void Cholesky(int n, double* b, double* x, double** A)
{
     int i, j, k;
     double som;
     double** L;
     double** Lt; // Transposée de L
     double* y;
     double* TabReel(int n);
	double** MatReelle(int n);
     void AfficheTabReel(int n, double* T);
     void AfficheMatReelle(int n, double** M);
     void SubstitutionArriere(int n, double* x, double* y, double** U);
     void SubstitutionAvant(int n, double*y, double* b, double** L);
     L=MatReelle(n);
     Lt=MatReelle(n);
     y=TabReel(n);

     cout<<"Methode de CHOLESKY"<<endl;
     cout<<"La matrice du systeme est: "<<endl;
     AfficheMatReelle(n, A);
     cout<<"Le second membre est: "<<endl;
     AfficheTabReel(n, b);

     L[1][1]=sqrt(A[1][1]);
     for(i=2; i<=n; i++)
          L[i][1]=A[i][1]/L[1][1];

     for(k=2; k<=n; k++)
     {
          som=0.0;
          for(j=k-1; j>=1; j--)
               som+=L[k][j]*L[k][j];
          som=A[k][k]-som;
          L[k][k]=sqrt(som);

          for(i=k+1; i<=n; i++)
          {
               som=0.0;
               for(j=k-1; j>=1; j--)
                    som+=L[i][j]*L[k][j];
               L[i][k]=(A[i][k]-som)/L[k][k];
          }
          for(i=k-1; i>=1; i--)
               for(j=k; j<=n; j++)
                    L[i][j]=0.0;
     }

      for(i=1; i<=n; i++)
               for(j=1; j<=n; j++)
                    Lt[i][j]=L[j][i];

     cout<<"La matrice L telle que A=L Lt est :"<<endl;
     AfficheMatReelle(n, L);
     cout<<"La transpossees de L est Lt qui est la suivante:"<<endl;
     AfficheMatReelle(n, Lt);
     SubstitutionAvant(n, y, b, L);
     SubstitutionArriere(n, x, y, Lt);
     cout<<"La solution du systeme est"<<endl;
     for(i=1; i<=n; i++)
          cout<<"x"<<i<<" = "<<x[i]<<endl;
}
