#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct komplex{
	double gercel;
	double sanal;
};
struct komplex degerAl(int a1, int b1, int a2, int b2){
	struct komplex z1;
	z1.gercel = (double)a1/b1;
	z1.sanal = (double)a2/b2;
	printf("%lf %lf", z1.gercel, z1.sanal);
	return z1;
}
struct komplex topla(struct komplex z1, struct komplex z2){
	struct komplex z3;
	z3.gercel = z1.gercel + z2.gercel;
	z3.sanal = z1.sanal + z2.sanal;
	return z3;
}

void toplayazdir(struct komplex z1, struct komplex z2){
	double gerceltoplam = z1.gercel + z2.gercel;
	double sanaltoplam = z1.sanal + z2.sanal;
	printf("Iki sayinin toplami : %lf %lfi", gerceltoplam, sanaltoplam);
}

int main(){
	
	int a1,b1,a2,b2;
	printf("Kesirli Degerleri giriniz(ilk gercel deger kesirleri sonra sanal deger kesirleri) : ");
	scanf("%d", &a1);
	scanf("%d", &b1);
	scanf("%d", &a2);
	scanf("%d", &b2);
	
	struct komplex z1 = degerAl(a1,b1, a2, b2);
	
	
	struct komplex z2 = degerAl(a2,b2, a1, b1);
	struct komplex z3 = topla(z1, z2);
	toplayazdir(z1, z2);
	return 0;}
	
	

