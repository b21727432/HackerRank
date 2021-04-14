#include<stdio.h>

int ebob(int x1, int x2, int x3){
	if(x1 % x3 == 0 && x2 % x3 == 0){
		return x3;
	}
	else{
		return ebob(x1, x2, x3-1);
	}
}

int ebob2(int x1, int x2){ // 360 90 ; 90 360 
	if(x1 == 0){
		return x2;
	}
	else{
		return ebob2(x2 % x1, x1); // ebob2(90, 360) ebob2(0, 90)
	}
}


int main(){
	
	int x1 = 360, x2 = 80, x3;	
	if(x1 > x2){
		x3 = x2;
	}
	else{
		x3 = x1;
	}
	
	int ebobsonuc = ebob(x1, x2, x3);
	
	printf("ebob : %d", ebobsonuc);
	
	return 0;
}
