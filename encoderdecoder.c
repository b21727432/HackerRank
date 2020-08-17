#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const char * sifrele(char metin[], int sifre);

int main(){
	
	
	int sifre;
	char metin[8];
	
	printf("4 basamakli sayiyi giriniz : \n");
	scanf("%d",&sifre);
	
	printf("4 veya 8 karakterli bir metin giriniz \n");
	scanf("%s",metin);
	
	printf("%d",strlen(metin));
	
	
	char secim;
	printf("1.sifrele \n2. sifre coz\n");
	scanf(" %c",&secim);
	
	switch(secim){
		
		case '1':	
			printf("sifrelenmis kelime: %s\n", sifrele(metin, sifre));
			break;
		case '2':
			printf("sifre cozumu yapilan kelime: %s\n", sifrele(metin, sifre));
			break;
		default:
			printf("hatali giris yaptiniz\n");
	}
	
	
	return 0;
}


const char * sifrele(char metin[], int sifre){
	
	char result[8];
	int _1 = (sifre / 1000) % 10;
	int _2 = (sifre / 100) % 10;
	int _3 = (sifre / 10) % 10;
	int _4 = sifre % 10;
	
	int size = strlen(metin);
	char temp;
	temp = metin[_2 - 1];
	metin[_2 - 1] = metin[_1 - 1];
	metin[_1 - 1] = temp;
	temp = metin[_3 - 1];
	metin[_3 - 1] = metin[_4 - 1];
	metin[_4 - 1] = temp;
	
	if(size == 8){
		temp = metin[_2 + 3];
		metin[_2 + 3] = metin[_1 + 3];
		metin[_1 + 3] = temp;
		temp = metin[_3 + 3];
		metin[_3 + 3] = metin[_4 + 3];
		metin[_4 + 3] =  temp;
	}
	
	return metin;
	
}
