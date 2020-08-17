
#include<stdio.h>
#include<stdlib.h>

int olcumuTestEt(float olcumSonucu);

int main(){
	
	float olcumSonucu;
 	int sonuc;
 	do{
 		printf("Olcumu giriniz : ");
 		scanf("%f", &olcumSonucu);
 		sonuc= olcumuTestEt( olcumSonucu );
 		if( sonuc==1 ){
 			printf("Olcum pozitiftir.\n");
 		}else if( sonuc==-1 ){
 			printf("Olcum negatiftir.\n");
 		}else{
 			printf("Olcum pozitif veya negatif degildir!\n");
 		}
 	}while(sonuc!=0);
	
	return 0;
}


int olcumuTestEt(float olcumSonucu){
	if(olcumSonucu > 0.000001){
		return 1;
	}
	else if(olcumSonucu < -0.000001){
		return -1;
	}
	else if(olcumSonucu <= 0.000001 && olcumSonucu >= -0.000001){
		return 0;
	}
}
