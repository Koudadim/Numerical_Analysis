#include<iostream>

using namespace std;

void GaussJordan(int n, double* b, double* x, double** A)
{
     int i, j, m, k;
     double pivot, coef, rapcoef, som;
     double** C;
     double** MatReelle(int n);
     void AfficheTabReel(int n, double* T);
     void AfficheMatReelle(int n, double** M);
     C=MatReelle(n);
     for(i=1; i<=n; i++)
          for(j=1; j<=n; j++)
          {
               if(i!=j)
                    C[i][j]=0;
               else
                    C[i][j]=1;
          }

     for(i=1; i<=n; i++)
     {
          pivot=A[i][i];
          if(pivot==0.0)
               {
                    m=1;
                    while(A[m][i]==0 && m<=n)
                         m++;
                    if(m>n)
                    {
                         cout<<"La matrice du systeme est non inversible"<<endl;
                         exit(-1);
                    }
                    else // On permute les lignes m et k des matrices A et B
                    {
                         for(k=i; k<=n; k++)
                         {
                              coef=A[i][k];
                              A[i][k]=A[m][k];
                              A[m][k]=coef;
                         }
                         pivot=A[k][k];

                         for(j=1; j<=n; j++)
                         {
                              coef=C[i][j];
                              C[i][j]=C[m][j];
                              C[m][j]=coef;
                         }
                    }
               }
               for(j=1; j<=n; j++)
                    {
                         if(i!=j)
                        {
                              rapcoef=A[j][i]/A[i][i];
                              for(k=1; k<=n; k++)
                              {
                                   A[j][k]-=rapcoef*A[i][k];
                                   C[j][k]-=rapcoef*C[i][k];
                              }
                        }
                    }
               }
          for(i=1; i<=n; i++)
               for(j=1; j<=n; j++)
                    C[i][j]/=A[i][i];
          cout<<"La matrice inverse de A est: "<<endl;
          AfficheMatReelle(n, C);
          cout<<"Le second membre est: "<<endl;
          AfficheTabReel(n, b);
          for(i=1; i<=n; i++)
               {
                    som=0.0;
                    for(j=1; j<=n; j++)
                         som+=C[i][j]*b[j];
                    x[i]=som;
               }
          cout<<"Par la methode de Gauss-Jordan la solution du systeme est:"<<endl;
          for(i=1; i<=n; i++)
               cout<<"x"<<i<<" = "<<x[i]<<endl;
}
