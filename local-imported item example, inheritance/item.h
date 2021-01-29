#ifndef ITEM_H
#define ITEM_H
#include <string>
using namespace std;
class item{
	public:
		string description;
		double price;
		
		string getDescription(){
			return description;
		}
		double getPrice(){
			return price;
		}
		item(string d, double p);
		item();
		virtual double tax();
};

#endif

