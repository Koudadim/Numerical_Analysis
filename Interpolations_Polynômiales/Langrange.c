#include<stdio.h>
double Lagrange(double*x,double*y,int N,double alpha)
{

	int j,i;
	double som,prod;
	som=0;
	for(i=1;i<=N+1;i++)
	{
		prod=1;

		for(j=1;j<=i-1;j++)
		prod*=(alpha-x[j])/(x[i]-x[j]);

		for(j=i+1;j<=N+1;j++)
		prod*=(alpha-x[j])/(x[i]-x[j]);
		som+=prod*y[i];

	}
	return som;
}


