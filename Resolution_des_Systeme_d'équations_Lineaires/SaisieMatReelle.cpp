#include<iostream>

using namespace std;

void SaisieMatReelle(double** M, int n)
{
	int i, j;
	for(i=1; i<=n; i++)
		for(j=1; j<=n; j++)
	 		cin>>M[i][j];
	 	
	cout<<"La matrice saisie: "<<endl;
	for(i=1; i<=n; i++)
		{
			for(j=1; j<=n; j++)
	 			cout<<M[i][j]<<"  ";
	 		cout<<endl;
		}
}
