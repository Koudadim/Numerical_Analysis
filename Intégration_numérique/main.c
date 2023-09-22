#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choix1, choix2, N;
    double A,B;
    char R;
    double* x;
    double* CreerTabReel(int n);
    void TabReel(double a, double b, int N, double* x);
    void Approximation(int choix1, int choix2, int N, double A, double B, double* x);
    printf("\t\t\t\t Integration numerique\n\n");
    printf("\tCe programme calcule une valeur approchee d'une integrale definie en utilisant \n soit la formule de trapeze, soit la formule de Simpson, soit les deux formules.");
    printf("\n\n\n");
    printf("\t\t\t Appuyez sur <Entree> pour continuer\n");
    getchar();
    printf("\n\n\n");
    do{
        printf("\t\t Choisissez la formule d'interpolation numerique.\n\n");
        printf("<1> Formule des trapezes\n");
        printf("<2> Formule de Simpson\n");
        printf("<3> Les deux formules (Trapezes et Simpson\n");
        printf("Choix <1 - 3>? ... "); scanf("%d", &choix1);
        if(choix1==1)
            printf("La formule des Trapezes est choisie pour approximer \n l'integrale d'une fonction sur un intervalle [A, B]\n");
        else if(choix1==2)
            printf("La formule de Simpson est choisie pour approximer \n l'integrale d'une fonction sur un intervalle [A, B]\n");
        else
            printf("Les formules des Trapezes et de Simpson sont choisies pour approximer \n l'integrale d'une fonction sur un intervalle [A, B]\n");
        printf("\n");
        do{
            printf("Choisissez une fonction parmi les fonctions suivantes:\n");
            printf("<1> F(X)=SIN(X)/X\n");
            printf("<2> F(X)=1/X\n");
            printf("<3> F(X)=SIN(X)\n");
            printf("<4> F(X)=4/(1+X*X)\n");
            printf("<5> F(X)=X/(1+X*X)\n");
            printf("<6> F(X)=1/(7-2*X)\n");
            printf("<7> F(X)=LOG(|X|)\n");
            printf("<8> F(X)=XEXP(-X)\n");
            printf("Choix <1 - 8>? ... ");
            scanf("%d", &choix2);
            do{
                printf("Entrez la borne gauche de l'intervalle A = ");
                scanf("%lf", &A);
                printf("La borne gauche de l'intervalle est A = %lf\n",A);
                printf("Entrez la borne droite de l'intervalle B = ");
                scanf("%lf", &B);
                printf("La borne droite de l'intervalle est B = %lf\n",B);
                printf("Entrez le nombre de subivisions N = ");
                scanf("%d", &N);
                getchar();
                printf("Le nombre de subdivisions est N = %d\n",N);
                if(choix1==2)
                    if(N%2!=0)
                       do{
                             printf("N doit etre pair!!!");
                             printf("Le nombre courant de subdivisions est N= %d\n", N);
                             printf("Entrez le nouveau nombre de subbdivisions N =");
                             scanf("%d", &N);
                             printf("Le nombre de subdivisions est N= %d", N);
                         }while(N%2!=0);
                printf("La borne gauche de l'intervalle est A= %lf\n",A);
                printf("La borne droite de l'intervalle est B= %lf\n",B);
                printf("Le nombre de subdivisions est N= %d\n",N);
                printf("\n");
                printf("Voulez-vous faire des changements? <Y/N\n");
                scanf("%c",&R);
                if(R=='Y')
                {
                    printf("La borne gauche courante de l'intervalle est A= %lf\n",A);
                    printf("Entrez la nouvelle borne gauche de l'intervalle A = ");
                    scanf("%lf",&A);
                    printf("La borne droite courante de l'intervalle est B= %lf\n",B);
                    printf("Entrez la nouvelle borne droite de l'intervalle B = ");
                    scanf("%lf",&B);
                    printf("Le nombre courant de subdivisions est N= %d\n", N);
                    printf("Entrez le nouveau nombre de subbdivisions N =");
                    scanf("%d",&N);
                }
                x=CreerTabReel(N);
                TabReel(A, B, N, x);
                Approximation(choix1, choix2, N, A, B, x);
                printf("\n");
                getchar();
                printf("Voulez-vous changer d'intervalle? <Y/N> ...");
                scanf("%c",&R);
                getchar();
            }while(R=='Y');
            printf("Voulez-vous essayer une autre fonction? <Y/N> ...");
            scanf("%c", &R);
        }while(R=='Y');
        getchar();
        printf("Voulez-vous essayer une autre formule? <Y/N> ...");
        scanf("%c", &R);
    }while(R=='Y');

    return 0;
}
