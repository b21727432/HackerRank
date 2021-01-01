#include <stdio.h>
int row,column,value, kazanma;
int gameTemplate[7][4] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
void gameplay1();
void gameplay2();
void l1();
void l2();
void l3();
void l4();
void print(int gameTemplate[7][4]){
    int i,j;

    // printf("| 0 | 0 | 0 | 0 | \n");
    // printf("| 0 | 0 | 0 | 0 | \n");
    // printf("| 0 | 0 | 0 | 0 | \n");
    // printf("| 0 | 0 | 0 | 0 | \n");
    // printf("| 0 | 0 | 0 | 0 | \n");
    // printf("| 0 | 0 | 0 | 0 | \n");
    // printf("| 0 | 0 | 0 | 0 | \n");

    printf("Two Dimensional array elements:\n");
    
   for(i=0; i<7; i++) {
   	printf("|");
      for(j=0;j<4;j++) {
         printf(" %d |", gameTemplate[i][j]);
         if(j==3){
            printf("\n");
         }
      }
   }
   printf("***************** \n");
   printf("  0   1   2   3  ");
}
void oyuncu1(){
	printf("\nOyuncu1 dizi seciniz (0-3): ");
   scanf("%d", &row);

  printf("Oyuncu1 konum seciniz (0-6): ");
  scanf("%d", &column);

  printf("Oyuncu1 yerlestirilecek elemani seciniz (1-2):");
  scanf("%d",&value);
}
void oyuncu2(){
	printf("\nOyuncu2 dizi seciniz (0-3): ");
   scanf("%d", &row);

  printf("Oyuncu2 konum seciniz (0-6): ");
  scanf("%d", &column);

  printf("Oyuncu2 yerlestirilecek elemani seciniz (1-2):");
  scanf("%d",&value);
}
void gamePlay(){
    
	
   gameplay1();
   return;
  

  

  
}

void gameplay1(){
	
	oyuncu1();
  if((value == 1 || value == 2) && (gameTemplate[column][row] != 2 || gameTemplate[column][row] != 1)){
  	if(row > 3 || row < 0){
  		printf("Gecerli dizi sayisi girmediniz");
  		gameplay1();
	  }
	else if(column > 6 || column < 0){
		printf("Gecerli konum sayisi girmediniz");
		gameplay1();
	}
	else{
		gameTemplate[column][row] = value;
  		print(gameTemplate);
  		l1();
		l2();
		l3();
		l4();
  		if(kazanma == 1){
			printf("Oyuncu 1 kazanmistir...\n");
			print(gameTemplate);
			
			return;
		}
		else{
			gameplay2();
			return;
		}
	}
  }
  else{
  	printf("\n 1 veya 2 deðerlerinden birini giriniz.");
  	gameplay1();
  }
  
  
	
}

void gameplay2(){
	
	oyuncu2();
  
  if((value == 1 || value == 2) && (gameTemplate[column][row] != 2 || gameTemplate[column][row] != 1)){
  	if(row > 3 || row < 0){
  		printf("Gecerli dizi sayisi girmediniz");
  		gameplay2();
	  }
	else if(column > 6 || column < 0){
		printf("Gecerli konum sayisi girmediniz");
		gameplay2();
	}
	else{
		gameTemplate[column][row] = value;
		print(gameTemplate);
		l1();
		l2();
		l3();
		l4();
		
		if(kazanma == 1){
			printf("Oyuncu 2 kazanmistir...\n");
			print(gameTemplate);
			return;
		}
		else{
			gameplay1();
			return;
		}
		
		
	}
  }
  else{
  	printf("\n 1 veya 2 deðerlerinden birini giriniz.");
  	gameplay2();
  }
	
}

void l1(){
	if(row == 3){
		return;	
	}
	if(column > 4){
		return;
	}
	if((gameTemplate[column][row] == gameTemplate[column + 1][row]) && (gameTemplate[column][row] == gameTemplate[column + 2][row]) && (gameTemplate[column][row] == gameTemplate[column + 2][row + 1])){
		kazanma = 1;
		return;
	}
}
void l2(){
	if(row == 3){
		return;	
	}
	if(column > 5){
		return;
	}
	if((gameTemplate[column][row] == gameTemplate[column - 1][row]) && (gameTemplate[column][row] == gameTemplate[column + 1][row]) && (gameTemplate[column][row] == gameTemplate[column + 1][row + 1])){
		kazanma = 1;
		return;
	}
}
void l3(){
	if(row == 3){
		return;	
	}
	if((gameTemplate[column][row] == gameTemplate[column - 1][row]) && (gameTemplate[column][row] == gameTemplate[column - 2][row]) && (gameTemplate[column][row] == gameTemplate[column][row + 1])){
		kazanma = 1;
		return;
	}
}
void l4(){
	if(row == 3){
		return;	
	}
	if((gameTemplate[column][row] == gameTemplate[column][row - 1]) && (gameTemplate[column][row] == gameTemplate[column - 1][row - 1]) && (gameTemplate[column][row] == gameTemplate[column - 2][row - 1])){
		kazanma = 1;
		return;
	}
}

int main()
{
	print(gameTemplate);

   gamePlay();





    return 0;
}
