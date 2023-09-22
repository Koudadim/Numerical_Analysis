#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void Newton(double x, double eps, int itMax, double(*f)(double a), double(*fnde)(double a))
{
    double y;
    int it;
    y=x-(*f)(x)/(*fnde)(x);
    it=1;
    while(fabs(y-x)>eps && it<=itMax)
    {
        x=y;
        y=x-((*f)(x))/((*fnde)(x));
        it++;
    }
    if(fabs(y-x)<=eps)
        printf("Solution: %6.6f \n Nombre d'iterations: %d", y, it);
    else
        printf("Precision %1.0e non atteinte apres %d iterations.\n", eps, itMax);
}

