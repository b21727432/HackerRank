#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int a[20];
	
	int i;
	for(i = 0; i < 20; i++){
		a[i] = rand() % 100;
	}
	
	int j;
	for(j = 0; j < 20; j++){
		printf("%d ", a[j]);
	}
	
	int minimum;
	
	for(i = 0; i < 20 - 1; i++){
		minimum = i;
		for(j = i + 1; j < 20; j++){
			if(a[j] < a[minimum]){
				minimum = j;
			}
		}
		
		int temp = a[i];
		a[i] = a[minimum];
		a[minimum] = temp; 
		
		printf("\n");
		for(j = 0; j < 20; j++){
			printf("%d ", a[j]);
		}
		
	}
	
	
	return 0;
}
