#include<stdlib.h>



void controlNumber(int array[], int n){
	
	int x =0;
	for(x = 0; x < n;x++){
		int j, r; 
		int i = 0;
		int arr[100];
		while (array[x] != 0) { 
  
        // Extract the last digit of N 
        r = array[x] % 10; 
  
        // Put the digit in arr[] 
        arr[i] = r; 
        i++; 
  
        // Update N to N/10 to extract 
        // next last digit 
        array[x] = array[x] / 10; 
    	}
    	int asd;
		for(asd = 0; asd < n; asd++){
			if(arr[asd] != arr[0]){
				printf("%d >> tum basamaklar esit degil\n", array[x]);
				break;
			}
		}
		printf("%d >> tum basamaklar esit\n", array[x]);
	 
	}
	
    
    
}

void main(){
	
	int A[] = {233,45,777};
	int size = sizeof A / sizeof A[0];
	controlNumber(A, size);

	
	
}
