#include<iostream> 
using namespace std; 
  
class Koordinat { 
private: 
    int x, y; 
public: 
    Koordinat(int r = 0, int i =0)  {x = r;   y = i;} 
      

    Koordinat operator + (Koordinat const &koor) { 
         Koordinat temp;
	 
         temp.x = x + koor.x; 
         temp.y = y + koor.y; 
         return temp; 
    }
	void operator > (Koordinat const &koor){
		Koordinat temp;
		if(x > koor.x){
			if(y > koor.y){
				cout << "A nin her iki degeri de B den buyuktur." << endl;
			}
			else{
				cout << "A nin X degeri B den buyuktur fakat Y degeri B den kucuktur." << endl; 
			}
		}
		else{
			if(y > koor.y){
				cout << "A nin X degeri B den kucuktur fakat Y degeri B den buyuktur." << endl;
			}
			else{
				cout << "A nin her iki degeri de B den kucuktur." << endl;
			}
		}
	}
	Koordinat operator * (){
		Koordinat temp;
		temp.x = x + 1;
		temp.y = y + 1;
		return temp;
	} 
    void print() { 
	cout << "X degeri : " << x << " Y degeri : "<< y << endl; 
	} 
}; 
  
int main() 
{ 
	cout << "Koordinatlari giriniz : (x1,y1) , (x2,y2)" << endl;
	int x1,y1,x2,y2;
	cin >> x1;
	cin >> y1;
	cin >> x2;
	cin >> y2;
    Koordinat A(x1, y1), B(x2, y2); 
    Koordinat C = A + B;
    C.print();
	A > B;
	A = *A;
	A.print();
} 
