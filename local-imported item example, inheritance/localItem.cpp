#include <string>
#include "localItem.h"
#include "item.h"

using namespace std;

localItem::localItem(string d, double p) : item( d,  p){
}
localItem::localItem(){
	
}

void localItem :: setTaxRate(double r){
	taxRate = r;
}

double localItem :: tax(){
	return price * (taxRate + 1);
}
