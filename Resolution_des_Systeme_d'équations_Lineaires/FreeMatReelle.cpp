#include<iostream>

void FreeMatReelle(double** M, int n)
{
	int i;
	void FreeTabReel(double* T);
	for(i=1; i<=n; i++)
		FreeTabReel(M[i]);
}
