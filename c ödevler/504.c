#include<stdio.h>

int faktoriyel(int n){
	int faktoriyel = 1, i;
	for(i = 2; i <= n; i++){
		faktoriyel = faktoriyel * i;
	}
	return faktoriyel;
}

int main(){
	
	int x;
	while(1){
		printf("1 ile 10 arasinda bir sayi giriniz : ");
		scanf("%d", &x);
		if(x >= 1 && x <= 10){
			printf("Islemin sonucu %d\n", faktoriyel(x));
			break;
		} else{
			printf("Gecersiz sayi girdiniz.\n");
		}
	}
	
}
