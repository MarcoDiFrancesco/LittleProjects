#include <iostream>

using namespace std;

// Ho sostituito per praticità DIFFERENCE con d
void derive(int v[], int n, int d[])
{
    for(int w=0;w<n-1;w++)
    {
        d[w]=v[w+1]-v[w];
    }
}

void stampa(int d[],int n)
{
    cout<<endl;
    for(int w=0;w<n-1;w++)
    {
        cout<<"La differenza tra il vettore numero "<<w+1<<" e il vettore numero "<<w+2<<" e': ";
        cout<<d[w]<<endl;
    }
}

void inserisci(int n,int v[])
{
    cout<<endl;
    for(int w=0;w<n;w++)
    {
        cout<<"Inserisci l'elemento numero "<<w+1<<": ";
        cin>>v[w];
    }
}

int main()
{
    int n;
    cout<<"Inserisci numero di elementi: ";
    cin>>n;
    int d[n];
    int v[n];
    inserisci(n,v);
    derive(v,n,d);
    stampa(d,n);
}
