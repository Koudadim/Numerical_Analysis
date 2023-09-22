#include<iostream>

using namespace std;

void SOR(int n, double* b, double* x, double** A)
{
     int i, j, NbreIt, ItMax;
     double eps, omega, som, erreur;
     double* x0;
     double* x1;
     double* TabReel(int n);
     double NormeInfinieDiff( double *x , double *y, int N);
     void AfficheTabReel(int n, double* T);
     x0=TabReel(n);
     x1=TabReel(n);
     erreur=10000000;
     NbreIt=0;

     cout<<"Methode SOR"<<endl;
     cout<<"Entrer une valeur initiale x0 approchant la solution du systeme"<<endl;
     for(i=1; i<=n; i++)
          cin>>x0[i];
     AfficheTabReel(n, x0);
     cout<<"A quelle erreur pres souhaitez-vous resoudre le systeme?"<<endl;
     cout<<"Epsilon = ";
     cin>>eps;
     cout<<"Entrez un nombre maximal d'iterations"<<endl;
     cout<<"ItMax= ";
     cin>>ItMax;
     cout<<"Entrer le parametre de relaxation Omega"<<endl;
     cout<<"Omega = ";
     cin>>omega;

     while(erreur>eps && NbreIt<=ItMax)
     {
          for(i=1; i<=n; i++)
          {
               som=0.0;
               for(j=1; j<=i-1; j++)
                    som+=A[i][j]*x1[j];
               for(j=i+1; j<=n; j++)
                    som+=A[i][j]*x0[j];
               x1[i]=(1-omega)*x0[i]+omega*((b[i]-som)/A[i][i]);
          }
          erreur=NormeInfinieDiff(x0, x1, n);
          for(i=1; i<=n; i++)
               x0[i]=x1[i];
          NbreIt++;
     }
     if(erreur <= eps)
     {
          cout<<"La methode SOR converge apres "<<NbreIt<<" iterations :"<<endl;
          cout<<"La solution est :"<<endl;
          for(i=1; i<=n; i++)
               cout<<"x"<<i<<" = "<<x1[i]<<endl;
     }
     else
          cout<<"Precision non atteite"<<endl;
}
