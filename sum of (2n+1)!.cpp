using namespace std;
#include <iostream>

int main(){
	
	int n = 4;
	int sum = 0;
	
	for(int i = 1; i <= n; i++){
		int x = (2*i + 1);
		int faktoriyel = 1;
		for (int j = 2; j <= x; j++){
    		faktoriyel *= j;
  		}
  		sum += faktoriyel;
	}
	
	cout << sum << endl;
	
	return 0;
}
