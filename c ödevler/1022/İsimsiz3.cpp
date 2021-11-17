#include<iostream>
using namespace std;


int main(){
	
	int x;
	cout << "enter x";
	cin >> x;
	if(-3 <= x && x < 0){
		cout << x * x << endl;
	} else if(0 <= x && x < 3){
		cout << 3 << endl;
	} else if(x >= 3){
		cout << 3-x << endl;
	}
	
	
	return 0;
}
