#include <stdio.h>


int main(void){
	
	int deger;
	int sayac1 = 0, sayac2 = 0;
	
	do{
		printf("Deger giriniz : ");
		scanf("%d", &deger);
		
		printf("Girdiginiz deger: %d\n", deger);
		
		if(deger >= 60){
			sayac1++;
		}
		else if(deger == -1){
			printf("Dongu kiriliyor...\n");
			printf("60 dan buyuk ya da esit girilen degerlerin sayisi : %d , 60 dan kucuk girilen degerlerin sayisi : %d\n", sayac1, sayac2);
			break;	
		}
		else if(deger < 0){
			printf("Hatali Deger! Sayma islemi negatif degerler icin gecerli degildir...\n");
		}
		else{
			sayac2++;
		}
		
 	}while(deger<100);{
 		
 		printf("Girdiginiz son deger: %d\n", deger);
 		
	 }
 	
 	return 0;
}
