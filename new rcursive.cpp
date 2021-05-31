#include<iostream>

int dorduncusoru(int n){
 if(n == 0){
  return 0;
 } else if(n == 1){
  return 1;
 } else{
  return dorduncusoru(n-1) + 4 * dorduncusoru(n-2) + 1;
 }
}

int main(){
	
	std::cout<<dorduncusoru(5);
	
	return 0;
}
