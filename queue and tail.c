#include<stdlib.h>

void main(){
	
	int arr[26];
	
	int i = 0;
	int tail = 25, head = 0;
	for(i = 0 ; i < 26; i++){
		printf("numara gir");
		int number;
		scanf("%d", &number);
		if(number % 2 == 0){
			arr[tail--] = number;
		}
		else{
			arr[head++] = number;
		}
	}
	for(i = 0; i < 26; i++){
		printf("%d ", arr[i]);
	}
	
}
