#include<iostream>

using namespace std;

int* TabEntier(int n)
{
     int* T;
     T=new int[n];
     if(T==NULL)
          cout<<"Espace insuffisant pour le tableau d'entiers!"<<endl;
     else
          T--;
     return T;
}
