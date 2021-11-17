#include<iostream>
using namespace std;

template <typename T>
T mutlak(T x)
{
   return (x > 0)? x: -x;
}


int main(){
	
	cout << "Aralarinda bosluk birarak 3 sayiyi giriniz (x y z):";
	int tamsayi;
	float floatsayi;
	double doublesayi;
	cin >> tamsayi >> floatsayi >> doublesayi;
	cout << "Tamsayi mutlak :" << mutlak(tamsayi) << " Float mutlak : " << mutlak(floatsayi) << " Double mutlak : " << mutlak(doublesayi) << endl;
	
	
	return 0;
}
