#include<stdio.h>

int basamaklar_toplami(int n){
	if(n == 0){ // geriye sayi kalmamis demek
		return 0;
	}
	int birler = n % 10; // birler basamagindaki sayiyi aldik
	return birler + basamaklar_toplami(n / 10); // birler basamagindaki sayi + recursive gelicek sayilar toplami
}

int main(){
	
	int sayi;
	printf("Basamak degerlerini toplamak uzere bir sayi giriniz : \n");
	scanf("%d", &sayi);
	printf("Girilen %d sayisinin basamaklari toplami = %d", sayi, basamaklar_toplami(sayi));
}
