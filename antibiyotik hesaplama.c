#include <stdio.h>
int main(){
	char antibiyotik;
	printf("Kullanilacak antibiyotik turunu giriniz ( A, a, B, b ):");
	scanf("%c", &antibiyotik);
	if(antibiyotik == 'a' || antibiyotik == 'A'){
		int cocugunkilosu;
		printf("Cocugun kilosunu giriniz(gr) giriniz:  ");
		scanf("%d",&cocugunkilosu);
		float doz;
		int defa = 4;
		if(cocugunkilosu < 10000){
			doz = cocugunkilosu / 1000.0 * 1500. / 2.0;
		} else if(cocugunkilosu >= 10000 && cocugunkilosu <= 40000){
			doz = cocugunkilosu / 1000.0 * 150.0;
		} else if(cocugunkilosu > 40000){
			doz = 4500.0;
		}
		printf("Cocuk, %c turundeki antibiyotikten gunde %d defa %.2f mglýk dozlar halinde almalidir. ", antibiyotik, defa, doz / 4.0);
	} else if(antibiyotik == 'b' || antibiyotik == 'B'){
		int cocugunkilosu;
		printf("Cocugun kilosunu giriniz(gr) giriniz:  ");
		scanf("%d", &cocugunkilosu);
		float doz;
		int defa = 3;
		if(cocugunkilosu < 10000){
			doz = cocugunkilosu / 1000.0 * 120.0 / 2.0;
		} else if(cocugunkilosu >= 10000 && cocugunkilosu <= 40000){
			doz = cocugunkilosu / 1000.0 * 120.0;
		} else if(cocugunkilosu > 40000){
			doz = 3000.0;
		}
		printf("Cocuk, %c turundeki antibiyotikten gunde %d defa %.2f mglik dozlar halinde almalidir. ", antibiyotik, defa, doz / 3);
	}
	return 0;
}
