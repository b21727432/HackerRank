#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct Tarih {
	int gun;
	int ay;
	int yil;
};

struct Ilan {
	char sehir[20];
	int fiyat;
	struct Tarih tarih;
	char marka[20];
	char model[20];
	int modelyili;	
};

int size = 0;

int main(){
	
	struct Ilan* ilanlar = malloc(5 * sizeof(struct Ilan));
	
	
	while(1){
		char line[256];
		printf("Ilan bilgilerini giriniz, cikmak icin exit giriniz");
		fgets(line,256,stdin);
		if(strcmp(line, "exit\n") == 0){
			break;
		}
		else{
			char* token;
			token = strtok(line, " ");
			strcpy(ilanlar[size].sehir,token);
			
			token = strtok(NULL, " ");
			ilanlar[size].fiyat = atoi(token);
			
			token = strtok(NULL, " ");
			ilanlar[size].tarih.gun = atoi(token);
			
			token = strtok(NULL, " ");
			ilanlar[size].tarih.ay = atoi(token);
			
			token = strtok(NULL, " ");
			ilanlar[size].tarih.yil = atoi(token);
			
			token = strtok(NULL, " ");
			strcpy(ilanlar[size].marka,token);
			
			token = strtok(NULL, " ");
			strcpy(ilanlar[size].model,token);
			
			token = strtok(NULL, " ");
			ilanlar[size].modelyili = atoi(token);
			
			size += 1; 
			printf("Eklendi\n");
			
			if(size != 0 && size % 5 == 0){
				printf("Liste boyutu arttirildi.\n");
				ilanlar = (struct Ilan *) realloc(ilanlar, (5 * sizeof(struct Ilan)));
			}	
		}
	}
	
	while(1){
		printf("\nArama kriterlerini giriniz : (1:sehir, 2:fiyat, 3:tarih, 4:marka,5:model, 6: model yili, -1: cikis)");
		int secim;
		scanf("%d", &secim);
		fflush (stdin);
		if(secim == 1){
			printf("Aramak istediginiz sehri giriniz : ");
			char sehir[20];
			scanf("%s", &sehir);
			fflush (stdin);
			int len = strlen(sehir);
			char kisim[20];
			if(sehir[len - 1 ] == '*'){
				printf("%d", len);
				strncpy(kisim, sehir, len-1);
				kisim[strlen(kisim)-1] = '\0';
				int i;
				for(i = 0; i < size; i++){
					if(strstr(ilanlar[i].sehir, kisim) != NULL){
						printf("%s %d %d %d %d %s %s %d\n", ilanlar[i].sehir, ilanlar[i].fiyat, ilanlar[i].tarih.gun, ilanlar[i].tarih.ay, ilanlar[i].tarih.yil, ilanlar[i].marka, ilanlar[i].model, ilanlar[i].modelyili);
					}
				}
				
			}
			else if(sehir[0] == '*'){
				char* foo = sehir;
				foo += 1;
				int i;
				for(i = 0; i < size; i++){
					if(strstr(ilanlar[i].sehir, kisim) != NULL){
						printf("%s %d %d %d %d %s %s %d\n", ilanlar[i].sehir, ilanlar[i].fiyat, ilanlar[i].tarih.gun, ilanlar[i].tarih.ay, ilanlar[i].tarih.yil, ilanlar[i].marka, ilanlar[i].model, ilanlar[i].modelyili);
					}
				}
				
			}
			else{
				int i;
				for(i = 0; i < size; i++){
					if(strcmp(ilanlar[i].sehir, sehir) == 0){
						printf("%s %d %d %d %d %s %s %d\n", ilanlar[i].sehir, ilanlar[i].fiyat, ilanlar[i].tarih.gun, ilanlar[i].tarih.ay, ilanlar[i].tarih.yil, ilanlar[i].marka, ilanlar[i].model, ilanlar[i].modelyili);
					}
				}
			}
		}
		else if(secim == 2){
			int alt, ust;
			printf("Alt ve ust fiyat degerini giriniz(ayri ayri entera basiniz) : ");
			scanf("%d", &alt);
			fflush (stdin);

			scanf("%d", &ust);
			fflush (stdin);

			int i;
			for(i = 0; i < size; i++){
				if(ilanlar[i].fiyat >= alt && ilanlar[i].fiyat <= ust){
					printf("%s %d %d %d %d %s %s %d\n", ilanlar[i].sehir, ilanlar[i].fiyat, ilanlar[i].tarih.gun, ilanlar[i].tarih.ay, ilanlar[i].tarih.yil, ilanlar[i].marka, ilanlar[i].model, ilanlar[i].modelyili);
				}
			}
		}
		else if(secim == 3){
			printf("Alt ve ust zaman sinirini giriniz(yan yana) : ");
			
			char line[50];
			fgets(line,50,stdin);
			int altgun, altay, altyil, ustgun, ustay, ustyil;
			
			char* token;
			token = strtok(line, " ");
			altgun = atoi(token);
			token = strtok(NULL, " ");
			altay = atoi(token);
			token = strtok(NULL, " ");
			altyil = atoi(token);
			
			token = strtok(NULL, " ");
			ustgun = atoi(token);
			token = strtok(NULL, " ");
			ustay = atoi(token);
			token = strtok(NULL, " ");
			ustyil = atoi(token);
			
			int i;
			for(i = 0 ; i < size; i++){
				
				if(ilanlar[i].tarih.yil > altyil && ilanlar[i].tarih.yil < ustyil){
					printf("%s %d %d %d %d %s %s %d\n", ilanlar[i].sehir, ilanlar[i].fiyat, ilanlar[i].tarih.gun, ilanlar[i].tarih.ay, ilanlar[i].tarih.yil, ilanlar[i].marka, ilanlar[i].model, ilanlar[i].modelyili);

				}
				else if(ilanlar[i].tarih.yil == altyil){
					if(ilanlar[i].tarih.ay > altay){
						printf("%s %d %d %d %d %s %s %d\n", ilanlar[i].sehir, ilanlar[i].fiyat, ilanlar[i].tarih.gun, ilanlar[i].tarih.ay, ilanlar[i].tarih.yil, ilanlar[i].marka, ilanlar[i].model, ilanlar[i].modelyili);
					}
					else if(ilanlar[i].tarih.ay == altay){
						if(ilanlar[i].tarih.gun >= altgun){
							printf("%s %d %d %d %d %s %s %d\n", ilanlar[i].sehir, ilanlar[i].fiyat, ilanlar[i].tarih.gun, ilanlar[i].tarih.ay, ilanlar[i].tarih.yil, ilanlar[i].marka, ilanlar[i].model, ilanlar[i].modelyili);
						}
					}
				}
				else if(ilanlar[i].tarih.yil == ustyil){
					if(ilanlar[i].tarih.ay < ustay){
						printf("%s %d %d %d %d %s %s %d\n", ilanlar[i].sehir, ilanlar[i].fiyat, ilanlar[i].tarih.gun, ilanlar[i].tarih.ay, ilanlar[i].tarih.yil, ilanlar[i].marka, ilanlar[i].model, ilanlar[i].modelyili);
					}
					else if(ilanlar[i].tarih.ay == ustay){
						if(ilanlar[i].tarih.gun <= ustgun){
							printf("%s %d %d %d %d %s %s %d\n", ilanlar[i].sehir, ilanlar[i].fiyat, ilanlar[i].tarih.gun, ilanlar[i].tarih.ay, ilanlar[i].tarih.yil, ilanlar[i].marka, ilanlar[i].model, ilanlar[i].modelyili);
						}
					}
				}
				

			}
			
		}
		else if(secim == 4){
			printf("Aramak istediginiz modeli giriniz : ");
			char marka[20];
			scanf("%s", &marka);
			fflush (stdin);
			int len = strlen(marka);
			char kisim[20];
			if(marka[len - 1 ] == '*'){
				strncpy(kisim, marka, len - 1);
				kisim[strlen(kisim)-1] = '\0';
				int i;
				for(i = 0; i < size; i++){
					if(strstr(ilanlar[i].marka, kisim) != NULL){
						printf("%s %d %d %d %d %s %s %d\n", ilanlar[i].sehir, ilanlar[i].fiyat, ilanlar[i].tarih.gun, ilanlar[i].tarih.ay, ilanlar[i].tarih.yil, ilanlar[i].marka, ilanlar[i].model, ilanlar[i].modelyili);
					}
				}
				
			}
			else if(marka[0] == '*'){
				char* foo = marka;
				foo += 1;
				int i;
				for(i = 0; i < size; i++){
					if(strstr(ilanlar[i].marka, kisim) != NULL){
						printf("%s %d %d %d %d %s %s %d\n", ilanlar[i].sehir, ilanlar[i].fiyat, ilanlar[i].tarih.gun, ilanlar[i].tarih.ay, ilanlar[i].tarih.yil, ilanlar[i].marka, ilanlar[i].model, ilanlar[i].modelyili);
					}
				}
			}
			else{
				int i;
				for(i = 0; i < size; i++){
					if(strcmp(ilanlar[i].marka, marka) == 0){
						printf("%s %d %d %d %d %s %s %d\n", ilanlar[i].sehir, ilanlar[i].fiyat, ilanlar[i].tarih.gun, ilanlar[i].tarih.ay, ilanlar[i].tarih.yil, ilanlar[i].marka, ilanlar[i].model, ilanlar[i].modelyili);
					}
				}
			}
		} 	
		else if(secim == 5){
			printf("Aramak istediginiz modeli giriniz : ");
			char model[20];
			scanf("%s", &model);
			fflush (stdin);
			int len = strlen(model);
			char kisim[20];
			if(model[len - 1 ] == '*'){
				strncpy(kisim, model, len - 1);
				kisim[strlen(kisim)-1] = '\0';
				int i;
				for(i = 0; i < size; i++){
					if(strstr(ilanlar[i].model, kisim) != NULL){
						printf("%s %d %d %d %d %s %s %d\n", ilanlar[i].sehir, ilanlar[i].fiyat, ilanlar[i].tarih.gun, ilanlar[i].tarih.ay, ilanlar[i].tarih.yil, ilanlar[i].marka, ilanlar[i].model, ilanlar[i].modelyili);
					}
				}
				
			}
			else if(model[0] == '*'){
				char* foo = model;
				foo += 1;
				int i;
				for(i = 0; i < size; i++){
					if(strstr(ilanlar[i].model, kisim) != NULL){
						printf("%s %d %d %d %d %s %s %d\n", ilanlar[i].sehir, ilanlar[i].fiyat, ilanlar[i].tarih.gun, ilanlar[i].tarih.ay, ilanlar[i].tarih.yil, ilanlar[i].marka, ilanlar[i].model, ilanlar[i].modelyili);
					}
				}
			}
			else{
				int i;
				for(i = 0; i < size; i++){
					if(strcmp(ilanlar[i].model, model) == 0){
						printf("%s %d %d %d %d %s %s %d\n", ilanlar[i].sehir, ilanlar[i].fiyat, ilanlar[i].tarih.gun, ilanlar[i].tarih.ay, ilanlar[i].tarih.yil, ilanlar[i].marka, ilanlar[i].model, ilanlar[i].modelyili);
					}
				}
			}
		} 	
		else if(secim == 6){
			int alt, ust;
			printf("Alt ve ust model yili degerini giriniz : ");
			scanf("%d", &alt);
			fflush (stdin);
			scanf("%d", &ust);
			fflush (stdin);
			int i;
			for(i = 0; i < size; i++){
				if(ilanlar[i].modelyili >= alt && ilanlar[i].modelyili <= ust){
					printf("%s %d %d %d %d %s %s %d\n", ilanlar[i].sehir, ilanlar[i].fiyat, ilanlar[i].tarih.gun, ilanlar[i].tarih.ay, ilanlar[i].tarih.yil, ilanlar[i].marka, ilanlar[i].model, ilanlar[i].modelyili);
				}
			}
		} 	
		else if(secim == -1){
			printf("Exiting the program...");
			break;
		} 	
			 	
	}
	
	
	
	return 0;
}

