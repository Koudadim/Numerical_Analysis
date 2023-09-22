#include<iostream>
#include<math.h>

using namespace std;

void GaussPivotTotal(int n, double* b, double* x, double** A)
{
      int k, i, j, m, imax, jmax, Np;
     double coefmax, coef, pivot, som, det;
     int* I;
     int* TabEntier(int n);
     double* TabReel(int n);
     void AfficheTabReel(int n, double* T);
     void AfficheMatReelle(int n, double** M);
     // Commençons par créer un tableau contenant les indices du vecteurs x
     I=TabEntier(n);
     for(i=1; i<=n; i++)
          I[i]=i;
     Np=0;
     cout<<endl<<endl;
     cout<<"Etape N° 0 "<<endl;
     cout<<"Matrice A du syteme. "<<endl;
     AfficheMatReelle(n, A);
     cout<<"Second membre "<<endl;
     AfficheTabReel(n, b);

     for(k=1; k<=n-1; k++)
     {
          cout<<endl<<endl;
          cout<<"Etape N° "<<k<<endl;
          coefmax=fabs(A[k][k]);
          imax=k;
          jmax=k;
          for(i=k; i<=n; i++ )
               {
                    for(j=k; j<=n; j++)
                    {
                         coef=fabs(A[i][j]);
                         if(coefmax<coef)
                         {
                              coefmax=coef;
                              imax=i;
                              jmax=j;
                         }
                    }
               }
          if(imax!=k)  // si le grand element en valeur est autre que akk;
          {
                 Np++;
               cout<<endl<<endl;
               cout<<"Le plus grand coefficient en dessous de la ligne "<<k-1<<"  se trouve sur la ligne "<<imax<<endl;
               for(j=k; j<=n; j++)
                    {
                         coef=A[imax][j];
                         A[imax][j]=A[k][j];
                         A[k][j]=coef;
                    }
               coef=b[k];
               b[k]=b[imax];
               b[imax]=coef;
          }
          if(jmax!=k)//Permtution des elements des colonnes k et q situés en dessous de la ligne k-1;
          {
                 Np++;
               cout<<"Le plus grand coefficient en dessous de la ligne "<<k-1<<"  se trouve sur la colonne "<<jmax<<endl;
               for(i=k; i<=n; i++)
                    {
                         coef=A[i][k];
                         A[i][k]=A[i][jmax];
                         A[i][jmax]=coef;
                    }
                         // Permutation des inconnues xk et xq;
               m=I[k];
               I[k]=I[jmax];
               I[jmax]=m;
          }
               pivot=A[k][k];
               cout<<"Apres permutation des lignes "<<k<<" et "<<imax<<" puis des colonnes "<<k<<" et "<<jmax<<endl;
               cout<<"Matrice "<<endl;
               AfficheMatReelle(n, A);
               cout<<"Second membre "<<endl;
               AfficheTabReel(n, b);
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
          cout<<endl<<endl;
          cout<<"Matrice "<<endl;
          AfficheMatReelle(n, A);
          cout<<"Second membre "<<endl;
          AfficheTabReel(n, b);
     }
     cout<<endl<<endl;
     cout<<"Tableau des indices des elements de x"<<endl;
     for(i=1; i<=n; i++)
          cout<<i<<"     ";
     cout<<endl;
     for(i=1; i<=n; i++)
          cout<<I[i]<<"     ";
     cout<<endl;
     if(A[n][n]==0.0)
          {
               cout<<"Le systeme n'admet pas de solution! "<<endl;
               exit(-1);
          }
     else
          {
               m=I[n];
               x[m]=b[n]/A[n][n];
               for(i=n-1; i>=1; i--)
               {
                     som=0.0;
                    for(j=i+1; j<=n; j++)
                    {
                         k=I[j];
                         som+=A[i][j]*x[k];
                    }
                    m=I[i];
                    x[m]=(b[i]-som)/A[i][i];
               }
               cout<<"La solution du systeme par la methode de Gauss pivot total est:"<<endl;
               for(i=1; i<=n; i++)
                    cout<<"x"<<i<<" = "<<x[i]<<endl;
          }
           det=1;
          for(i=1; i<=n; i++)
               det*=A[i][i];
          det*=pow(-1, Np);
          cout<<"Le determinant de la matrice A du syteme est: det(A) = "<<det<<endl;
}
