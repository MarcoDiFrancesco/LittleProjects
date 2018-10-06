#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

int main()
{
    int i;
    ofstream outputFile;
    outputFile.open("inputNumeri.txt");
    while(i!=0){
        cout<<"Inserisci un numero: ";
        cin>>i;
        if(i!=0)
        {outputFile<<i<<endl;}
    }
    outputFile.close();
}

