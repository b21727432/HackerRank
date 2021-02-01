#include<stdio.h>
#include<stdlib.h>
#include<string.h>



void karakter_degistir(char* dizi, char karakter1, char karakter2){
	int i;
	for(i = 0; i < strlen(dizi); i++){
		if(dizi[i] == karakter1){
			dizi[i] = karakter2;
		}
	}
	printf("%s", dizi);
}

int main(){
	
	
	char x,y;
	printf("Sirasiyla karakter1 ve karakter2 degerlerini giriniz ");
	scanf(" %c", &x);
	scanf(" %c", &y);
	
	char kelime[64] = "selam ben ornek kelimeyim";
	karakter_degistir(kelime, x, y);
	printf("%s", kelime);
	return 0;
}
	
	

