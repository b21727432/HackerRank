#include<stdio.h>

int main(){
	
	int girilensayi, usdegeri;
	printf("Sirasiyla sayiyi ve us degerini giriniz :");
	scanf("%d", &girilensayi);
	scanf("%d", &usdegeri);
	
	int i, carpim = 1;
	for(i = 1; i <= usdegeri; i++){
		carpim *= girilensayi;
	}
	
	printf("Sonuc : %d", carpim);
	return 0;
}
