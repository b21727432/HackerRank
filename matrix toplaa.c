#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	
	int A[3][3], B[3][3], C[3][3];
	
	printf("A matrisinin degerlerini giriniz : ");
	int i, j;
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			scanf("%d", &A[i][j]);
		}
	}
	printf("B matrisinin degerlerini giriniz : ");
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			scanf("%d", &B[i][j]);
		}
	}
	
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			C[i][j] = A[i][j] + B[i][j];
		}
	}
	
	printf("A ve B matrisinin toplami olan C matrisinin degerleri :\n");
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			printf("%d ", C[i][j]);
		}
		printf("\n");
	}
	
	
	return 0;
}
