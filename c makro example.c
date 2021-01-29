#include<stdio.h>

#define give_info(kisaltma, code) printf("Department : %c%c%c Course Code=%d", kisaltma[0], kisaltma[1], kisaltma[2], code)


void main(){
	
	
	char ders_kisaltma[3]={'A','C','M'};
	int code=222;
	
	give_info(ders_kisaltma,code);
	
	
}
