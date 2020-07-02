
#include<string>
#include<stdlib.h>
#include<stdio.h>
#include<iostream>

using namespace std;

class iha{
	public:
		string ad;
		int ucusSayisi;
		double depodakiYakit;
		int ucusSayilari[5];
		double tuketilenYakit[5];
		
		iha(string a, double b = 50){
			
			ad = a;
			ucusSayisi = 0;
			depodakiYakit = b;
			for(int i = 0; i < 5; i++){
				ucusSayilari[i] = 0;
				tuketilenYakit[i] = 0.0;
			}
			
		}
		
		void ucusEkle(int a, double b){
			
			if(ucusSayisi >= 5 ){
				cout << ad << "aracýnda maximum ucus sayisina (5) ulasildi \n --> Bakim yapilmadan ucus eklenemez" << endl;
			}
			else{
				if(depodakiYakit < b){
					cout << ad << "aracina yeni ucus eklenemedi, Depodaki yakit yetersiz" << endl;
					
				}
				else{
					cout << ad <<" aracina yeni ucus eklendi" << endl;
					ucusSayisi = ucusSayisi + 1;
					depodakiYakit -= b;
					ucusSayilari[ucusSayisi - 1 ] = a;
					tuketilenYakit[ucusSayisi - 1 ] = b;
				}	
			}
			
		}
		
		void operator += (double const &a){
			
			if(depodakiYakit +a > 250 ){
				cout << "Yakit 250den buyuk olamaz";
			}
			else if(depodakiYakit +a < 0){
				cout << "Yakit 0 dan kucuk olamaz";
			}
			else{

				depodakiYakit = depodakiYakit + a;
				cout << ad << "aracina yakit eklendi, depodaki yakit : " <<depodakiYakit << endl;
			}
	
		}
		
		bool operator > (const iha& a){
			int first,second = 0;
			for(int i = 0; i < ucusSayisi; i++){
				first = first + ucusSayilari[i];
			}
			first = first / ucusSayisi;
			for(int y = 0; y < a.ucusSayisi; y++){
				second = second + a.ucusSayilari[y];
			}
			second = second / a.ucusSayisi;
			
			if(first > second){
				return true;
			}
			else{
				return false;
			}
			
		}
		
		
		void bakimYap(){
			
			for(int i = 0; i < ucusSayisi; i++){
				tuketilenYakit[i] = 0;
				ucusSayilari[i] = 0;
			}
			cout << ad << "Aracine Bakim Yapildi" << endl;
		}
		
		void raporVer(){
	
			if(ucusSayisi == 0){
				cout << "--> Ad :" << ad << endl;
				cout << "--> Yakit :" << depodakiYakit << "lt" << endl;
				cout << "--> Toplam ucus sayisi : 0" << endl;
				cout << "--> Ort. Yak. Tuk: 0 lt/km" << endl;
			}
			else{
				cout << "--> Ad :" << ad << endl;
				cout << "--> Yakit :" << depodakiYakit << "lt" << endl;
				cout << "--> Toplam ucus sayisi" << ucusSayisi << endl;
				
				
				cout << "-->Ucuslar:"<< endl;
				for(int i = 0; i < ucusSayisi ; i++){
					cout << "-->" << i+1 << ". ucus" << ucusSayilari[i] << "    |    " << tuketilenYakit[i] << endl;  
				}
				}
			}
			
			double getOYT(){
			int first = 0;
			for(int i = 0; i < ucusSayisi; i++){
				first = first + ucusSayilari[i];
			first = first / ucusSayisi;
			return first;
			}
		}
		
			double getYakit(){
				return depodakiYakit;
			}
		
		
		
		
		
	
};


int main(){
	
	iha m1("MX", 200);
	m1.raporVer();
	m1.ucusEkle(400, 20);
	m1.ucusEkle(540, 34);
	m1.ucusEkle(320, 18);
	m1.ucusEkle(320, 18);
	m1.ucusEkle(20, 6);
	m1.ucusEkle(38, 7);
	m1+=100;
	m1.raporVer();
	cout << "-------------------------------"<<endl;
	iha m2("TRFX");
	m2.raporVer();
	m2.ucusEkle(1930,30);
	if(m2 >m1 ){
		cout << "Ýlk arac daha cok yakit tüketiyor" << endl;
	}else{
		cout << "Ýkinci arac daha cok yakit tüketiyor" << endl;
	}
	m2.raporVer();
	m2.ucusEkle(850, 40);
	
	return 0;
	
}
