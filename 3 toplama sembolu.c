#include<stdio.h>

int main(){
	int a[5] = {-1,-2,5, 7, -4};
	int enbtoplam = 0, i, j, k, n = 5, toplam, bas, son;
	for(i = 0; i < 5; i++){
		toplam = 0;
		for(j = i; j < n; j++){
			toplam += a[j];
			if(toplam > enbtoplam){
				enbtoplam = toplam;
				bas = i;
				son = j ;
			}
		}
	}
	
	printf("\n%d %d %d", enbtoplam, bas, son);
	
	
	return 0;
}
