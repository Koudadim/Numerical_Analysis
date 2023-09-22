#include<iostream>

#include<math.h>

using namespace std;

/* Nous concevons ici une classe Matrice qui permet de représenter les matrices et d'effectuer 
des operations relatives aux matrices*/

double* TabReel(int n) // Une fonction qui permettra de déclarer un tableau de taille n
{
	int i;
	double* T;
	T=new double [n];
	if(T==NULL)
		cout<<"Espace insuffisant!!!"<<endl;
	else 
		T--;
		return T;
}

double ** MatReelle(int n) // Une fonction qui permettra de creer une matrice de taille n
{
	int i;
	double** M;
	M=new double*[n];
	if(M==NULL)
		cout<<"Espace insuffisant"<<endl;
	else
		M-=1;
	for(i=1; i<=n; i++)
	 	M[i]=TabReel(n);
	return M;
}

class Matrice;

class Vecteur
{
	private:
		int m;
		double *vect;
	public:
		Vecteur(int k, double a):m(k)
		{
			int i;
			vect=TabReel(m);
			for(i=1; i<=m; i++)
				vect[i]=a;
		}
		
		Vecteur(int k):m(k)
		{
			cout<<"Saisie d'un vecteur de taille "<<m<<endl;
			int i;
			vect=TabReel(m);
			for(i=1; i<=m; i++)
			    cin>>vect[i];
		}
		
	void AfficheVecteur()
	{
		int i;
		cout<<"( ";
			for(i=1; i<=m; i++)
				cout<<vect[i]<<" ";
		cout<<" )"<<endl;
	}
	friend Vecteur operator*(const Matrice& A, const Vecteur& V);
};

class Matrice
{
	private:
		int n;
		double** M;
	public:
		Matrice(int m); 				// Constructeur acceptant l'ordre de la matrice
		Matrice(int m, double a);		 // Constructeur acceptant l'ordre de la matrice et une valeur d'initialisation
		Matrice(const Matrice& A);			 // Constructeur de recopie
		//Matrice(int m, double** M); // Constructeur d'un objet de type Matrice à partir d'une matrice
		~Matrice(); 					// Destructeur
		friend double Det(const Matrice& A); 	// Methode calculant le determinant de la matrice
		double Trace(); 				// Methode de calcul de la trace de la matrice
		Matrice Transposee(); 			// Methode de determination de la transposée de la matrice
		friend bool TriangSup(const Matrice& A); // Methode verifiant la triangularité supérieure de la matrice
		bool TriangInf(); 						//Methode vérifiant la triangularité inférieure de la matrice
		bool Diag(); 	// Methode vérifiant la diagonalité de la matrice
		// Sucharge des opérateurs: +, -, +=, -=, *, *=, ==, !=, <<, et >>
		// Nous utiliserons tantot des fonctions amies, tantot des méthodes membres 
		friend Matrice operator+(Matrice& A, Matrice& B);
		Matrice operator-(Matrice& A);
		friend Matrice operator+=(Matrice& A, Matrice& B);
		Matrice operator-=(Matrice& A);
		Matrice operator*(Matrice& A);	// Multplication de deux matrices
		friend Vecteur operator*(const Matrice& A, const Vecteur& V);	// Multiplication d'une matrice par un vecteur
		friend Matrice operator*=(Matrice& A, Matrice& B);
		friend bool operator==(Matrice& A, Matrice& B);
		bool operator!=(Matrice& A);
		/*ostream& operator<<(ostream out, Matrice& A);
		friend istream operatot>>(istream in, Matrice& B);*/
		void AfficheMatrice();
};
// Implémentation des contructeurs, des fonctions membres et amies de la classe vecteur
Matrice::Matrice(int m):n(m)
{
	int i, j;
	M=MatReelle(n);
	cout<<"Saisie de la matrice de taille n= "<<n<<endl;
	for(i=1; i<=n; i++)
	 	for(j=1; j<=n; j++)	
	 		cin>>M[i][j];
}
Matrice::Matrice(int m, double a):n(m)
{
	int i, j;
	M=MatReelle(n);
	for(i=1; i<=n; i++)
	 	for(j=1; j<=n; j++)	
	 		M[i][j]=a;
}
Matrice::Matrice(const Matrice& A):n(A.n)
{
	int i, j;
	M=MatReelle(n);
	cout<<"Creation d'une matrice de taille n= "<<n<<" par copie d'une autre...'"<<endl;
	for(i=1; i<=n; i++)
	 	for(j=1; j<=n; j++)	
	 		M[i][j]=A.M[i][j];
}
/*Matrice::Matrice(int m, double** A): n(m)
{
	int i, j;
	for(i=1; i<=n; i++)
		for(j=1; j<=n; j++)
			M[i][j]=A[i][j];
}*/
Matrice::~Matrice()
{
	int i;
	for(i=1; i<=n; i++)
		delete [] M[i];
}
double Det(const Matrice& A)
{
	double delta=0;
	int N, i, j, p, q, k;
	N=A.n;
	while(N>0)
	{
		if(N==1) 
			delta=A.M[N][N];
		else
		{
			N--;
			signed int sign;
			double* det;
			det=TabReel(N+1);
			for(i=1; i<=N+1; i++)
				det[i]=0.0;
			j=1;  					//On choisit de d'appliquer la formule du determinant en fixant la première colonne
			Matrice B(N, 0.0);	// Contruction d'un objet de classe Matrice dont tous les éléments sont nuls
			// On construit une matrice B de taille n-1 en sautant la la i-ème ligne et la j-ème colonne
			for(i=1; i<=N+1; i++)			
				{
					for(q=j+1; q<=N+1; q++)
						{
							for(p=1; p<i; p++)
								B.M[p][q-1]=A.M[p][q];
							for(p=i+1; p<=N+1; p++)
								B.M[p-1][q-1]=A.M[p][q];	
						}
					k=i+j;
					sign=pow((-1), k);					
					det[i]+=sign*A.M[i][j]*Det(B); 	// La recursivité est exploitée ici							
				}
			
			for(i=1; i<=N; i++)
				delta+=det[i];		 
		}
	}
	return delta;	
}

double Matrice::Trace()
{
	double trM=0;
	int i;
	for(i=1; i<=n; i++)
		trM+=M[i][i];
		
	return trM;
}
Matrice Matrice::Transposee()
{
	Matrice tM(n, 0.0);
	int i, j;
	for(i=1; i<=n; i++)
		for(j=1; j<=n; j++)
			tM.M[i][j]=M[j][i];
			
	return tM;
}
bool TriangSup(const Matrice& A)
{
	int i, j;
	for(j=1; j<=A.n; j++)
		for(i=1; i<j; i++)
			{
				if(A.M[i][j]!=0) 		// Si au moins un élément situé strictement en dessous de la diagonale est non nul
					return false;	// Alors la matrice n'est pas triangulaire supérieure
			}
	return true;
}
bool Matrice::TriangInf()
{
	int i, j;
	for(i=1; i<=n; i++)
		for(j=i+1; j<=n; j++)
			{
				if(M[i][j]!=0)		// Si au moins un élément situé strictement au dessus de la diagonale est non nul
					return false;	// Alors la matrice n'est pas triangulaire inférieure
			}
	return true;
}
bool Matrice::Diag()
{
	int i, j;
	for(i=1; i<=n; i++)
		for(j=1; j<=n; j++)
		 if(i!=j && M[i][j]) // Si au moins un élément n'appartenant pas à la diagonale est non nul, alors la matrice n'est pas diagonale
		 	return false;
	return true;
}
Matrice operator+(Matrice& A, Matrice& B)
{
	int i, j;
	if(A.n!=B.n)
		cout<<"Deux matrices de tailles differentes! Operations non valide."<<endl;
	else
		{
			Matrice S(A.n, 0.0);
			for(i=1; i<=A.n; i++)
				for(j=1; j<=A.n;j++)
					S.M[i][j]=A.M[i][j]+B.M[i][j];
			
			return S;	
		}
}
Matrice Matrice::operator-(Matrice& A)
{
	if(A.n!=n)
		cout<<"Deux matrices de tailles differentes! Operations non valide."<<endl;
	else
		{
			int i, j;
			Matrice D(A.n, 0.0);
			for(i=1; i<=A.n; i++)
				for(j=1; j<=A.n;j++)
					D.M[i][j]=A.M[i][j]+M[i][j];
			
			return D;	
		}
}
Matrice operator+=(Matrice& A, Matrice& B)
{
	if(A.n!=B.n)
		cout<<"Deux matrices de tailles differentes! Operations non valide."<<endl;
	else
		{
			int i, j;
			for(i=1; i<=A.n; i++)
				for(j=1; j<=A.n;j++)
					A.M[i][j]+=B.M[i][j];	
		}
	return A;
}
Matrice Matrice::operator-=(Matrice& A)
{
	if(A.n!=n)
		cout<<"Deux matrices de tailles differentes! Operations non valide."<<endl;
	else
		{
			int i, j;
			for(i=1; i<=A.n; i++)
				for(j=1; j<=A.n;j++)
					M[i][j]+=A.M[i][j];	
		}
	return *this;
}
Matrice Matrice::operator*(Matrice& A)
{
	if(A.n!=n)
		cout<<"Deux matrices de tailles differentes! Operations non valide."<<endl;
	else
		{
			int i, j, k;
			Matrice P(A.n, 0.0);
			for(i=1; i<=A.n; i++)
				for(j=1; j<=A.n;j++)
					for(k=1; k<=A.n; k++)
						P.M[i][j]+=M[i][k]*A.M[k][j];
			
			return P;
		}
}
Vecteur operator*(const Matrice& A, const Vecteur& V)
{
	if(A.n!=V.m)
		cout<<"Une matrice dont le nombre de colonne differe du nombre d'element du vecteur!!! Operation non valide."<<endl;
	else
		{
			int i, j;
			Vecteur P(A.n, 0.0);
			for(i=1; i<=A.n; i++)
				for(j=1; j<=V.m;j++)
						P.vect[i]+=A.M[i][j]*V.vect[j];
						
			return P;
		}
}

Matrice operator*=(Matrice& A, Matrice& B)
{
		if(A.n!=B.n)
		cout<<"Deux matrices de tailles differentes! Operations non valide."<<endl;
	else
		{
			double Mij;
			int i, j, k;
			for(i=1; i<=A.n; i++)   // instruction: A=A*B <=> A*=B
				for(j=1; j<=A.n;j++)
					{
						Mij=A.M[i][j];		// On recupère A.M[i][j]
						A.M[i][j]=0.0;  	// On initialise A.M[i][j] à 0.0
						for(k=1; k<=A.n; k++)
							A.M[i][j]+=A.M[i][k]*B.M[k][j];  
						// A la fin de la boucle, la vraie valeur de (A*B).M[i][j] est diminuée de Mij*B.M[i][j] 
						A.M[i][j]+=Mij*B.M[i][j]; 	// Ce qui la valeur correcte...
					}
		}
	return A;	
}

bool operator==(Matrice& A, Matrice& B)
{
	if(A.n!=B.n)			// Deux matrice de tailles différentes ne peuvent jamais etre égales
		return false;
	else
		{
			int i, j;
			for(i=1; i<=A.n; i++)
				for(j=1; j<=A.n;j++)
					if(A.M[i][j]!=B.M[i][j]) // Si au moins deux éléments de meme dans A.M et B.M sont differents;
						return false;			// Alors il n'y a pas d'égalité!!!			
		}
	return true;
}

bool Matrice::operator!=(Matrice& A)
{
	if(A.n!=n)			// Deux matrice de tailles différentes sont toujours différentes
		return true;
	else
		{
			int i, j;
			for(i=1; i<=A.n; i++)
				for(j=1; j<=A.n;j++)
					if(A.M[i][j]!=M[i][j]) // Si au moins deux éléments de meme dans A.M et B.M sont differents;
						return true;			// Alors il y a inégalité!!!			
		}
	return false;	
}

void Matrice::AfficheMatrice()
{
	int i, j;
	for(i=1; i<=n; i++)
		{
			for(j=1; j<=n;j++)
				cout<<M[i][j]<<" ";
			cout<<endl;
		}	
}

int main()
{
	cout<<"*<======OPERATIONS SUR LES MATRICES======>*"<<endl<<endl;
	Matrice A(2, 2.5);
	cout<<"Matrice A: "<<endl;
	A.AfficheMatrice();
	
	Matrice B(2);
	cout<<"Matrice B: "<<endl;
	B.AfficheMatrice();
	
	/*Vecteur V1(3, 3.6);
	cout<<"Vecteur V1: ";
	V1.AfficheVecteur();
	
	Vecteur V2(3);
	cout<<"Vecteur saisi V2: ";
	V2.AfficheVecteur();*/
	
	cout<<"Les determinants de A est: "<<Det(A)<<endl;
	cout<<"Les determinants de B est: "<<Det(B)<<endl;
}
