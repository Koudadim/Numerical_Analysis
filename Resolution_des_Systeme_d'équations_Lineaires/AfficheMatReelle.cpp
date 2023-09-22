#include<iostream>

using namespace std;

void AfficheMatReelle(int n, double** M)
{
    int i, j;
    for(i=1; i<=n; i++)
		{
			for(j=1; j<=n; j++)
	 			cout<<M[i][j]<<"  ";
	 		cout<<endl;
		}
}
