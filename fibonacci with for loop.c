#include<stdio.h>
// {fn } = 0,1,1,2,3,5,8,13,21,34,55
int fibonacci(int n){
	
	if(n <= 1){
		return n;
	}
	return fibonacci(n-2) + fibonacci(n-1);
}

int fibonaccifor(int n){
	
	int ilk = 0, ikinci = 1;
	int i;
	int sonra;
	for(i = 0; i < n; i++){
		if(i <= 1){
			sonra = i;
		}
		else{
			sonra = ilk + ikinci;
			ilk = ikinci;
			ikinci = sonra;
		}
		printf("%d\n", sonra);
	}
	
}

int main(){
	
	int eleman = fibonaccifor(10);  // fibonacci(0) + fibonacci(1) fibonacci(n-2) + fibonacci(n-1)
	printf("Fibonacci 5. elemani : %d", eleman);
	
	return 0;
}
