#include <stdio.h>
#include <math.h>

double fonctions(double x, int k)
{
    if(k==1)
        return sin(x)+x;
    else if(k==2)
        return sin(x)/(2+cos(x));
    else if(k==3)
        return x+exp(-x);
    else if(k==4)
        return 1/cos(x);
    else return log(1+x*x);
}
