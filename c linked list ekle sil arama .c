#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct ogrenci{
	int ogrno;
	char *ogradi;
	char *ogrsoyadi;
	struct ogrenci *sonraki;
}Ogrenci;


Ogrenci* ogrenci_olustur()
{
	Ogrenci* newNode = (Ogrenci*)malloc(sizeof(Ogrenci));
	printf("Ogrenci numarasini giriniz: ");
	int yeniogrno;
	scanf("%d", &yeniogrno);
	newNode->ogrno = yeniogrno;
	printf("Ogrenci adini giriniz: ");
	char ad[20];
	scanf("%s", ad);
	newNode->ogradi = malloc(strlen(ad)+1);
	strcpy(newNode->ogradi, ad);
	printf("Ogrenci soyadini giriniz: ");
	char soyad[20];
	scanf("%s", soyad);
	newNode->ogrsoyadi= malloc(strlen(soyad)+1);
	strcpy(newNode->ogrsoyadi, soyad);
	newNode->sonraki = NULL;
	return newNode;
}


void silme(Ogrenci** head, int silinenno)
{
    Ogrenci *temp = *head, *prev;
 
    if (temp != NULL && temp->ogrno == silinenno) {
        *head = temp->sonraki; // Changed head
        free(temp); // free old head
        return;
    }

    while (temp != NULL && temp->ogrno != silinenno) {
        prev = temp;
        temp = temp->sonraki;
    }
 
    if (temp == NULL)
        return;
 
    prev->sonraki = temp->sonraki;
 
    free(temp); // Free memory
}

void listele(Ogrenci** head){
	Ogrenci* current = *head;
	printf("Ogrenci Numarasi        Ogrenci adi        Soyadi        Sira No\n");
	
	while (current != NULL){
		printf("%d        %s        %s\n", current->ogrno, current->ogradi, current->ogrsoyadi);
		current = current->sonraki;
	}
}

void ekle(Ogrenci** head, Ogrenci* newNode)//function to insert data in sorted position
{
	if (*head == NULL || (*head)->ogrno >= newNode->ogrno)
	{
		newNode->sonraki = *head;
		*head = newNode;
		return;
	}
		
	Ogrenci* current = *head;
	while (current->sonraki != NULL && current->sonraki->ogrno <= newNode->ogrno){
		if(current->ogrno == newNode->ogrno){
			printf("Bu numarali ogrenci bulunuyor. Eklenemez");
			return;
		}
		current = current->sonraki;
	}
		
	newNode->sonraki = current->sonraki;
	current->sonraki = newNode;
}

void no_arama(Ogrenci** head, int arananno){
	Ogrenci* current = *head;
	int sira = 0;
	printf("Ogrenci Numarasi        Ogrenci adi        Soyadi        Sira No\n");
	while (current != NULL){
		if(current->ogrno == arananno){
			printf("%d        %s        %s        %d\n", current->ogrno, current->ogradi, current->ogrsoyadi, sira++);
		}
		current = current->sonraki;
	}
}

void ad_arama(Ogrenci** head, char * arananad){
	Ogrenci* current = *head;
	int sira = 0;
	printf("Ogrenci Numarasi        Ogrenci adi        Soyadi        Sira No\n");
	while (current != NULL){
		if(strcmp(current->ogradi,arananad)==0){
			printf("%d        %s        %s        %d\n", current->ogrno, current->ogradi, current->ogrsoyadi, sira++);
		}
		current = current->sonraki;
	}
}

void soyad_arama(Ogrenci** head, char * aranansoyad){
	Ogrenci* current = *head;
	int sira = 0;
	printf("Ogrenci Numarasi        Ogrenci adi        Soyadi        Sira No\n");
	while (current != NULL){
		if(strcmp(current->ogrsoyadi,aranansoyad) == 0){
			printf("%d        %s        %s        %d\n", current->ogrno, current->ogradi, current->ogrsoyadi, sira++);
		}
		current = current->sonraki;
	}
}


int main(){
	
	Ogrenci* head = NULL;
	
	while(1){
		printf("Seciminiz: Arama(1), Ekleme(2), Silme(3), Listeleme(4), Cikis(5) :");
		int secim;
		scanf("%d", &secim);
		if(secim == 1){
			printf("Arama kriteriniz: Numara(1), Adi(2), Soyadi(3):");
			int aramasecim;
			scanf("%d", &aramasecim);
			if(aramasecim == 1){
				printf("Ogrenci numarasini giriniz: ");
				int arananogrencino;
				scanf("%d", &arananogrencino);
				no_arama(&head, arananogrencino);
			} else if(aramasecim == 2){
				printf("Ogrenci adini giriniz: ");
				char arananogrenciad[20];
				scanf("%s", arananogrenciad);
				ad_arama(&head, arananogrenciad);
			} else if(aramasecim == 3){
				printf("Ogrenci soyadini giriniz: ");
				char arananogrencisoyad[20];
				scanf("%s", arananogrencisoyad);
				soyad_arama(&head, arananogrencisoyad);
			} else{
				printf("Gecerli bir secim yapmadiniz...\n");
				continue;
			}
		} else if(secim == 2){ // ekleme
			Ogrenci* eklenicekogrenci = ogrenci_olustur();
			ekle(&head, eklenicekogrenci);
		} else if(secim == 3){ // silme
			printf("Ogrenci numarasini giriniz:");
			int silincekno;
			scanf("%d", &silincekno);
			printf("Ilgili kaydi silmek istediginize emin misiniz?(E/H):");
			char evethayir;
			scanf(" %c", &evethayir);
			if(evethayir == 'E'){
				silme(&head, silincekno);
			} else if(evethayir == 'H'){
				continue;
			} else{
				printf("Gecerli bir secim yapmadiniz...\n");
				continue;
			}
		} else if(secim == 4){ // listemele
			listele(&head);
		} else if(secim == 5){ // çýkýþ
			printf("Programdan cikiliyor...");
			break;
		} else{
			printf("Gecerli bir secim yapmadiniz...\n");
			continue;
		}
	}
	
	return 0;
}
