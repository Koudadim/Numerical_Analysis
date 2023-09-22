#include<iostream>

using namespace std;

double** MatReelle(int n)
{
	int i, j;
	double* TabReel(int n);
	double** M;
	M=new double*[n];
	if(M==NULL)
		{
			cout<<"Espace insuffisant!"<<endl;
			exit(-1);
		}
	else
		M--;
		for(i=1; i<=n; i++)
			M[i]=TabReel(n);
	return M;
}
