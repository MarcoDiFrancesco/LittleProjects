#include <cstdlib>
#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

struct giornata
{
float giorno;
float mese;
float anno;
};

struct mattinaIngresso
{
float minutoIngressoMattina;
float oraIngressoMattina;
};

struct mattinaUscita
{
float minutoUscitaMattina;
float oraUscitaMattina;
};


struct pomeriggioIngresso
{
float oraIngressoPomeriggio;
float minutoIngressoPomeriggio;
};

struct pomeriggioUscita
{
float oraUscitaPomeriggio;
float minutoUscitaPomeriggio;
};

/*
numeroGiorni
numeroPersone

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
*/

int main()
{
    ifstream file;
    file.open("OrariDipendenti.txt");

    int numeroPersone=20;

    for(int q=0;q<numeroPersone;q++)
    {
    int id;
    file>>id;

    int numeroGiorni=21;///-----------------------------------------------------------------
    for(int w=0;w<numeroGiorni;w++)
    {
///giornata
    giornata g;
    char dataGiornata[10];
    file>>dataGiornata;
    sscanf(dataGiornata,"%d/%d/%d",&g.giorno,&g.mese,&g.anno);
///mattinaIngresso
    mattinaIngresso mi;
    char ingressoMattina[10];
    file>>ingressoMattina;
    sscanf(ingressoMattina,"%d:%d",&mi.oraIngressoMattina,&mi.minutoIngressoMattina);
///mattinaUscita
    mattinaUscita mu;
    char uscitaMattina[10];
    file>>uscitaMattina;
    sscanf(uscitaMattina,"%d:%d",&mu.oraUscitaMattina,&mu.minutoUscitaMattina);
///pomeriggioIngresso
    pomeriggioIngresso pi;
    char ingressoPomeriggio[10];
    file>>ingressoPomeriggio;
    sscanf(ingressoPomeriggio,"%d:%d",&pi.oraIngressoPomeriggio,&pi.minutoIngressoPomeriggio);
///pomeriggioUscita
    pomeriggioUscita pu;
    char uscitaPomeriggio[10];
    file>>uscitaPomeriggio;
    sscanf(uscitaPomeriggio,"%d:%d",&pu.oraUscitaPomeriggio,&pu.minutoUscitaPomeriggio);


    cout<<mi.oraIngressoMattina;

/*  NON FUNZIONA, HO TOLTO TUTTE LE DICHIARAZIONI DELLE VARIABILI
    if(anno<10){cout<<"0"<<anno<<"/";}else{cout<<anno<<"/";}
    if(mese<10){cout<<"0"<<mese<<"/";}else{cout<<mese<<"/";}
    if(giorno<10){cout<<"0"<<giorno;}else{cout<<giorno;}
    if(oraIngressoMattina<10){cout<<" Ent mat="<<"0"<<oraIngressoMattina<<":";}else{cout<<" Ent mat="<<oraIngressoMattina<<":";}
    if(minutoIngressoMattina<10){cout<<"0"<<minutoIngressoMattina;}else{cout<<minutoIngressoMattina;}
    if(oraUscitaMattina<10){cout<<" Usc mat="<<"0"<<oraUscitaMattina<<":";}else{cout<<" Usc mat="<<oraUscitaMattina<<":";}
    if(minutoUscitaMattina<10){cout<<"0"<<minutoUscitaMattina;}else{cout<<minutoUscitaMattina;}
    if(oraIngressoPomeriggio<10){cout<<" Ent pom="<<"0"<<oraIngressoPomeriggio<<":";}else{cout<<" Ent pom="<<oraIngressoPomeriggio<<":";}
    if(minutoIngressoPomeriggio<10){cout<<"0"<<minutoIngressoPomeriggio;}else{cout<<minutoIngressoPomeriggio;}
    if(oraUscitaPomeriggio<10){cout<<" Usc pom="<<"0"<<oraUscitaPomeriggio<<":";}else{cout<<" Usc pom="<<oraUscitaPomeriggio<<":";}
    if(minutoUscitaPomeriggio<10){cout<<"0"<<minutoUscitaPomeriggio;}else{cout<<minutoUscitaPomeriggio;}
*/
    }
    }


///CALCOLI



    file.close();
}
