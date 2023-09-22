#include<iostream>

using namespace std;

void SaisieTabReel(double* T, int n)
{
	int i;
	for(i=1; i<=n; i++)
	 	cin>>T[i];
	cout<<"Vecteur saisi: ( ";
	for(i=1; i<=n; i++)
	 	cout<<T[i]<<" ";
	cout<<" )"<<endl;
}
