#include<iostream>
#include <string>
using namespace std;

class Ogrenci{
	private:
		int OgrenciNo;
		string OgrSinif;
	public:
		void OgrenciBilgileri();
		Ogrenci(int no, string sinif){
			OgrenciNo = no;
			OgrSinif = sinif;
		}
		Ogrenci(string sinif){
			OgrenciNo = 0;
			OgrSinif = sinif;
		}
		void setOgrenciNo(int no){
			OgrenciNo = no;
		}
		void setOgrSinif(string sinif){
			OgrSinif = sinif;
		}
		int getOgrenciNo(){
			return OgrenciNo;
		}
		string getOgrSinif(){
			return OgrSinif;
		}
};

void Ogrenci::OgrenciBilgileri(){
	if(getOgrenciNo() == 0){
		cout << "Ogrenci Numaram Yok, Sinifim " << getOgrSinif() << endl;
	}
	else{
		cout << "Ogrenci Numaram : " << getOgrenciNo() << " Sinifim " << getOgrSinif() << endl;
	}
	
}

int main(){
	
	Ogrenci ben(30718082, "Yazilim Muh 2.sinif");
	Ogrenci yarim("2.sinif");
	
	ben.OgrenciBilgileri();
	yarim.OgrenciBilgileri();
	
	return 0;
}
