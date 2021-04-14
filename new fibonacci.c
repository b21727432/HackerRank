#include<stdio.h>
int fonksiyon(int n){
	if(n == 0){
		return 1;
	}
	else if(n == 1){
		return 3;
	}
	else if(n == 2){
		return 5;
	}
	else{
		return fonksiyon(n-1) + (fonksiyon(n-3) * fonksiyon(n-3)); 
	}
}


int main(){
	int x = fonksiyon(3);
	printf("%d", x);
}
