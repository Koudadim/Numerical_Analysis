#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void PointFixe(double x, double eps, int itMax, double (*f)(double a))
{
    double y;
    int it;
    y=(*f)(x);
    it=1;
    while(fabs(y-x)>eps && it<=itMax)
    {
        x=y;
        y=(*f)(x);
        it++;
    }
    if(fabs(y-x)<=eps)
        printf("Solution: %6.6f \n Nombre d'iterations: %d\n", y, it);
    else
        printf("Precision %1.0e non atteinte apres %d iterations\n", eps, itMax);
}
