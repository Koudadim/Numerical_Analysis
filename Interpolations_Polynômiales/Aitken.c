#include<stdio.h>
#include<stdlib.h>
double Aitken(double* x,double* y, int N, double alpha)
{
	int i,j;
	double **MatriceCarreeDouble(int N);
	double **M;
	double num,dem;
	M=MatriceCarreeDouble(N+1);
	for(i=1;i<=N+1;i++)
		M[i][1]=y[i];
	for(j=2;j<=N+1;j++)
		for(i=j;i<=N+1;i++)
		{
			num=(x[i]-alpha)*M[j-1][j-1]-(x[j-1]-alpha)*M[i][j-1];
			dem=x[i]-x[j-1];
			M[i][j]=num/dem;
		}
	return M[N+1][N+1];

}
