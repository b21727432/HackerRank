

#include<stdio.h>
#include<stdlib.h>


int main(){
	
	int sayi1, sayi2;
	printf("1. sayiyi giriniz...");
	scanf("%d", &sayi1);
	printf("2. sayiyi giriniz...");
	scanf("%d", &sayi2);
	
	
	printf("Islemden once Birinci sayi : %d , ikinci sayi : %d\n",sayi1,sayi2);
	if(sayi1 < sayi2){
		sayi1 -= 5;
		sayi2 += 2;
	}
	else{
		sayi1 += 5;
		sayi2 -= 2;
	}
	printf("Islemden sonra Birinci sayi : %d , ikinci sayi : %d\n",sayi1,sayi2);
	
	
	
	return 0;
}
