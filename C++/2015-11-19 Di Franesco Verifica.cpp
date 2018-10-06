//Studente Marco Di Francesco

#include <cstdlib>
#include <iostream>

using namespace std;

int A[15],i,x,z,f=1;

int main()
{ 
  for(i=0;i<15;i++)
  {
    cout<<f<<" numero: ";
    cin>>A[i];
    f=f+1;
  }

x=A[0];
z=1;
for(i=0;i<15;i++)
{
  if(x!=A[i])
  {
   z=z+1;
   x=A[i];
  }
  else
  {
    x=A[i];
  }               
}

cout<<"\n--> "<<z<<"\n\n";
   
    system("PAUSE");
    return EXIT_SUCCESS;
}
