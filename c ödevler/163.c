#include<stdio.h>

void f1(int x);
void f2(int y);


int main(){
    int myInt;

    printf("Enter the integer ");
    scanf("%d",&myInt);
    f1(myInt);
}

void f1(int x){
    if(x < 10){
        printf("%d",x);
    }
    else if(x >= 10){
        f2(x);
    }
}
void f2(int y){
    int remainder = 0;
    int sum = 0;

    while(y > 0){
        remainder = y % 10;
        sum = sum + remainder;
        y = y / 10;
    }
    f1(sum);

}
