#include<stdio.h>


int ikinci_soru(int n, int yaricap, int kacinci_daire){
	if(kacinci_daire < n){
		return 3.14*yaricap*yaricap + ikinci_soru(n, yaricap/2, ++kacinci_daire);
	}
}

int main(){
	
	int n; 
	int yaricap;
	printf("N degerini giriniz : ");
	scanf("%d", &n);
	printf("Yaricap degerini giriniz : ");
	scanf("%d", &yaricap);
	int kacinci_daire = 0;
	int alan = ikinci_soru(n, yaricap, kacinci_daire);
	printf("%d", alan);
	return 0;
}
