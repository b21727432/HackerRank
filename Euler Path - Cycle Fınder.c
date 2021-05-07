#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <time.h>

void komsulukmatrix(int dugum, int komsuluk[dugum][dugum]){
	int i, j;
	for(i = 0; i < dugum; i++){
		for(j = 0; j < dugum; j++){
			if(i == j){
				komsuluk[i][j] = 0;
				break;
			} else{
				int x = rand() % 2;
				komsuluk[i][j] = x;
				komsuluk[j][i] = x;
			}
		}
	}
	
	int zerocount; // serim tek parca mý kontrolu, degilse tekrar cagrýlmasý
	int isok;
	for(i = 0; i < dugum; i++){
		zerocount = 0;
		for(j = 0; j < dugum; j++){
			if(komsuluk[i][j] == 0){
				zerocount++;
			}
		}
		if(zerocount == dugum){ // hepsi 0 ayrýk
			komsulukmatrix(dugum, komsuluk);
		}
	}
}

int findStartVert(int dugum, int yedekkomsuluk[dugum][dugum]){
	int i,j;
   for(i = 0; i<dugum; i++){
      int deg = 0;
      for(j = 0; j<dugum; j++){
         if(yedekkomsuluk[i][j])
         deg++; 
      }
      if(deg % 2 != 0) 
      return i; 
   }
   return 0; 
}

int isBridge(int u, int v, int dugum, int yedekkomsuluk[dugum][dugum]){
   int deg = 0, i;
   for(i = 0; i<dugum; i++)
      if(yedekkomsuluk[v][i])
         deg++;
      if(deg>=1){
         return 0; 
      }
   return 1; 
}

int edgeCount(int dugum, int yedekkomsuluk[dugum][dugum]){
   int count = 0, i, j;
   for(i = 0; i<dugum; i++)
      for(j = i; j<dugum; j++)
         if(yedekkomsuluk[i][j] == 1)
            count++;
   return count; 
}
void fleuryAlgorithm(int start, int dugum, int komsuluk[dugum][dugum], int yedekkomsuluk[dugum][dugum], int edge){
	int v;
   for(v = 0; v<dugum; v++){
      if(yedekkomsuluk[start][v]){
         if(edge <= 1 || !(isBridge(start, v, dugum, yedekkomsuluk))){
         	printf("%d -- %d ", start, v);
            yedekkomsuluk[start][v] = yedekkomsuluk[v][start] = 0; 
            edge--;
            fleuryAlgorithm(v, dugum, komsuluk, yedekkomsuluk, edge);
         }
      }
   }
}

void findTourorPath(int dugum, int komsuluk[dugum][dugum], int yedekkomsuluk[dugum][dugum]){
	int i,j;
	
	int edge = edgeCount(dugum, yedekkomsuluk);
	
	for(i = 0; i<dugum; i++){
		for(j = 0; j<dugum; j++){
			yedekkomsuluk[i][j] = komsuluk[i][j];
		}
	}
	printf("Euler Yolu ve Turu: ");
   	fleuryAlgorithm(findStartVert(dugum, yedekkomsuluk), dugum, komsuluk, yedekkomsuluk, edge);		
}

void eulerTourControl(int dugum, int komsuluk[dugum][dugum], int yedekkomsuluk[dugum][dugum]){
	int ciftkomsucount = 0, komsucount, tekkomsucount = 0, i, j;
	for(i = 0; i < dugum; i++){
		komsucount = 0;
		for(j = 0; j < dugum; j++){
			if(komsuluk[i][j] == 1){
				komsucount++;
			}
		}
		if(komsucount % 2 == 0){
			ciftkomsucount++;
		} else{
			tekkomsucount++;
		}
	}
	
	if(tekkomsucount > 2){
		printf("Derecesi tek olan noktalarin sayisi ikiden fazla o yuzden bu cizgede Euler turu ve yolu yoktur...\n");
	}
	else if(tekkomsucount == 2){
		printf("Tek Dereceli Dugum Sayisi 2 oldugundan bu cizgede Euler turu yoktur, euler yolu vardir  ve bu yol, bu noktalardan birinde baslayip digerinde biter...\n");
		findTourorPath(dugum, komsuluk, yedekkomsuluk);
	}	
	else if(tekkomsucount == 0){
		printf("Cizgede tum dugumlerin derecesi cift, Euler turu vardir...\n");
		findTourorPath(dugum, komsuluk, yedekkomsuluk);
	}
}

int main(){
	
	srand(time(NULL));
	
	int dugum;
	printf("Dugum sayisini giriniz : ");
	scanf("%d", &dugum);
	
	int komsuluk[dugum][dugum];
	
	int yedekkomsuluk[dugum][dugum];
	
	komsulukmatrix(dugum, komsuluk);
	
	int i, j;
	for(i = 0; i < dugum; i++){
		for(j = 0; j < dugum; j++){
			printf("%d ", komsuluk[i][j]);
		}
		printf("\n");
	}	
	
	eulerTourControl(dugum, komsuluk, yedekkomsuluk);
	
	return 0;
}
