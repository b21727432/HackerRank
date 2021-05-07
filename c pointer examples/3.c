#include<stdio.h>

void liste_yazdir(int* liste, int boyut){
	int i;
	for(i = 0; i < boyut; i++){
		printf("%d", liste[i]);
	}
}

int main(){
	
	
	int liste[10] = {1,2,3,4,5,6,7,8,9,0};
	liste_yazdir(liste, 10);
	
	return 0;
}
