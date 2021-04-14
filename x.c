#include<stdio.h>
#include<stdlib.h>

void func(int a){
	//printf("a: before %d", a);
	int k;
	if(a % 3 == 0){
		k = a / 2;
	}
	else{
		k = (a+1) / 2;
	}
	printf("k: %d\n", k);
	if(k == 2){
		printf("a: %d\n", a);
	}
	else{
		a = k;
		func(a);
	}

	
}

int main(){
	
	int a = 15;
	
	func(a);
	
	return 0;
}
