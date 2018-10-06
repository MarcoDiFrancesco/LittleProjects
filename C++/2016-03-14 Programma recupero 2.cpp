#include <iostream>
#include <cmath>
using namespace std;

struct punto
{
    float x;
    float y;
};

void calcolaDistanza(punto punti1[],punto punti2[],float distanze,int n)
{
    for(int w=0;w<n;w++)
    {
        distance[n]=calcolaDistanza(punti1,punti2);
    }
}

void printPunti(punto punti1[],punto punti2[],int n)
{
    for(int w=0;w<n;w++)
    {
        cout<<punti1[w].x<<","<<punti1[w].y<<endl;
    }
    cout<<endl;
    for(int w=0;w<n;w++)
    {
        cout<<punti2[w].x<<","<<punti2[w].y<<endl;
    }
}

int main()
{
    int n=3;
    punto punti1[3]={{10,20},{30,40},{50,60}};/* punti1[0].x=10; punti1[0].y=20; */
    punto punti2[3]={{20,30},{40,50},{60,70}};
    float distanze[3];
    printPunti(punti1,punti2,n);
}
