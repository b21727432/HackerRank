#include<iostream>
using namespace std;
int secenek = 0;
float BUTCE = 0;
float ANLIK = 0;
float CUZDAN = 100;
float PARA = 0;
void icecek();
void yiyecek();
void ekstra();
void odemeekrani();
void siparis() {
	ANLIK = 0;
	cout << "1.Icecek\n2.Yiyecek\n3.Ekstra\n4.Siparisi Bitir\n\nToplam Fiyat:" << BUTCE << endl << endl;
	cin >> secenek;
	system("cls");
	if (secenek == 1)
		icecek();
	else if (secenek == 2)
		yiyecek();
	else if (secenek == 3)
		ekstra();
	else if (secenek == 4) {
		cout << "Toplam tutariniz :" << BUTCE << "\n\nsiparisi iptal etmek icin 1'e basiniz siparisi odemek icin 2 ye basip tutari giriniz\n\n";
		cin >> secenek;
		while (secenek != 2 && secenek != 1) {
			system("cls");
			cout << "Hatali tuslama yaptiniz,siparisi iptal etmek icin 1'e basiniz siparisi odemek icin 2 ye basip tutari giriniz\n\n";
			cout << "Toplam tutariniz :" << BUTCE <<"\n\n";
			cin >> secenek;
		}
		if (secenek == 1)
			exit;
		else
			odemeekrani();
	}
	else{
		cout << ("Hatali Kodlama yaptiniz tekrar deneyiniz \n\n");
        siparis(); }
}
void icecek() {
	system("cls");
	cout << "1.Su=1.00                    2.Cay=1.50\n\n3.Kahve=1.75                 4.Kola=3.50\n\n5.Fanta=3.50                 6.Gazoz=3.50\n\n7.PortakalliMeyveSuyu=2.00   8.ElmaliMeyveSuyu=2.00\n\n9.VisneliMeyveSuyu=2.00      10.KarisikMeyveSuyu=2.00\n\n11.Geri Don\n\nAnlik fiyat:" << ANLIK << "\n\n\n";
	cin >> secenek;
	switch (secenek) {
	case 0:
	case 1:
		ANLIK = ANLIK + 1;
		icecek();
		break;
	case 2:
		ANLIK = ANLIK + 1.50;
		icecek();
		break;
	case 3:
		ANLIK = ANLIK + 1.75;
		icecek();
		break;
	case 4:
		ANLIK = ANLIK + 3.50;
		icecek();
		break;
	case 5:
		ANLIK = ANLIK + 3.50;
		icecek();
		break;
	case 6:
		ANLIK = ANLIK + 3.50;
		icecek();
		break;
	case 7:
		ANLIK = ANLIK + 2.00;
		icecek();
		break;
	case 8:
		ANLIK = ANLIK + 2.00;
		icecek();
		break;
	case 9:
		ANLIK = ANLIK + 2.00;
		icecek();
		break;
	case 10:
		ANLIK = ANLIK + 2.00;
		icecek();
		break;
	case 11:
		BUTCE = BUTCE + ANLIK;
		system("cls");
		siparis();
		break;
	default :
	icecek();
	}
}
void yiyecek() {
	system("cls");
	cout << "1.Tost=4.50                    2.SucukluTost=5.50\n\n3.PeynirliBorek=8.00                 4.KiymaliBorek=8.00\n\n5.MiniPizza=12.00                 6.Patso = 4.50\n\n7.KahvaltiTepsisi=12.00  8.Sandvic = 9.00\n\n9.Geri Don\n\nAnlik fiyat:" << ANLIK << "\n\n\n";
	cin >> secenek;
	switch (secenek) {
	case 0:
	case 1:
		ANLIK = ANLIK + 4.50;
		yiyecek();
		break;
	case 2:
		ANLIK = ANLIK + 5.50;
		yiyecek();
		break;
	case 3:
		ANLIK = ANLIK + 8.00;
		yiyecek();
		break;
	case 4:
		ANLIK = ANLIK + 8.00;
		yiyecek();
		break;
	case 5:
		ANLIK = ANLIK + 12.00;
		yiyecek();
		break;
	case 6:
		ANLIK = ANLIK + 4.50;
		yiyecek();
		break;
	case 7:
		ANLIK = ANLIK + 12.00;
		yiyecek();
		break;
	case 8:
		ANLIK = ANLIK + 9.00;
		yiyecek();
		break;
	case 9:
		BUTCE = BUTCE + ANLIK;
		system("cls");
		siparis();
		break;
		default :
		yiyecek();
	}
}
void ekstra() {
	system("cls");
	cout << "1.Ekler=5.00                    2.Kek=1.50\n\n3.Gofret=2.00                 4.Naneli Sakiz Paketi=2.50\n\n5.Karpuzlu Sakiz Paketi=2.50                 6.Damla Sakizi Paketi=2.50\n\n7.Cubuk Kraker=1.50  8.Kurabiye=1.25\n\n9.Geri Don\n\nAnlik fiyat:" << ANLIK << "\n\n\n";
	cin >> secenek;
	switch (secenek) {
	case 0:
	case 1:
		ANLIK = ANLIK + 5.00;
		ekstra();
		break;
	case 2:
		ANLIK = ANLIK + 1.50;
		ekstra();
		break;
	case 3:
		ANLIK = ANLIK + 2.00;
		ekstra();
		break;
	case 4:
		ANLIK = ANLIK + 2.50;
		ekstra();
		break;
	case 5:
		ANLIK = ANLIK + 2.50;
		ekstra();
		break;
	case 6:
		ANLIK = ANLIK + 2.50;
		ekstra();
		break;
	case 7:
		ANLIK = ANLIK + 1.50;
		ekstra();
		break;
	case 8:
		ANLIK = ANLIK + 1.25;
		ekstra();
		break;
	case 9:
		BUTCE = BUTCE + ANLIK;
		system("cls");
		siparis();
		break;
		default:
		ekstra();
	}
}
void odemeekrani() {
	cin >> PARA;
	if (PARA > CUZDAN)
		cout << "Hatali islem cuzdan limitini astiniz limitiniz:" << CUZDAN << "\n";
	else if (PARA <= CUZDAN ) {
		BUTCE = BUTCE - PARA;
		if (BUTCE == 0)
			cout << "siparisiniz tamamlanmistir yine bekleriz";
		else if (PARA > BUTCE)
			cout << "Tercih ettiginiz icin tesekkur ederiz, para ustunuz " << -BUTCE;
		else {
			cout << "odemeniz gereken kalan bakiye:" << BUTCE << "\n";
			odemeekrani();
		}
	}
	else if (PARA > BUTCE) 
        cout << "Tercih ettiginiz icin tesekkur ederiz, para ustunuz " << PARA-BUTCE; 
	}
	class Icecek {
		float Su = 1.00;
		float Cay = 1.50;
		float Kahve = 1.75;
		float Kola, Fanta, Gazoz = 3.50;
		float PortakalliMeyveSuyu, ElmaliMeyveSuyu, VisneliMeyveSuyu, KarisikMeyveSuyu = 2.00;
	};
	class Yiyecek {
		float Tost = 4.50;
		float SucukluTost, KasarliTost = 5.50;
		float PeynirliBorek, KiymaliBorek = 8.00;
		float MiniPizza = 12.00;
		float Patso = 4.50;
		float KahvaltiTepsisi/*Ýçinde Siyah ve Yeþil Zeytin, Peynir, Kaþar, Salam, Salatalýk, Ekmek var*/ = 12.00;
		float Sandvic = 9.00;
	};
	class Ekstra {
		float Ekler = 5.00;
		float Kek = 1.50;
		float Gofret = 2.00;
		float NaneliSakizPaketi, KarpuzluSakizPaketi, DamlaSakiziPaketi = 2.50;
		float CubukKraker = 1.50;
	};
	int main() {
		siparis();
	}

