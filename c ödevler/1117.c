#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main(){
	
	int i = 1, toplam = 0;
	while(1){
		int agirlik;
		printf("%d.Malzemenin agirligini girin : ", i);
		scanf("%d", &agirlik);
		if(agirlik == -1){
			printf("Kamyona %d malzeme Yuklendi.\n", i-1);
			printf("Malzemelerin Toplam Agirligi : %d", toplam);
			break;
		} else{
			toplam += agirlik;
			i = i+1;
		}
		
	}
	
	return 0;
}
