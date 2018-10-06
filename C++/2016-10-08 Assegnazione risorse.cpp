#include <iostream>
#define _WIN32_WINNT 0x0500
#include <windows.h>
using namespace std;

void RichiestaRisorsa(),RilasciaRisorsa(),RilasciaTutto(),Stato(),MettiInCoda(int ParametroUno,int ParametroDue);
int NumeroProcessi,RisorsaSelezionata,ProcessoSelezionato,RisultatoSwitch,RisorsaRilasiata,ProcessoRilasciato,RisorsaDaRilasciareCompletamente;
int Risorse[15]; //Risorse
int Coda[15][10]; //Coda

int main()
{
    HWND console = GetConsoleWindow();
    MoveWindow(console, 0, 0, 1000, 850, TRUE);//Modifica grandezza console

    for(int w=0;w<15;w++)
    {
        Risorse[w]=-1;
        for(int ww=0;ww<10;ww++)
        {
            Coda[w][ww]=-1; //Inizializzo tutto a -1 ovvero svuoto le celle dallo 0
        }
    }
    do{
        //Menu per lo switch
        cout<<"\n 1- Richiedi la risorsa \n 2- Rilascia la risorsa \n 3- Termina processo \n 4- Stato \n 5-  \n";
        cout<<"Digita cosa vuoi fare --> ";
        cin>>RisultatoSwitch;
        cout<<endl;

        do
        {
            if(RisultatoSwitch>5)
            {
                cout<<"Il numero e' maggiore di 5, inserisci un numero piu' piccolo: ";
                cin>>RisultatoSwitch;
            }else if(RisultatoSwitch<1){
                cout<<"Il numero e' minore di 1, inserisci un numero piu' grande: ";
                cin>>RisultatoSwitch;
            }
        }while(RisultatoSwitch>5 || RisultatoSwitch<1);

        //Switch del menu
        switch(RisultatoSwitch)
        {
            case 1:
                RichiestaRisorsa();
                break;
            case 2:
                RilasciaRisorsa();
                break;
            case 3:
                RilasciaTutto();
                break;
            case 4:
                Stato();
                break;
            case 5:
                break;
        }
    }while(RisultatoSwitch!=5);
}

void RichiestaRisorsa() //Con questa funzione chiedo all'utente la risorsa e il processo
{
    cout<<"Inserisci risorsa: ";
    cin>>RisorsaSelezionata;
    do //Controllo risorsa del processo selezionato se è compresa tra 15 e 1
    {
        if(RisorsaSelezionata>15 || RisorsaSelezionata<1)
        {
            cout<<"Il numero non e' valido, inserisci un altro numero: ";
            cin>>RisorsaSelezionata;
        }
    }while(RisorsaSelezionata>15 || RisorsaSelezionata<1);

    cout<<"Inserisci processo: ";
    cin>>ProcessoSelezionato;
    do //Controllo errore del processo selezionato se è compreso tra 10 e 1
    {
        if(ProcessoSelezionato>10 || ProcessoSelezionato<1)
        {
            cout<<"Il numero non e' valido, inserisci un altro numero: ";
            cin>>ProcessoSelezionato;
        }
    }while(ProcessoSelezionato>10 || ProcessoSelezionato<1);
    //---------------------------------------------------------------------------------------------------------------------------------------------
    if(Risorse[RisorsaSelezionata]==-1) //controllo se è occupata la risorsa, non posso farlo con il diverso da 0 ma lo devo fare con il meno uno
    {
        Risorse[RisorsaSelezionata]=ProcessoSelezionato;
    }
    else
    {
        MettiInCoda(RisorsaSelezionata,ProcessoSelezionato);
    }
}

void RilasciaRisorsa()
{
    cout<<"Inserisci risorsa: ";
    cin>>RisorsaRilasiata;
    do
    {
        if(RisorsaRilasiata>15 || RisorsaRilasiata<1)
        {
            cout<<"Il numero non e' valido, inserisci un altro numero: ";
            cin>>RisorsaRilasiata;
        }
    }while(RisorsaRilasiata>15 || RisorsaRilasiata<1);

    cout<<"Inserisci processo: ";
    cin>>ProcessoRilasciato;
    do
    {
        if(ProcessoRilasciato>10 || ProcessoRilasciato<1)
        {
            cout<<"Il numero non e' valido, inserisci un altro numero: ";
            cin>>ProcessoRilasciato;
        }
    }while(ProcessoRilasciato>10 || ProcessoRilasciato<1);

    for(int w=0;w<15;w++)
    {
        if(Risorse[w]==ProcessoRilasciato)
        {
            Risorse[w]=-1; //In questo punto la rilascio
        }
    }
}
void RilasciaTutto()
{
    cout<<"Rlascia la risorsa che vuoi completamente rilasciare: ";
    cin>>RisorsaDaRilasciareCompletamente;
    cout<<endl;
    for(int w=0;w<15;w++)
    {
        if(Risorse[w]==RisorsaDaRilasciareCompletamente)
        {
            Risorse[w]=0; //Tolgo quello che c'era dentro la cella
        }
    }
}
void Stato()
{
    cout<<"Stato processi";
    for(int w=0;w<15;w++)
    {
        cout<<endl;
//        if(Risorse[w]!=-1) //Controllo se nella risorsa c'è qualche processo, se così è allora non la visualizzo
//        {
            cout<<"Risorsa "<<w<<" processo "<<Risorse[w];
//        }
    }
    cout<<endl<<endl<<"Stato della coda"<<endl;
    int counter=0;
    for(int w=0;w<15;w++)
    {
        cout<<counter<<" --> ";
        counter=counter+1;
        for(int ww=0;ww<10;ww++)
        {
            if(Coda[w][ww]!=-1)
            {
                cout<<Coda[w][ww]<<" ";
            }
        }
        cout<<endl;
    }
}

void MettiInCoda(int RisorsaSelezionataVoid,int ProcessoSelezionatoVoid) //Funzione per mettere in coda in caso ci sia già un processo in corso
{
    int risultaltoWhile=0;
    int i=0;
    do
    {
        if(Coda[RisorsaSelezionataVoid][i]!=-1)
        {
            Coda[RisorsaSelezionataVoid][i]=ProcessoSelezionatoVoid;
            risultaltoWhile=1;
        }
        i=i+1;
    }while(risultaltoWhile!=1);
}
//FARE ANCHE GRAFO RIDUCIBILE DI HOLT
//FARE IL MENU PER IL QUALE RICONOSCE I PROGETTI RIDUCIBILI NEL PUNTO CINQUE
//QUANDO LA RISORSA NON E' DISPONIBILE LA METTO NELLA CODA

//PRIMO - RIDUCIBILE, NON RIDUCIBILE, RIDOTTO AL MASSIMO
