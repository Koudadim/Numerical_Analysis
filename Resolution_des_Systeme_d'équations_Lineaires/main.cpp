#include <iostream>
#include<string>

using namespace std;

int main()
{
     cout<<"<=== TRAORE KOUDADIM OLIVIER  ===>"<<endl;
     cout<<"<=== FILIERE: IFA I ===>"<<endl;
     cout<<"<=== PROJET N° 5 D'ANALYSE NUMERIQUE===>"<<endl;
	cout<<endl<<"<===RESOLUTION NUMERIQUE DES SYSTEMES D''EQUATIONS LINEAIRES===>"<<endl<<endl;
	int n, choix;
	string reponse;
	double* x;
	double* b;
	double* b0;
	double* x0;
	double* x1;
	double** A;
	double** B;
	FILE* fichier;
	double* TabReel(int n);
	double** MatReelle(int n);
	void RemplissageTabReel(double* T, int n, FILE* fichier);
	void AfficheTabReel(int n, double* T);
	void FreeMatReelle(double** M, int n);
	void FreeTabReel(double* T);
     void RemplissageMatReelle(double** M, int n, FILE* fichier);
     void AfficheMatReelle(int n, double** M);
     void RecopieTab(int n, double* x, double* y);
     void RecopieMat(int n, double** A, double** B);
	void Gauss(int n, double* b, double* x, double** A);
	void GaussPivotPartiel(int n, double* b, double* x, double** A);
	void GaussPivotTotal(int n, double* b, double* x, double** A);
	void GaussJordan(int n, double* b, double* x, double** A);
	void DecompositionLU(int n, double* b, double* x, double** A);
	void Cholesky(int n, double* b, double* x, double** A);
	void GaussSeidel(int n, double* b, double* x, double** A);
     void Jacobi(int n, double* b, double* x, double** A);
     void SOR(int n, double* b, double* x, double** A);

	cout<<"Saisir la dimension n du syteme a resoudre: ";
	cin>>n;
	x=TabReel(n);
	b=TabReel(n);
	b0=TabReel(n);
	A=MatReelle(n);
	B=MatReelle(n);
	fichier=fopen("donnees.txt", "r");
	fscanf(fichier, "%d", &n);

	RemplissageMatReelle(A, n, fichier);

	RemplissageTabReel(b, n,  fichier);


     cout<<"La matrice du systeme A est: "<<endl;
     AfficheMatReelle(n, A);
     RecopieMat(n, B, A);                         // On recopie la matrice A dans B;
     cout<<endl<<"Le Second membre b du syteme"<<endl;
	AfficheTabReel(n, b);
	RecopieTab(n, b0, b);
	cout<<"Choisir parmi les methodes suivantes celle avec laquelle vous resoudre les systeme"<<endl;
	cout<<"1. Gauss"<<endl<<"2. GaussPivotPartiel"<<endl<<"3. GaussPivotTotal"<<endl;
	cout<<"4. GaussJordan"<<"5. Decomposition LU"<<endl<<"6. Cholesky"<<endl;
	cout<<"7. Jacobi"<<endl<<"8. GaussSeidel"<<endl<<"9. SOR"<<endl;

	do{
          cout<<"Choix= .... ";
          cin>>choix;
          void (*TabMethodes[9])(int n, double* b, double* x, double** A)={Gauss, GaussPivotPartiel, GaussPivotTotal, GaussJordan, DecompositionLU,
                                             Cholesky, Jacobi, GaussSeidel, SOR};
          TabMethodes[choix-1](n, b, x, A);
          RecopieMat(n, A, B);               // On conserve la matrice originale meme si des méthodes la modifie
          RecopieTab(n, b, b0);
          cout<<"::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::"<<endl;
          cout<<"Voulez-vous changer de methodes? Repondre par Yes / No : ";
          cin>>reponse;
	}while(reponse=="Yes");

	FreeTabReel(x);
	FreeTabReel(b);
	FreeTabReel(b0);
	FreeMatReelle(A, n);
	FreeMatReelle(B, n);

	return 0;
}
