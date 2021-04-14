#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

void Insertion_Sort(int a[], int n); // Eklemeli sýralama algoritmasýnýn bulunduðu fonksiyon
void Selection_Sort(int a[], int n); // Seçerek sýralama algoritmasýnýn bulunduðu fonksiyon
void Bubble_Sort(int a[], int n); // Kabarcýk sýralama algoritmasýnýn bulunduðu fonksiyon
void dizi_olustur(int a[], int n); // n adet veriyi oluþturan fonksiyon

int main()
{
	int a[100001]={0}; // Tek bir dizi kullanýlacaktýr.
	
	int n;
	printf("Dizinin uzunlugunu giriniz : ");
	scanf("%d", &n);
	
	
	clock_t start,end; // Fonksiyonlarýn sürelerini tutmak için gerekli
	double elapsed; // tutulan deðerleri atamak için gerekli
	
	dizi_olustur(a, n); // Farklý sayýlar üretecek
	
	start = clock(); // ayný kalacak
	Insertion_Sort (a, n);
	end = clock();// ayný kalacak
	elapsed = ((double) (end - start)) / CLOCKS_PER_SEC; // ayný kalacak
	printf("%lf\n",elapsed);
	start = clock(); // ayný kalacak
	Selection_Sort (a, n);
	end = clock(); // ayný kalacak
	elapsed = ((double) (end - start)) / CLOCKS_PER_SEC; // ayný kalacak
	printf("%lf\n",elapsed);
	start = clock(); // ayný kalacak
	Bubble_Sort(a, n);
	end = clock(); // ayný kalacak
	elapsed = ((double) (end - start)) / CLOCKS_PER_SEC; // ayný kalacak
	printf("%lf\n",elapsed);
} // main sonu

void dizi_olustur(int a[], int n){

	int i;
	time_t t;
	srand((unsigned) time(&t));

	for(i = 0; i < n; i++){
		a[i] = rand() % 30000;
	}
	
	
}


void Insertion_Sort(int a[], int n){
	int liste[n];
	int i, j, deger;
	
	for(i = 0; i < n; i++){
		liste[i] = a[i];
	}
	for(i = 1; i < n; i++){
		deger = liste[i];
		for(j = i - 1; j >= 0; j--){
			if(liste[j] > deger){
				liste[j+1] = liste[j];
			}
			else{
				break;
			}
		}
		liste[j + 1] = deger;
	}
	/*for(i = 0; i < n; i++){
		printf("%d\n", liste[i]);
	}*/
}


void Selection_Sort(int a[], int n){
	int liste[n];
	int i, j, minimum;
	
	for(i = 0; i < n; i++){
		liste[i] = a[i];
	}
	
	for(i = 0; i < n - 1; i++){
		minimum = i;
		for(j = i + 1; j < n; j++){
			if(liste[j] < liste[minimum]){
				minimum = j;
			}
		}
		
		int temp = liste[i];
		liste[i] = liste[minimum];
		liste[minimum] = temp; 
		
	}
	
	/*for(i = 0; i < n; i++){
		printf("%d\n", liste[i]);
	}*/
}

void Bubble_Sort(int a[], int n){
	int liste[n];
	int i, j;
	
	for(i = 0; i < n; i++){
		liste[i] = a[i];
	}
	
	for(i = 0; i < n - 1; i++){
		for(j = 0; j < n - 1 -i; j++){
			if(liste[j] > liste[j + 1]){
				int temp = liste[j];
				liste[j] = liste[j + 1];
				liste[j + 1] = temp;
			}
		}
	}
	
	/*for(i = 0; i < n; i++){
		printf("%d\n", liste[i]);
	}*/
	
}

