#include<stdio.h>
#include<stdlib.h>

struct ogrenci{
	char isim[50];
	int no;
	int ortalama;
};

void struct_fonksiyon(struct ogrenci ben){
	printf("Ismim : %s\nNumaram : %d\nOrtalamam : %d", ben.isim, ben.no, ben.ortalama);
}

void ortalama_guncelle(struct ogrenci ben, int ort){
	printf("Ogrenci ortalamasi guncellendi...");
	ben.ortalama = ort;
}

void no_guncelle(struct ogrenci ben, int yenino){
	printf("Ogrenci no guncellendi...");
	ben.no = yenino;
}

int main(){
	
	struct ogrenci ben;
	strcpy(ben.isim,"aykut elmas");
	ben.no = 123456789;
	ben.ortalama = 90;
	
	struct_fonksiyon(ben);
	
	return 0;
}
