 #include<stdio.h>
 int eksikDeger(int a[]){
 	
 	int n = sizeof(a)/sizeof(int);
 	int sum = (3*n*n + 5*n)/2;
 	printf("%d %d", n, sum);
 	
 	
 }
 
 int main(){
 	
 	int a[6] = {1,4,7,10,13,16};
 	int n = 6;
 	eksikDeger(a);
 	
 	
 	
 	return 0;
 }
