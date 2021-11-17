#include<stdio.h>


int main(){
	
	int boyut;
	printf("Kac elemana sahip bir dizi olmasini istersiniz?\n");
	scanf("%d", &boyut);
	int dizi[boyut];
	printf("%d adet sayi giriniz :\n", boyut);
	int i, temp;
	for(i =0; i < boyut; i++){
		
		scanf("%d", &dizi[i]);
	}
	printf("Dizi icin girilen sayilar :\n");
	for(i =0; i < boyut; i++){
		printf("%d ", dizi[i]);
	}
	printf("Dizi sayilari arasina eklemek istediginiz sayi nedir : \n");
	int yenisayi;
	scanf("%d", &yenisayi);
	printf("Dizi sayilari arasina eklenecek sayi hangi indise eklenecek : \n");
	int yeniindes;
	scanf("%d", &yeniindes);
	int yenidizi[boyut+1];
	int eskii = 0;
	int yenii = 0;
	for(i = 0; i < boyut + 1;i++){
		if(i == yeniindes){
			yenidizi[yenii] = yenisayi;
			yenii++;
		} else{
			yenidizi[yenii++] = dizi[eskii++];
		}
	}
	printf("Dizi arasina eklenen sayi sonrasi yeni liste : \n");
	for(i =0; i < boyut + 1; i++){
		printf("%d ", yenidizi[i]);
	}
	return 0;
}
