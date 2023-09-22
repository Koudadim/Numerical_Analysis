#include<iostream>

using namespace std;

/* Dans ce exercice il est question de créer une classe Vecteur representant les vecteurs mathématiques réels de type double
avec leurs opérations habituelles. Nous surchargerons les opérateurs: +, -, +=, -=, *=, *, ==, <<, >> et != */

class Vecteur
{
	private:
		int n;				//Taille du vecteur
		double *Vect;		//Pointeur sur un tableau de taille n;
	public:
		Vecteur(int m, double x): n(m)	// Constructeur
		{
			int i;
			Vect=new double [n];
			for(i=0; i<n; i++)
				Vect[i]=x;
		}
		Vecteur(int m):n(m)
		{
			int i;
			Vect=new double[n];
			for(i=0; i<n; i++)
				cin>>Vect[i];	
		}
		// Surcharge des opérateurs
		Vecteur operator+(Vecteur &v); // Fonction membre
		friend Vecteur operator-(Vecteur& v, Vecteur& w); //Fonction amie
		Vecteur operator+=(Vecteur& v);
		friend Vecteur operator-=(Vecteur& v, Vecteur& w);
		double operator*(Vecteur& v);
		friend double operator*=(Vecteur& v, Vecteur& w);
		bool operator==(Vecteur& v);
		friend bool operator!=(Vecteur& v, Vecteur& w);
		//ostream& operator<<(ostream& out);  // Pour l'affichage du Vecteur
		//friend istream operator>>(istream& in, Vecteur& v); // Pour la saisie du vecteur
		void afficheVecteur();
};
Vecteur Vecteur::operator+(Vecteur& v)
{
	int i;
	Vecteur V(n, 0.0);
	V.n=n;
	if(n!=v.n)
		{
			cout<<"Deux vecteurs de tailles differentes! Operation non valide!!!"<<endl;
			exit(-1);
		}
	else
		for(i=0; i<n; i++)
			V.Vect[i]=Vect[i]+v.Vect[i];
	return V;
}
Vecteur operator-(Vecteur& v, Vecteur& w)
{
	Vecteur V(v.n, 0.0);
	int i;
	if(v.n!=w.n)
		{
			cout<<"Deux vecteurs de tailles differentes! Operation non valide!!!"<<endl;
			exit(-1);
		}
	else
		for(i=0; i<v.n; i++)
			V.Vect[i]=v.Vect[i]-w.Vect[i];
	return V;
}
Vecteur Vecteur::operator+=(Vecteur& v)
{
	int i;
	if(n!=v.n)
		{
			cout<<"Deux vecteurs de tailles differentes! Operations non valide!!!"<<endl;
			exit(-1);
		}
	else
		for(i=0; i<n; i++)
			Vect[i]+=v.Vect[i];
	return *this;
}
Vecteur operator-=(Vecteur& v, Vecteur& w)
{
	int i;
	if(v.n!=w.n)
		{
			cout<<"Deux vecteurs de tailles differentes! Operations non valide!!!"<<endl;
			exit(-1);
		}
	else
		for(i=0; i<v.n; i++)
			v.Vect[i]-=w.Vect[i];
	return v;
}
double Vecteur::operator*(Vecteur& v)
{
	int i;
	double prod;
	if(n!=v.n)
		{
			cout<<"Deux vecteurs de tailles differentes! Operations non valide!!!"<<endl;
			exit(-1);
		}
	else
		for(i=0; i<n; i++)
			prod+=(Vect[i])*(v.Vect[i]);
	return prod;
}
double operator*=(Vecteur& v, Vecteur& w)
{
	int i;
	double prod;
	if(v.n!=w.n)
		{
			cout<<"Deux vecteurs de tailles differentes! Operations non valide!!!"<<endl;
			exit(-1);
		}
	else
		for(i=0; i<v.n; i++)
			prod+=(v.Vect[i])*(w.Vect[i]);
	return prod;
}
bool Vecteur::operator==(Vecteur& v)
{
	int i;
	if(n!=v.n)
		{
			cout<<"Deux vecteurs de tailles differentes! Operations non valide!!!"<<endl;
			exit(-1);
		}
	else
		{
			for(i=0; i<n; i++)
				{
					if(Vect[i]!=v.Vect[i]);
						return false;
				}
			return true;			
		}
}
bool operator!=(Vecteur& v, Vecteur& w)
{
	int i;
	if(v.n!=w.n)
		{
			cout<<"Deux vecteurs de tailles differentes! Operations non valide!!!"<<endl;
			exit(-1);
		}
	else
		{
			for(i=0; i<v.n; i++)
				{
					if(v.Vect[i]!=w.Vect[i])
						return true;
				}
			return false;
		}
}
/*ostream& Vecteur::operator<<(ostream& out)
{
	int i;
	out<<"Vecteur: (";
	for(i=0; i<n; i++)
		out<<this->Vect[i]<<", ";
	out<<endl;
	return out;	
}
istream operator>>(istream& in, Vecteur& v)
{
	int i;
	cout<<"Les composantes du Vecteur:"<<endl;
	for(i=0; i<v.n; i++)
		in>>v.Vect[i];
	return in;	
}*/

void Vecteur::afficheVecteur()
{
	int i;
	cout<<"(";
	for(i=0; i<n; i++)
		cout<<Vect[i]<<", ";
	cout<<")"<<endl;
}

int main()			// Programme d'éssai
{
	Vecteur w(3, 2.5);
	cout<<"Vecteur w: ";
	w.afficheVecteur();
	Vecteur v1(5);
	cout<<"Vecteur v1: ";
	v1.afficheVecteur();
	Vecteur v2(5);
	cout<<"Vecteur v2: ";
	v2.afficheVecteur();
	Vecteur v(5, 0.0);
	v=v1+v2;
	cout<<"Somme des vecteurs v1 et v2: v = ";
	v.afficheVecteur();
	v=v1-v2;
	cout<<"Difference des vecteurs v1 et v2: v = ";
	v.afficheVecteur();
	/*cout<<"Somme des vecteurs v1 et w: ";
	v=v1+w;*/
	double prod;
	prod=v1*v2;
	cout<<"Produit scalaire de v1 et v2: "<<prod<<endl;
	return 0;	
}
