#include<stdio.h>


int main(){
	
	int size, i, a[10];
	int cift = 0, tek = 0;
	printf("dizi sayisi ");
	scanf("%d", &size);
	printf("\nogeleri girin");
	for(i = 0; i < size; i++){
		scanf("%d", &a[i]);
	}
	for(i = 0; i < size; i++){
		if(a[i] % 2 == 0){
			cift++;
		}
		else{
			tek++;
		}
	}
	
	printf("tek %d cift %d", tek, cift);
	
}
