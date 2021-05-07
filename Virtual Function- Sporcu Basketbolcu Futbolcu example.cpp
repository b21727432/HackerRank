#include<iostream>
#include <string>
using namespace std;

class Sporcu{
	public:
		virtual void Bilgilerim() = 0;
		string Isim;
		int SporcuNo;
		
};

class Basketbolcu : public Sporcu{
	public:
		int boy;
		Basketbolcu(string isim, int sporcuno, int boyu){
			Isim = isim;
			SporcuNo = sporcuno;
			boy = boyu;
		}
		void Bilgilerim(string isim, int sporcuno, int boyu){
			Isim = isim;
			SporcuNo = sporcuno;
			boy = boyu;
			cout << "Bilgilerim: Ismim " << Isim << " Sporcu Numaram " << SporcuNo << " Boyum " << boy << endl;
		}
		void Bilgilerim(){
			cout << "Bilgilerim: Ismim " << Isim << " Sporcu Numaram " << SporcuNo << " Boyum " << boy << endl;
		}	
};

class Futbolcu : public Sporcu{
	public:
		string mevki;
		Futbolcu(string isim, int sporcuno, string sporcumevki){
			Isim = isim;
			SporcuNo = sporcuno;
			mevki = sporcumevki;
		}
		void Bilgilerim(string isim, int sporcuno, string sporcumevki){
			Isim = isim;
			SporcuNo = sporcuno;
			mevki = sporcumevki;
			cout << "Bilgilerim: Ismim " << Isim << " Sporcu Numaram " << SporcuNo << " Mevkim " << mevki << endl;
		}
		void Bilgilerim(){
			cout << "Bilgilerim: Ismim " << Isim << " Sporcu Numaram " << SporcuNo << " Mevkim " << mevki << endl;
		}
};

class Kaleci : public Futbolcu{
	public:
		Kaleci(string isim, int sporcuno):Futbolcu(isim, sporcuno, "Kaleci"){
			Isim = isim;
			SporcuNo = sporcuno;
		}
		void Bilgilerim(string isim, int sporcuno){
			Isim = isim;
			SporcuNo = sporcuno;
			cout << "Bilgilerim: Ismim " << Isim << " Sporcu Numaram " << SporcuNo << " Mevkim Kaleci" << endl;
		}
		void Bilgilerim(){
			cout << "Bilgilerim: Ismim " << Isim << " Sporcu Numaram " << SporcuNo << " Mevkim Kaleci" << endl;
		}
};

int main(){
	
	Futbolcu osman("osman", 75, "forvet");
	Basketbolcu cedi("cedi", 30, 190);
	Kaleci altay("altay", 11);
	
	osman.Bilgilerim();
	cedi.Bilgilerim();
	altay.Bilgilerim();
	
	osman.Bilgilerim("osman", 13, "defans");
	cedi.Bilgilerim("cedi", 29, 191);
	altay.Bilgilerim("altay", 12);
	
	return 0;
}
