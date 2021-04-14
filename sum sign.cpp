using namespace std;
#include <iostream>


int main(){
	
	int a = 3, b = 4, c = 2, sum = 0;
	for(int i = 1; i <= a; i++){
		for(int j = 1; j <= b; j++){
			for(int z = 1; z <= c; z++){
				sum += z + 3*j - 2*i;
			}
		}
	}
	
	cout << sum << endl;
	
	return 0;
}
