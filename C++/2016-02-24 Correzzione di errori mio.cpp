#include <iostream>

using namespace std;
void primoif(),secondoif(),tuttoilresto();

float primo[60],secondo[60];
int a=0,b=0;

int main()
{
//cicla 60 volte
    for(a=0;a<60;a++)
    {
        cout<<a<<" numero: ";cin>>primo[a];
    }


    for(a=0;a<b;a++)
    {
        if(a==1){primoif();}
        else{tuttoilresto();}

//se uguale a 60 fai il primo preso
        if(a==60){secondoif();}
        else{tuttoilresto();}
    }
//il cout col for da problemi...
}

void primoif() //primo caso
{
    secondo[a]=(primo[a]/*primo una sola volta*/+2*primo[a+1]/*successivo 2 volte*/)/*totale diviso 3*//3;
}

void secondoif() //secondo caso
{
    secondo[a]=(primo[a]/*penultimo una volta*/+2*primo[a-1]/*secondo 2 volte*/)/*totale diviso 3*//3;
}

void tuttoilresto()
{
    secondo[a]=(primo[a]/*numero in considerazione una volta*/+primo[a+1]/*numero successivo*/+primo[a-1]/*numero precedente*/)/*totale diviso 3*//3;
}
