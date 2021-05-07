#include<stdio.h>
#include<string.h>
int karakter_sayac(char* cumle){
	int i;
	for (i = 0; cumle[i] != '\0'; ++i);
	return i;
}

int main(){
	
	
	char cumle[64];
	scanf("%[^\n]", cumle);
	int sayac = karakter_sayac(cumle);
	printf("%d, %s", sayac, cumle);
	
	return 0;
}
