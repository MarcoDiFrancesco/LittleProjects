#include <iostream>

using namespace std;

void Stampa1(){
     int n = 20;
     for(int i = 10; i <= n; i++){
cout<<i<<endl;
     }
}

void Stampa2(){
     int n = -20;
     for(int i = -10; i >= n; i--){
cout<<i<<endl;

     }
}

void Stampa3(){
     int n = 20;
     for(int i = 10; i<= n; i++){
cout<<i<<endl;
             i++;
     }
}

void Stampa4(){
     int n = -20;
     for(int i = -10; i>= n; i--){
cout<<i<<endl;
             i--;
     }
}

void StampaNumeri(int nIniziale, int nFinale, int i){
     cout<<nIniziale<<endl;
     do{
            nIniziale = nIniziale + i;
            cout<<nIniziale<<endl;
     }while(nIniziale < nFinale);
}

int main(){
    cout<<"Stampa da 10 a 20\n";
    Stampa1();
    cout<<"\nStampa da -10 a -20\n";
    Stampa2();
    cout<<"\nStampa da 10 a 20 con +2\n";
    Stampa3();
    cout<<"\nStampa da 10 a 20 con -2\n";
    Stampa4();
    cout<<"\nStampa numeri:\n";
    StampaNumeri(2,8,3);
    system("PAUSE");
    return 0;
}
