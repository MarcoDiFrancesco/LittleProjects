#include <cstdlib>
#include <iostream>
using namespace std;
int i; //inserisco la i che conta i cicli
int main()
{
    cout<< "\n  Numeri:\n\n  ";
    float somma; //aggiungo la somma in float
    float temp [10]={5,9,6,3,5,5,6,4,2,9}; //gli dico i numeri
    for(i=0; i<10; i++) //metto il for per ciclare la somma
    {
    cout<<temp[i]<<"  ";
    somma=somma+temp[i]; //calcolo la sonmma
    }

    cout<< "\n\n  somma:"<<somma;  //scrivo la somma
    somma=somma/10; //calcolo la media
    cout<< "\n\n  media:"<<somma; //scrivo la media
    cout<< "\n\n"; //spazio di 2
    
    //Calcolo da zero il minimo
    float min=temp[0];
    for(i=0; i<10; i++) //faccio il "for" per fare il minimo
    if(min>temp[i]) //if che segna se il numero temp[x] è maggiore di quello selezionato prima, se si scambia questo in max
    {
    min=temp[i]; //se si scambia questo in max
    }
    cout<< "  minimo:"<<min;
    cout<<"\n\n"; //spazio di 2
    
    //Calcolo da zero il massimo
    float max=temp[0];
    for(i=0; i<10; i++) //faccio il "for" per fare il minimo
    if(max<temp[i]) //if che segna se il numero temp[x] minore di quello selezionato prima
    {
    max=temp[i]; //se si scambia questo in min
    }
    cout<< "  massimo:"<<max; //stampo il numero massimo
    cout<<"\n\n\n  "; //spazio di 3 per la fine
    
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
