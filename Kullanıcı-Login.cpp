#include<iostream>
#include <string>
using namespace std;
class Kullanici{
	
	public:
		string Uyelik;
		string UyelikBilgisi(){
			cout << "Uyelik Durumunu Giriniz: (Uye, UyeDegil)";
			cin >> Uyelik;
			return Uyelik;
		}
		
};
class Login{
	public:
		void girisYap(){
			Kullanici Kl;
			string sonuc = Kl.UyelikBilgisi();
			if(sonuc == "Uye"){
				cout << "Basarili Giris" << endl;
			}
			else if(sonuc == "UyeDegil"){
				cout << "Basarisiz Giris" << endl;
			}
			else{
				cout << "Hatali Bilgi" << endl;
			}
		}
};


int main(){
	
	Login login1;
	login1.girisYap();
	Login login2;
	login2.girisYap();
	Login login3;
	login3.girisYap();
	
	return 0;
}
