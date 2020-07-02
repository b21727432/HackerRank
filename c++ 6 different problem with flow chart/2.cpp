#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

void buyuk_kucuk(){
	
	int sayac, buyuk, kucuk = 0;
	int sayi = 0;
	while(sayi != -1){
		cout << "Sayi Giriniz : ";
		cin >> sayi;
		if(sayi == -1){
			break;
		}
		if(sayac == 0){
			buyuk = sayi;
			kucuk = sayi;
		}
		if(sayi > buyuk){
			buyuk = sayi;
		}
		if(sayi < kucuk){
			kucuk = sayi;
		}
		sayac++;
	}
	cout << "En buyuk sayi : " << buyuk << endl;
	cout << "En kucuk sayi : " << kucuk << endl;
	
}


int main(){
	
	buyuk_kucuk();
	
	return 0;
}
