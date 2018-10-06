#include <iostream>
using namespace std;
int main() {

float var[61] = {6, 12, 18, 6, 10, 14, 6, 12, 18, 6, 22, 18, 6, 12, 6, 6, 14, 18, 6, 10,18, 6, 12, 10, 14, 28, 6, 2, 14, 12, 18, 6, 2, 10, 22, 8, 6, 2, 16, 12,18, 6, 12, 8, 6, 12, 1, 6, 12, 28, 18, 6, 22, 18, 6, 12, 18, 6, 12, 18}; /*Valori scelti a caso*/

float flag1, flag2, media1, media2, somma1= 0, somma2= 0;
int div= 3, div2= 60;

for (int i=0; i<60; i=i+1){
      somma1 = somma1+var[i]; /*Il loop somma tutti i dati dell'array*/
}

for (int i=2; i<59; i=i+1){
      somma2 = somma2 + (var[i-1]+var[i]+var[i+1]); /*Il loop effettua la correzione*/
}

flag1 = (var[1] + var[2] + var[2])/div; /*Il primo valore e l'ultimo per comodità sono calcolati a parte*/
flag2 = (var[59] + var[59] + var[60])/div;

media1 = somma1/div2; /*Dividendo per il divisore, si ottengono le medie*/
media2 = (flag1+flag2+somma2)/div2;

cout <<"La media statistica e':" << media1 << endl;
cout <<"La media corretta e':" << media2 << endl;

system("PAUSE");
}
