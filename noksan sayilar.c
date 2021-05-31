#include <stdio.h>
int main()
{
	int i,j, toplamnoksan = 0;
	for(i = 100 ; i <= 999; i++){
		int toplam = 0;
		for(j = 1; j < i; j++){
			if(i % j == 0){
				toplam += j;
			}
		}
		if(toplam < i){
			toplamnoksan++;
		}
	}
	printf("%d", toplamnoksan);
return 0;
}
