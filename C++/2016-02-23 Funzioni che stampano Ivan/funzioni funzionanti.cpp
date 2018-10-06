#include <stdio.h>
#include <stdlib.h>

void stampa(int);
void stampa2(int);
void stampascelta(int,int,int);

int main()
{
    int n=10,n2=-10,controllo=0,inizio,fine,aumento;
    printf("inserisci 1 per stampare i numeri da 10 a 20\n");
    printf("inserisci 2 per stampare i numeri da -10 a -20\n");
    printf("inserisci 3 per stampare i numeri pari  da 10 a 20\n");
    printf("inserisci 4 per stampare i numeri pari  da -10 a -20\n");
    printf("inserisci 5 se vuoi stampare un elenco di numeri personalizzati\n");
    scanf("%d",&controllo);
    switch(controllo){
        case 1:
            stampa(n);
            break;
        case 2:
            stampa(n2);
            break;
        case 3:
            stampa2(n);
            break;
        case 4:
            stampa2(n2);
            break;
        case 5:
            printf("inserisci il numero da cui vuoi partire");
            scanf("%d",&inizio);
            printf("inserisci il numero a cui vuoi arrivare");
            scanf("%d",&fine);
            printf("inserisci il numero che vuoi aumentare ogni volta");
            scanf("%d",&aumento);
            stampascelta(inizio,fine,aumento);
            break;
            default:
            printf("hai inserito un numero non valido");
    }
    return 0;
}
void stampa(int n){
    if(n>0)
    for(n;n<=20;n++)
    {
        printf("%d\n",n);
    }
    else
     for(n;n>=-20;n--)
    {
        printf("%d\n",n);
    }
}
void stampa2(int n){
    if(n>0)
    for(n;n<=20;n++)
    {
        printf("%d\n",n);
        n++;
    }
    else
    for(n;n>=-20;n--)
    {
        printf("%d\n",n);
        n--;
    }
}
void stampascelta(int iniziale,int finale,int aumento){
    for(iniziale;iniziale<=finale;iniziale++){
        printf("%d\n",iniziale);
        iniziale=iniziale+aumento-1;
    }
}
