#include <iostream>

using namespace std;

void cryptROT13(char string[]);
void decryptROT13(char string[]);

int main()
{
    char secretMessage[100]="Questo messaggio segreto deve essere criptato";
    cout<<"Il messaggio originale e: "<<secretMessage<<endl;
    cryptROT13(secretMessage);
    cout<<"Il messaggio criptato e: "<<secretMessage<<endl;
    decryptROT13(secretMessage);
    cout<<"Il messaggio decriptato e: "<<secretMessage<<endl;
}


//lettere[26]={a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z};

void cryptROT13(char string[])
{
    int i;
    for(i=0;i<100;i++)
    {
        string[i]=string[i]+13;
        cout<<string[i];
    }
}
void decryptROT13(char string[])
{
    int i;
    for(i=0;i<100;i++)
    {
        string[i]=string[i]-13;
        cout<<string[i];
    }
}

