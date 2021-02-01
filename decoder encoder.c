#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main(){
	
	
	printf("[1] Sifreleme\n[2] Sifre Cozme\n");
	int x, i;
	printf("Seceneginiz : ");
	scanf("%d", &x);
	char kelime[64];
	printf("Kelimeyi Giriniz : ");
	scanf("%s", &kelime);
	int lenght = strlen(kelime);
	if(x == 1){
		for(i = 0; i < lenght; i++){
			kelime[i] = kelime[i] + 33;
		}
		printf("Sifreleme sonrasi kelime : %s", kelime);
		
	}
	else if(x == 2){
		for(i = 0; i < lenght; i++){
			kelime[i] = kelime[i] - 33;
		}
		printf("Sifresi Cozulen Kelime : %s", kelime);
	}
	else{
		printf("Gecersiz bir secenek girdiniz. Program Kapaniyor...");
	}
}
