#include<iostream>
using namespace std;

int main(){
	
	
	int d[10] = {25,11,70,33,99,66,55,40,88,20};
	int n = 10;
	
	int i, j; // bubble sortta dogru yerini bulana kadar yer degistriyirouz
    for (i = 0; i < n-1; i++){ // son eleman� alm�yorum cunku ondan sonras� yok
    	for (j = 0; j < n-i-1; j++){ // i tanesi gercek yerinde demek o y�zden -i yaparak onlara bakm�yoruz
    		if (d[j] > d[j+1]){ // eger buyukse yanl�s yerde demektir o y�zden yer degistiriyorum
    			int gecici = d[j];
    			d[j] = d[j+1];
    			d[j+1] = gecici;
			}
		}
	}    
     
    
    for(i = 0; i < 10; i++){
    	cout << d[i] << " ";
	}
            
	
	
	return 0;
}
