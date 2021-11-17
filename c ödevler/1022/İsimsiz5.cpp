#include<iostream>
using namespace std;

int main(){
	
	cout << "enter 2 numbers to find greatest common factors(insert space between numbers such as x y)" << endl;
	int x, y;
	cin >> x >> y;
	
	while(x != y){ // sayilar esit degilse devam et,
		if(x > y){ // eger x büyükse x den y yi cıkart, eger esitlerse bulduk demektir
			x = x - y;
		} else{
			y = y - x; // eger y buyukse y den x i cıkart 
		}
	}
	
	cout << "greatest common factors of these 2 numbers are : " << x << endl;	
	
	return 0;
}
