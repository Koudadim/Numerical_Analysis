#include<iostream>
#include<math.h>

using namespace std;

void GaussPivotPartiel(int n, double* b, double* x, double** A)
{
     int k, i, j, m, imax, Np;
     double coefmax, coef, pivot, som, det;
     void AfficheTabReel(int n, double* T);
     void AfficheMatReelle(int n, double** M);
     Np=0;
     cout<<" Resolution par la methode de Gauss Pivot partiel"<<endl;
     for(k=1; k<=n-1; k++)
     {
          cout<<endl<<endl;
          cout<<"Etape N° "<<k-1<<endl<<endl;
          cout<<"Matrice "<<endl;
          AfficheMatReelle(n, A);
          cout<<"Second membre "<<endl;
          AfficheTabReel(n, b);
          coefmax=fabs(A[k][k]);
          imax=k;
          for(m=k+1; m<=n; m++)      // On cherche l'element maximal dans la colonne en partant de la ligne k;
          {
               coef=fabs(A[m][k]);
               if(coefmax<coef)
               {
                    coefmax=coef;
                    imax=m;
               }
          }
          cout<<endl<<endl;
          cout<<"La ligne "<<imax<<" contient le plus grand coefficient en valeur absolue dans la colonne "<<k<<endl;
          // Une fois le coefficient amximal trouvé, on permute les lignes m et k
          for(j=k; j<=n; j++)
          {
               coef=A[imax][j];
               A[imax][j]=A[k][j];
               A[k][j]=coef;
               Np++;
          }
          coef=b[k];
          b[k]=b[imax];
          b[imax]=coef;
          cout<<"Apres permutation des lignes "<<imax<<" et "<<k<<" la matrice devient : "<<endl;
          AfficheMatReelle(n, A);
          pivot=A[k][k];
          if(pivot==0.0)
          {
               cout<<"Le systeme n'admet aucune solution!!"<<endl;
               exit(-1);
          }
          else
          {
               for(i=k+1; i<=n; i++)
                    {
                         coef=(A[i][k]/pivot);
                         for(j=k+1; j<=n; j++)
                              A[i][j]-=coef*A[k][j];
                         for(j=1; j<=k; j++)
                              A[i][j]=0.0;
                         b[i]-=coef*b[k];
                    }
          }
     }
     cout<<endl<<endl;
     cout<<"Etape "<<k<<endl;
     cout<<"Matrice "<<endl;
     AfficheMatReelle(n, A);
     cout<<"Second membre "<<endl;
     AfficheTabReel(n, b);
     cout<<endl<<endl;
     if(A[n][n]==0.0)
     {
          cout<<"Le systeme n'admet pas de solution! "<<endl;
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
          cout<<"La solution du systeme par la methode de Gauss pivot partiel est:"<<endl;
          for(i=1; i<=n; i++)
               cout<<"x"<<i<<" = "<<x[i]<<endl;
     }
          det=1;
          for(i=1; i<=n; i++)
               det*=A[i][i];
          det*=pow(-1, Np);
          cout<<"Le determinant de la matrice A du syteme est: det(A) = "<<det<<endl;
}
