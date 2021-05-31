#include<iostream>

using namespace std;

class Takvim{
	public:
		int gun;
		int ay;
		int yil;
		Takvim(int x, int y, int z){
			gun = x;
			ay = y;
			yil = z;
		}
		void tarih(){
			cout << gun << "/" << ay << "/" << yil << endl;
		}
		void tarihi_ayarla(int x, int y, int z){
			cout << "Girdiginiz tarih degistiriliyor..." << endl;
			gun = x;
			ay = y;
			yil = z;
		}
		void gun_ayarla(int x){
			gun = x;
		}
		void ay_ayarla(int y){
			ay = y;
		}
		void yil_ayarla(int z){
			yil = z;
		}
		
};

int main(){
	
	Takvim bugun(20, 05, 2021);
	
	bugun.tarih();
	
	bugun.tarihi_ayarla(21, 5, 2021);
	
	bugun.tarih();
	
	
	return 0;
}
