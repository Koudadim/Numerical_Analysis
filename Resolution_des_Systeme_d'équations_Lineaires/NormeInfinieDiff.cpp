#include <math.h>

double NormeInfinieDiff( double *x , double *y, int N)

{
	double max ;
	int i;
	max = fabs(x[1]-y[1]);
	for ( i=2;i<=N;i++)
	     if( fabs(x[i]-y[i])> max)
	       max =fabs(x[i]-y[i]);
	return max;
}
