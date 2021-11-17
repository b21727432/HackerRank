#include<stdlib.h>
#include<stdio.h>


struct Ogrenci{
	char ogrenci_isim[10];
	int ogrenci_puan;
};

int main(){
	
	printf("Kac yarismaci giriceksiniz:");
	int yarismacisayisi;
	scanf("%d", &yarismacisayisi);
	int i;
	
	struct Ogrenci *ogrenciPointer;
	ogrenciPointer = (struct Ogrenci *)malloc(yarismacisayisi * sizeof(struct Ogrenci));
	
	for(i = 0; i < yarismacisayisi; i++){
		printf("%d. yarismacinin adini ve puanini giriniz:\n", i+1);
		scanf("%s", (ogrenciPointer + i)->ogrenci_isim);
		scanf("%d", &(ogrenciPointer + i)->ogrenci_puan);
	}
	
	FILE *fp;
	fp = fopen("yarisma.txt", "w+");
	
	for(i = 0; i < yarismacisayisi; i++){
		fprintf(fp, "Isim : %s Puan : %d\n", (ogrenciPointer+i)->ogrenci_isim, (ogrenciPointer+i)->ogrenci_puan);
	}
	
	int ortalama = 0;
	int enyuksek = 0;
	int enyuksekkisi = 0;
	for(i = 0; i < yarismacisayisi; i++){
		if((ogrenciPointer+i)->ogrenci_puan > enyuksek){
			enyuksek = (ogrenciPointer+i)->ogrenci_puan;
			enyuksekkisi = i;
		}
		ortalama += (ogrenciPointer+i)->ogrenci_puan;
	}
	float ort = (float)ortalama / (float)yarismacisayisi;
	printf("Ortalama : %.2f En Yuksek Puan : %s %d", ort, (ogrenciPointer+enyuksekkisi)->ogrenci_isim, (ogrenciPointer+enyuksekkisi)->ogrenci_puan);
	
	fprintf(fp, "Ortalama : %.2f, En Yuksek Puan : %s %d\n", ort, (ogrenciPointer+enyuksekkisi)->ogrenci_isim, (ogrenciPointer+enyuksekkisi)->ogrenci_puan);
	
	free(ogrenciPointer);
	fclose(fp);
	
	return 0;
}
