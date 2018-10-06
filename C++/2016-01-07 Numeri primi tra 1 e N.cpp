/*#include <iostream>

using namespace std;
int n,x,a;
int main()
{
    cout<<"Inserisci fino a che numero vuoi vedere se e primo: ";
    cin>>n;
    int arrey[n+1];
    for(x=1;x<=n;x++)
    {
        if(x=x)
        {
            cout<<x<<"\t";
        }
    }
    cout<<"\n\n\n\n";
}


#include<iostream>

using namespace std;

bool isPrime(int n) {
// Se e' pari non e' primo, fatta eccezione
// per il numero 2
if(n%2 == 0 && n!=2) return false;

// Controllo i primi scorrendo sino al massimo
// numero divisibile per n (ovvero n/2)
// Si puo' anche scorrere sino alla radice di n
for(int i=3; i<n/2; i+=2) {
if(n%i == 0) return false;
}

return true;
}

int main() {
int num, count=0;

cout << "Inserisci un numero: ";
cin >> num;


for(int i=1; i<num; i++) {
if(isPrime(i)) cout << i << endl;
}

return 0;
}
*/

#include<iostream>
#include<cstdlib>
using namespace std;

int main()
{
    cout<<"\n ";
    int max=100;
    int vettore[max+1];
    for(int i=1;i<=max;i++)
    {
        vettore[i]=1;
    }
    for(int n=2;n<=max;n++)
    {
        for(int c=n+n;c<=max;c=c+n)
        {
            vettore[c]=0;
        }
    }
    for(int i=1;i<=max;i++)
    {
        if(vettore[i]!=0)
        {
            cout<<i<<" ";
        }
    }
    cout<<"\n\n\n\n\n\n\n\n\n\n";
}

