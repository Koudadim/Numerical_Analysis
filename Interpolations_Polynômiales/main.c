#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Interpolation polynomiale\n");
    printf("\n");
    printf("Ce programme calcule la valeur du polynome d'interpolation (relativement a\n");
    printf("\t N+1 points) de degre N en un point x donne, en utilisant l'un des trois\n");
    printf("\talgorithmes suivants: polynomes d'interpolation de lagrange, polynome\n");
    printf("\t\td'interpolation de Newton et l'algoritme d'Aitken\n\n");

    char C1, C2, C3, E='e';
    int N, i, j, k1, k2, i0, ch, choix;
    double x1, h, A, B, Val, valeur;
    double* X;
    double* Y;
    double* TabReel(int n);
    double* TabDouble(int N);
    void AfficheTabReel(double* T, int n);
    void AbscisseCalcule(double* x, double x1, double h, int n);
    void OrdonneeCalcule(double* x, double* y,int n, int k);
    double CalculValPolynome(double* X, double* Y, double Val, int N, int choix);

    do{
        printf("Appuyez sur <Entree> pour continuer\n");
        scanf("%c",&E);
    }while(E!=10);
    printf("\n");
    printf("Entrez le degre du polynome\n");
    scanf("%d", &N);
    printf("Le degre du polynome est : %d\n", N);
    printf("\n");
    do{
        printf("Vous pouvez choisir comment entrer les abscisses\n");
        printf("<1> Toutes les valeurs des abcisses seront saisies par l'utilisateur\n");
        printf("<2> Les abscisses seront construits a partir du premier point et un pas h\n");
        printf("\t(xi=x1+(i-1)h pour i=1, ..., N+1)\n");
        printf("<3> Les points sont equidistants dans un intervalle [A, B]\n");
        printf("\t(xi=x1+(i-1)h pour i=1, ..., N+1) abec h=[B-A]/N)\n");
        printf("\n");
        printf("Choix <1-3> ?...\n");
        scanf("%d", &choix);

        if(choix==1)
        {
            printf("Entrez les N+1 abscisses\n");
            X=TabReel(N);
            printf("\t\tLes abscisses que vous avez saisis sont:\n");
            AfficheTabReel(X, N+1);
        }
        else if(choix==2)
        {
            printf("Vous avez choisi de construire xi=x1+(i-1)h pour i=1, ..., N+1\n");
            printf("Entrez X1= ... ");
            scanf("%lf", &x1);
            printf("Entrez h= ... ");
            scanf("%lf", &h);
            X=TabDouble(N+1);
            AbscisseCalcule(X, x1, h, N+1);
        }
        else{
            printf("Vous avez choisi de construire des points des points équidistants sur un intervalle [A, B]\n");
            printf("(xi=x1+(i-1)h pour i=1, ..., N+1) abec h=[B-A]/N)\n");
            printf("Entrez la borne gauche de l'intervalle A= ...");
            scanf("%lf",&A);
            printf("la borne gauche de l'intervalle A= %12.14f\n",A);
            printf("Entrez la borne droite de l'intervalle B= ...");
            scanf("%lf",&B);
            printf("la borne droite de l'intervalle B= %12.14f\n",B);
            printf("\n");
            h=(B-A)/N;
            X=TabDouble(N+1);
            AbscisseCalcule(X, A, h, N+1);
        }
        printf("\n\n");
        printf("Vous pouvez choisir comment entrer les ordonnees\n");
        printf("<1> Toutes les valeurs des ordonnees seront saisaies par l'utilisateur\n");
        printf("<2> Utiliser une fonction pour calculer Yi=F(Xi)\n");
        printf("Choix<1-2>... ");
        scanf("%d", &choix);
        printf("\n");
        Y=TabDouble(N+1);
        if(choix==1)
        {
            for(i=1; i<=N+1; i++)
            {
                printf("X%d = %12.14f\n", i, X[i]);
                printf("Entrer Y%d = ", i);
                scanf("%lf", Y+i);
            }
        }
        else{
            printf("Choisissez une fonction parmi les fonctions suivantes:\n");
            printf("F(X)= sin(X) + X\n");
            printf("F(X)= sin(X) / (2+cosX)\n");
            printf("F(X)= X+EXP(-X)\n");
            printf("F(X)= 1 / cos(X)\n");
            printf("F(X)= LOG(1+X*X)\n");
            printf("Choix<1-5>= ");
            scanf("%d", &ch);
            getchar();
            OrdonneeCalcule(X, Y, N+1, ch);
        }
        printf("\n");
        printf("Les points d'interpolations sont:\n");
        for(i=1; i<=N+1; i++)
            {
                printf("X%d = %12.14f \t\t", i, X[i]);
                printf("Y%d = %12.14f\n", i, Y[i]);
            }

        for(i=1; i<N+1; i++)
            for(j=i+1; j<=N+1; j++)
                if(X[i]==X[j])
                {
                    k1=i;
                    k2=j;
                    printf("Les abscisses ne sont pas distincts, vous devez changer un.\n");
                    printf("Pour changer un point, choisir i= %d ou %d\n",k1, k2);
                    printf("Entrer i = "); scanf("%d", &i0);
                    printf("Les cordonnees du point courant sont: X%d=%12.14f et Y%d=%12.14f\n",i0, X[i0], i0, Y[i0]);
                    printf("Nouveau X%d = ",i0); scanf("%lf",&X[i0]);
                    printf("Nouveau Y%d = ",i0); scanf("%lf",&Y[i0]);
                    exit(-1);
                }
            printf("\n");
        do{
             printf("Choisissez un algorithme:\n");
             printf("Polynome d'interpolation de Lagrange\n");
             printf("Polynome d'interpolation de Newton\n");
             printf("Polynome d'Aitken\n");
             printf("Choix <1-3>... ");
             scanf("%d",&choix);
             printf("\n");
             do{
                 printf("Entrez un reel Val = ");
                 scanf("%lf", &Val);
                 getchar();
                 valeur=CalculValPolynome(X, Y, Val, N, choix);
                 printf("La valeur du polynome d'interpolation en %12.14f est %12.14f\n", Val, valeur);
                 printf("Voulez-vous changer la valeur du reel? <Y/N> ...");
                 scanf("%c",&C1);
                 getchar();
             }while(C1=='Y');
            printf("\n");
            printf("Voulez-vous changer d'algorithme? <Y/N> ...");
            scanf("%c",&C2);
            getchar();
        }while(C2=='Y');
        printf("\n");
        printf("Voulez-vous changer les points d'interpolations? <Y/N> ...");
        scanf("%c",&C3);
    }while(C3=='Y');
    return 0;
}
