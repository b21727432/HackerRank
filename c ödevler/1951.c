#include<stdio.h>
#include<stdlib.h>
#include<string.h>



int main(){
	int i;
	for(i = 0; i < 10; i++){
		if(i % 2 == 0){
			printf("A");
		} else if(i % 3 == 0){
			printf("B");
		} else{
			printf("C");
		}
	}
	return 0;
}
