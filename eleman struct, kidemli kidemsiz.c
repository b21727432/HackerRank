#include<stdio.h>
#include<string.h>

struct eleman{
	char isim[50];
	int gun;
	int ay;
	int yil;
	float yil_toplam;
};

int main(){
	
	struct eleman elemanlar[10];	
	
	int i;
	FILE *fptr;
	fptr = fopen("personelBilgileri.txt", "w");
	for(i = 0; i < 10; i++){
		char satir[100];
		printf("Personel Bilgilerini Giriniz : ");
		scanf("%[^\n]%*c", satir);
		fprintf(fptr,"%s",satir);
		
		char * isim;
		isim = strtok(satir, ",");
		char * tarih;
		tarih = strtok(NULL, " ");
		printf("%s\n", tarih);

		char * gun;
		gun = strtok(tarih, "/");
		char * ay;
		ay = strtok(NULL, "/");
		char * yil;
		yil = strtok(NULL, "/");
		
		strcpy(elemanlar[i].isim, isim);
		
		int x = atoi(gun);
		int y = atoi(ay);
		int z = atoi(yil);
		
		int bugun = 18;
		int buay = 5;
		int buyil = 2021;
		
		if(x > bugun){
			bugun = bugun + 30;
			buay = buay - 1;
		}
		
		if(y > buay){
			buay = buay + 12;
			buyil = buyil - 1;
		}
		
		elemanlar[i].gun = bugun - x;
		elemanlar[i].ay = buay - y;
		elemanlar[i].yil = buyil - z;
		
		elemanlar[i].yil_toplam = ((float)elemanlar[i].yil * 365.0 + (float)elemanlar[i].ay * 30.0 + (float)elemanlar[i].gun)/365.0;
		
		//printf("%s %d %d %d %f", elemanlar[i].isim, elemanlar[i].gun, elemanlar[i].ay, elemanlar[i].yil, elemanlar[i].yil_toplam);
	}
	FILE *fptr2;
	fptr2 = fopen("kidemliler.txt", "w");
	for(i = 0; i < 10; i++){
		if(elemanlar[i].yil_toplam > 5.6){
			fprintf(fptr,"%s, %d yil + %d ay + %d gun\n",elemanlar[i].isim, elemanlar[i].yil, elemanlar[i].ay, elemanlar[i].gun);
		}
	}
	int min = 999;
	int minkisi;
	int max = 0;
	int maxkisi;
	for(i = 0; i < 10; i++){
		if(elemanlar[i].yil_toplam > max){
			maxkisi = i;
			max = elemanlar[i].yil_toplam;
		}
		if(elemanlar[i].yil_toplam < min){
			minkisi = i;
			min = elemanlar[i].yil_toplam;
		}
	}
	
	printf("En kidemli eleman = %.2f yil ile %s", elemanlar[maxkisi].yil_toplam, elemanlar[maxkisi].isim);
	printf("En kidemsiz eleman = %.2f yil ile %s", elemanlar[minkisi].yil_toplam, elemanlar[minkisi].isim);
	
	fclose(fptr2);
	fclose(fptr);
	return 0;
}
