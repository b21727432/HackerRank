#include<stdio.h>
#include<math.h>

int main(){
	
	int a[6] = {1,2,3,4,5,-10};
	int m = 0, i, n = 6, j;
	for(i = 0; i <= n-2; i++){
		for(j = i + 1;j <= n-1; j++){
			if(abs(a[i]-a[j]) > m){
				m = abs(a[i] - a[j]);
			}
		}
	}
	printf("%d", m);
}
