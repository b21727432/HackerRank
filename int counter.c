#include<string.h>
#include<stdio.h>

void sayiSayici(int dizi[], int uzunluk){
	int i,j,tekrar=0;
	for(i=0;i<uzunluk;i++){
     	tekrar=1;
    	if(dizi[i]){
 		  for(j=i+1;j<uzunluk;j++){   
	    	if(dizi[i]==dizi[j]){
                tekrar++;
                dizi[j]=0;
	     	}
	      }  
	      printf("Dizi icerisinde %d harfinden %d tekrar bulunmustur. \n",dizi[i],tekrar);
       }
 	}
}


int main()
{
    int dizi[] = {2,3,3,5,3,4,1,7,7,7,7};  
    int uzunluk = 11;
    
	printf("Girilen dizideki sayilarin tekrar sayisi :\n");
 	sayiSayici(dizi, uzunluk);
     
    return 0;
}
