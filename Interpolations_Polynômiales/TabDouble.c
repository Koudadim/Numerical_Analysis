#include<stdio.h>
#include<stdlib.h>

double* TabDouble(int N)
{
	double*T;
	T=(double*)malloc(N*sizeof(double));
	if(T==NULL)
	{
		printf("TabDouble:pas assez de memoire \n");
		exit(-1);
	}
	return T-1;
}

