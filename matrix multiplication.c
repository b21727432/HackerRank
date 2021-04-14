#include <stdio.h>
#include <stdlib.h>


int main(){
	
	int m, n;
	
	scanf("%d", &m);
	scanf("%d", &n);
	
	int a[m][n];
	int b[m][n];
	int carp[m][n];
	
	int i, j;
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			scanf("%d", &a[i][j]);
		}
	}
	
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			b[i][j] = a[i][j];
		}
	}
	
	
	int z;
	for(i = 0 ; i < m; i++){
		for(j = 0; j < n; j++){
			carp[i][j] = 0;
			for(z = 0; z < n; z++){
				carp[i][j] += a[i][z] * b[z][k];
			}
		}
	}
	
}
