#include<iostream>
using namespace std;

class Sekil{
	private:
		int x;
		int y;
	public:
		Sekil(int x1, int y1){
			this->x = x1;
			this->y = y1;
		}
		void koordinatYazdir(){
			cout << "X : " << this->getX() << " Y : " << this->getY() << endl;
		}
		void setX(int x1){
			this->x = x1;
		}
		int getX(){
			return this->x;
		}
		void setY(int y1){
			this->y = y1;
		}
		int getY(){
			return this->y;
		}
};

class Daire : public Sekil{
	private:
		float yaricap;
	public:
		Daire(int x1, int y1, float yaricap1) : Sekil(x1,y1){
			
			this->yaricap = yaricap1;
		}
		void yaricapliKoordinatYazdir(){
			cout << "X : " << this->getX() << " Y : " << this->getY() << " Yaricap : " << this->getYaricap() << endl;
		}
		void setYaricap(float yaricap1){
			this->yaricap = yaricap1;
		}
		int getYaricap(){
			return this->yaricap;
		}
};

class Dikdortgen : public Sekil{
	private:
		float kisakenar;
		float uzunkenar;	
	public:

		Dikdortgen(int x1, int y1, float kisakenar1, float uzunkenar1) : Sekil(x1, y1){
			this->kisakenar = kisakenar1;
			this->uzunkenar = uzunkenar1;
		}
		void uzunkisaKoordinatYazdir(){
			cout << "X : " << this->getX() << " Y : " << this->getY() << " Kisakenar : " << this->getKisakenar() << " Uzunkenar : " << this->getUzunkenar() << endl;
		}
		void setKisakenar(float kisakenar1){
			this->kisakenar = kisakenar1;
		}
		int getKisakenar(){
			return this->kisakenar;
		}
		void setUzunkenar(float uzunkenar1){
			this->uzunkenar = uzunkenar1;
		}
		int getUzunkenar(){
			return this->uzunkenar;
		}
};


int main(){
	
	Dikdortgen dikdortgen1(1,2,3.5,5);
	Daire daire1(2,3,5.5);
	dikdortgen1.uzunkisaKoordinatYazdir();
	daire1.yaricapliKoordinatYazdir();
	
	
	return 0;
}
