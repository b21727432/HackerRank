#include<stdlib.h>
#include<stdio.h>
#include<string.h>



int main(){
	
	int i;
	float arr[10];
	printf("Arrayin elemanlarini giriniz : ");
	for(i = 0 ; i < 10; i++){
		scanf("%f", &arr[i]);
	}
	
	float temp;
	temp = arr[5];
	arr[5] = arr[2];
	arr[2] = temp;
	
	FILE * fp;
	fp = fopen ("dizi.txt","w");
	
	for(i = 0; i < 10; i++){
		fprintf(fp, "%f ", arr[i]);
	}
	
	fclose(fp);
	
	return 0;
}
