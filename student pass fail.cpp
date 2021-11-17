#include<iostream>
#include<fstream>
#include <vector>
#include <sstream>
#include <string>
#include<cstdlib>
using namespace std;

class Ogrenci{
	public:
		string isim;
		string soyisim;
		int vize;
		int final;
		float ort;
		Ogrenci(){
			
		}
		Ogrenci(string x, string y, int z, int t){
			isim = x;
			soyisim = y;
			vize = z;
			final = t;
		}
		void ortalamaHesapla(){
			ort = vize * 40.0 / 100.0 + final * 60.0 / 100.0;
		}
};

int main(){
	
	Ogrenci ogrenciler[15];
	int ogrenci_sayisi = 0;
	string line;
	ifstream veriler("veriler.txt");
	while(getline(veriler, line)){
		
		vector<string> kelimeler;
		stringstream ss(line);
		while(ss.good()){
			string substr;
   	 		getline( ss, substr, ',' );
    		kelimeler.push_back( substr );
		}
    	
    	ogrenciler[ogrenci_sayisi].isim = kelimeler[0];
    	ogrenciler[ogrenci_sayisi].soyisim = kelimeler[1];
    	
    	stringstream degree(kelimeler[2]);
    	degree >> ogrenciler[ogrenci_sayisi].vize;
    	
    	stringstream degree2(kelimeler[3]);
    	degree2 >> ogrenciler[ogrenci_sayisi].final;
    	
    	ogrenciler[ogrenci_sayisi].ortalamaHesapla();
    	ogrenci_sayisi++;
	}
	
	int kalan_sayisi = 0;
	float kalanlarin_ort = 0;
	cout << "Gecen Ogrencilerin Adi Soyadlari :" << endl;
	for(int i = 0; i < 15; i++){
		if(ogrenciler[i].ort >= 50){
			cout << "Adi : " << ogrenciler[i].isim << " Soyadi : " << ogrenciler[i].soyisim << " Vize Notu : " << ogrenciler[i].vize << " Final Notu : " << ogrenciler[i].final << " Ortalamasi : " << ogrenciler[i].ort << endl;
		} else{
			kalanlarin_ort += ogrenciler[i].ort;
			kalan_sayisi++;
		}
	} 
	cout << "Dersten kalan ogrencilerin sayisi : " << kalan_sayisi << " Kalan ogrencilerin ortalamasi : " << kalanlarin_ort / kalan_sayisi << endl;
	cout << "Final Notu Vize Notundan Buyuk Olan Ogrenciler :" << endl;
	for(int i = 0; i < 15; i++){
		if(ogrenciler[i].final > ogrenciler[i].vize){
			cout << "Final Notu Vize Notundan Buyuk Olan Ogrencinin Adi : " << ogrenciler[i].isim << " Soyadi : " << ogrenciler[i].soyisim << " Vize Notu : " << ogrenciler[i].vize << " Final Notu : " << ogrenciler[i].final << " Ortalamasi : " << ogrenciler[i].ort << endl;
		}
	}
	return 0;
}
