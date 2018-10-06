#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

int main()
{
    int i=-1;

    ofstream outputFile1;
    ofstream outputFile2;
    outputFile1.open("NumeriPari.txt");
    outputFile2.open("NumeriDispari.txt");

    while(i!=0){
        cout<<"Inserisci un numero: ";
        cin>>i;
        if( (i%2)==0  )
        {outputFile1<<i<<endl;}
        else
        {outputFile2<<i<<endl;}
    }
    outputFile1.close();
    outputFile2.close();
}

