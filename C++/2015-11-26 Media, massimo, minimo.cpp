#include <cstdlib>
#include <iostream>


using namespace std;

void riempivettore(int n,int B[]);
void scrivivettore(int n,int B[]);
float average(int n,int B[]);    
float Somma(int n,int B[]);
int max(int n,int B[]);
int min(int n,int B[]);
int main()

{
    system("color 2F");
    int N;
    cout<<"\n Inserisci cifre totali da somma: ",cin>>N;
    int A[N];
    cout<<"\n";
    int scelta;
    riempivettore(N,A);
    cout<<"\n";
    scrivivettore(N,A);
    cout<<"\n\n";
    cout<<" Media: ";
    cout<<average(N,A);
    cout<<"\n";
    cout<<"\n Somma: ";
    cout<<Somma(N,A);
    cout<<"\n\n";
    cout<<" Valore massimo: "<<max(N,A)<<endl;
    cout<<" Valore minimo:  "<<min(N,A)<<endl;    //<<min(A);
    cout<<"\n";
    
    system("PAUSE");
    return EXIT_SUCCESS;
}

void riempivettore(int n,int B[])
{
     for(int i=0;i<n;i++)
     {
          cout<<" ";
          cin>>B[i];
     }
}

cout>>"cosa fare?";
cin>>scelta; 
switch(scelta)
{    
     case 0:  cout<<"\n media  "<<AVERAGE(L,A)<<"\t";
          break;
     case 1:   cout<<"\n minimo  "<<MINIMO(MIN,L,A)<<"\t";
          break;
     case 2:   cout<<"\n massimo  "<<MASSIMO(MAX,L,A)<<"\t";
          break;
}

void scrivivettore(int n, int B[])
{
     for(int i=0;i<n;i++)
     cout<<" "<<B[i]<<"     ";
}     

//float della media
float average(int n,int B[])
{
      return Somma(n,B)/(float)n;
}

//float della Somma
float Somma(int n,int B[])
{
     float Somma=0;
     for(int i=0;i<n;i++)
     {     
          Somma=B[i]+Somma;
     }
     return Somma;
}
     
//numero massimo
int max(int n,int A[])
{
     int i,max;
     max=A[0];     
     for(i=1;i<n;i++)
     {
          if(A[i]>max)
          {     
               max=A[i];
          }
     }  
     return max;
}

//numero minimo
int min(int n,int A[])
{
     int i,min;
     min=A[0];     
     for(i=1;i<n;i++)
     {
          if(A[i]<min)
          {     
                min=A[i];
          }
     }  
     return min;
}
