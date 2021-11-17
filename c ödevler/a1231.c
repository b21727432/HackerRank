#include<stdio.h>

#define N 10
int a[N] = {1,2,3,4,5,6,7,8,9,10};
int *p = &a[0], *q = &a[N-1], temp;


int main(){
	while(p < q){
	temp = *p;
	*p++ = *q;
	*q-- = temp;
}
	
	int i;
	for(i = 0; i < 10; i++){
		printf("%d ", a[i]);
	}
	
	
	
	
	return 0;
}
