#include<stdio.h>
#include<string.h>

int main(){
	
	char line[256];
	gets(line);
	
	int n, j, i, tekrar = 0;
	
	for(j=0;line[j];j++);
	 n=j; 
	
	for(i = 0; i < n; i++){
		tekrar = 1;
		if(line[i]){
			for(j = i+1; j < n; j++){
				if(line[i] == line[j]){
					tekrar++;
					line[j] = '\0';
				}
			}
			
		}
		printf("'%c' harfi %d kadar bulunmaktadır\n", line[i], tekrar);
	}
	
	return 0;
}
