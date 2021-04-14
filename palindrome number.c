#include<stdio.h>	
int main() 	
{	
  int sayi;	
  int ab, cd;	
  printf("4 basamaklý bir sayý giriniz: ");	
  scanf("%d", &sayi);	
	
   ab = sayi/100;	
   cd = sayi%100;
    if( ab == cd )	
    {	
      printf("sayi= %d ", sayi);	
    }	
   else	
     printf("yanlýþ sayý");	
	
  return 0;	
}	

