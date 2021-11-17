#include<iostream>
#include <cmath>


using namespace std;

int main(){
	
	int n = 100;
	float t;
	int k;
	for(k = 1; k <= n; k++){
		t += pow(-1, k+1)/(2*k);
	}
		
	cout << t << endl;
	return 0;
}
