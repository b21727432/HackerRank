#include <string>
#include "item.h"
item :: item(string d, double p)
{
	description = d;
	price = p;
}

double item :: tax(){
	return 0;
}
