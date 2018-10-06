#include <iostream>


using namespace std;

void stampa(int v[],int i)
{
    cout<<"Stampa i numeri dell'array\n\n";
    for(int f=0;f<i;f++)
    {
        cout<<"   "<<v[f]<<"\n";
    }
    cout<<endl;
}

void trova(int v[],int i,int numero)
{
    cout<<"Stampa se trova il numero\n\n";
    for(int f=0;f<i;f++)
    {
        if(v[f]==numero)
        {
            cout<<"   Ho trovato il numero\n";
        }
        else
        {
            cout<<"   Non ho trovato il numero\n";
        }
    }
}
void sub(int v[],int i,int f,int somma)
{
    cout<<"\nIl totale e' --> ";
    for(f=0;f<i;f++)
    {
        somma=somma+v[f];
    }
        cout<<somma<<endl;
}

void subpositivi(int v[],int i,int sub)
{
    for(int f=0;f<i;f++)
    {
        if(v[f]>0)
        {
            sub=sub+v[f];
        }
    }
    cout<<"\nIl mumero totale dei positivi e' --> "<<sub<<endl<<endl;
}

void copia(int v[],int i,int c[])
{
    for(int f=0;f<i;f++)
    {
        c[f]=v[f];
    }
}

void stampa2(int c[],int i)
{
    for(int f=0;f<i;f++)
    {
        cout<<"   "<<c[f]<<"\n";
    }
    cout<<endl;
}

void inverti(int v[],int c[],int i)
{
    int n=i-1;
    for(int f=0;f<i;f++)
    {
        c[f]=v[n];
        n=n-1;
    }
}

void scalare(int v[],int c[],int i,int scalare)
{
    for(int f=0;f<i;f++)
    {
        c[f]=v[f]*scalare;
    }
}

int main()
{
    int v[3]={8,9,7};
    int c[3];
    stampa(v,3);
    trova(v,3,9);
    sub(v,3,0,0);
    subpositivi(v,3,0);
    copia(v,3,c);
    cout<<"Stampa i numeri del secondo array\n\n";
    stampa2(c,3);
    inverti(v,c,3);
    cout<<"Stampa i numeri del primo array invertiti\n\n";
    stampa2(c,3);
    scalare(v,c,3,5);
    cout<<"Stampa i numeri del primo array in modo scalare\n\n";
    stampa2(c,3);
}
