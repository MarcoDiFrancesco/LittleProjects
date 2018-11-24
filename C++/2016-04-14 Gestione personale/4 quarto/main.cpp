#include <cstdlib>
#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

/*
id

numeroGiorni
numeroPersone

dataGiornata
giorno
mese
anno

ingressoMattina
oraIngressoMattina
minutoIngressoMattina

uscitaMattina
oraUscitaMattina
minutoUscitaMattina

ingressoPomeriggio
oraIngressoPomeriggio
minutoIngressoPomeriggio

uscitaPomeriggio
oraUscitaPomeriggio
minutoUscitaPomeriggio

giornoAnalizzato

personaDaAnalizzare
minutiLavoroMattina
minutiLavoroPomeriggio
minutiLavoroMese

erroreMattina
errorePomeriggio
*/

int main()
{
    ifstream file;
    file.open("OrariDipendenti.txt");

    int numeroPersone=20;
    int numeroGiorni=26;

    int id[numeroPersone];

    int giorno[numeroPersone][numeroGiorni];
    int mese[numeroPersone][numeroGiorni];
    int anno[numeroPersone][numeroGiorni];

    int oraIngressoMattina[numeroPersone][numeroGiorni];
    int minutoIngressoMattina[numeroPersone][numeroGiorni];

    int oraUscitaMattina[numeroPersone][numeroGiorni];
    int minutoUscitaMattina[numeroPersone][numeroGiorni];

    int oraIngressoPomeriggio[numeroPersone][numeroGiorni];
    int minutoIngressoPomeriggio[numeroPersone][numeroGiorni];

    int oraUscitaPomeriggio[numeroPersone][numeroGiorni];
    int minutoUscitaPomeriggio[numeroPersone][numeroGiorni];

    int giornoAnalizzato=0;
    int contatore=0;

    for(int cicloPersone=1;cicloPersone<numeroPersone+1;cicloPersone++)
    {
        file>>id[cicloPersone];

        for(int cicloGiorni=1;cicloGiorni<numeroGiorni+1;cicloGiorni++)
        {
            contatore=contatore+1;
        ///giornata
            char dataGiornata[10];
            file>>dataGiornata;
            sscanf(dataGiornata,"%d/%d/%d",&giorno[cicloPersone][cicloGiorni],&mese[cicloPersone][cicloGiorni],&anno[cicloPersone][cicloGiorni]);
        ///mattinaIngresso
            char ingressoMattina[10];
            file>>ingressoMattina;
            if(ingressoMattina!="-")
            {sscanf(ingressoMattina,"%d:%d",&oraIngressoMattina[cicloPersone][cicloGiorni],&minutoIngressoMattina[cicloPersone][cicloGiorni]);}

        ///mattinaUscita
            char uscitaMattina[10];
            file>>uscitaMattina;
            sscanf(uscitaMattina,"%d:%d",&oraUscitaMattina[cicloPersone][cicloGiorni],&minutoUscitaMattina[cicloPersone][cicloGiorni]);
        ///pomeriggioIngresso
            char ingressoPomeriggio[10];
            file>>ingressoPomeriggio;
            sscanf(ingressoPomeriggio,"%d:%d",&oraIngressoPomeriggio[cicloPersone][cicloGiorni],&minutoIngressoPomeriggio[cicloPersone][cicloGiorni]);
        ///pomeriggioUscita
            char uscitaPomeriggio[10];
            file>>uscitaPomeriggio;
            sscanf(uscitaPomeriggio,"%d:%d",&oraUscitaPomeriggio[cicloPersone][cicloGiorni],&minutoUscitaPomeriggio[cicloPersone][cicloGiorni]);
        }
    }

///CALCOLI

    ///CALCOLARE ORE DI LAVORO

    /*
    personaDaAnalizzare
    minutiLavoroMattina
    minutiLavoroPomeriggio
    */
    int personaDaAnalizzare=1;
    int minutiLavoroMattina[numeroPersone][numeroGiorni];
    int minutiLavoroPomeriggio[numeroPersone][numeroGiorni];
    int minutiLavoroMese[numeroPersone];
    int erroreMattina[numeroPersone][numeroGiorni];
    int errorePomeriggio[numeroPersone][numeroGiorni];


    cout<<"Che persona vuoi analizzare? --> ";
//  cin>>personaDaAnalizzare;
    personaDaAnalizzare=1;cout<<" 1";
    cout<<endl;

    for(int w=1;w<=numeroGiorni;w++)
    {

///CALCOLO TEMPO DI MATTINA

        if(oraIngressoMattina[personaDaAnalizzare][w]==0){erroreMattina[personaDaAnalizzare][w]=1;}
        else if(oraUscitaMattina[personaDaAnalizzare][w]==0){erroreMattina[personaDaAnalizzare][w]=1;}
        else if(oraIngressoMattina[personaDaAnalizzare][w]==8)
        {
            minutiLavoroMattina[personaDaAnalizzare][w]=minutiLavoroMattina[personaDaAnalizzare][w]+(minutoUscitaMattina[personaDaAnalizzare][w]-0);
            minutiLavoroMattina[personaDaAnalizzare][w]=minutiLavoroMattina[personaDaAnalizzare][w]+((oraUscitaMattina[personaDaAnalizzare][w]-9)*60);
        }
        else if(oraIngressoMattina[personaDaAnalizzare][w]==9)
        {
            minutiLavoroMattina[personaDaAnalizzare][w]=minutiLavoroMattina[personaDaAnalizzare][w]+((oraUscitaMattina[personaDaAnalizzare][w]-9)*60);
            if(minutoIngressoMattina[personaDaAnalizzare][w]==0){minutiLavoroMattina[personaDaAnalizzare][w]=minutiLavoroMattina[personaDaAnalizzare][w]+(minutoUscitaMattina[personaDaAnalizzare][w]-0);}
            else if(minutoIngressoMattina[personaDaAnalizzare][w]<30){minutiLavoroMattina[personaDaAnalizzare][w]=minutiLavoroMattina[personaDaAnalizzare][w]+(minutoUscitaMattina[personaDaAnalizzare][w]-30);}
            else if(minutoIngressoMattina[personaDaAnalizzare][w]<60){minutiLavoroMattina[personaDaAnalizzare][w]=minutiLavoroMattina[personaDaAnalizzare][w]+(minutoUscitaMattina[personaDaAnalizzare][w]-60);}
        }
        else if(oraIngressoMattina[personaDaAnalizzare][w]==10)
        {
            minutiLavoroMattina[personaDaAnalizzare][w]=minutiLavoroMattina[personaDaAnalizzare][w]+((oraUscitaMattina[personaDaAnalizzare][w]-10)*60);
            if(minutoIngressoMattina[personaDaAnalizzare][w]==0){minutiLavoroMattina[personaDaAnalizzare][w]=minutiLavoroMattina[personaDaAnalizzare][w]+(minutoUscitaMattina[personaDaAnalizzare][w]-0);}
            else if(minutoIngressoMattina[personaDaAnalizzare][w]<30){minutiLavoroMattina[personaDaAnalizzare][w]=minutiLavoroMattina[personaDaAnalizzare][w]+(minutoUscitaMattina[personaDaAnalizzare][w]-30);}
            else if(minutoIngressoMattina[personaDaAnalizzare][w]<60){minutiLavoroMattina[personaDaAnalizzare][w]=minutiLavoroMattina[personaDaAnalizzare][w]+(minutoUscitaMattina[personaDaAnalizzare][w]-60);}
        }

///CALCOLO TEMPO DI POMERIGGIO

        if(oraIngressoPomeriggio[personaDaAnalizzare][w]==0){errorePomeriggio[personaDaAnalizzare][w]=1;}
        else if(oraIngressoPomeriggio[personaDaAnalizzare][w]==12)
        {
            minutiLavoroPomeriggio[personaDaAnalizzare][w]=minutiLavoroPomeriggio[personaDaAnalizzare][w]+(minutoUscitaPomeriggio[personaDaAnalizzare][w]-0);
            minutiLavoroPomeriggio[personaDaAnalizzare][w]=minutiLavoroPomeriggio[personaDaAnalizzare][w]+((oraUscitaMattina[personaDaAnalizzare][w]-9)*60);
        }
        else if(oraIngressoPomeriggio[personaDaAnalizzare][w]==13)
        {
            minutiLavoroPomeriggio[personaDaAnalizzare][w]=minutiLavoroPomeriggio[personaDaAnalizzare][w]+((oraUscitaMattina[personaDaAnalizzare][w]-9)*60);
            if(minutoIngressoMattina[personaDaAnalizzare][w]==0){minutiLavoroPomeriggio[personaDaAnalizzare][w]=minutiLavoroPomeriggio[personaDaAnalizzare][w]+(minutoUscitaPomeriggio[personaDaAnalizzare][w]-0);}
            else if(minutoIngressoMattina[personaDaAnalizzare][w]<30){minutiLavoroPomeriggio[personaDaAnalizzare][w]=minutiLavoroPomeriggio[personaDaAnalizzare][w]+(minutoUscitaPomeriggio[personaDaAnalizzare][w]-30);}
            else if(minutoIngressoMattina[personaDaAnalizzare][w]<60){minutiLavoroPomeriggio[personaDaAnalizzare][w]=minutiLavoroPomeriggio[personaDaAnalizzare][w]+(minutoUscitaPomeriggio[personaDaAnalizzare][w]-60);}
        }
        else if(oraIngressoPomeriggio[personaDaAnalizzare][w]==14)
        {
            minutiLavoroPomeriggio[personaDaAnalizzare][w]=minutiLavoroPomeriggio[personaDaAnalizzare][w]+((oraUscitaMattina[personaDaAnalizzare][w]-9)*60);
            if(minutoIngressoMattina[personaDaAnalizzare][w]==0){minutiLavoroPomeriggio[personaDaAnalizzare][w]=minutiLavoroPomeriggio[personaDaAnalizzare][w]+(minutoUscitaPomeriggio[personaDaAnalizzare][w]-0);}
            else if(minutoIngressoMattina[personaDaAnalizzare][w]<30){minutiLavoroPomeriggio[personaDaAnalizzare][w]=minutiLavoroPomeriggio[personaDaAnalizzare][w]+(minutoUscitaPomeriggio[personaDaAnalizzare][w]-30);}
            else if(minutoIngressoMattina[personaDaAnalizzare][w]<60){minutiLavoroPomeriggio[personaDaAnalizzare][w]=minutiLavoroPomeriggio[personaDaAnalizzare][w]+(minutoUscitaPomeriggio[personaDaAnalizzare][w]-60);}
        }
    }

///CALCOLO DEL TEMPO NEL MESE

    for(int w=1;w<=numeroGiorni;w++)
    {
        minutiLavoroMese[personaDaAnalizzare]=minutiLavoroMese[personaDaAnalizzare]+minutiLavoroMattina[personaDaAnalizzare][w]+minutiLavoroPomeriggio[personaDaAnalizzare][w];
    }
    cout<<minutiLavoroMese[personaDaAnalizzare]<<endl<<endl;
///STAMPA DELLA RICHIESTA

    cout<<"";

///ERRORE DI TIMBRO BADGE
    for(int w=1;w<=numeroGiorni;w++)
    {
        if(erroreMattina[personaDaAnalizzare][w]==1)
        {cout<<"Il giorno "<<w<<" di mattina non e' stato timbrato il badge"<<endl;}
        if(errorePomeriggio[personaDaAnalizzare][w]==1)
        {cout<<"Il giorno "<<w<<" di pomeriggio non e' stato timbrato il badge"<<endl;}
    }
    file.close();
     system("PAUSE");
    return EXIT_SUCCESS;
}
