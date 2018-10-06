#include <iostream>

using namespace std;

int main()
{
	float a;
	float b;
	int scelta;

	a=0;
	b=0;
	scelta=1;

	while(scelta!=0)
	{
		cout<<"1. Addizione fra due numeri\n";
		cout<<"2. Sottrazione fra due numeri\n";
		cout<<"3. Moltiplicazione fra due numeri\n";
		cout<<"4. Divisione fra due numeri\n";
		cout<<"5. Potenza fra due numeri\n";
		cout<<"\nInserisci la scelta: ";
		cin>>scelta;

		switch(scelta)
		{
			case 1:
				cout<<"\nImmettere primo numero: ";
				cin>>a;
				cout<<"\nImmettere secondo numero: ";
				cin>>b;
				cout<<"\nLa loro somma e': "<<a+b;
				return 0;

			case 2:
				cout<<"\nImmettere primo numero: ";
				cin>>a;
				cout<<"\nImmettere secondo numero: ";
				cin>>b;
				cout<<"\nLa loro differenza e': "<<a-b;
				return 0;

			case 3:
				cout<<"\nImmettere primo numero: ";
				cin>>a;
				cout<<"\nImmettere secondo numero: ";
				cin>>b;
				cout<<"\nIl loro prodotto e': "<<a*b;
				return 0;

			case 4:
				cout<<"\nImmettere primo numero: ";
				cin>>a;
				cout<<"\nImmettere secondo numero: ";
				cin>>b;
				cout<<"\nLa loro divisione e': "<<a/b;
				return 0;

			case 5:
				cout<<"\nImmettere primo numero: ";
				cin>>a;
				cout<<"\nImmettere la potenza: ";
				cin>>b;
				cout<<"\nLa loro potenza e': "<<(a*b); //non si riesce a fare l'operazione col ^ (non esegue)
				return 0;
		}
	}

}

