#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main(){
	
	int aracsayisi = 0;
	
	while(1){
		printf("Arac Girisi(1)\n");
		printf("Arac Cikisi(2)\n");
		printf("Program Cikisi(-1)\n");
		printf("Seciminiz : ");
		int secim;
		scanf("%d", &secim);
	
		if(secim == 1){
			if(aracsayisi == 20){
				printf("Otopark Dolu. Ilk olarak Arac Cikisi Yapin\n");
			} else{
				char plaka[64];
				printf("Arac plakasini girin : ");
				scanf("%s", plaka);
				fflush(stdin);
				aracsayisi++;
				printf("Iceride toplam %d arac var.\n", aracsayisi);
			}
		} else if(secim == 2){
			char plaka[64];
			printf("Arac plakasini giriniz : ");
			scanf("%s", plaka);
			fflush(stdin);
			float saat;
			printf("Kac saat kaldiginizi giriniz : ");
			scanf("%f", &saat);
			if(saat <= 1){
				printf("5 TL ödeyin.\n");
			} else if(saat <= 2){
				printf("10 TL ödeyin.\n");
			} else if(saat <= 3){
				printf("15 TL ödeyin.\n");
			} else if(saat > 3){
				printf("40 TL ödeyin.\n");
			}
			aracsayisi--;
		} else if(secim == -1){
			break;
		} else{
			printf("Duzgun secim yapmadiniz...\n");
		}
	}
	
	
	
	return 0;
}
