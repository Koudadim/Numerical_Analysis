#include<iostream>

using namespace std;

void Permutation(int n, int k, double*T1, double* T2) // k désigne la colonne courante du pivot
{
	int i;
	double p;
     for(i=k; i<=n; i++)
	 	{
	 		p=T1[i];
	 		T1[i]=T2[i];
	 		T2[i]=p;
		}
}
