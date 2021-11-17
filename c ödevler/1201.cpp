#include<iostream>
#include<fstream>
#include <math.h>  

using namespace std;


int main(){
	int a[9] = {3,-4,5,2,-8,6,4,1,3};
	int i, t = 0;
	for(i = 2; i < 10;i++){
		t+=a[i];
		if(t == i){
			break;
		}
	}
	cout << t;
}
