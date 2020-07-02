#include<stdlib.h>
#include<iostream>
using namespace std;
namespace N
{
	class RitmikSayma{
		public:
			int adet;
			int sayilar[20];
			int puan;
			int sayi;
			RitmikSayma(int a){
				if(a < 3 || a > 20){
					a = 3;
				}
				adet = a;
				puan = 0;
			}
			void sayilariAyarla(){
				
				int a = rand() % 100;
				sayilar[0] = a;
				int count = 0;
				while(count != adet){
					int x  = rand() % 100;
					
					int fark = abs(x - a);
					
					if(fark >= 2 && fark <= 9){
						count++;
						sayilar[count] = x;
					}
				}
				for(int i = 0; i < adet ; i++){
					cout << sayilar[i] << endl;
				}
				
				cout << "Sayilar Ayarlandi, Puaniniz : "<< puan << endl;
			}
			int bozanSayi(){
				int min = sayilar[0];
				int max = sayilar[0];
				for(int i = 0 ; i < adet ; i++){
					if(sayilar[i] < min){
						min = sayilar[i];
					}
					if(sayilar[i] > max){
						max = sayilar[i];
					}
				}
				for(int i = 0; i < adet; i++){
					if(sayilar[i] - min > 9 || max - sayilar[i] > 9 || sayilar[i] - min < 2 ){
						return sayilar[i];
					}
					
				}
				
			}
			RitmikSayma operator += (int const &a){
				this->puan += a;
				return *this;
			} 
			void yazdir(){
				cout << "Hangi sayi kurali bozmaktadir ?" << endl;
				for(int i = 0 ; i < adet ; i++){
					cout << "_" << sayilar[i];
					 
				}
				cout << "_" << endl;
			
			}
	};
	
	
	
	
}
