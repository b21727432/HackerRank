#include<stdio.h>
#include<stdlib.h>


int main(){
	
	int a,b;
	scanf("%d", &a);
	scanf("%d", &b);
	int* apt, bpt;
	apt = &a;
	bpt = &b;
	printf("%d %d \n", a, b);
	swap(apt,bpt);
	printf("%d %d \n", a, b);
	
	
	
	return 0;
}

void swap(int* px, int* py){
	int temp;
	temp = *px;
	*px = *py;
	*py = temp;
}
