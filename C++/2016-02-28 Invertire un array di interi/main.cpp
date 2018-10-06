#include <iostream>
using namespace std;

void stampa_array(int v[],int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        cout<<v[i];
        cout<<"\n";
    }

}

void inverti_destinazione(int v1[],int v2[],int n)
{
    int x;
    int i;
    x=n-1;
    for(i=0; i<n; i++)
    {
        v2[i]=v1[x];
        x--;
    }
}

void inverti_inarray(int v1[],int n)
{
    int x;
    int i;
    int tmp[n];
    x=n-1;
    for(i=0; i<n; i++)
    {
        tmp[i]=v1[x];
        x--;
    }
    for(i=0; i<n; i++)
    {
        v1[i]=tmp[i];
    }
}

int main()
{
    int v1[10]= {1,2,3,4,5,6,7,8,9,10}; //modifica
    int v2[10];

    cout<<"Stampa array V1\n";
    stampa_array(v1,10);
    cout<<"-----------------------\n";
    cout<<"Inversione in array V2\n";
    cout<<"-----------------------\n";
    inverti_destinazione(v1,v2,10);
    cout<<"Stampa array V2\n";
    stampa_array(v2,10);
    cout<<"---------------------------\n";
    cout<<"Inversione in array stesso\n";
    cout<<"---------------------------\n";
    inverti_inarray(v1,10);
    cout<<"Stampa array V1\n";
    stampa_array(v1,10);
}
