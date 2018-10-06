#include <cstdlib>
#include <iostream>

using namespace std;
int a, b, c, d;
int main()
{
    cout<<"\nInserisci quantita di numeri da visualizzare \n\n\t";
    cin>>a;
    cout<<"\nInserisci quantita di colonne \n\n\t";
    cin>>c;
    for(b=1;b<a;b=b+2)
    {  
        d=d+1;          
        cout<<b<<"\t";        
        if (d==c)
        {
                 cout<<"\n";
                 d=0;
        }         
    }   
    cout<<"\n";
    system("PAUSE");
    return EXIT_SUCCESS;
}
