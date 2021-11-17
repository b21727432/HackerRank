#include<stdio.h>
int main(){
    int x;
    int sum = 0;
    int remainder = 0;
    int i;
    int prime = 1;

    //find the sum of the digits
    printf("Enter a number: ");
    scanf("%d", &x);
    while(x>0){
        remainder = x % 10;
        sum = sum + remainder;
        x = x / 10;
    }
    //find if the sum is prime
    for(i = 2; i < sum; i++){
        if((sum % i) == 0){
            prime = 0;
        }
    }
    if(prime == 1){
        printf("%d is a prime number", sum);

    }
    else{
        printf("%d is not a prime number", sum);
    }
    return 0;
}
