#include<stdio.h>


int main(){
	
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	int copya[10];
	int i;
	for(i = 0; i < 10; i++){
		copya[i] = a[9 - i];
	}
	
	for(i = 0; i < 10; i++){
		printf("%d ", copya[i]);
	}
	
	
	return 0;
}
