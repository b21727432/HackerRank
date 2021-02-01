#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	

	int x,y,z;
	printf("Sirasiyla x y z degerlerini giriniz");
	scanf("%d", &x);
	scanf("%d", &y);
	scanf("%d", &z);
	min = 0
	if(x < y && x < z){
		min = x;
	}
	else if(y < x && y < z){
		min = y
	}
	else if(z < x && z < y){
		min = z
	}
	printf("Minimum number is %d", min);
	
	return 0;
}
