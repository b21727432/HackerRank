#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>

using namespace std;


double ucgenAlan(double birinci_kenar, double ikinci_kenar, double aradaki_aci){
	
	double aci_radyan = 3.14 * aradaki_aci / 180.0;
	double ucgenin_alani = 0.5 * (birinci_kenar * ikinci_kenar) * sin(aci_radyan);

	return ucgenin_alani;
}
double daireAlan(double yaricap){
	
	double dairenin_alani = 3.14 * yaricap * yaricap;
	
	return dairenin_alani;
}
double dikdortgenAlan(double birinci_kenar, double ikinci_kenar){
	
	double dikdortgenin_alani = birinci_kenar * ikinci_kenar;
	
	return dikdortgenin_alani;
}
double yamukAlan(double ust_kenar, double alt_kenar, double yukseklik){
	
	double yamugun_alani = ((ust_kenar + alt_kenar)/2) * yukseklik;
	
	return yamugun_alani;
}


void alanlar(int secim){
	if(secim == 1){
		cout << "Ucgenin alanini sinus alan formulu ile(1/2 * a * b * sin(c)) hesaplamak icin iki kenar ve aralarindaki aciyi giriniz" << endl;
		double birinci_kenar;
		cout << "Birinci kenari giriniz : ";
		cin >> birinci_kenar;
		double ikinci_kenar;
		cout << "Ikinci kenari giriniz : ";
		cin >> ikinci_kenar;
		double aradaki_aci;
		cout << "Kenarlarin arasindaki aci : ";
		cin >> aradaki_aci;
		double ucgenin_alani = ucgenAlan(birinci_kenar, ikinci_kenar, aradaki_aci);
		cout << "Ucgenin Alani : " << ucgenin_alani;
	}
	else if(secim == 2){
		cout << "Dairenin alanini pi*r^2 formulu ile hesaplamak icin yaricap uzunlugunu giriniz" << endl;
		double yaricap;
		cout << "Yaricapi giriniz : ";
		cin >> yaricap;
		double dairenin_alani = daireAlan(yaricap);
		cout << "Dairenin Alani : " << dairenin_alani;
	}
	else if(secim == 3){
		cout << "Dikdortgenin alanini a x b formulu ile hesaplamak icin birinci kenari ve ikinci kenari giriniz" << endl;
		double birinci_kenar;
		cout << "Birinci kenari giriniz : ";
		cin >> birinci_kenar;
		double ikinci_kenar;
		cout << "Ikinci kenari giriniz : ";
		cin >> ikinci_kenar;
		double dortgenin_alani = dikdortgenAlan(birinci_kenar, ikinci_kenar);
		cout << "Dikdortgenin Alani : " << dortgenin_alani;
	}
	else if(secim == 4){
		cout << "Yamukun alanini (ust + alt) / 2 * yukseklik formulu ile hesaplamak icin ust kenari, alt kenari ve yuksekligi giriniz" << endl;
		double ust_kenar;
		cout << "Ust kenari giriniz : ";
		cin >> ust_kenar;
		double alt_kenar;
		cout << "Alt kenari giriniz : ";
		cin >> alt_kenar;
		double yukseklik;
		cout << "Yuksekligi giriniz : ";
		cin >> yukseklik;
		double yamugun_alani = yamukAlan(ust_kenar, alt_kenar, yukseklik);
		cout << "Yamugun Alani : " << yamugun_alani;
	}
	else if(secim == -1){
		cout << "Programdan cikiliyor";		
	}
}

int main(){
	
	cout << "Ucgenin Alani (1)" << endl;
	cout << "Daire Alani (2)" << endl;
	cout << "Diktortgen Alani (3)" << endl;
	cout << "Yamuk (4)" << endl;
	cout << "Cikis (-1)" << endl;
	cout << "Seciminiz : ";
	
	int secim;
	cin >> secim;
	alanlar(secim);
	
	return 0;
	
}
