#include "importedItem.h"
#include <string>
importedItem::importedItem(string d, double p) : item(d,p){
	
}
importedItem::importedItem(){
	
}
void importedItem :: setTaxRate(double r){
	taxRate = r;
}

double importedItem :: tax(){
	return price * (taxRate + 1);
}
