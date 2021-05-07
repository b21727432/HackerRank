#include<stdio.h>
#include<string.h>
int karakter_sayac(char* cumle){
	int i;
	for (i = 0; cumle[i] != '\0'; ++i);
	// strlen fonksiyonu da kullanýlabilir
	return i;
}

int main(){
	
	printf("Uzunlugunu bulmak istediginiz cumleyi giriniz ....");
	char cumle[64];
	scanf("%[^\n]", cumle);
	int sayac = karakter_sayac(cumle);
	printf("Cumlenin uzunlugu : %d, cumle : %s", sayac, cumle);
	
	return 0;
}
