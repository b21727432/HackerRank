#include<stdio.h>


int main(){
	
	int A[4][4];
	
	int i,j;
	int enbuyukpozitif = -1, enkucuknegatif  = 0;
	for(i = 0; i < 4; i++){
		for(j = 0; j < 4 ; j++){
			if(j + i == 3){
				continue;
			} else if(j + i < 3){ // pozitifler
				if(A[i][j] > enbuyukpozitif){
					enbuyukpozitif = A[i][j];
				}
			}
			else if(j + i > 3){
				if(A[i][j] < enkucuknegatif){
					enkucuknegatif = A[i][j];
				}
			}
		}
		
		
	}
	
	printf("X ler arasinda en buyuk pozitif %d, Y ler arasinda en kucuk negatif %d", enbuyukpozitif, enkucuknegatif)
	return 0;
}
