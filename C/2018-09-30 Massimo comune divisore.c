#include <stdio.h>
#include <stdlib.h>

int main(){
	int n1,n2,mcd,min =0;
	int counter=1;
	scanf("%d",&n1);
	scanf("%d",&n2);
	if(n1<=n2){
		min=n1;
	} else {
		min=n2;
	}
	while(counter <= min){
		if(((n1/counter)*counter == n1) && ((n2/counter)*counter == n2)){
			mcd=counter;
		}
		counter++;
	}
	printf("MCD: %d", mcd);
  return 0;
}
