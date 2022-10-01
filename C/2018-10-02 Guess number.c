#include <stdio.h>
#include <math.h>
#include <header_file>
int main()
{
    int n1 = 0, n2, test = 0; // Initializing int
    printf("Insert a number: ");
    scanf("%d",&n1);
    printf("\x1b[H\x1b[J");
    while(test == 0){
        if(n1 > 100 || n1 < 0){
            printf("Type another number: ");
            scanf("%d",&n1);
        } else {
            test = 1;
        }
    }
    test = 0;
    int tmp=0;
    printf("Guess the numer: ");
    while(test == 0){
        if(tmp==0)
        {
            scanf("%d",&n2);
            ++tmp;
        }
        if(n1>n2){
            printf("\nToo small. Type another number: ");
            scanf("%d",&n2);
        } else if(n1<n2) {
            printf("\nToo big. Type another number: ");
            scanf("%d",&n2);
        } else { 
            test = 1;
            printf("\nNumber correct\n");
        }
    }
    printf("End");
    return 0;
}
