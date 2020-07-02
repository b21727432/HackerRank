#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

void notlari_sirala(int ders_notlari[]){
	int gecenler, kalanlar = 0;
	int i = 0;
	while(i < 29){
		if(ders_notlari[i] > 50){
			gecenler++;
		}
		else{
			kalanlar++;
		}
		i++;
	}
	cout << "50'den yuksek alanlar : " << gecenler << endl;
	cout << "Notlari : ";
	i = 0;
	while(i < 29){
		if(ders_notlari[i] > 50){
			cout << ders_notlari[i] << " ";
		}
		i++;
	}
	cout << endl;
	cout << "50 ve alti alanlar : " << kalanlar << endl;
	cout << "Notlari : ";
	i = 0;
	while(i < 29){
		if(ders_notlari[i] <= 50){
			cout << ders_notlari[i] << " ";
		}
		i++;
	}
	
}



int main(){
	
	int ders_notlari[29];
	int sayac = 0;
	while(sayac < 29){
		cout << "Not giriniz : ";
		cin >> ders_notlari[sayac++];
	}
	
	notlari_sirala(ders_notlari);
	
	return 0;
}
