#include<stdio.h>

void recursiveMatrixCarpim(int x, int y, int matrix[x][y], int x2, int y2, int matrix2[x2][y2], int carpim[x][y2]){
	
	static int i = 0, j = 0, k = 0;
	
	if(i >= x){
		return;
	}
		if(j < y2){
			if(k < y){
				carpim[i][j] += matrix[i][k] * matrix2[k][j];
         		k++;
         		recursiveMatrixCarpim(x, y, matrix, x2, y2, matrix2, carpim);
			}
			
			k = 0;
			j++;
			recursiveMatrixCarpim(x, y, matrix, x2, y2, matrix2, carpim);
		}
		
		j = 0;
		i++;
		recursiveMatrixCarpim(x, y, matrix, x2, y2, matrix2, carpim);
	
}


int main(){
	
	int x, y;
	printf("Birinci Matrixin satir ve sutun sayisini giriniz : ");
	scanf("%d", &x);
	scanf("%d", &y);
	
	int x2,y2;
	printf("Ikinci Matrixin satir ve sutun sayisini giriniz : ");
	scanf("%d", &x2);
	scanf("%d", &y2);
	
	if (y != x2)
    {
        printf("Matrix carpimina uygun degil.\n");
        return 0;
    }
	
	int matrix[x][y];
	int matrix2[x2][y2];
	int carpim[x][y2];
	
	printf("Birinci Matrixin degerlerini giriniz : ");
	int i,j;
	for(i = 0; i < x; i++){
		for(j = 0; j < y; j++){
			scanf("%d", &matrix[i][j]);
		}
	}
	
	printf("Ikinci Matrixin degerlerini giriniz : ");
	int i2,j2;
	for(i2 = 0; i2 < x2; i2++){
		for(j2 = 0; j2 < y2; j2++){
			scanf("%d", &matrix2[i2][j2]);
		}
	}
	
	for(i = 0; i < x; i++){
		for(j = 0; j < y2; j++){
			carpim[i][j] = 0;
		}
	}

	recursiveMatrixCarpim(x, y, matrix, x2, y2, matrix2, carpim);
	
	printf("Carpim matrixi : ");
	for(i = 0; i < x; i++){
		for(j = 0; j < y2; j++){
			printf("%d ", carpim[i][j]);
		}
		printf("\n");
	}
	
	
	return 0;
}
