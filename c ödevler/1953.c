#include<stdio.h>
#include<stdlib.h>
#include<string.h>



int main(){
	
	char string[] = {"BADGERS"};
	char *ptr = string;
	*ptr = *ptr + 2;
	ptr = ptr + 2;
	printf("%c", *ptr);
	ptr--;
	printf("%c", *ptr);
	ptr++;
	printf("%c", *ptr);
	return 0;
}
