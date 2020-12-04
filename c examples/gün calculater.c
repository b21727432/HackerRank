#include<stdio.h>
#include<stdlib.h>


int main(){
	
	
	char aylar[12][7] = {"Ocak", "Subat", "Mart", "Nisan", "Mayis", "Haziran", "Temmuz", "Agustos", "Eylul", "Ekim", "Kasim", "Aralik"};
	
	int gun,ayindex, j = 0;
	char ay[7];
	
	printf("gun ve ay giriniz : ");
	scanf("%d %s", &gun, &ay);
	
	
	for(j = 0; j < 12; j++){
		if(strcmp(aylar[j], ay) == 0){
			ayindex = j + 1;
		}
	}
	
	switch(gun){
		case 28:
			if(strcmp(ay,"nisan") == 0){
				printf("bir gun sonrasi : %d %s",1, aylar[ayindex]);
			}
			else{
				printf("bir gun sonrasi : %d %s", gun+1, ay);
			}
			break;
		case 30:
			
			if(strcmp(ay, "nisan") == 0 || strcmp(ay, "haziran") == 0 || strcmp(ay, "eylul") == 0 || strcmp(ay, "kasim") == 0){
				printf("bir gun sonrasi : %d %s", 1, aylar[ayindex]);
			}
			else{
				printf("bir gun sonrasi : %d %s", gun+1, ay);
			}
			break;
		case 31:
			
			if(strcmp(ay, "ocak") == 0 || strcmp(ay, "mart") == 0 || strcmp(ay, "mayis") == 0 || strcmp(ay, "temmuz") == 0 || strcmp(ay, "agustos") == 0 || strcmp(ay, "ekim") == 0 || strcmp(ay, "aralik") == 0){
				printf("bir gun sonrasi : %d %s", 1, aylar[ayindex]);
			}
			else{
				printf("bir gun sonrasi : %d %s", gun+1, ay);
			}
			break;
		default:
			printf("bir gun sonrasi : %d %s", gun+1, ay);
	}
	
	return 0;
}
