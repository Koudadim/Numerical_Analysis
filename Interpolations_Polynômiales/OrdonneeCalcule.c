#include <stdio.h>
#include <stdlib.h>
void OrdonneeCalcule(double* x, double* y, int n, int k)
{
    int i;int l=k;
    double F1(double x);
    double F2(double x);
    double F3(double x);
    double F4(double x);
    double F5(double x);
    double(*fonctions[5])(double)={F1, F2, F3, F4, F5};
    double(*f)(double);
    f=fonctions[l-1];
    for(i=1;i<=n+1;i++)
        y[i]=f(x[i]);

    /*switch(k)
        {
        case 1:
            for(i=1;i<=n+1;i++)
                y[i]=F1(x[i]);
            break;
        case 2:
            for(i=1;i<=n+1;i++)
                y[i]=F2(x[i]);
            break;
        case 3:
            for(i=1;i<=n+1;i++)
                y[i]=F3(x[i]);
            break;
        case 4:
            for(i=1;i<=n+1;i++)
                y[i]=F4(x[i]);
            break;
        case 5:
            for(i=1;i<=n+1;i++)
                y[i]=F5(x[i]);
            break;
        default:
            printf("Fonction non disponible!!!\n");
            break;
        }*/
}
