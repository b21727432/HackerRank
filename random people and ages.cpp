#include<iostream>
#include <cstdlib>
#include <ctime> 
using namespace std;


int main(){
	
	srand(time(0));
	
	int people[10];
	int i;
	for(i = 0; i < 10; i++){
		people[i] = (rand() % 100);
	}
	int y;
	for(y = 0; y < 10; y++){
		if(people[y] >= 0 and people[y] <= 17){
			cout << y+1 << ".th person is adolesgent" << endl;
		}
		else if(people[y] >= 18 and people[y] <= 65){
			cout << y+1 << ".th person is young" << endl;
		}
		else if(people[y] >= 66 and people[y] <= 79){
			cout << y+1 << ".th person is middle age" << endl;
		}
		else if(people[y] >= 80 and people[y] <= 99){
			cout << y+1 << ".th person is old" << endl;
		}
	}
	
	
	return 0;
}
