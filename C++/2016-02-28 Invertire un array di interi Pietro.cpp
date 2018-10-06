
#include <iostream>
using namespace std;
void stampaArray(int array[], int n);
void invertiArray(int src[], int dest[], int n);
void invertiArray(int array[], int n)
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

int main(int argc, char **argv)
{
int v1[10] = { 1, 6, 3, 6, 8, 12, 7, 2, 18, 20 };
int v2[10];
invertiArray(v1, v2, 10);
for(int m=0;m<10;m++)
{
int f=9;
f=f-1;
v2[m]=v1[f];
}
cout<<"Stampa array v1 : " <<v1<< "\n\n";
cout<<"Stampa array v2 : " <<v2<< "\n\n";
}
