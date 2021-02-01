#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int yinelenenBul(int dizi[], int uzunluk){
	int i, j, maxcount = 0;
	for(i = 0 ; i < uzunluk ; i++){
		int count = 1;
		for(j = i + 1; j < uzunluk ; j++){
			if(dizi[i] == dizi[j]){
				count++;
			}
		}
		if(count > maxcount){
			maxcount = count;
		}
	}
	
	for(i = 0; i < uzunluk; i++){
		int count = 1;
		for(j = i + 1; j < uzunluk; j++){
			if(dizi[i] == dizi[j]){
				count++;
			}
		}
		if(count == maxcount){
			printf("En cok tekrar edilen eleman : %d", dizi[i]);
		}
	}
	
}

	

