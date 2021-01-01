#include<stdlib.h>
#include<stdio.h>
#include<string.h>


struct Item{
	char itemName[30];
	int quantity;
	float price;
	float amount;
};

int main(){
	
	struct Item itm;
	struct Item *pItem;
	pItem = &itm;
	readItem(pItem);
	printItem(pItem);
	
	
	return 0;
}

void readItem(struct Item *i){
	
	char temp[30];
	int tempquantity;
	float tempprice, tempamount;
	printf("enter item name : ");
	scanf("%s", &i->itemName);
	printf("enter item quantity : ");
	scanf("%d", &i->quantity);
	printf("enter item price : ");
	scanf("%f", &i->price);
	&i->amount = &i->quantity * &i->price;
	
	
}

void printItem(struct Item *i){
	printf("name of item : %s, item quantity : %d, item price : %f, item amount : %f\n", i->itemName, i->quantity, i->price, i->amount);
}
