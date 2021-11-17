#include<iostream>
using namespace std;

class Bina{
	private:
		int katSayi;
		int fiyat;
	public:
		Bina(){
			
		}
		Bina(int x, int y){
			this->katSayi = x;
			this->fiyat = y;
		}
		int getkatSayi(){
			return this->katSayi;
		}
		void setkatSayi(int x){
			this->katSayi = x;
		}
		int getfiyat(){
			return this->fiyat;
		}
		void setfiyat(int y){
			this->fiyat = y;
		}
		void ekranaYaz(){
			cout << "Bu bir binadir. Kat sayisi : " << this->getkatSayi() << " Fiyatı : " << this->getfiyat() << endl;
		}
		void ekranaYaz(string adres){
			cout << "Bu bir binadir. Kat sayisi : " << this->getkatSayi() << " Fiyatı : " << this->getfiyat() << " Adresi : " << adres << endl;
		}
};

class MustakilEv : public Bina{
	public:
		string ad;
		int fiyat;
		MustakilEv(string ad, int fiyat){
			this->ad = ad;
			this->fiyat = fiyat;
			this->setfiyat(fiyat);
			this->setkatSayi(1);
		}
		void ekranaYaz(){
			cout << "Bu bir mustakil evdir. Kat sayisi : " << this->getkatSayi() << " Fiyatı : " << this->getfiyat() << " Adi : " << this->ad <<  endl;
		}
		void ekranaYaz(string adres){
			cout << "Bu bir mustakil evdir. Kat sayisi : " << this->getkatSayi() << " Fiyatı : " << this->getfiyat() << " Adi : " << this->ad << " Adresi : " << adres << endl;
		}
};

int main(){
	
	
	Bina bina1(1,1);
	MustakilEv mustakil1("ev", 5);
	bina1.ekranaYaz();
	mustakil1.ekranaYaz();
	
	
	return 0;
}
