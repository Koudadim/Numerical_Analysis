#include<iostream>
#include<math.h>
using namespace std;

void Gauss(int n, double* b, double* x, double** A)
{
     int i, j, k, m;
     double pivot, som, aide, coef, det;
     int NbrePermut=0;
     void AfficheTabReel(int n, double* T);
     void AfficheMatReelle(int n, double** M);
     cout<<"Nous sommes dans Gauss!"<<endl<<endl;
     for(k=1; k<=n-1; k++)
     {
          cout<<"Etape N° "<<k-1<<endl;
          AfficheMatReelle(n, A);
          cout<<endl;
          AfficheTabReel(n, b);
          cout<<endl;
          pivot=A[k][k];
          if(pivot==0)
          {
               m=k+1;
               while(m<=n && A[m][k]==0)
                    m++;
               if(m<=n)
               {
                    cout<<"Permutation des lignes "<<k<<" et "<<m<<endl;
                    for(j=1; j<=n; j++)
                    {
                         aide=A[k][j];
                         A[k][j]=A[m][j];
                         A[m][j]=aide;
                    }
                    aide=b[k];
                    b[k]=b[m];
                    b[m]=aide;
                    pivot=A[k][k];
                    NbrePermut++;
               }
               else
               {
                    cout<<"La matrice du systeme est non inversible!"<<endl;
                    exit(-1);
               }
          }
          for(i=k+1; i<=n; i++)
               {
                    coef=A[i][k]/pivot;
                    for(j=k; j<=n; j++)
                         A[i][j]-=coef*A[k][j];

                    for(j=1; j<=k; j++)
                         A[i][j]=0;

                    b[i]-=coef*b[k];
               }

     }
     cout<<"Apres triangularisation: "<<endl;
     cout<<"1 .La matrice du systeme A devient: "<<endl;
     AfficheMatReelle(n, A);
     cout<<"2. Et le second membre b devient: "<<endl;
     AfficheTabReel(n, b);

     if(A[n][n]==0.0)
     {
          cout<<"La matrice est non inversible!"<<endl;
          exit(-1);
     }
     else
     {
          x[n]=b[n]/A[n][n];
          for(i=n-1; i>=1; i--)
          {
               som=0.0;
               for(j=i+1; j<=n; j++)
                    som+=A[i][j]*x[j];
               x[i]=(b[i]-som)/A[i][i];
          }
     }
     cout<<"Par la methode de Gauss, la solution du syteme est:"<<endl;
     for(i=1; i<=n; i++)
               cout<<"x"<<i<<" = "<<x[i]<<endl;

     det=1.0;
     for(i=1; i<=n; i++)
          det*=A[i][i];
     det*=pow(-1, NbrePermut);
     cout<<"Det(A)= "<<det<<endl;
}
