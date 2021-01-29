#include<stdlib.h>

int seri(int arr[], int n){
	if(n == 0){
		return arr[0];
	}
	else if(n == 1){
		return arr[1];
	}
	else if(n == 2){
		return arr[2];
	}
	else{
		return seri(arr, n-2) + seri(arr, n-3);
	}
}
	

void main(){
	
	int x[] = {3,0,2};
	int i = 0;
	for(i = 0; i < 15; i++){
		printf("%d ", seri(x,i));
	}
}
