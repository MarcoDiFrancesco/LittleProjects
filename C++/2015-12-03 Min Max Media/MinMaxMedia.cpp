#include <cstdlib>
#include <iostream>

using namespace std;

void riempivettore(int N, int B[]);
void scrivivettore(int N, int B[]);
float average(int N, int B[]);
float minimo(int N,int B[]);
float massimo(int N,int B[]);
float Somma(int N,int B[]);
void contrario(int N, int B[]);
float coutoveraverage(int N, int B[]);

int main()
{
    int n,cont;
    char r;
    cout<<"Quanti numeri vuoi analizzare? ";
    cin>>n;
    n=n+1; //aggiungo un n per non pertire dal numero 0
    int A[n];
    float media,min,max,SOMMA;

    riempivettore(n,A);
    do
    {
     cout<<"\nInserisci i numeri per ricevere le seguenti funzioni\n\n0=Media 1=Max 2=Minimo 3=Somma 4=Contrario del vettore 5=Numeri sopra la media \n\n";
     cout<<"Hai selezionato: ";
     cin>>cont;
     switch (cont)
     {
      case 0:cout<<"La media e': "<<average(n,A)<<"\n";break;
      case 1:cout<<"Il numero massimo e': "<<massimo(n,A)<<"\n";break;
      case 2:cout<<"Il numero minimo e': "<<minimo(n,A)<<"\n";break;
      case 3:cout<<"La somma e': "<<Somma(n,A)<<"\n";break;
      case 4:contrario(n,A);break;
      case 5:cout<<"I numeri superiori alla media sono in totale: "<<coutoveraverage(n,A)<<"\n";break;
      default:cout<<"La media e': "<<average(n,A)<<"\n";cout<<"Il numero massimo e': "<<massimo(n,A)<<"\n";cout<<"Il numero minimo e': "<<minimo(n,A)<<"\n";cout<<"La somma e': "<<Somma(n,A)<<"\n";cout<<"I numeri superiori alla media sono in totale: "<<coutoveraverage(n,A)<<"\n";contrario(n,A);
      }
     cout<<"Vuoi ripetere?";
     cin>>r;
     }
     while (r=='s');


system("PAUSE");
return EXIT_SUCCESS;
}
void riempivettore(int N, int B[])
{
for(int i=1;i<N;i++)
{cout<<i<<" numero: ";
cin>>B[i];}
}
void scrivivettore(int N, int B[])
{for(int i=0;i<N;i++)
{cout<<B[i]<<"\n";}
}
float average(int N, int B[])
{return Somma(N,B)/(float)N;}
float minimo(int N, int B[])
{
float min=B[0];
for(int i=1;i<N;i++)
{ if (min > B[i])
{ min = B[i];}
}
return min;
}
float massimo(int N, int B[])
{
float max=B[0];
for(int i=1;i<N;i++)
{ if (max<B[i])
{ max = B[i];}
}
return max;
}
float Somma(int N, int B[])
{
float SOMMA=0;
for (int i=0;i<N;i++)
{ SOMMA = SOMMA + B[i];}
return SOMMA;
}
void contrario(int N, int B[])
{
for(int i=N-1;i>=0;i--)
{cout<<B[i]<<"\n";}
}
float coutoveraverage(int N, int B[])
{float M,sup;sup=0;M=average(N,B);for (int i=0;i<N;i++)
{if (B[i]>M)
{sup=sup+1;}
}
return sup;
}
