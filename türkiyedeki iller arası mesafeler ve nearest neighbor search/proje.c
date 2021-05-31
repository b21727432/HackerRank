#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <time.h>

void mesafeleri_oku(int iller[81][81]){
	FILE *fp = fopen("mesafe.txt", "r"); // excel dosyas�n� txte ge�irdim, 81 tane sat�r var, bir sat�rda 81 de�er var hepsinin aras�nda bo�luk var
	
	int i = 0, j = 0;
	
	char chunk[1024];
	while(fgets(chunk, sizeof(chunk), fp) != NULL) { // sat�r sat�r okuyorum mesafe.txt k�sm�n�
		//printf("%s", chunk);
		char * pch;
		pch = strtok(chunk," "); // burda sat�r� bo�luklardan par�al�yorum pchde ilk numara var
		
		//iller[i][j++] = atoi(pch);
  		while (pch != NULL){ // bu while loopunun mant�g� while ile sat�r sonuna kadar bosluktan b�le b�le t�m kelimeleri al�yoruz
  			iller[i][j++] = atoi(pch); // mesafeler string oldugu i�in bunu int yapmak laz�m
    		pch = strtok (NULL, " ");
  		}
  		i++; // ilk �ehir i�in okuduk i sat�r�n� artt�rarak di�er illere ge�iyoruz
  		j = 0; 
	}
	
	/*for(i = 0; i < 81; i++){ do�ru okunmu� mu diye kontrol ediyorum.
		for(j =0; j < 81; j++){
			printf("%d ", iller[i][j]);
		}
		printf("\n");
	}*/
}

// derste ��rendi�imiz nearest neighbor methodunu kullan�yorum, iller aray�, gezilenleri ekledi�im bir array ve ba�lang�� noktas�n� yolluyorum
void hamilton_turu_bul(int iller[81][81], int gezilenler[82], int start){
	int gezme_sayisi = 0, i, j;
	gezilenler[gezme_sayisi++] = start; // ilk ankaraya gidildi yani
	gezilenler[81] = start; // hamilton turu oldugu i�in en son d���m de  ba�lang��taki d���m olmal�
	for(i = 0; i < 80; i++){ // ankara ile ba�lad���m�z i�in 81 yerine 80 tane d���m geziyoruz 
		int min = 9999;
		int next;
		for(j = 0; j < 81; j++){ // burda 81 tane kom�u aras�nda geziyoruz, en k����� bulup min ve next ile en k����� buluyoruz
			if(iller[start-1][j] < min && iller[start-1][j] != 0 && daha_once_gidilmismi(gezilenler, j)){ // daha k���k bir de�erse, 0 de�ilse ��nk� 0 ise kendisidir, daha once gidilmi�se eklenmemeli, daha �nce gidilmezse oraya gidilmeli
				min = iller[start-1][j];
				next = j;
			}
		}

		gezilenler[gezme_sayisi++] = next + 1; // en k����� bulduk, onu gezilenler listesine ekledim
		start = next + 1; // �imdi start� en k���k olan d���me e�itliyoruz
	}
	
	printf("Turkiyede Buldugum Hamilton Turu : ");
	
	for(i = 0; i < 82; i++){
		printf("%d ", gezilenler[i]);
	}
}

// gezilenler listesini bulmustuk, simdi de 82lik bir listede 81 kere gezip i ile i+1 aras�ndaki mesafeyi bulup ekliyorum
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
		// eger eklenmisse 0 d�n ve ba�ka bir d���m bul
		if(gezilenler[i] == j+1){
			return 0;
		}
	}
	return 1;
}

int main(){
	
	int iller[81][81];
	
	mesafeleri_oku(iller); // mesafeleri okuyup iller arrayine okudugum k�s�m
	
	int start = 6;
	int gezilenler[82];
	
	hamilton_turu_bul(iller, gezilenler, start);
	
	hamilton_turu_maliyet_hesapla(gezilenler, iller);
	
}
