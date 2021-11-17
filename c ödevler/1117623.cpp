#include<iostream>
using namespace std;
class myClass{
	private:
		string x,y;
	public:
		myClass operator+(const myClass& b) {
         myClass myClass;
         myClass.x = this->x + b.x;
         myClass.y = this->y + b.y;
         return myClass;
      	}
      	string getX(){
      		return x;
		  }
		void setX(string yenix){
			this->x = yenix;
		}
		string getY(){
      		return y;
		  }
		void setY(string yeniy){
			this->y = yeniy;
		}
};

int main(){
	
	myClass obje1;
	myClass obje2;
	string x1,y1,x2,y2;
	cout << "2 sozcuk girin:" << endl;
	cout << "x:";
	cin >> x1;
	cout << "y:";
	cin >> y1;
	obje1.setX(x1);
	obje1.setY(y1);
	cout << "2 sozcuk girin:" << endl;
	cout << "x:";
	cin >> x2;
	cout << "y:";
	cin >> y2;
	obje2.setX(x2);
	obje2.setY(y2);
	myClass obje3 = obje1 + obje2;
	cout << "Yeni x:" << obje3.getX() << endl;
	cout << "Yeni y:" << obje3.getY() << endl;
	
	
	return 0;
}
