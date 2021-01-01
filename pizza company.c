#include<stdlib.h>
#include<stdio.h>
#include<string.h>




typedef struct Customer{
	int customerNo;
	int cPhone;
}Customer;


typedef struct Pizza{
	
	enum{
	Margherita,
	Neapolitan,
	Chicago
	}type;
	
	
}Pizza;


typedef struct Order{
	int orderNumber;
	
	Pizza pizza;
	
	Customer *customer;
	
	int amount;
	

}Order;

int main(){
	
	Order order;
	
	int selection;
	int inList=-1;
	int cnumber;
	
	
	
    
	
	Customer cs1={3,2165654444};
    Customer cs2={4,2123433466};
    Customer cs3={5,2168787444};

	Customer customers[3]={cs1,cs2,cs3};
	
	do{
    int i=0;
    printf("Enter your customer number please:");
		scanf("%d",&cnumber);
    for(i=0; i<3;i++)
    	if(customers[i].customerNo==cnumber){
		    inList=i;
	        break;
		}
		i=0;
	}while(inList==-1);
	
	order.customer = &customers[inList];
	
	printf("Welcome Kooopernik Pizza\n");
	printf("Enter your pizza selection:\n");
	printf("Margherita(Press 1) \n Neapolitan (Press 2)\n Chicago (Press 3)");
	printf("Enter your choice: ");
	scanf("%d",&selection);
	
	if(selection == 1){
		order.pizza.type = Margherita;
	}
	else if(selection == 2){
		order.pizza.type = Neapolitan;
	}
	else if(selection == 3){
		order.pizza.type = Chicago;
	}
	
	printf("Enter amount of pizza you want to buy : ");
	scanf("%d", &order.amount);
	

	
	

	switch(order.pizza.type){
		case Margherita : 
			printf("Your order details\n Your Customer No : %d\n Your Phone Number : %d \n Selected Pizza Type : Margherita\n", order.customer->customerNo, order.customer.cPhone);
			break;
		case Neapolitan :
			printf("Your order details\n Your Customer No : %d, Your Phone Number : %d, Selected Pizza Type : Neopolitan\n", order.customer->customerNo, order.customer->cPhone);

			break;
		case Chicago :
			printf("Your order details\n Your Customer No : %d, Your Phone Number : %d, Selected Pizza Type : Chiago\n", order.customer->customerNo, order.customer->cPhone);
			break;
	}
	
	
	printf("Amount of pizza you wanted to buy : %d\n", order.amount);
	
	printf("Thanks for your selection, your order will be delivered within 30 minutes\n");  
	
	return 0;
}
