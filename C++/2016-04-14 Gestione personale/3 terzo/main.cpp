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
    cout<<contatore<<endl;

    cout<<oraUscitaMattina[11][12]<<" - ";
    cout<<minutoIngressoMattina[1][1];
//    cout<<minutoIngressoMattina[id*numeroGiorni+giornoAnalizzato];

///CALCOLI

    //CALCOLARE ORE DI LAVORO

    file.close();
}


