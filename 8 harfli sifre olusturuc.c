#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>
  

void sifre_olustur(int N, char sifreler[10][9], int n)
{
    int i = 0;
  
    char rakamlar[] = "0123456789";
  
    char harfler[] = "abcdefgh";
  
    char simgeler[] = "+-*";
  
    char sifre[N+1];
  	
  	int boyut = 0;
    
    for(i = 0; i < 5; i++){
    	sifre[boyut++] = harfler[rand() % 8];
	}
	for(i = 0; i < 1; i++){
    	sifre[boyut++] = simgeler[rand() % 3];
	}
	for(i = 0; i < 2; i++){
    	sifre[boyut++] = rakamlar[rand() % 10];
	}
	sifre[8] = '\0';
	//printf("%s\n", password);
	strcpy(sifreler[n],sifre);
}
  
// Driver Code
int main()
{	

	FILE *fp;

   	fp = fopen("sifre.txt", "w");
		
	char sifreler[10][9];
	srand(time(NULL));
	
	int i = 0;
    int N = 8;
    for(i = 0; i < 10; i++){
    	sifre_olustur(N, sifreler, i);
	}
	
	for(i = 0; i < 10; i++){
    	fprintf(fp, "%s\n", sifreler[i]);
	}
	
	fclose(fp);
  
    return 0;
}
