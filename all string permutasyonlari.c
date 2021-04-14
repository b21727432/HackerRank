#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void yer_degistir(char* harf1, char* harf2){
	char gecici;
    gecici = *harf1;
    *harf1 = *harf2;
    *harf2 = gecici;
}


void permutasyon_hesapla(char* hesaplanicak_kelime, int i, int n){
	int sayac;
	
	if(i == n){ // bitiþ bulunduysa
		printf("%s ", hesaplanicak_kelime);
	}
	else{
		for(sayac = i; sayac <= n; sayac++){
			yer_degistir((hesaplanicak_kelime + i), (hesaplanicak_kelime + sayac)); // ileri gidiþ
			permutasyon_hesapla(hesaplanicak_kelime, i+1 , n);
			yer_degistir((hesaplanicak_kelime + i), (hesaplanicak_kelime + sayac)); // geri gidiþ 
		}
	}
}


void main(){
	
	char girilen_kelime[64];
	printf("Permutasyonlari hesaplanicak kelimeyi giriniz : ");
	scanf("%s", &girilen_kelime);
	
	int uzunluk = strlen(girilen_kelime);
	printf("Girilen kelimenin uzunlugu : %d", uzunluk);
	
	char kopya_kelime[uzunluk + 1];
	int i = 0;
	for(i = 0; i < uzunluk; i++){
		kopya_kelime[i] = girilen_kelime[i];
	}
	kopya_kelime[uzunluk] = '\0';
	printf("%s", kopya_kelime);
	
	printf("%s kelimesinin tum permutasyonlari : \n");
	permutasyon_hesapla(kopya_kelime, 0, uzunluk - 1);
	
}
