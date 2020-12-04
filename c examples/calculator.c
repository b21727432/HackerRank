#include <stdio.h>

void sum(double a, double b){
	printf("Summing %lf and %lf\n", a, b);
	printf("The result is : %lf", a+b);
}
	
void subtract(double a, double b){
	printf("Subtracting %f from %f\n",a, b);
	printf("The result is : &f", a-b);
}
	

void multiply(double a, double b){

	printf("Multiplying %f with %f", a, b);
	printf("The result is : %f", a*b);
}
void divide(double a, double b){
	if(b == 0){
		printf("Error attemping to divide by zero");
		printf("Enter another number\n");
		
		scanf("%lf", &b);
	}
	else{
		printf("Dividing %f with %f", a, b);
		printf("The result is : %f", a/b);
	}
}
	

void (*p[4]) (double a, double b) = {sum, subtract, multiply, divide};

int main(){
	
	/*p[0] = sum;
	p[1] = subtract;
	p[2] = mul;
	p[3] = div;*/
	
	printf("===.Calculator Menu.===\n");
	printf("Please Select from the options below \n");
	
	printf("(0) Add a number to another \n");
	printf("(1) Subtract a number from another\n");
	printf("(2) Multiply a number to another\n");
	printf("(3) Divide a number by another\n");
	
	int secim;
	while(1){
		printf("Enter your selection : ");
		scanf("%d", &secim);
	
		if(secim == 0 || secim == 1 || secim == 2 || secim == 3){
			break;
		}
		else{
			printf("invalid selection select again");
		}
	}
	
	double a, b;
	printf("Enter a number\n");
	scanf("%lf", &a);
	printf("Enter another number\n");
	scanf("%lf", &b);
	
	(*p[secim])(a, b);
	
	
	
	
	return 0;
}
