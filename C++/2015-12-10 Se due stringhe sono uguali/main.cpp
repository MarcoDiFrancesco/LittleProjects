#include <cstdlib>
#include <iostream>

using namespace std;

void Stampa1(){
     int n = 20;
     for(int i = 10; i <= n; i++){
cout<<i;
     }
}

void Stampa2(){
     int n = -20;
     for(int i = -10; i >= n; i--){
             printf("%d \n",i);

     }
}

void Stampa3(){
     int n = 20;
     for(int i = 10; i<= n; i++){
             printf("%d \n",i);
             i++;
     }
}

void Stampa4(){
     int n = -20;
     for(int i = -10; i>= n; i--){
             printf("%d \n",i);
             i--;
     }
}

void StampaNumeri(int nIniziale, int nFinale, int i){
     printf("%d\n",nIniziale);
     do{
            nIniziale = nIniziale + i;
            printf("%d\n",nIniziale);
     }while(nIniziale < nFinale);

}

int main(){
    printf("Stampa da 10 a 20\n");
    Stampa1();
    printf("\nStampa da -10 a -20\n");
    Stampa2();
    printf("\nStampa da 10 a 20 con +2\n");
    Stampa3();
    printf("\nStampa da 10 a 20 con -2\n");
    Stampa4();
    printf("\nStampa numeri:\n");
    StampaNumeri(2,8,3);
    system("PAUSE");
    return 0;
}

