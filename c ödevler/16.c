#include <stdio.h>
#include <string.h>
int main(){
    int myInt;
    char myStr[5];
    double myDouble;
    char myChar;

    scanf("%d", &myInt);
    scanf("%s", myStr);
    scanf("%lf", &myDouble);
    scanf(" %c", &myChar);

    printf("%d %s %lf %c", myInt, myStr, myDouble, myChar);

    return 0;
}
