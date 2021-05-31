#include<stdio.h>
#include<stdlib.h>

int main(){
	
	char * kelime;
	kelime = malloc(64);
	printf("Bir kelime giriniz : ");
	scanf("%[^\n]%*c", kelime);
	
	int i = 0;
	int ksayac = 0;
	while(kelime[i] != '\0'){
		if(kelime[i] == 'k'){
			ksayac++;
		}
		i++;
	}
	
	printf("Girdiginiz kelimede kulunan k harfi sayisi : %d", ksayac);
	
	return 0;
}
