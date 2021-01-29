#include<stdlib.h>
#include<stdio.h>
#include<string.h>



int main(){
	
	int n;
	printf("N sayisini giriniz : ");
	scanf("%d", &n);
	
	float b[n], c[n];
	
	int i,y;
	printf("B arrayini giriniz : ");
	for(i = 0; i < n; i++){
		scanf("%f", &b[i]);
	}
	printf("C arrayini giriniz : ");
	for(y = 0; y < n ; y++){
		scanf("%f", &c[y]);
	}
	
	float S, bsum, csum;
	for(i = 0; i < n; i++){
		bsum += b[i];
		csum += c[i];
	}
	S = (bsum + 5) / csum;
	printf("S degeri : %f", S);
	
	
	return 0;
}
