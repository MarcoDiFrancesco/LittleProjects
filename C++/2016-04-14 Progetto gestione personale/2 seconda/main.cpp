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

*/

int main()
{
    ifstream file;
    file.open("OrariDipendenti.txt");

    int numeroPersone=20;
    int numeroGiorni=26;

    int numeroTotale=0;
    numeroTotale=numeroGiorni*numeroPersone+50;/// DA TOGLIERE +50
    cout<<"Numero totale "<<numeroTotale<<endl;

    int id[numeroPersone];

    int giorno[numeroTotale];
    int mese[numeroTotale];
    int anno[numeroTotale];

    int oraIngressoMattina[numeroTotale];
    int minutoIngressoMattina[numeroTotale];

    int oraUscitaMattina[numeroTotale];
    int minutoUscitaMattina[numeroTotale];

    int oraIngressoPomeriggio[numeroTotale];
    int minutoIngressoPomeriggio[numeroTotale];

    int oraUscitaPomeriggio[numeroTotale];
    int minutoUscitaPomeriggio[numeroTotale];

    int giornoAnalizzato=0;
    int contatore=0;

    for(int q=1;q<numeroPersone+1;q++)
    {
        file>>id[q];

        for(int w=1;w<numeroGiorni+1;w++)
        {
            contatore=contatore+1;
        ///giornata
            char dataGiornata[10];
            file>>dataGiornata;
            sscanf(dataGiornata,"%d/%d/%d",&giorno[contatore],&mese[contatore],&anno[contatore]);
        ///mattinaIngresso
            char ingressoMattina[10];
            file>>ingressoMattina;
            if(ingressoMattina!="-")
            {sscanf(ingressoMattina,"%d:%d",&oraIngressoMattina[contatore],&minutoIngressoMattina[contatore]);}
            else
            {cout<<"Trovato! "<<contatore<<endl;}
        ///mattinaUscita
            char uscitaMattina[10];
            file>>uscitaMattina;
            sscanf(uscitaMattina,"%d:%d",&oraUscitaMattina[contatore],&minutoUscitaMattina[contatore]);
        ///pomeriggioIngresso
            char ingressoPomeriggio[10];
            file>>ingressoPomeriggio;
            sscanf(ingressoPomeriggio,"%d:%d",&oraIngressoPomeriggio[contatore],&minutoIngressoPomeriggio[contatore]);
        ///pomeriggioUscita
            char uscitaPomeriggio[10];
            file>>uscitaPomeriggio;
            sscanf(uscitaPomeriggio,"%d:%d",&oraUscitaPomeriggio[contatore],&minutoUscitaPomeriggio[contatore]);
        }
    }

    cout<<minutoIngressoMattina[0]<<" - ";
    cout<<minutoIngressoMattina[1]<<" - ";
//    cout<<minutoIngressoMattina[id*numeroGiorni+giornoAnalizzato];

///CALCOLI

    file.close();
}


