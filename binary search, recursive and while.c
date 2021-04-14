#include <stdio.h>
#include <stdlib.h>

int ikili_arama(int a[], int baslangic, int bitis, int aranan){
	if(bitis >= baslangic){
		int orta = baslangic + (bitis - baslangic) / 2;
	
		if(a[orta] == aranan){
			return orta;
		}
	
		if(a[orta] > aranan){
			return ikili_arama(a, baslangic, orta - 1, aranan);
		}
	
		if(a[orta] < aranan){
			return ikili_arama(a, orta + 1, bitis, aranan);
		}
	}	
}
int ikili_arama2(int a[], int baslangic, int bitis, int aranan){
	while(baslangic <= bitis){
		int mid = baslangic + (bitis - baslangic) / 2;
		if(a[mid] == hedef){
			return mid;
		}
		else if(hedef > a[mid]){
			baslangic = mid + 1;
		}
		else{
			bitis = mid - 1;
		}
	}
}

	
	

//1 5 10 15 24 42 56 78 98 112 123 144


int main(){
	
	int a[20];
	
	int i;
	for(i = 0; i < 20; i++){
		a[i] = rand() % 100;
	}
	
	int minimum, j;
	
	for(i = 0; i < 20 - 1; i++){
		minimum = i;
		for(j = i + 1; j < 20; j++){
			if(a[j] < a[minimum]){
				minimum = j;
			}
		}
		
		int temp = a[i];
		a[i] = a[minimum];
		a[minimum] = temp; 
		
	}
	
	
	
	for(i = 0; i < 20; i++){
		printf("%d\n", a[i]);
	}
	
	int bulundu = ikili_arama(a, 0, 19, 95);
	printf("\n 61 in bulundugu index : %d", bulundu);
	
	return 0;
}
