#include<stdio.h>


int main(){
	
	int a[6] = {4,5,30, 7, 13, 30};
	int n = 6;
	int yer = 0;
	int i = 2, j;
	while(i<=n && yer == 0){
		j = 1;
		while(j < i && yer == 0){
			if(a[i] == a[j]){
				yer = i;
				
			}
			else{
				j = j+ 1;
			}
		}
		i = i+1;
	}
	printf("%d %d %d", i, j, yer);
	return 0;
}
