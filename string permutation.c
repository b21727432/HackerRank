#include<stdio.h>
#include<string.h>
void permutasyon(char * x, int sol, int sag){
	int i;
	if(sol == sag){
		printf("%s ", x);
	}else{
		for(i = sol; i <= sag ; i++){
			char temp;
    		temp = *(x+sol);
    		*(x+sol) = *(x+i);
    		*(x+i) = temp;
    		
    		permutasyon(x, sol+1, sag);
    		
    		char temp2;
    		temp2 = *(x+sol);
    		*(x+sol) = *(x+i);
    		*(x+i) = temp2;
		}
	}
}


int main(){
	
	char kelime[100];
	scanf("%s", &kelime);
	int x = strlen(kelime);
	char copykelime[x];
	strcpy(copykelime, kelime);
	
	printf("%s kelimesinin permutasyonlari :\n", copykelime);
	permutasyon(copykelime, 0, x-1);
	
	return 0;
}
