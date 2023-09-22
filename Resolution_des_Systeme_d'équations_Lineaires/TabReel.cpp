#include<iostream>

using namespace std;

double* TabReel(int n)
{
	double* T;
	T=new double[n];
	if(T==NULL)
		{
			cout<<"Espace insuffisant!"<<endl;
			exit(-1);
		}
	else
		T--;
		return T;
}
