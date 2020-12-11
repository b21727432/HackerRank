#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct NewCustomer{
	char ageGroup;
	char name[10];
};

/* ödevde musterileri listelerde tutmak için doubly linked list yapýsýný kullandým.
giriþ ve çýkýþ elementleri kullandým, front giris kýsmýný rear çýkýþ kýsmýný tutuyor
bu sayede front ile önden musterileri çýkartýp rear ile arkadan ekliyorum*/
int efront = -1, erear = -1;
int afront = -1, arear = -1;
int cfront = -1, crear = -1;
int dfront = 0;

// dolu mu deðil mi kontrol fonksiyonu
int isFull(int front, int rear) {
  if ((front == rear + 1) || (front == 0 && rear == 10 - 1)) return 1;
  return 0;
}

// boþ mu fonksiyonu
int isEmpty(int front) {
  if (front == -1) return 1;
  return 0;
}



int main(){
	
	//dosya okuma elemanlarý
	FILE *input  = fopen("input.txt", "r");
	FILE *output = fopen("output.txt", "w");
	char line[256];
	
	// yas grubuna ait lýsteler
	struct NewCustomer E[10];
	struct NewCustomer A[10];
	struct NewCustomer C[10];
	
	// gunluk rapor icin listeler
	struct NewCustomer D[100];
	
	//satirlari okuyoruz sirayla
	while (fgets(line, sizeof(line), input)) {
		// bosluklardan ayýrýyoruz strtok fonksiyonu ile
		char *token = strtok(line, " ");
		// new customer komutu geldiyse bu if komutundan ilerliyoruz
   		if(strcmp(token, "NewCustomer") == 0){
   			token = strtok(NULL, " ");
   			// yas gruplarýna gore kontrol edip if in icinde gelen komuta gore hallediyoruz
   			if(strcmp(token,"E")==0){
   				token = strtok(NULL, " ");
   				if (isFull(efront, erear))
   					// full olma durumu
    				printf("Liste dolu!!");
  				else {
  					// boyutu bir arttýrýyoruz,  listesine ekliyoruz
    				if (efront == -1)
      					efront = 0;
    				erear = (erear + 1) % 10 ;
    				E[erear].ageGroup = 'E';
    				token[strlen(token) - 1] = '\0';
    				strcpy(E[erear].name, token);
  				}
			}
			else if(strcmp(token,"A")==0){
				token = strtok(NULL, " ");
				// full olma durumu
				if (isFull(afront, arear))
    				printf("Liste dolu!!");
  				else {
  					// boyutu bir arttýrýyoruz,  listesine ekliyoruz
    				if (afront == -1)
      					afront = 0;
    				arear = (arear + 1) % 10;
    				A[arear].ageGroup = 'A';
    				token[strlen(token) - 1] = '\0';
    				strcpy(A[arear].name, token);
  				}
			}
			else{
				// geriye kalan c kýsmý için
				token = strtok(NULL, " ");
				// full olma durumu
				if (isFull(cfront, crear))
    				printf("Liste dolu!!");
  				else {
  					// boyutu bir arttýrýyoruz,  listesine ekliyoruz
    				if (cfront == -1)
      					cfront = 0;
    				crear = (crear + 1) % 10;
    				C[crear].ageGroup = 'C';
    				token[strlen(token) - 1] = '\0';
    				strcpy(C[crear].name, token);
  				}
			}
		}
		else{
			// yeni musteri degilse silme islemidir yani burda hizmet etme kýsmý
			token = strtok(NULL, " ");
   			if(strcmp(token,"E")==0){
   				token = strtok(NULL, " ");
   				// kac kisi silinceðini int haline getirdik
   				int a = atoi(token), i;
   				for(i = 0; i < a; i++){
   					// eger bossa erisim yapamayýz demek yani **** yazýcaz
   					if (isEmpty(efront)){
   						D[dfront].ageGroup = 'E';
   						strcpy(D[dfront].name,"****");
   						dfront++;
					}
  					else {
  						// bos degilse islemi gunluk listesine ekliyorum 
  						D[dfront].ageGroup = 'E';
   						strcpy(D[dfront].name,E[efront].name);
   						dfront++;
    					/*efront++;
    					if (efront > erear)
      						efront = erear = -1;*/
      						
      					// bu kýsým listeden silme islemi, frontu bir attýrarak silmiþ oluyoruz
      					if(efront == erear){
      						efront = -1;
      						erear = -1;
						  }
						else{
							efront = (efront + 1) % 10;
						}
  					}	
				}
   				
			}
			else if(strcmp(token,"A")==0){
				// yukarýdaki islemlerin aynýsýný a için yapýyorum burda
				token = strtok(NULL, " ");
				int a = atoi(token), i;
   				for(i = 0; i < a; i++){
   					if (isEmpty(afront)){
   						D[dfront].ageGroup = 'A';
   						strcpy(D[dfront].name,"****");
   						dfront++;
					}
  					else {
  						D[dfront].ageGroup = 'A';
   						strcpy(D[dfront].name,A[afront].name);
   						dfront++;
    					/*afront++;
    					if (afront > arear)
      						afront = arear = -1;*/
      					if(afront == arear){
      						afront = -1;
      						arear = -1;
						  }
						else{
							afront = (afront + 1) % 10;
						}
  					}	
				}
			}
			else{
				// yukarýdaki islemlerin aynýsýný c için yapýyorum burda 
				token = strtok(NULL, " ");
				int a = atoi(token), i;
   				for(i = 0; i < a; i++){
   					if (isEmpty(cfront)){
   						D[dfront].ageGroup = 'C';
   						strcpy(D[dfront].name,"****");
   						dfront++;
					}
  					else {
  						D[dfront].ageGroup = 'C';
   						strcpy(D[dfront].name,C[cfront].name);
   						dfront++;
    					/*cfront++;
    					if (cfront > crear)
      						cfront = crear = -1;*/
      					if(cfront == crear){
      						cfront = -1;
      						crear = -1;
						  }
						else{
							cfront = (cfront + 1) % 10;
						}
  					}	
				}
			}
		}
		
		   	
    }
    
    // bu kýsýmda ise gunluk rapor icine kaydettiðimiz islemleri yazdýrýyorum
	int i;
	for(i = 0; i < dfront; i++){
		fprintf(output,"%c %s\n", D[dfront - 1 - i].ageGroup, D[dfront - 1 - i].name);
	}
	
	fclose(input);
	fclose(output);
	
	return 0;
}
