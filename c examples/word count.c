#include<stdio.h>
#include<stdlib.h>


int main(){
	
	
	
	
	char s[150];
    scanf("%[^!]",s);
    
    
    int i, count = 0, len = strlen(s);
    
    for(i = 0; i < len ; i++){
    	if((s[i] == ' ') || (s[i] == '\n') || (s[i] == '\t') || (s[i] == '\0')){
    		count++;
		}
	}
	
	printf("kelime sayisi : ",count);
   	
	
	
	
	return 0;
}
