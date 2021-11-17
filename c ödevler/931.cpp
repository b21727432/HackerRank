#include<iostream>
#include <fstream>
using namespace std;

int main(){
	
	ofstream myfile;
  	myfile.open ("cikti.txt");
	
	for(int i = 0; i < 10; i++){
		int sayi;
		cin >> sayi;
		myfile << sayi * 200 << endl;
	}
	myfile.close();
	
	return 0;
}
