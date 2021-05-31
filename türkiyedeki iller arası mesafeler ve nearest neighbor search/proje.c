#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <time.h>

void mesafeleri_oku(int iller[81][81]){
	FILE *fp = fopen("mesafe.txt", "r"); // excel dosyasýný txte geçirdim, 81 tane satýr var, bir satýrda 81 deðer var hepsinin arasýnda boþluk var
	
	int i = 0, j = 0;
	
	char chunk[1024];
	while(fgets(chunk, sizeof(chunk), fp) != NULL) { // satýr satýr okuyorum mesafe.txt kýsmýný
		//printf("%s", chunk);
		char * pch;
		pch = strtok(chunk," "); // burda satýrý boþluklardan parçalýyorum pchde ilk numara var
		
		//iller[i][j++] = atoi(pch);
  		while (pch != NULL){ // bu while loopunun mantýgý while ile satýr sonuna kadar bosluktan böle böle tüm kelimeleri alýyoruz
  			iller[i][j++] = atoi(pch); // mesafeler string oldugu için bunu int yapmak lazým
    		pch = strtok (NULL, " ");
  		}
  		i++; // ilk þehir için okuduk i satýrýný arttýrarak diðer illere geçiyoruz
  		j = 0; 
	}
	
	/*for(i = 0; i < 81; i++){ doðru okunmuþ mu diye kontrol ediyorum.
		for(j =0; j < 81; j++){
			printf("%d ", iller[i][j]);
		}
		printf("\n");
	}*/
}

// derste öðrendiðimiz nearest neighbor methodunu kullanýyorum, iller arayý, gezilenleri eklediðim bir array ve baþlangýç noktasýný yolluyorum
void hamilton_turu_bul(int iller[81][81], int gezilenler[82], int start){
	int gezme_sayisi = 0, i, j;
	gezilenler[gezme_sayisi++] = start; // ilk ankaraya gidildi yani
	gezilenler[81] = start; // hamilton turu oldugu için en son düðüm de  baþlangýçtaki düðüm olmalý
	for(i = 0; i < 80; i++){ // ankara ile baþladýðýmýz için 81 yerine 80 tane düðüm geziyoruz 
		int min = 9999;
		int next;
		for(j = 0; j < 81; j++){ // burda 81 tane komþu arasýnda geziyoruz, en küçüðü bulup min ve next ile en küçüðü buluyoruz
			if(iller[start-1][j] < min && iller[start-1][j] != 0 && daha_once_gidilmismi(gezilenler, j)){ // daha küçük bir deðerse, 0 deðilse çünkü 0 ise kendisidir, daha once gidilmiþse eklenmemeli, daha önce gidilmezse oraya gidilmeli
				min = iller[start-1][j];
				next = j;
			}
		}

		gezilenler[gezme_sayisi++] = next + 1; // en küçüðü bulduk, onu gezilenler listesine ekledim
		start = next + 1; // þimdi startý en küçük olan düðüme eþitliyoruz
	}
	
	printf("Turkiyede Buldugum Hamilton Turu : ");
	
	for(i = 0; i < 82; i++){
		printf("%d ", gezilenler[i]);
	}
}

// gezilenler listesini bulmustuk, simdi de 82lik bir listede 81 kere gezip i ile i+1 arasýndaki mesafeyi bulup ekliyorum
void hamilton_turu_maliyet_hesapla(int gezilenler[82], int iller[81][81]){
	int i, maliyet = 0;
	for(i = 0 ; i < 81; i++){
		maliyet += iller[gezilenler[i]-1][gezilenler[i+1]-1];
	}
	printf("\nHamilton Turunun Uzunluk Degeri : %d", maliyet);
}


// bu fonksiyonla mesafenin bulundugu dugum daha once eklenmis mi? eklendiyse o dugume gitme gidilmediyse ziyaret et
int daha_once_gidilmismi(int gezilenler[82], int j){
	int i;
	for(i =0; i < 82; i++){
		// eger eklenmisse 0 dön ve baþka bir düðüm bul
		if(gezilenler[i] == j+1){
			return 0;
		}
	}
	return 1;
}

int main(){
	
	int iller[81][81];
	
	mesafeleri_oku(iller); // mesafeleri okuyup iller arrayine okudugum kýsým
	
	int start = 6;
	int gezilenler[82];
	
	hamilton_turu_bul(iller, gezilenler, start);
	
	hamilton_turu_maliyet_hesapla(gezilenler, iller);
	
}
