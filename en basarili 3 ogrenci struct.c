#define boyut 10
#include<stdio.h>
#include<string.h>

struct student{
	char name[50];
	long number;
	float agno;
};

typedef struct student STD;

STD ogr[boyut];

int main(){
	
	int i;
	for(i = 0; i < 10; i++){
		printf("Ogrenci bilgilerini giriniz...\n");
		printf("Ogrenci ismi : ");
		char isim[50];
		scanf("%s", isim);
		strcpy(ogr[i].name, isim);
		printf("Ogrenci not ortalamasi : ");
		int ogrnot;
		scanf("%d", &ogrnot);
		ogr[i].agno = ogrnot;
		printf("Ogrenci Numarasi : ");
		int ogrnum;
		scanf("%d", &ogrnum);
		ogr[i].number = ogrnum;
	}
	
	int ilk, iki, uc = -999;
	int ilkindex, ikinciindex, ucuncuindex = 0;
	for(i = 0; i < 10; i++){
		if(ogr[i].agno > ilk){
			uc = iki;
            iki = ilk;
            ilk = ogr[i].agno;
            ilkindex = i;
		} else if(ogr[i].agno > iki){
			uc = iki;
            iki = ogr[i].agno;
            ikinciindex = i;
		} else if (ogr[i].agno > uc){
			uc = ogr[i].agno;
			ucuncuindex = i;
		}
            
	}
	
	printf("En basarili ilk uc ogrenci sirasiyla : %s\n%s\n%s\n", ogr[ilkindex].name, ogr[ikinciindex].name, ogr[ucuncuindex].name);
	
	
	return 0;
}
