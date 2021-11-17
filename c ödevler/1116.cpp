#include<iostream>
#include<fstream>
#include <math.h>  

using namespace std;


int main(){
	string satir;
	ifstream sayilar("sayilar.txt");
	
	while (getline (sayilar, satir)) {
  		double sayi = stod(satir);
  		if(sayi >= 1 && sayi <=20){
  			cout << sayi << " " << sqrt(sayi) << endl;
		} else{
			cout << sayi << endl;
		}
	}
	
	sayilar.close();
}
