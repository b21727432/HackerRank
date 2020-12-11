#include<stdio.h>
#include<stdlib.h>


int main(){
	
	int yolcusayisi, zaman, sinif, ucret;
	
	printf("Yolcu sayisini giriniz : ");
	scanf("%d", &yolcusayisi);
	
	printf("Zaman giriniz : ");
	scanf("%d", &zaman);
	
	printf("Sinif giriniz : ");
	scanf("%d", &sinif);
	
	if(zaman == 1){
		if(sinif == 1){
			if(yolcusayisi > 2){
				ucret = (yolcusayisi * 150) * 85 / 100;
			}
			else{
				ucret = yolcusayisi * 150;
			}
		}
		else if(sinif == 2){
			if(yolcusayisi > 2){
				ucret = (yolcusayisi * 100) * 85 / 100;
			}
			else{
				ucret = yolcusayisi * 100;
			}
		}
	}
	else if(zaman == 2){
		if(sinif == 1){
			if(yolcusayisi > 2){
				ucret = (yolcusayisi * 140) * 85 / 100;
			}
			else{
				ucret = yolcusayisi * 140;
			}
		}
		else if(sinif == 2){
			if(yolcusayisi > 2){
				ucret = (yolcusayisi * 90) * 85 / 100;
			}
			else{
				ucret = yolcusayisi * 90;
			}
		}
		
	}
	else if(zaman == 3){
		if(sinif == 1){
			if(yolcusayisi > 2){
				ucret = (yolcusayisi * 120) * 85 / 100;
			}
			else{
				ucret = yolcusayisi * 120;
			}
		}
		else if(sinif == 2){
			if(yolcusayisi > 2){
				ucret = (yolcusayisi * 70) * 85 / 100;
			}
			else{
				ucret = yolcusayisi * 70;
			}
		}
	}
	
	printf("Odemeniz gereken ucret : %d ", ucret);
	
	return 0;
}
