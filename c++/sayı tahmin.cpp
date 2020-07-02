#include<iostream>

#include"x.h"

using namespace std;
using namespace N;


int main(){
	
	RitmikSayma x(7);
	int s, sayi;
	
	cout << " Oyuna Hosgeldiniz" << endl;
	for(s = 1; s < 4; s++){
		x.sayilariAyarla();
		x.yazdir();
		cout << " Cevabinizi giriniz : ";
		cin >> sayi;
		
		if(sayi == x.bozanSayi()){
			cout << "Tebrikler !!!" << endl;
			x += 100;
		}
		else{
			cout << "Uzgunum bilemedin" << endl;
			cout << "Kurali bozan sayi = " << x.bozanSayi() << endl; 
		}
		
	}
	
	
	
	return 0;
}
