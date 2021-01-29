#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int biggerthanzero(int arr[], int size){
	int i, count = 0;
	for(i = 0; i < size; i++){
		if(arr[i] > 0){
			count++;
		}
	}
	return count;
}

int main(){
	
	int i;
	int arr[7];
	for(i = 0; i < 7; i++){
		scanf("%d", &arr[i]);
	}
	int count = biggerthanzero(arr, 7);
	
	printf("0 dan buyuk sayilarin sayisi : %d", count);
	
	
	return 0;
}
