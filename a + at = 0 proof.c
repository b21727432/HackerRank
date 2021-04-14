#include <stdio.h>
#include <stdlib.h>

int main(){
	
	
	int n;
	
	scanf("%d", &n);
	
	int a[n][n];
	int at[n][n];
	
	int i,j;
	for(i = 0;i < n; i++){
		for(j = 0; j < n; j++){
			scanf("%d", &a[i][j]);
		}	
	}
	
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			printf("%d", a[i][j]);
		}
		printf("\n");
	}
	
	
	
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			at[j][i] = a[i][j];
		}
	}
	
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			printf("%d", at[i][j]);
		}
		printf("\n");
	}
	
	
	int flag = 0;
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++){
			if(a[i][j] + at[i][j] != 0){
				printf("toplam 0 degil");
				flag = 1;
				break;
			}
		}
		if(flag == 1){
			break;
		}
	}
	
	
	
	return 0;
}
