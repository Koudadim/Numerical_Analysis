#include<iostream>

using namespace std;

void AfficheTabReel(int n, double* T)
{
    int i;
    cout<<"( ";
    for(i=1; i<=n; i++)
        cout<<T[i]<<"  ";
     cout<<" )"<<endl;
}
