
#include<iostream>

using namespace std;

void kamyonu_yukle(int kamyon_malzemeler[100]){
	int yuk_sayac = 0;
	int yuk;
	while(yuk != -1){
		cout << yuk_sayac + 1 << ".Malzemenin agirligini girin: ";
		cin >> yuk;
		if(yuk == -1){
			break;
		}
		kamyon_malzemeler[yuk_sayac] = yuk;
		yuk_sayac++;
	}
	int toplam_yuk = 0;
	for(int i = 0; i < yuk_sayac ; i++ ){
		toplam_yuk = toplam_yuk + kamyon_malzemeler[i];
		}
	cout << "Kamyona " << yuk_sayac << " Malzeme Yuklendi" << endl;
	cout << "Malzemelerin Toplam Agirligi:" << toplam_yuk << endl;
}

int main(){
	int kamyon_malzemeler[100];
	kamyonu_yukle(kamyon_malzemeler);
	return 0;
}
