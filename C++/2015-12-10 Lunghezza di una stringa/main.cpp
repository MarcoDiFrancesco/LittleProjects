#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
    cout<<"Inserisci una stringa: ";
    char string[100];
    cin.getline(string,100); //oppure uso "gets" per prendere direttamente tutta la stringa sempre tra parentesi ma senza il numero di caratteri
    int n=0,i=0; //"N" è il contattore "i" è la funzione che incrementa string al carattere successivo
    while(string[i]!='\0')
    {
        i=i+1;
        n=n+1;
    }
    //return n;
    cout<<"La stringa e lunga "<<n<<" caratteri"<<endl<<endl; 
    system("PAUSE");
    return EXIT_SUCCESS;
}
