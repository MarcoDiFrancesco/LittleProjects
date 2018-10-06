#include <iostream>

using namespace std;

int main()
{
    char c[100];
    cin.getline(c,100);

//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//
//vedere la lunghezza

    int r=0,n=0,k=0; //R è il contattore
    while(c[r]!='\0')
    {
        r=r+1;
        n=n+1;
        k=k+1;
    }
    cout<<"\n\La frase e lunga "<<r<<" caratteri\n\n";

//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//
//inizia e termina con la stessa lettera

    if(c[0]==c[r-1])
    {
        cout<<"La prima e l'ultima lettera sono uguali\n\n";
    }
    else
    {
        cout<<"La prima e l'ultima lettera sono diverse\n\n";
    }

//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//
//stringa al contrario

    cout<<"La stringa al contrario e'-->";
    int t=0;
    for(t=n;n>=0;n--)
    {
        cout<<c[n];
    }
    cout<<"\n\n";

//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//
//numero di vocali che contiene

    int w,x,g,p,b;
    r=0;
    p=0;
    do
    {
        if(c[r]=='a')
        {
            p=1;
        }
        if(c[r]=='e')
        {
            p=1;
        }
        if(c[r]=='i')
        {
            p=1;
        }
        if(c[r]=='o')
        {
            p=1;
        }
        if(c[r]=='u')
        {
            p=1;
        }
    r=r+1;
    }
    while(p==0);
    cout<<"La lettera in cui si piazza la prima vocale e' la numero "<<r<<"\n";

//-//-//-//-//-//-//-//-//-//-//-//-//-//-//-//
//Numero di vocali che contiene

    p=0;
    for(r=0;r<k;r++)
    {
        if(c[r]=='a')
            {
                p=p+1;
            }
        if(c[r]=='e')
            {
                p=p+1;
            }
        if(c[r]=='i')
            {
                p=p+1;
            }
        if(c[r]=='o')
            {
                p=p+1;
            }
        if(c[r]=='u')
            {
                p=p+1;
            }
    }
    cout<<"\nIl nuemero di vocali nella frase e': "<<p<<"\n";
}
