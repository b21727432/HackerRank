#ifndef LOCALITEM_H
#define LOCALITEM_H
#include "item.h"
#include <string>
using namespace std;
class localItem : public item{
    public:
    	static double taxRate;
    	
        localItem(string d, double p);
		localItem();
        static double getTaxRate(){
			return taxRate;
        }
        static void setTaxRate(double r);
        
        double tax();
};

#endif

