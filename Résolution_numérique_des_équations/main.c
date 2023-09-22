#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choix, choice, Nmax, ON, YN;
    char C;
    double a, b, x, Eps;
    char R[]="Nn";
    char S[2];

    void Dichotomie(double a , double b, double eps , int itMax, double (*f)(double x));
    void PointFixe(double x, double eps, int itMax, double (*f)(double a));
    void Secante(double x, double extFix, double eps, int itMax, double(*f)(double a));
    void Newton(double x, double eps, int itMax, double(*f)(double a), double(*fnde)(double a));

    /*double (*pf)(double x);
    double (*pfprime)(double x);
    double (*pg)(double x);*/
    double f1(double x);
    double f1nde(double x);
    double f2(double x);
    double f2nde(double x);
    double f3(double x);
    double f3nde(double x);
    double f4(double x);
    double f4nde(double x);
    double g1(double x);
    double g2(double x);
    double g3(double x);
    double g4(double x);

    printf("Resolution de f(x)=0\n\n");
    printf("Ce programme resout plusieurs equations f(x)=0\n\n");
    do
    {
        printf("Appuyer sur Entree pour continuer\n");
        scanf("%c", &C);
    }while(C!=10);
    do{
        YN=0;
        printf("Choisissez une fonction parmi les fonctions suivantes:\n\n");
        printf("< 1 > f(x) = sin(x) /x [a, b] = [−4, −2] X0 = −3\n");
        printf("< 2 > f(x) = sqrt(x*x+1) - 2*x [a, b] = [0, 1] X0 = 0\n");
        printf("< 3 > f(x) = 4/(x*x+1) -10*cos(x) [a, b] = [1, 2] X0 = 2\n");
        printf("< 4 > f(x) = log(x*x+1)+x*x/2 -2 [a, b] = [0.5, 2] X0 = 2\n");
        scanf("%d", &choix);
        printf("Choix < 1 a 4 >? ....\n");

        if(choix>0 && choix<5)
            printf("Oui!!\n");
        else
            printf("Non!!\n");
        switch (choix)
        {
            case 1:
                a=-4; b=-2; x=-3; //pf=&f1; pfprime=&f1prime; pg=&g1;
                do{
                    ON=0;
                    printf("Vous avez choisi de resoudre l’equation f(x) = sin(x) /x  dans l'intervalle [a, b] = [%4.4f, %4.4f]\n", a, b);
                    printf("Choisissez la methode de resolution pour resoudre votre equation :\n");
                    printf("< 1 > Methode de Dichotomie\n");
                    printf("< 2 > Methode des approximations successives\n");
                    printf("< 3 > Methode de la secante\n");
                    printf("< 4 > Methode de Newton\n");
                    scanf("%d",&choice);
                    printf("Choix < 1 − 4 >? ....\n");

                    if(choice>0 && choice<5)
                        printf("Oui!!\n");
                    else
                        printf("Non!!\n");

                    switch(choice)
                    {
                        case 1:
                            printf("Entrez la precision Eps : ....."); scanf("%lf", &Eps);
                            printf("\nEntrez le nombre maximal d'iteration Nmax : ....."); scanf("%d", &Nmax);
                            Dichotomie(a , b, Eps , Nmax, &f1);
                            break;
                        case 2:
                            printf("Entrez la precision Eps : ....."); scanf("%lf", &Eps);
                            printf("\nEntrez le nombre maximal d'iteration Nmax : ....."); scanf("%d", &Nmax);
                            PointFixe(x, Eps, Nmax, &g1);
                            break;
                        case 3:
                            printf("La fonction f(x)=sin(x)/x est concave decroissante sur [%2.3f, %2.3f]\n",a, b);
                            printf("Entrez la precision Eps : ....."); scanf("%lf", &Eps);
                            printf("\nEntrez le nombre maximal d'iteration Nmax : ....."); scanf("%d", &Nmax);
                            Secante(a, b, Eps, Nmax, &f1);
                            break;
                        case 4:
                            x=-3;
                            printf("Entrez la precision Eps : ....."); scanf("%lf", &Eps);
                            printf("\nEntrez le nombre maximal d'iteration Nmax : ....."); scanf("%d", &Nmax);
                            Newton(x, Eps, Nmax, &f1, &f1nde);
                            break;
                        default:
                            printf("Option non disponible!\n");
                            break;
                }

                printf("Voulez-vous changer la methode ? < Oo, Nn >\n");
                printf("Repondez par Oo si Oui et par Nn si Non:");
                scanf("%s",&R);
                if(R=="Oo")
                    ON=1;
             }while(ON!=1);
                break;
            case 2:
                a=0; b=1; x=0;
                do{
                    ON=0;
                    printf("Vous avez choisi de resoudre l’equation f(x) = 4/(x*x+1)-10*cos(x)=0;  dans l'intervalle [a, b] = [%4.4f, %4.4f]\n", a, b);
                    printf("Choisissez la methode de resolution pour resoudre votre equation :\n");
                    printf("< 1 > Methode de Dichotomie\n");
                    printf("< 2 > Methode des approximations successives\n");
                    printf("< 3 > Methode de la secante\n");
                    printf("< 4 > Methode de Newton\n");
                    scanf("%d",&choice);
                        printf("Choix < 1 − 4 >? ....\n");
                    if(choice>0 && choice<5)
                        printf("Oui!!\n");
                    else
                        printf("Non!!\n");

                    switch(choice)
                    {
                        case 1:
                            printf("Entrez la precision Eps : ....."); scanf("%lf", &Eps);
                            printf("\nEntrez le nombre maximal d'iteration Nmax : ....."); scanf("%d", &Nmax);
                            Dichotomie(a , b, Eps , Nmax, &f2);
                            break;
                        case 2:
                            printf("Entrez la precision Eps : ....."); scanf("%lf", &Eps);
                            printf("\nEntrez le nombre maximal d'iteration Nmax : ....."); scanf("%d", &Nmax);
                            PointFixe(x, Eps, Nmax, &g2);
                            break;
                        case 3:
                            printf("La fonction f(x)=sqrt(x*x+1)-2*x est convexe decroissante sur [%2.3f, %2.3f]\n",a, b);
                            printf("Entrez la precision Eps : ....."); scanf("%lf", &Eps);
                            printf("\nEntrez le nombre maximal d'iteration Nmax : ....."); scanf("%d", &Nmax);
                            Secante(b, a, Eps, Nmax, &f2);
                            break;
                        case 4:
                            x=0;
                            printf("Entrez la precision Eps : ....."); scanf("%lf", &Eps);
                            printf("\nEntrez le nombre maximal d'iteration Nmax : ....."); scanf("%d", &Nmax);
                            Newton(x, Eps, Nmax, &f2, &f2nde);
                            break;
                        default:
                            printf("Option non disponible!\n");
                            break;
                    }
                    printf("Voulez-vous changer la methode ? < Oo, Nn >\n");
                    printf("Repondez par Oo si Oui et par Nn si Non:");
                    scanf("%s",&R);
                    if(R=="Oo")
                        ON=1;
                 }while(ON!=1);
                    break;
                case 3:
                    a=1; b=2; x=2;
                    do{
                        ON=0;
                        printf("Vous avez choisi de resoudre l’equation f(x) =  4/(x*x+1)-10*cos(x)=0 dans l'intervalle [a, b] = [%4.4f, %4.4f]\n", a, b);
                        printf("Choisissez la methode de resolution pour resoudre votre equation :\n");
                        printf("< 1 > Methode de Dichotomie\n");
                        printf("< 2 > Methode des approximations successives\n");
                        printf("< 3 > Methode de la secante\n");
                        printf("< 4 > Methode de Newton\n");
                        scanf("%d",&choice);
                            printf("Choix < 1 a 4 >? ....\n");
                        if(choice>0 && choice<5)
                            printf("Oui!!\n");
                        else
                            printf("Non!!\n");

                        switch(choice)
                        {
                            case 1:
                                printf("Entrez la precision Eps : ....."); scanf("%lf", &Eps);
                                printf("\nEntrez le nombre maximal d'iteration Nmax : ....."); scanf("%d", &Nmax);
                                Dichotomie(a , b, Eps , Nmax, &f3);
                                break;
                            case 2:
                                printf("Entrez la precision Eps : ....."); scanf("%lf", &Eps);
                                printf("\nEntrez le nombre maximal d'iteration Nmax : ....."); scanf("%d", &Nmax);
                                PointFixe(x, Eps, Nmax, &g3);
                                break;
                            case 3:
                                printf("La fonction f(x)=  4/(x*x+1)-10*cos(x)  est convexe croissante sur [%2.3f, %2.3f]\n",a, b);
                                printf("Entrez la precision Eps : ....."); scanf("%lf", &Eps);
                                printf("\nEntrez le nombre maximal d'iteration Nmax : ....."); scanf("%d", &Nmax);
                                Secante(a, b, Eps, Nmax, &f3);
                                break;
                            case 4:
                                printf("Entrez la precision Eps : ....."); scanf("%lf", &Eps);
                                printf("\nEntrez le nombre maximal d'iteration Nmax : ....."); scanf("%d", &Nmax);
                                Newton(x, Eps, Nmax, &f3, &f3nde);
                                break;
                            default:
                                printf("Option non disponible!\n");
                                break;
                        }
                        printf("Voulez-vous changer la methode ? < Oo, Nn >\n");
                        printf("Repondez par Oo si Oui et par Nn si Non:");
                        scanf("%s",&R);
                        if(R=="Oo")
                            ON=1;
                  }while(ON!=1);
                    break;
                case 4:
                    a=0.5; b=2; x=2;
                    do{
                        ON=0;
                        printf("Vous avez choisi de resoudre l’equation f(x) =  log(x*x+1)+x*x/2-2=0 dans l'intervalle [a, b] = [%4.4f, %4.4f]\n", a, b);
                        printf("Choisissez la methode de resolution pour resoudre votre equation :\n");
                        printf("< 1 > Methode de Dichotomie\n");
                        printf("< 2 > Methode des approximations successives\n");
                        printf("< 3 > Methode de la secante\n");
                        printf("< 4 > Methode de Newton\n");
                        scanf("%d",&choice);
                        printf("Choix < 1 a 4 >? ....\n");
                        if(choice>0 && choice<5)
                            printf("Oui!!\n");
                        else
                            printf("Non!!\n");

                        switch(choice)
                        {
                            case 1:
                                printf("Entrez la precision Eps : ....."); scanf("%lf", &Eps);
                                printf("\nEntrez le nombre maximal d'iteration Nmax : ....."); scanf("%d", &Nmax);
                                Dichotomie(a , b, Eps , Nmax, &f4);
                                break;
                            case 2:
                                printf("Entrez la precision Eps : ....."); scanf("%lf", &Eps);
                                printf("\nEntrez le nombre maximal d'iteration Nmax : ....."); scanf("%d", &Nmax);
                                PointFixe(x, Eps, Nmax, &g4);
                                break;
                            case 3:
                                printf("La fonction f(x)=  log(x*x+1)+x*x/2 -2  est concave decroissante sur [%2.3f, %2.3f]\n",a, b);
                                printf("Entrez la precision Eps : ....."); scanf("%lf", &Eps);
                                printf("\nEntrez le nombre maximal d'iteration Nmax : ....."); scanf("%d", &Nmax);
                                Secante(a, b, Eps, Nmax, &f4);
                                break;
                            case 4:
                                printf("Entrez la precision Eps : ....."); scanf("%lf", &Eps);
                                printf("\nEntrez le nombre maximal d'iteration Nmax : ....."); scanf("%d", &Nmax);
                                Newton(x, Eps, Nmax, &f4, &f4nde);
                                break;
                            default:
                                printf("Option non disponible!\n");
                                break;
                        }
                        printf("Voulez-vous changer la methode ? < Oo, Nn >\n");
                        printf("Repondez par Oo si Oui et par Nn si Non:");
                        scanf("%s",&R);
                        if(R=="Oo")
                            ON=1;
                    }while(ON!=1);
                    break;
                default:
                    do{
                        ON=0;
                        printf("Option Non disponible!!!\n");
                        printf("Voulez-vous changer la methode ? < Oo, Nn >\n");
                        printf("Repondez par Oo si Oui et par Nn si Non:");
                        scanf("%s",&R);
                        if(R=="Oo")
                            ON=1;
                    }while(ON!=1);
                    break;
            }
            printf("Voulez-vous changer d’equation ?< Oo, Nn >\n");
            printf("Repondez par Oo si Oui et par Nn si Non:");
            scanf("%s", &S);
            if (S=="Oo")
                YN=1;
      }while(YN!=1);

    return 0;
}
