#include<stdio.h>
#include<stdlib.h>

int max(int liste[], int n);
int min(int liste[], int n);

int main(){
	
	int a[] = {9,2};
	int b[] = {8,10,2};
	int c[] = {3,2,4};
	int d[] = {0,5,6};
	int e[4];
	e[0] = max(a, sizeof(a) / sizeof(a[0]));
	e[1] = max(b, sizeof(b) / sizeof(b[0]));
	e[2] = max(c, sizeof(c) / sizeof(c[0]));
	e[3] = max(d, sizeof(d) / sizeof(d[0]));
	int f[] = {8,6,7,5};
	int g[2];
	g[0] = min(e, sizeof(e) / sizeof(e[0]));
	g[1] = min(f, sizeof(f) / sizeof(f[0]));
	
	
	printf("Final result is %d", max(g, sizeof(g) / sizeof(g[0])));
	
	
	
	return 0;
}

int max(int liste[], int n){
	int i,max = 0;
	for(i = 0; i < n; i++){
		if(liste[i] > max){
			max = liste[i];
		}
	}
	return max;
}

int min(int liste[], int n){
	int i,min = liste[0];
	for(i = 0; i < n; i++){
		if(liste[i] < min){
			min = liste[i];
		}
	}
	return min;
}
