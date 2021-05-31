#include<stdio.h>
#include<stdlib.h>


int main(){
	
	char * il;
	il = malloc(64);
	printf("Turkiyeden bir il ismi giriniz : ");
	scanf("%s", il);
	
	int i = 0;
	while(il[i] != '\0'){
		i++;
	}
	printf("Girdiginiz ilin harf sayisi : %d", i);
	
	return 0;
}
