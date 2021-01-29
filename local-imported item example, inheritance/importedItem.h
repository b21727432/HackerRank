#ifndef IMPORTEDITEM_H
#define IMPORTEDITEM_H
#include "item.h"
#include <string>
class importedItem : public item
{
    public:
    	static double taxRate;
    	
        importedItem(string d, double p);
        importedItem();
        static double getTaxRate(){
			return taxRate;
        }
        
        static void setTaxRate(double r);
        
        double tax();

};

#endif

