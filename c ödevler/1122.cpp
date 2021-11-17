#include<iostream>
using namespace std;

int carpim(int tam1, int tam2, int tam3){
	return tam1 * tam2 * tam3;
}

float carpim(float ondalik1, float ondalik2, float ondalik3){
	return ondalik1 * ondalik2 * ondalik3;
}

int main(){
	
	int tam1, tam2, tam3;
	float ondalik1, ondalik2, ondalik3;
	cin >> tam1 >> tam2 >> tam3;
	cin >> ondalik1 >> ondalik2 >> ondalik3;
	
	int intsonuc = carpim(tam1, tam2, tam3);
	float floatsonuc = carpim(ondalik1, ondalik2, ondalik3);
	
	cout <<"Tam sonuc : " << intsonuc << " Ondalik sonuc: " << floatsonuc << endl;
	
	
	return 0;
}
