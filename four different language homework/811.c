#include<stdio.h>
#include<stdlib.h>


void bul(int matrisboyut, int matris[][matrisboyut], int* toplam){
	int i,j;
	for(i = 0; i < matrisboyut; i++){
		for(j = 0; j < i ; j++){
			*toplam += matris[i][j];
		}
	}
}

int main(){
	
	
	printf("Matris islemi icin 1, isim girmek icin 2 giriniz:");
	int secim;
	scanf("%d", &secim);
	if(secim == 1){
		int matrisboyut;
		printf("matris boyutunu giriniz : ");
		scanf("%d", &matrisboyut);
		int matris[matrisboyut][matrisboyut];
		int i,j;
		printf("Matris elemanlarini giriniz:");
		for(i = 0; i < matrisboyut; i++){
			for(j = 0; j < matrisboyut; j++){
				scanf("%d", &matris[i][j]);
			}
		}
		for(i = 0; i < matrisboyut; i++){
			for(j = 0; j < matrisboyut; j++){
				printf("   %d   ", matris[i][j]);
			}
			printf("\n");
		}
		int toplam = 0;
		bul(matrisboyut, matris, &toplam);
		printf("Toplam : %d", toplam);
	} else if(secim == 2){
		
	} else{
		printf("Yanlis islem sectiniz...");
	}
	
	return 0;
}
