using namespace std;
#include <iostream>
#include <cstdlib>

int main(){
	
	srand((unsigned) time(0));
	int ogrencinot;
	int group1 = 0, group2 = 0, group3 = 0, group4 = 0;
	
	for (int i = 0; i < 10; i++) {
    	ogrencinot = (rand() % 100) + 1;
    	if(ogrencinot < 50){
    		group1 += 1;
		}
		else if(ogrencinot >= 50 and ogrencinot < 70){
			group2 += 1;
		}
		else if(ogrencinot >= 70 and ogrencinot < 90){
			group3 += 1;
		}
		else{
			group4 += 1;
		}
  	}
  	
  	
	return 0;
}
