#include <stdio.h>
#include <time.h> 

  
int main(){
	
	clock_t start, end;
	double cpu_time_used;
 
   
	start = clock();
	 
	int n1=0,n2=1,n3,i,number;    
 	printf("Eleman sayisini giriniz : ");    
 	scanf("%d",&number);    
 	for(i=2;i<number;++i){
  		n3=n1+n2;
  		if(i == number - 1){
  			printf("%d. fibonacci serisi elemani bulundu.", number);   	
		}
  		n1=n2;    
  		n2=n3;    
 	}
	 
	end = clock();
	// 1GHZ OLARAK 1000000000 kullan�yorum. ( oras� clocks per sec olarak b�rak�lm�� time.h k�t�phanesinde o y�zden oraya 1000000000 yazarsak 1ghz olarak beirlemi� olabiliriz.
    cpu_time_used = ((double) (end - start)) / 1000000000;
    printf("\nN = %d elemanli Fibonacci serisi %f saniyede calisti. \n", number, cpu_time_used);
	 
    return 0; 
} 
