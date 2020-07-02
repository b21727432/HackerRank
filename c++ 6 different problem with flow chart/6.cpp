#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

int main(){
	
	int N;
	cout << "N sayisinin faktoriyelini hesaplamak icin N sayisini giriniz" << endl;
	cout << "Sayiniz : ";
	cin >> N;
	
	
	int faktoriyel = 1;
	while(N >= 1){
		faktoriyel *= N;
		N--;
	}
	
	cout << "N sayisinin faktoriyel degeri : " << faktoriyel << endl;
	
	return 0;
}
