#include<stdio.h>


void main(){
	
	
	
	int x = 5, y = 5;
	int matrix[x][y];
	
	printf("Birinci Matrixin degerlerini giriniz : ");
	int i,j;
	for(i = 0; i < x; i++){
		for(j = 0; j < y; j++){
			scanf("%d", &matrix[i][j]);
		}
	}
	int max = 0;
	for(i = 0; i < x; i++){
		for(j = 0; j < y; j++){
			if(matrix[i][j] > max){
				max = matrix[i][j];
			}
		}
	}
	if(max % 2 == 0){
		printf("En buyuk cift");
	}
	else{
		printf("En buyuk tek");
	}
}
