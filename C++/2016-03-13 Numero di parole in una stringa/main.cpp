#include <iostream>

using namespace std;

/*
Creare una funzione che copi una stringa in un altra stringa duplicando tutti gli spazi che trova:

void copyWithDoubleSpaces(char src[], char dest[]);
// esempio "ciao a tutti" -> "ciao  a  tutti"

Creare una funzione che copi una stringa in un altra stringa inserendo uno spazio dopo ogni carattere della stringa di partenza:

void copyAddingSpaces(char src[], char dest[]);
// esempio "ciao a tutti" -> "c i a o  a  t u t t i "

Creare una funzione che prenda in input una stringa e conti il numero di parole di cui la stringa è formata:
void wordCount(char src[]);
// esempio "ciao a tutti" -> 3 parole
*/

void wordCount(char src[],int r)
{
    int contaSpazi=1;
    for(int w=0;w<r;w++)
    {
        if(src[w]==' ') //Controllo spazi
        {
            if(src[w]==src[w-1]) //Controllo per spazi multipli
            {

            }
            else
            {
                contaSpazi=contaSpazi+1;
            }
        }
    }
    cout<<"Il numero di parole e': "<<contaSpazi<<endl<<endl;
}

void copyWithDoubleSpaces(char src[], char dest[],int r)
{
    int t=0;
    for(int w=0;w<r;w++)
    {
        if(src[w]==' ')
        {
            dest[t]=src[w];
            t=t+1;
            dest[t]=src[w];
            r=r+1;
        }
        else
        {
            dest[t]=src[w];
        }
        t=t+1;
    }
    //Stampa dest
    cout<<"Stringa con doppio spazio --> ";
    for(int w=0;w<r;w++)
    {
        cout<<dest[w];
    }
    cout<<endl<<endl;
}

void copyAddingSpaces(char src[], char dest[],int r)
{
    int t=0;
    for(int w=0;w<r*2;w++)
    {
        if(src[w]==' ') //IF PER VEDERE SE E' UNO SPAZIO IL CARATTERE
                        //IN CASO LO SIA NON AGGIUNGERE LO SPAZIO
        {
        dest[t]=src[w];
        t=t+1;
        }
        else
        {
        dest[t]=src[w];
        t=t+1;
        dest[t]=' ';
        t=t+1;
        }

    }
    //Stampa dest
    cout<<"Stringa che aggiunge ad ogni lettera uno spazio --> ";
    for(int w=0;w<r*2;w++)
    {
        cout<<dest[w];
    }
    cout<<endl<<endl;
}

int main()
{
    int r=0;
    char src[100];
    char dest[100];
    cout<<"Stringa --> ";
    cin.getline(src,100);
    ///////////////////////////////////////////////////////// CONTA CARATTERI
    while(src[r]!='\0')
    {
        r=r+1;
    }
    cout<<endl<<"Il numero di caratteri e': "<<r<<endl<<endl;
    /////////////////////////////////////////////////////////
    wordCount(src,r);
    copyWithDoubleSpaces(src,dest,r);
    copyAddingSpaces(src,dest,r);
}
