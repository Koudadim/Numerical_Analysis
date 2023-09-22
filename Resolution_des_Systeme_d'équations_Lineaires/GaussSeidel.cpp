#include<iostream>

using namespace std;

void GaussSeidel(int n, double* b, double* x, double** A)

{
     int i,j,it, ItMax;
	double eps, som, erreur;
     double* x0;
     double* x1;
     double* TabReel(int n);
     void AfficheTabReel(int n, double* T);
     double NormeInfinieDiff( double *x , double *y, int N);
     x0=TabReel(n);
     x1=TabReel(n);

     cout<<"Methode de GaussSeidel"<<endl;
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

    erreur=10000;
	it=0;
	while (erreur > eps && it <= ItMax)
	      {
	           for ( i  = 1 ; i <= n ; i++)
	            {
		        	som = 0;
		        	for (j=1;j<=i-1;j++)
		        	    som += A[i][j]*x1[j];
                    for (j=i+1;j<=n;j++)
		        	    som += A[i][j]*x0[j];
		        	 x1[i]=( b[i]-som)/A[i][i];
                 }
	        	erreur=NormeInfinieDiff(x0, x1, n);
	        	it++;
	        	for ( i  = 1 ; i <= n ; i++)
	               x0[i] =x1[i];
		  }
        if(erreur <= eps)
	      {
	      	cout<<"La methode de Gauss Seidel converge apres "<< it<<"  iterations"<<endl;
	      	cout<<"La solution est :"<<endl;
		    for(i=1; i<=n; i++)
               cout<<"x"<<i<<" = "<<x1[i]<<endl;
		  }
          else
               cout<<"Precision non atteinte!!!"<<endl;
}
