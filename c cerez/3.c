#include <stdio.h>



int main(void){
	
	int toplam = 0;
	int i,j;
	for(i=12; i<=186; i+=6 ){
 		toplam+=i;
 	}
 	
 	for(j=-9; j<=78; j+=3 ){
 		toplam+=j;
 	}
 	
 	printf("12-9+18-6+24-3+30-0+36+3+42+6+...............+186+78 = %d\n", toplam);
 	
 	return 0;
}
