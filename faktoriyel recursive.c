#include<stdio.h>
int faktoriyel(int n){
	if(n <= 1){
		return 1;
	}
	else{
		return n * faktoriyel(n - 1);
	}
	
}


int main(){
	
	int n = faktoriyel(5);
	printf("10un faktoriyeli : %d", n);
	return 0;
}
