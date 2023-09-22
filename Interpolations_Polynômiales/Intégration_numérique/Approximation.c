#include<stdio.h>

void Approximation(int choix1, int choix2, int N, double A, double B, double* x) // Pour calculer la valeur approchée de l'integrale
{
    double ValApp;
    double Trapeze(int N, double A, double B, double* x, double(*f)(double x));
    double Simpson(int N, double A, double B, double* x, double(*f)(double x));
    double(*Formules[2])(int N, double A, double B, double* x, double(*f)(double x))={Trapeze, Simpson}; // Un tableau des méthodes d'integrations
    //double (*MethodeChoisie)(int N, double A, double B, double* x, double(*f)(double x));

    double F1(double x);
    double F2(double x);
    double F3(double x);
    double F4(double x);
    double F5(double x);
    double F6(double x);
    double F7(double x);
    double F8(double x);
    double(*Fonctions[8])(double x)={F1, F2, F3, F4, F5, F6, F7, F8};
    double(*F)(double x);
    F=Fonctions[choix2-1];
    char TabCarac[8][10]={{"SIN(X)/X"}, {" 1/X "}, {"SIN(X)"}, {"4/(1+X*X)"}, {"X/(1+X*X)"}, {"1/(7-2*X)"}, {"LOG(|X|)"}, {"X*EXP(-X)"}};
    if(choix1==1 || choix1==2)
        {
            //MethodeChoisie=Formules[choix1-1];
            if(choix1==1)
            {
                printf("La formule des trapezes est utilisiee pour approximer l'integrale definie par ");
                printf("F(X)= %s sur l'intervalle [%12.4f, %12.4f] en subdivisant cet intervalle en %d ", TabCarac[choix2-1], A, B, N);
                printf("intervalles egaux.\n");
                ValApp=(Formules[0])(N, A, B, x, F);
                printf("La valeur approchee de l'integrale est = %12.8f", ValApp);
            }
            else
            {
                printf("La formule de Simpson est utilisiee pour approximer l'integrale definie par ");
                printf("F(X)= %s sur l'intervalle [%12.4f, %12.4f] en subdivisant cet intervalle en %d ", TabCarac[choix2-1], A, B, N);
                printf("intervalles egaux.\n");
                ValApp=(Formules[1])(N, A, B, x, F);
                printf("La valeur approchee de l'integrale est = %12.8f", ValApp);
            }

        }
        else
        {
            printf("Les formules de Simpson sont utilisiees pour approximer l'integrale definie par ");
            printf("F(X)= %s sur l'intervalle [%12.4f, %12.4f] en subdivisant cet intervalle en %d ", TabCarac[choix2-1], A, B, N);
            printf("intervalles egaux.\n");
            ValApp=(Formules[0])(N, A, B, x, F);
            printf("La formule des trapezes donne %12.8f\n", ValApp);
            ValApp=(Formules[1])(N, A, B, x, F);
            printf("Et la formule de Simpson donne %12.8f\n", ValApp);
        }
}
