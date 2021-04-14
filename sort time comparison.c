#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

void Insertion_Sort(int a[], int n); // Eklemeli s�ralama algoritmas�n�n bulundu�u fonksiyon
void Selection_Sort(int a[], int n); // Se�erek s�ralama algoritmas�n�n bulundu�u fonksiyon
void Bubble_Sort(int a[], int n); // Kabarc�k s�ralama algoritmas�n�n bulundu�u fonksiyon
void dizi_olustur(int a[], int n); // n adet veriyi olu�turan fonksiyon

int main()
{
	int a[100001]={0}; // Tek bir dizi kullan�lacakt�r.
	
	int n;
	printf("Dizinin uzunlugunu giriniz : ");
	scanf("%d", &n);
	
	
	clock_t start,end; // Fonksiyonlar�n s�relerini tutmak i�in gerekli
	double elapsed; // tutulan de�erleri atamak i�in gerekli
	
	dizi_olustur(a, n); // Farkl� say�lar �retecek
	
	start = clock(); // ayn� kalacak
	Insertion_Sort (a, n);
	end = clock();// ayn� kalacak
	elapsed = ((double) (end - start)) / CLOCKS_PER_SEC; // ayn� kalacak
	printf("%lf\n",elapsed);
	start = clock(); // ayn� kalacak
	Selection_Sort (a, n);
	end = clock(); // ayn� kalacak
	elapsed = ((double) (end - start)) / CLOCKS_PER_SEC; // ayn� kalacak
	printf("%lf\n",elapsed);
	start = clock(); // ayn� kalacak
	Bubble_Sort(a, n);
	end = clock(); // ayn� kalacak
	elapsed = ((double) (end - start)) / CLOCKS_PER_SEC; // ayn� kalacak
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

