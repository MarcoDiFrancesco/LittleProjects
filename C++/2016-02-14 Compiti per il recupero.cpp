#include <cstdlib>
#include <iostream>

using namespace std;
    int a=0; //numero di caratteri
    int b=0; //contattore per tutte le lettere uguali
    int c=0; //secondo contattore per tutte le lettere uguali
    int d=0;
    int e=0;
    char t[100];
    void contalettere(),primo(),secondo(),terzo();


int main()
{
    cin.getline(t,100);
    contalettere();
    primo();
    secondo();
    terzo();
    if(c>2) //imposto 2 l'if perche' in numero che dovrebbe rimanere di base 1, aumenta con i vari cicli
    {
        cout<<"\nLa stringa e' diversa\n\n";
    }
    else
    {
        cout<<"\nLa stringa e' uguale\n\n";
    }
}
////////////////////////////////////////////////////////
//funzione per vedere la quantità di lettere
void contalettere()
{
    while(t[a]!='\0')
    {
        a=a+1;
    }
}
////////////////////////////////////////////////////////
//Funzione col for
void primo()
{
    for(b=0;b<a;b++)
    {
        if(t[b]!=t[b+1])
        {
            c=c+1;          //se è uguale aumenta
        }
        else
        {
            c=c+0;
        }
    }
}
////////////////////////////////////////////////////////
//Funzione col while
void secondo()
{
    b=0;
    while(b<a)
    {
        b++;
        if(t[b]!=t[b+1])
        {
            c=c+1;          //se è uguale aumenta
        }
        else
        {
            c=c+0;
        }
    }
}
////////////////////////////////////////////////////////////
//Funzione col do
void terzo()
{
    do
    {
        b++;
        if(t[b]!=t[b+1])
        {
            c=c+1;          //se è uguale aumenta
        }
        else
        {
            c=c+0;
        }
    }while(b<a);
}



