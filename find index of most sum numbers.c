#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int a[5] = {1,2,3,4,5};
	int enbToplam = 0;
	
	
	int i, j, toplam, k, bas, son;
	for(i = 0; i < 5; i++){
		toplam = 0;
		for(j = i; j < 5; j++){
			if(a[j] < 0){
				break;
			}
			toplam = toplam + a[j];
		}
		if(toplam > enbToplam){
				enbToplam = toplam;
				bas = i;
				son = j - 1;
			}
	}
	printf("%d %d %d", enbToplam, bas, son);
	
	return 0;
}
