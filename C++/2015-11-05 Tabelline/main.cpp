#include <cstdlib>
#include <iostream>

using namespace std;
int main()
{
    system ("color FC");
    int tab[10],a,x;
    for(x=1;x<=10;x++)
    {
        for(a=0;a<10;a++)
        {
            tab [a]=(a+1)*x;
            cout << tab[a]<<"\t";
        }
    cout<<"\n ";
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}
