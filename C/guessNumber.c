/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main()
{
    int n1 = 0, n2, test = 0;
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
    printf("Guess the numer: ");
    while(test == 0){
        scanf("%d",&n2);
        if(n1>n2){
            printf("Too small. Type another number: ");
            scanf("%d",&n2);
        } else if(n1<n2) {
            printf("Too big. Type another number: ");
            scanf("%d",&n2);
        } else { 
            test = 1;
            printf("Number correct");
        }
    }
    printf("End");
    return 0;
}
