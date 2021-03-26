#include <stdio.h>
#include <time.h> 

int fib(int n) { 

    if (n <= 1) 
        return n; 
        
    return fib(n - 1) + fib(n - 2); 
    
} 
  
int main(){
	
	clock_t start, end, start2, end2, start3, end3;
	double cpu_time_used, cpu_time_used2, cpu_time_used3;
 
   
	
	 
	int n1=0,n2=1,n3,i,number = 1000, number2 = 10000, number3 = 10000000;    
 	
	start = clock();
 	
 	for(i=2;i<number;++i){
  		n3=n1+n2;
  		if(i == number - 1){
  			break;  	
		}
  		n1=n2;    
  		n2=n3;    
 	}
	 
	end = clock(); 
    cpu_time_used2 = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    printf("\nN = %d elemanli Fibonacci serisi %f saniyede calisti. \n", number, cpu_time_used);
    
    start2 = clock();
    
    for(i=2;i<number2;++i){
  		n3=n1+n2;
  		if(i == number2 - 1){
  			break;  	
		}
  		n1=n2;    
  		n2=n3;    
 	}
	 
	end2 = clock(); 
    cpu_time_used2 = ((double) (end2 - start2)) / CLOCKS_PER_SEC;
    
    printf("\nN = %d elemanli Fibonacci serisi %f saniyede calisti. \n", number2, cpu_time_used2);
    
    start3 = clock();
    
    for(i=2;i<number3;++i){
  		n3=n1+n2;
  		if(i == number3 - 1){
  			break;  	
		}
  		n1=n2;    
  		n2=n3;    
 	}
	 
	end3 = clock(); 
    cpu_time_used3 = ((double) (end3 - start3)) / CLOCKS_PER_SEC;
    
    printf("\nN = %d elemanli Fibonacci serisi %f saniyede calisti. \n", number3, cpu_time_used3);
    
	 
    return 0; 
} 
