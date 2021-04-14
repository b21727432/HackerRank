#include<stdio.h>


int main(){
	
	int a[20];
	
	int i;
	for(i = 0; i < 20; i++){
		a[i] = rand() % 100;
	}
	
	int minimum, n = 20, j;
	
	for(i = 0; i < n - 1; i = i + 2){
		minimum = i;
		for(j = i + 2; j < n; j = j + 2){
			if(a[j] < a[minimum]){
				minimum = j;
			}
		}
		
		int temp = a[i];
		a[i] = a[minimum];
		a[minimum] = temp; 
		
		printf("\n");
		for(j = 0; j < n; j++){
			printf("%d ", a[j]);
		}
		
	}
	int maks;
	for(i = 1; i < n - 1; i = i + 2){
		maks = i;
		for(j = i + 2; j < n; j = j + 2){
			if(a[j] > a[maks]){
				maks = j;
			}
		}
		
		int temp = a[i];
		a[i] = a[maks];
		a[maks] = temp; 
		
		printf("\n");
		for(j = 0; j < n; j++){
			printf("%d ", a[j]);
		}
		
	}
	
	
	return 0;
}
