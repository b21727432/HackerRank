#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Ogrenci{
	char isim[32];
	char soyisim[32];
	int vize;
	int final;
	float ort;
};

int main(){
	struct Ogrenci ogrenciler[15];
	char line[128];
	FILE* veriler = fopen("veriler.txt", "r");
	int ogrenci_sirasi = 0;
	while ( fgets( line, 128, veriler ) != NULL ) {
		
		char *satir, *isim, *soyisim, *vize, *final;
		satir = strtok(line, "\n");
        
		isim = strtok(satir, ",");
		soyisim = strtok(NULL, ",");
		vize = strtok(NULL, ",");
		final = strtok(NULL, ",");
		
		strcpy(ogrenciler[ogrenci_sirasi].isim, isim);
		strcpy(ogrenciler[ogrenci_sirasi].soyisim, soyisim);
		ogrenciler[ogrenci_sirasi].vize = atoi(vize);
		ogrenciler[ogrenci_sirasi].final = atoi(final);
		ogrenciler[ogrenci_sirasi].ort = ogrenciler[ogrenci_sirasi].vize * 40.0 / 100.0 + ogrenciler[ogrenci_sirasi].final*60.0/100.0;
		ogrenci_sirasi++;
    } 
	int i;
	int kalan_sayisi = 0;
	float kalan_ort = 0.0;
	printf("Gecen Ogrencilerin Adi Soyadi :\n");	
	for(i = 0; i < 15;i++){
		if(ogrenciler[i].ort >= 50){
			printf("Adi Soyadi : %s %s Ortalamasi : %f\n", ogrenciler[i].isim, ogrenciler[i].soyisim, ogrenciler[i].ort);
		} else{
			kalan_ort += ogrenciler[i].ort;
			kalan_sayisi++;
		}
		
	}
	printf("Kalan ogrencilerin not ortalamasi : %f\n", kalan_ort / kalan_sayisi);
	printf("Final Notu Vize Notundan Buyuk Olan Ogrenciler :\n");
	for(i = 0; i < 15; i++){
		if(ogrenciler[i].final > ogrenciler[i].vize){
			printf("Adi Soyadi : %s %s Vize Notu : %d Final Notu : %d Ortalamasi : %f\n", ogrenciler[i].isim, ogrenciler[i].soyisim, ogrenciler[i].vize, ogrenciler[i].final, ogrenciler[i].ort);
		}
	}
	return 0;
}
