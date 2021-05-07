#include<stdio.h>

int arayici(int * liste, int aranicak, int boyut){
	int sayac = 0;
	int i;
	for(i = 0 ; i < boyut ; i++){
		if(liste[i] == aranicak){
			sayac++;
		}
	}
	return sayac;
}


int main(){
	
	int liste[10] = {1,2,3,4,5,6,7,7,7,9};
	int toplam = arayici(liste, 7, 10);
	printf("Toplam %d kadar %d listede var.", toplam, 7);
	
	
	return 0;
}
