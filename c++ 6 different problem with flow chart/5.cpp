#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

int main(){
	
	int N;
	cout << "1 den N'e kadar sayilari toplamak icin N sayisini giriniz" << endl;
	cout << "Sayiniz : ";
	cin >> N;
	
	
	int toplam = 0;
	while (N >= 1){
		toplam = toplam + N;
		N--;
	} 
	
	cout << "1 den N'e kadar olan sayilarin toplami : " << toplam << endl;
	
	return 0;
}
