#include <cstdlib>
#include <iostream>

using namespace std;

void contattore(),primo(),secondo(),terzo(),finale();
char a[100];
int i;
int r;
int m=0;
int b=0,c=0,d=0,e=0,f=0,g=0,h=0,j=0,k=0,l=0;

int main()
{
    cin.getline(a,100);
    contattore();
    primo();
    secondo();
    terzo();
    finale();
    cout<<"\nIl numero massimo inserito e' --> "<<m<<"\n\n";
}

//////////////////////////////////////////////////////////////////////
void contattore()
{
    while(a[r]!='\0')
    {
        r=r+1;
    }
}

void terzo()
{
    while(i<r)
    {
        if(a[i]=='1')  {b=1;}
        if(a[i]=='2')  {c=1;}
        if(a[i]=='3')  {d=1;}
        if(a[i]=='4')  {e=1;}
        if(a[i]=='5')  {f=1;}
        if(a[i]=='6')  {g=1;}
        if(a[i]=='7')  {h=1;}
        if(a[i]=='8')  {j=1;}
        if(a[i]=='9')  {k=1;}
        if(a[i]=='0')  {l=1;}
    }
}
//////////////////////////////////////////////////////////////////////
void secondo()
{
    do
    {
        if(a[i]=='1')  {b=1;}
        if(a[i]=='2')  {c=1;}
        if(a[i]=='3')  {d=1;}
        if(a[i]=='4')  {e=1;}
        if(a[i]=='5')  {f=1;}
        if(a[i]=='6')  {g=1;}
        if(a[i]=='7')  {h=1;}
        if(a[i]=='8')  {j=1;}
        if(a[i]=='9')  {k=1;}
        if(a[i]=='0')  {l=1;}
    }
    while(i<r);
}
//////////////////////////////////////////////////////////////////////
void primo()
{
    for(i=0;i<r;i++)
    {

          if(a[i]>k)
            {
                k=a[i];
            }
        }
        cout<<k;


        //SISTEMA NORMALE NON FUNZIONA
        //sistema dei 10 if

    }
}
////////////////////////////////////////////////////////////////////
void finale()
{
    if(b>0)  {m=1;}
    if(c>0)  {m=2;}
    if(d>0)  {m=3;}
    if(e>0)  {m=4;}
    if(f>0)  {m=5;}
    if(g>0)  {m=6;}
    if(h>0)  {m=7;}
    if(j>0)  {m=8;}
    if(k>0)  {m=9;}
    if(l>0)  {m=1;}
    if(l=0)  {m=0;}
}
