#include <iostream>
using namespace std;


void stampaHello(char name[])
{
    cout<<"Hello "<<name<<endl;
}

void introduce(char name[],int age)
{
    cout<<"Mi chiamo "<<name<<" e ho "<<age<<" anni"<<endl;
}

void stampaChar(char c1,char c2)
{
    cout<<"Il carattere e' "<<c1<<","<<c2<<endl;
}

void stampaNome(char s[])
{
    int i=0;
    while(s[i]!='\0')
    {
        i++;
    }
    cout<<"La parola s' di "<<i<<" caratteri"<<endl;
}

int stampaNome2(char s[])
{
    int i=0;
    while(s[i]!='\0')
    {
        i++;
    }
    cout<<"La parola s' di "<<i<<" caratteri"<<endl;
    return i;
}

float somma(float money[],int n)
    {
        float sum=0;
        for(int w=0;w<n;w++)
        {
            sum=sum+money[w];
        }
            return sum;

    }

bool trovaZeri(int v[],int n)
{
    for(int w=0;w<n;w++)
    {
        if(v[w]==0)
        {
            return true;
        }
    }
    return false;
}

bool stesseLettere(char lettere[])
{
    for(int w=1;lettere[w]!='\0';w++)
    {
        if(lettere[w]!=lettere[w-1])
        {
            return true;
        }
    }
    return false;
}

/*
VOID DEVE FARE TUTTO ALL'INTERNO DELLA FUNZIONE
INT MANDA UN'AUT COL RETURNDI INTERI
FLOAT MANDA UN'OUT CON NUMERI CON LA VIRGOLA
*/

int main()
{
    stampaHello("Paolo");
    stampaHello("Giovanni");
    stampaHello("Marco");

    char s1[]="Giuseppe";
    char s2[]="Andrea";

    stampaHello(s1);
    stampaHello(s2);

    introduce("Paolo",41);
    introduce("Giusi",41);

    stampaChar(s1[0],s1[1]);
    stampaNome(s1);

    int l;
    l=stampaNome2(s1);

    float money[5]={3.4,5.4,1.6,4.5,1.3};
    float o;
    o=somma(money,5);
    cout<<"La somma di soldi e' "<<o<<" money"<<endl;

    int r1[]={1,1,1,1,1};
    int r2[]={0,1,1,1,1};
    int p;

    p=trovaZeri(r1,5);

    if(trovaZeri(r1,5)!=false)
    {cout<<"Trovato lo zero"<<endl;}
    else
    {cout<<"Non trovato lo zero"<<endl;}

    char e1[]="aaa";
    char e2[]="bbb";
    char e3[]="aba";

    if(stesseLettere(e1)==true)
    {
        cout<<"La stringa e1 ha i caratteri diversi"<<endl;
    }
    else
    {
        cout<<"La stringa e1 ha i caratteri uguali"<<endl;
    }
    //STESSA COSA REPLICATA PER LE ALTRE DUE STRINGHE MA COMPRESSA
    if(stesseLettere(e2)==true)  {cout<<"La stringa e2 ha i caratteri diversi"<<endl;}  else  {cout<<"La stringa e2 ha i caratteri uguali"<<endl;}
    if(stesseLettere(e3)==true)  {cout<<"La stringa e3 ha i caratteri diversi"<<endl;}  else  {cout<<"La stringa e3 ha i caratteri uguali"<<endl;}
}
