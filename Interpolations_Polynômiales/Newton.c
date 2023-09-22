#include<stdio.h>
#include<stdlib.h>
double Newton(double* x,double *y,int N, double alpha)
{
	double **MatriceCarreeDouble(int N);
	int i,j;
	double som, prod;
	double **M;
	M=MatriceCarreeDouble(N);
	for (i=1; i<=N;i++)
		M[i][1]=y[i];
	for (j=2; j<=N;j++)
		for(i=j;i<=N;i++)
			M[i][j]=(M[i][j-1]-M[i-1][j-1])/(x[i]-x[i-j+1]);

	som=M[1][1];
	prod=1;
	for(i=1;i<N;i++)
	{
		prod*=(alpha-x[i]);
		som+=prod*M[i+1][i+1];
	}
	return som;
}
