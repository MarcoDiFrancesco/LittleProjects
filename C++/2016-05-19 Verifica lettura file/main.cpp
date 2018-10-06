#include <cstdlib>
#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

struct corsa
{
    int numeroCorridore;
    char nome[20];
    char cognome[20];
    int minutiCorsa;
};

void scambio(corsa persone[x],corsa persone[y])
{
    int z;
    z=x;
    x=y;
    y=z;
}

void exchangeSort(corsa persone[],int N)
{
    for(int i=1;i<N;i++){
        for(int j=i+1;j<N;j++){
            if(persone[i].minutiCorsa>persone[j].minutiCorsa){
                scambio(persone[i],persone[j]);
            }
        }
    }
}

int main()
{
    ifstream file;
    file.open("risultati.txt");
///-------------------------------- VARIABILI DA CAMBIARE DIPENDENTEMENTE DAL FILE
    int numeroPersone=41;
///--------------------------------

    corsa persone[numeroPersone];

    for(int w=1;w<numeroPersone+1;w++)
    {
        file>>persone[w].numeroCorridore;
        file>>persone[w].nome;
        file>>persone[w].cognome;
        file>>persone[w].minutiCorsa;
    }

    file.close();

    exchangeSort(persone,numeroPersone);

///-------------------------------- PROVA COUT
  for(int w=1;w<numeroPersone;w++)
    {
        cout<<persone[w].numeroCorridore<<" ";
        cout<<persone[w].nome<<" ";
        cout<<persone[w].cognome<<" ";
        cout<<persone[w].minutiCorsa<<endl;
    }
///--------------------------------

}
